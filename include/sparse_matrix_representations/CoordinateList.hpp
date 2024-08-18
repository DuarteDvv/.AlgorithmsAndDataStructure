#ifndef MATRIX_COO
#define MATRIX_COO

#include <iostream>
#include <vector>

template <typename T>
struct Element
{
   int line;
   int col;
   T value;
};

template <typename T>
class CoordinateList
{
private:
   Element<T> *Matrix;
   int rows;     // Número de linhas da matriz
   int cols;     // Número de colunas da matriz
   int size;     // Número de elementos armazenados
   int capacity; // Capacidade atual do array

   // Método para redimensionar o array dinâmico quando necessário
   void resize();

   int findInsertPosition(int linha, int coluna);

public:
   CoordinateList(int linhas, int colunas, bool leTeclado);

   ~CoordinateList()
   {
      delete[] Matrix;
   }

   T Get(int linha, int coluna)
   {
      for (int i = 0; i < size; ++i)
      {
         if (Matrix[i].line == linha && Matrix[i].col == coluna)
         {
            return Matrix[i].value;
         }
      }
      return 0; // Retorna 0 se o elemento não estiver armazenado explicitamente (matriz esparsa)
   }

   void Set(int linha, int coluna, T valor)
   {
      if (linha >= rows || coluna >= cols || linha < 0 || coluna < 0)
      {
         std::cerr << "Posição inválida!" << std::endl;
         return;
      }

      if (valor == 0)
         return;

      int pos = findInsertPosition(linha, coluna);

      // Se o elemento já existe, atualiza o valor
      if (pos < size && Matrix[pos].line == linha && Matrix[pos].col == coluna)
      {
         Matrix[pos].value = valor;
         return;
      }

      // Se o array estiver cheio, redimensiona
      if (size == capacity)
      {
         resize();
         pos = findInsertPosition(linha, coluna); // Recalcula a posição após redimensionar
      }

      // Move os elementos posteriores para a direita
      for (int i = size; i > pos; --i)
      {
         Matrix[i] = Matrix[i - 1];
      }

      // Insere o novo elemento
      Matrix[pos] = {linha, coluna, valor};
      ++size;
   }

   void Imprime() // O(n^2)
   {
      for (int i = 0; i < rows; ++i)
      {
         for (int j = 0; j < cols; ++j)
         {
            std::cout << Get(i, j) << " ";
         }
         std::cout << std::endl;
      }
   }

   // Somar duas matrizes COO
   static CoordinateList<T> Soma(const CoordinateList<T> &A, const CoordinateList<T> &B) // O(max(k1,k2)) sendo k o size
   {
      if (A.rows != B.rows || A.cols != B.cols)
      {
         throw std::invalid_argument("Dimensões das matrizes incompatíveis");
      }

      CoordinateList<T> C(A.rows, A.cols, false);
      int kA = 0, kB = 0;

      while (kA < A.size && kB < B.size)
      {
         if (A.Matrix[kA].line < B.Matrix[kB].line || (A.Matrix[kA].line == B.Matrix[kB].line && A.Matrix[kA].col < B.Matrix[kB].col))
         {
            C.Set(A.Matrix[kA].line, A.Matrix[kA].col, A.Matrix[kA].value);
            ++kA;
         }
         else if (A.Matrix[kA].line > B.Matrix[kB].line || (A.Matrix[kA].line == B.Matrix[kB].line && A.Matrix[kA].col > B.Matrix[kB].col))
         {
            C.Set(B.Matrix[kB].line, B.Matrix[kB].col, B.Matrix[kB].value);
            ++kB;
         }
         else
         {
            T valor = A.Matrix[kA].value + B.Matrix[kB].value;
            if (valor != 0)
            {
               C.Set(A.Matrix[kA].line, A.Matrix[kA].col, valor);
            }
            ++kA;
            ++kB;
         }
      }

      while (kA < A.size)
      {
         C.Set(A.Matrix[kA].line, A.Matrix[kA].col, A.Matrix[kA].value);
         ++kA;
      }

      while (kB < B.size)
      {
         C.Set(B.Matrix[kB].line, B.Matrix[kB].col, B.Matrix[kB].value);
         ++kB;
      }

      return C;
   }

