#ifndef HASH_OPEN
#define HASH_OPEN

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class HashTableOpen
{
private:
   int M; // Tamanho da tabela hash
   vector<T> Tabela;
   vector<bool> vazio;
   vector<bool> retirado;

   int Hash(int chave) const
   {
      return chave % M;
   }

   void Redimensiona()
   {
      int oldM = M;
      M *= 2;
      vector<T> oldTabela = Tabela;
      vector<bool> oldVazio = vazio;
      vector<bool> oldRetirado = retirado;

      Tabela.resize(M);
      vazio.resize(M, true);
      retirado.resize(M, false);

      for (int i = 0; i < oldM; ++i)
      {
         if (!oldVazio[i] && !oldRetirado[i])
         {
            Insere(oldTabela[i]);
         }
      }
   }

public:
   HashTableOpen(int tamanhoInicial = 101);
   T Pesquisa(int chave) const;
   void Insere(T item);
   void Remove(int chave);
};

template <typename T>
HashTableOpen<T>::HashTableOpen(int tamanhoInicial) : M(tamanhoInicial), Tabela(tamanhoInicial), vazio(tamanhoInicial, true), retirado(tamanhoInicial, false) {}

template <typename T>
T HashTableOpen<T>::Pesquisa(int chave) const
{
   int pos = Hash(chave);
   int i = 0;

   while ((i < M) && !vazio[(pos + i) % M] && (Tabela[(pos + i) % M].GetChave() != chave))
      i++;

   if ((i < M) && (Tabela[(pos + i) % M].GetChave() == chave) && !retirado[(pos + i) % M])
   {
      return Tabela[(pos + i) % M];
   }
   else
   {
      throw runtime_error("Erro: Item não encontrado");
   }
}

template <typename T>
void HashTableOpen<T>::Insere(T item)
{
   try
   {
      Pesquisa(item.GetChave());
      throw runtime_error("Erro: Item já está presente");
   }
   catch (runtime_error &e)
   {
      // Item não encontrado, prossegue para inserir
   }

   int pos = Hash(item.GetChave());
   int i = 0;

   while ((i < M) && !vazio[(pos + i) % M] && !retirado[(pos + i) % M])
      i++;

   if (i == M)
   {
      Redimensiona();
      Insere(item);
   }
   else
   {
      Tabela[(pos + i) % M] = item;
      vazio[(pos + i) % M] = false;
      retirado[(pos + i) % M] = false;
   }
}

template <typename T>
void HashTableOpen<T>::Remove(int chave)
{
   int pos = Hash(chave);
   int i = 0;

   while ((i < M) && !vazio[(pos + i) % M] && (Tabela[(pos + i) % M].GetChave() != chave))
      i++;

   if ((i < M) && (Tabela[(pos + i) % M].GetChave() == chave) && !retirado[(pos + i) % M])
   {
      retirado[(pos + i) % M] = true;
   }
   else
   {
      throw runtime_error("Erro: Item não está presente");
   }
}

#endif
