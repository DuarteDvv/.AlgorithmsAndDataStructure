#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    // Método para empilhar um elemento na pilha
    void push(int value) {
        data.push_back(value);
    }

    // Método para desempilhar um elemento da pilha
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    // Método para verificar se a pilha está vazia
    bool isEmpty() {
        return data.empty();
    }

    // Método para obter o elemento no topo da pilha
    int top() {
        if (!isEmpty()) {
            return data.back();
        }
        // Retornar um valor especial se a pilha estiver vazia (pode ser ajustado conforme necessário)
        return -1;
    }
};

int main() {
    // Exemplo de uso da pilha
    Stack myStack;

    // Empilhando alguns elementos
    myStack.push(5);
    myStack.push(10);
    myStack.push(20);

    // Obtendo o elemento no topo
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Desempilhando um elemento
    myStack.pop();

    // Verificando se a pilha está vazia
    if (myStack.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}