   // Produto da matriz por um vetor
   static T *ProdutoVec(const CoordinateList<T> &A, const T *v, int n) // Cada linha x Vec O(k) sendo k a quantidade armazenada
   {
      if (A.cols != n)
      {
         throw std::invalid_argument("Dimensões da entrada incompatíveis");
      }

      T *s = new T[A.rows]();
      for (int i = 0; i < A.size; ++i) // Passa pelo array de elementos inteiro e multiplica linhas com repectivo vec
      {
         int linha = A.Matrix[i].line;
         int coluna = A.Matrix[i].col;
         s[linha] += A.Matrix[i].value * v[coluna];
         // Elemento da linha 0 vai ser a soma dos produtos da linha 0 com o vetor
         //(cada respectivo elemento de cada coluna da linha é multiplicado pelo seu respectivo no vetor)
      }
      return s;
   }

   static CoordinateList<T> Multiplicacao(const CoordinateList<T> &A, const CoordinateList<T> &B)
   {
      if (A.cols != B.rows) // número de colunas diferente do número de linhas
      {
         throw std::invalid_argument("Dimensões das matrizes incompatíveis para multiplicação");
      }

      CoordinateList<T> C(A.rows, B.cols, false);

      // Criar um vetor de vetores para armazenar os elementos de B por linha
      std::vector<std::vector<Element<T>>> B_by_row(B.rows);

      // Preencher o vetor de vetores com os elementos de B
      for (int i = 0; i < B.size; ++i)
      {
         B_by_row[B.Matrix[i].line].push_back(B.Matrix[i]);
      }

      // Para cada elemento de A, encontrar elementos correspondentes em B
      for (int i = 0; i < A.size; ++i)
      {
         int rowA = A.Matrix[i].line;
         int colA = A.Matrix[i].col;
         T valA = A.Matrix[i].value;

         // Percorrer elementos de B na linha colA
         for (const Element<T> &elemB : B_by_row[colA])
         {
            int colB = elemB.col;
            T valB = elemB.value;

            // Produto dos elementos
            T valor = valA * valB;

            // Acumular no resultado
            T soma = C.Get(rowA, colB) + valor;

            // Se a soma for diferente de zero, insere no resultado
            if (soma != 0)
            {
               C.Set(rowA, colB, soma);
            }
         }
      }

      return C;
   }
};

template <typename T>
void CoordinateList<T>::resize()
{
   capacity++;
   Element<T> *newMatrix = new Element<T>[capacity];
   for (int i = 0; i < size; ++i)
   {
      newMatrix[i] = Matrix[i];
   }
   delete[] Matrix;
   Matrix = newMatrix;
}

template <typename T>
int CoordinateList<T>::findInsertPosition(int linha, int coluna)
{
   int left = 0;
   int right = size - 1;
   while (left <= right)
   {
      int mid = left + (right - left) / 2;
      if (Matrix[mid].line < linha || (Matrix[mid].line == linha && Matrix[mid].col < coluna))
      {
         left = mid + 1;
      }
      else
      {
         right = mid - 1;
      }
   }
   return left;
}

template <typename T>
CoordinateList<T>::CoordinateList(int linhas, int colunas, bool leTeclado) : rows(linhas), cols(colunas), size(0)
{
   if (leTeclado)
   {
      capacity = (int)(0.5 * linhas * colunas);
      Matrix = new Element<T>[capacity];
      std::cout << "Digite os elementos no formato linha coluna valor (digite -1 -1 -1 para parar):" << std::endl;
      while (true)
      {
         int linha, coluna;
         T valor;
         std::cin >> linha >> coluna >> valor;
         if (linha == -1 && coluna == -1 && valor == -1)
         {
            break;
         }
         Set(linha, coluna, valor);
      }
   }
   else
   {
      capacity = linhas;
      Matrix = new Element<T>[capacity];
   }
}
#endif // MATRIX_COO