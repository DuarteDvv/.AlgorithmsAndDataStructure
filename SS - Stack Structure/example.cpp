#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
   
    void push(int value) {
        data.push_back(value);
    }

    
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    
    bool isEmpty() {
        return data.empty();
    }

   
    int top() {
        if (!isEmpty()) {
            return data.back();
        }
        
        return -1;
    }
};

int main() {
    
    Stack myStack;

  
    myStack.push(5);
    myStack.push(10);
    myStack.push(20);

    
    std::cout << "Top element: " << myStack.top() << std::endl;

   
    myStack.pop();

    
    if (myStack.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}
