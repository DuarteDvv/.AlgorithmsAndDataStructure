class Stack:
    def __init__(self):
        self.data = []

    
    def push(self, value):
        self.data.append(value)

    
    def pop(self):
        if not self.is_empty():
            self.data.pop()

   
    def is_empty(self):
        return len(self.data) == 0

    
    def top(self):
        if not self.is_empty():
            return self.data[-1]
        
        return -1


my_stack = Stack()


my_stack.push(5)
my_stack.push(10)
my_stack.push(20)


print("Top element:", my_stack.top())


my_stack.pop()


if my_stack.is_empty():
    print("Stack is empty.")
else:
    print("Stack is not empty.")
