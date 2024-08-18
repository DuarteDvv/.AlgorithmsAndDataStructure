#include "hash_table_open_ad.hpp"
#include <iostream>

class Item
{
private:
    int chave;
    std::string valor;

public:
    Item(int c = 0, std::string v = "") : chave(c), valor(v) {}

    int GetChave() const
    {
        return chave;
    }

    std::string GetValor() const
    {
        return valor;
    }

    bool operator==(const Item &other) const
    {
        return chave == other.chave;
    }

    bool operator!=(const Item &other) const
    {
        return chave != other.chave;
    }

    bool Vazio() const
    {
        return chave == 0 && valor == "";
    }

    friend std::ostream &operator<<(std::ostream &os, const Item &item)
    {
        os << "Chave: " << item.chave << ", Valor: " << item.valor;
        return os;
    }
};

int main()
{
    HashTableOpen<Item> tabela;

    // Inserindo itens na tabela
    Item item1(1, "Item 1");
    Item item2(2, "Item 2");
    Item item3(3, "Item 3");
    Item item4(4, "Item 4");

    try
    {
        tabela.Insere(item1);
        tabela.Insere(item2);
        tabela.Insere(item3);
        tabela.Insere(item4);

        std::cout << "Itens inseridos com sucesso." << std::endl;

        // Pesquisa de itens
        std::cout << "Pesquisa de item com chave 2: " << tabela.Pesquisa(2) << std::endl;
        std::cout << "Pesquisa de item com chave 4: " << tabela.Pesquisa(4) << std::endl;

        // Remoção de itens
        tabela.Remove(2);
        std::cout << "Item com chave 2 removido." << std::endl;

        // Tentativa de pesquisa após remoção
        try
        {
            std::cout << "Pesquisa de item com chave 2: " << tabela.Pesquisa(2) << std::endl;
        }
        catch (const char *msg)
        {
            std::cerr << msg << std::endl;
        }

        // Tentativa de inserir item duplicado
        try
        {
            tabela.Insere(item1);
        }
        catch (const char *msg)
        {
            std::cerr << msg << std::endl;
        }
    }
    catch (const char *msg)
    {
        std::cerr << msg << std::endl;
    }

    return 0;
}
