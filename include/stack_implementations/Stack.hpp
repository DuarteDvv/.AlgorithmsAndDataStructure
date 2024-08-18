#ifndef STACK
#define STACK

#include "tools.hpp"

#define MAXSIZE 1000


template<typename T>
class Stack {
    protected:
        int size;

    public:
        Stack(): size(0){};
        int getSize() const { return this->size; };
        bool isEmpty() const {return size == 0;};

        virtual void stack(T object) = 0;
        virtual T unstack() = 0;
        virtual void clear() = 0;

};

/////////////////////////////////////////////////

template<typename T>
class ArrayStack : public Stack<T>{
    private:
        T objects[MAXSIZE];
        int top;

    public:
        ArrayStack():Stack<T>(), top(-1){};
        void stack(T object) override;
        T unstack() override; 
        void clear() override;

};


//O(1)
template<typename T> 
void ArrayStack<T>::stack(T obj){
    if (this->size == MAXSIZE) {
        throw "Error: Stack is full"; 
    }
    this->objects[++this->top] = obj; 
    this->size++;
}

//O(1)
template<typename T>
T ArrayStack<T>::unstack(){
    if (this->size == 0) {
        throw "Error: Stack is empty"; 
    }

    T aux = this->objects[this->top--]; 
    this->size--;
    return aux;
}

//O(1)
template<typename T> 
void ArrayStack<T>::clear(){
    this->size = 0;
    this->top = -1;
}

///////////////////////////////////////////////////////////////////

template<typename T>
class LinkedStack : public Stack<T>{
    private:
        Cell<T>* top;
        
    public:
        LinkedStack():Stack<T>(), top(nullptr){};
        //O(n)
        ~LinkedStack(){ 
            Cell<T>* aux;
            while(top != nullptr){
                aux = top;
                top = top->next;
                delete aux;  
            }
        }

        void stack(T object) override;
        T unstack() override; 
        void clear() override;
        void sort();


};

//O(1)
template<typename T> 
void LinkedStack<T>::stack(T obj){
    Cell<T>* newCell = new Cell<T>;
    newCell->object = obj;

    newCell->next = top;
    top = newCell;

    this->size++;
   
}

//O(1)
template<typename T>
T LinkedStack<T>::unstack(){
    if (this->size == 0) throw "Error: Stack is empty"; 
    
    Cell<T>* p = top;
    T aux = top->object;

    top = top->next;
    delete p;

    this->size--;
    return aux;
}

//O(n)
template<typename T> 
void LinkedStack<T>::clear(){
    while(!this->isEmpty()){
        this->unstack();
    }
}

//O(n²)
template<typename T>
void LinkedStack<T>::sort() {

    if (this->top == nullptr || this->top->next == nullptr) {
        return;
    }
    
    LinkedStack<T> auxStack; 

    while (!(this->isEmpty())) {
        
        T current = unstack();

        
        while (!auxStack.isEmpty() && auxStack.top->object > current) {
            stack(auxStack.unstack());
        }
        auxStack.stack(current);
    }

    while (!auxStack.isEmpty()) {
        stack(auxStack.unstack());
    }
}


////////////////////////////////////////////////////////////////////////

template<typename T>
class VectorStack : public Stack<T>{
    private:
        T* objects; 
        int capacity; 
        int top; 

    public:
        
        VectorStack(): Stack<T>(), objects(nullptr), capacity(0), top(-1) {}
   
        ~VectorStack() {
            delete[] objects;
        }

        
        void stack(T object) override;
        T unstack() override;
        void clear() override;
        void sort();
        
};

//O(n)
template<typename T>
void VectorStack<T>::stack(T object) {
            
    if (this->top == this->capacity - 1) {
        int newCapacity = (this->capacity == 0) ? 1 : this->capacity * 2; 
        T* newObjects = new T[newCapacity];

        for (int i = 0; i <= this->top; ++i) {
            newObjects[i] = this->objects[i];
        }
        
        delete[] this->objects;
        
        this->objects = newObjects;
        this->capacity = newCapacity;
    }
    
    
    this->objects[++this->top] = object;
    this->size++;
}

//O(1)
template<typename T> 
T VectorStack<T>::unstack() {
    if (this->size == 0) throw "Error: Stack is empty"; 

    
    T object = this->objects[this->top--];
    this->size--;
    return object;
}

//O(1)
template<typename T>
void VectorStack<T>::clear(){
    this->top = -1; 
    this->size = 0;
    this->capacity = 0;
    delete[] this->objects;
    this->objects = nullptr;
}

//O(n²) O(1)
template<typename T>
void VectorStack<T>::sort(){
    if(this->size == 0 || this->size == 1){
        return; 
    }

    VectorStack<T> auxStack;

    while (!(this->isEmpty())) {
        
        T current = unstack();

        
        while (!auxStack.isEmpty() && auxStack.objects[auxStack.top] > current) {
            stack(auxStack.unstack());
        }
        auxStack.stack(current);
    }

    while (!auxStack.isEmpty()) {
        stack(auxStack.unstack());
    }
}

////////////////////////////////////////////////////////////////////


#endif