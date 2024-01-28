class Stack:
    def __init__(self):
        self.data = []

    # Método para empilhar um elemento na pilha
    def push(self, value):
        self.data.append(value)

    # Método para desempilhar um elemento da pilha
    def pop(self):
        if not self.is_empty():
            self.data.pop()

    # Método para verificar se a pilha está vazia
    def is_empty(self):
        return len(self.data) == 0

    # Método para obter o elemento no topo da pilha
    def top(self):
        if not self.is_empty():
            return self.data[-1]
        # Retornar um valor especial se a pilha estiver vazia (pode ser ajustado conforme necessário)
        return -1

# Exemplo de uso da pilha
my_stack = Stack()

# Empilhando alguns elementos
my_stack.push(5)
my_stack.push(10)
my_stack.push(20)

# Obtendo o elemento no topo
print("Top element:", my_stack.top())

# Desempilhando um elemento
my_stack.pop()

# Verificando se a pilha está vazia
if my_stack.is_empty():
    print("Stack is empty.")
else:
    print("Stack is not empty.")
