#ifndef HASH_LIST
#define HASH_LIST

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class HashTableLinked // Tamanho esperado das listas (e todas as operações) é O(N/M) sendo N numero de registros e M tamanho da tabela
{
private:
   int M;
   vector<T> *Tabela;

   int Hash(int chave)
   {
      return chave % M;
   }

public:
   HashTableLinked(int tamanho);
   ~HashTableLinked();
   T Pesquisa(int chave);
   void Insere(T item);
   void Remove(int chave);
};

template <typename T>
HashTableLinked<T>::HashTableLinked(int tamanho) : M(tamanho)
{
   Tabela = new vector<T>[M];
}

template <typename T>
HashTableLinked<T>::~HashTableLinked()
{
   delete[] Tabela;
}

template <typename T>
T HashTableLinked<T>::Pesquisa(int chave)
{
   int pos = Hash(chave);

   for (int i = 0; i < Tabela[pos].size(); i++)
   {
      if (Tabela[pos][i].GetChave() == chave)
         return Tabela[pos][i];
   }

   throw("Erro: Item não encontrado");
}

template <typename T>
void HashTableLinked<T>::Insere(T item)
{
   int chave = item.GetChave();
   int pos = Hash(chave);

   // Verificar se o item já existe
   for (int i = 0; i < Tabela[pos].size(); i++)
   {
      if (Tabela[pos][i].GetChave() == chave)
         throw("Erro: Item já está presente");
   }

   Tabela[pos].push_back(item);
}

template <typename T>
void HashTableLinked<T>::Remove(int chave)
{
   int pos = Hash(chave);

   for (int i = 0; i < Tabela[pos].size(); i++)
   {
      if (Tabela[pos][i].GetChave() == chave)
      {
         Tabela[pos].erase(Tabela[pos].begin() + i);
         return;
      }
   }

   throw("Erro: Item não encontrado");
}

#endif
