#ifndef QUEUE
#define QUEUE

#include <thread>
#include <mutex>
#include <condition_variable>

using std::mutex;
using std::lock_guard;


#define MAXSIZE 1000

template<typename T>
class Queue{
    protected:
        int size;

    public:
        Queue(): size(0) {};
        int getSize() const {return size;};
        bool isEmpty() { return this->size == 0;};

        virtual T unqueue() = 0;
        virtual void enqueue(T obj) = 0;
        virtual void clear() = 0;
};

////////////////////////////////////////////////////

template<typename T>
class ArrayQueue : public Queue<T>{
    private:
        T objects[MAXSIZE];

    public:
        ArrayQueue(): Queue<T>() {};
        T unqueue() override;
        void enqueue(T obj) override;
        void clear() override;
};

//O(1)
template<typename T>
void ArrayQueue<T>::enqueue(T obj){
    if(this->size == MAXSIZE) throw "Error: Queue full";
    this->objects[this->size++] = obj;
}                       

//O(n)
template<typename T>
T ArrayQueue<T>::unqueue (){
    if(this->size == 0) throw "Error: Empty Queue";
    T aux = this->objects[0];

    for(int i = 0; i < this->size - 1; i++) this->objects[i] = this->objects[i + 1];
    this->size--;

    return aux;
}

//O(1)
template<typename T>
void ArrayQueue<T>::clear(){
    this->size = 0;
}

 ///////////////////////////////////////////////////////////////////

template<typename T>
class CircularArrayQueue : public Queue<T>{
    private:
        T objects[MAXSIZE];
        int front;
        int back;

    public:
        CircularArrayQueue(): Queue<T>(), front(0), back(0) {};

        void enqueue(T obj) override;
        T unqueue() override;
        void clear() override;

};

//O(1)
template<typename T>
void CircularArrayQueue<T>::enqueue(T obj){
    if(this->size == MAXSIZE) throw "Error: Queue full";

    this->objects[this->back] = obj;
    this->back = (this->back + 1) % MAXSIZE;
    this->size++;
}                       

//O(1)
template<typename T>
T CircularArrayQueue<T>::unqueue (){
    if(this->size == 0) throw "Error: Empty Queue";

    T aux = this->objects[this->front];

    this->front = (this->front + 1) % MAXSIZE;

    this->size--;
    
    return aux;
}

//O(1)
template<typename T>
void CircularArrayQueue<T>::clear(){
    this->size = 0;
    this->front = 0;
    this->back = 0;
}

////////////////////////////////////////////////////////////////

template<typename T>
class LinkedQueue : public Queue<T>{
    private:
        struct Cell{
            T data;
            Cell* next;

           Cell(const T& Data, Cell* Next = nullptr)
            : data(Data), next(Next) {};
        };

        Cell* head;
        Cell* tail;

        public:

            LinkedQueue(): Queue<T>(), head(new Cell(T())), tail(head) {};
            //O(n)
            ~LinkedQueue(){
                Cell* current = head;
                while (current != nullptr) {
                    Cell* next = current->next;
                    delete current;
                    current = next;
                }
            }
            void enqueue(T obj) override;
            T unqueue() override;
            void clear() override;

};


//O(1)
template<typename T>
void LinkedQueue<T>::enqueue(T obj){
    Cell* newCell = new Cell(obj);
    tail->next = newCell;
    tail = newCell;
    this->size++;
}                       

//O(1)
template<typename T>
T LinkedQueue<T>::unqueue (){
    if(this->size == 0) throw "Error: Empty Queue";

    Cell* p = head->next;
    T aux = p->data;

    head->next = p->next;
    delete p;
    this->size--;
    
    return aux;
}

//O(n)
template<typename T>
void LinkedQueue<T>::clear(){
    while(!(this->isEmpty())){
        unqueue();
    } 
}

///////////////////////////////////////////////////

template<typename T>
class VectorQueue : public Queue<T>{
    private:
        T* objects;
        int capacity;

        void resize(int newCapacity);

    public:
        VectorQueue(): Queue<T>(), objects(nullptr), capacity(0) {};

        T unqueue() override;
        void enqueue(T obj) override;
        void clear() override;

};


//O(n)
template<typename T>
void VectorQueue<T>::enqueue(T obj){
    if (this->size == capacity) {
        resize((capacity == 0) ? 1 : capacity * 2);
    }
    objects[this->size++] = obj;
}                       

//O(n)
template<typename T>
T VectorQueue<T>::unqueue (){
    if(this->size == 0) throw "Error: Empty Queue";
    T aux = this->objects[0];

    for(int i = 0; i < this->size - 1; i++) this->objects[i] = this->objects[i + 1];
    this->size--;

    return aux;
}

//O(1)
template<typename T>
void VectorQueue<T>::clear(){
    delete this->objects;
    this->size = 0;
    this->capacity = 0;
}

//O(n)
template<typename T>
void VectorQueue<T>::resize(int newCapacity) {
    T* newObjects = new T[newCapacity];
    for (int i = 0; i < this->size; ++i) {
        newObjects[i] = this->objects[i];
    }
    delete[] this->objects;
    this->objects = newObjects;
    this->capacity = newCapacity;
}

/////////////////////////////////////////////////////////////////////////

template<typename T>
class Deque :public Queue<T> {
    private:
        struct DoublyCell {
            T data;
            DoublyCell* next;
            DoublyCell* prev;
            DoublyCell(const T& newData, DoublyCell* newNext = nullptr, DoublyCell* newPrev = nullptr)
                : data(newData), next(newNext), prev(newPrev) {};
        };

        DoublyCell* head;
        DoublyCell* tail;

    public:

        Deque(): Queue<T>(), head(new DoublyCell(T())), tail(head){};
        ~Deque(){
            DoublyCell* current = head;
            while (current != nullptr) {
                DoublyCell* next = current->next;
                delete current;
                current = next;
            }
        };

        T unqueue() override;
        T unqueueRight();
        void enqueue(T obj) override;
        void enqueueLeft(T obj);
        void clear() override;


 
};

//O(1)
template<typename T>
void Deque<T>::enqueue(T obj){
    DoublyCell* newCell = new DoublyCell(obj, nullptr, tail);
    tail->next = newCell;
    tail = newCell;
    this->size++;
}    

//O(1)
template<typename T>
void Deque<T>::enqueueLeft(T obj){
    DoublyCell* newDoublyCell = new DoublyCell(obj, head->next, head);
    if (head->next != nullptr) {
        head->next->prev = newDoublyCell;
    } else {
        tail = newDoublyCell;
    }
    head->next = newDoublyCell;
    this->size++;
}

//O(1)
template<typename T>
T Deque<T>::unqueue (){
    if (this->size == 0) throw "ERROR: Empty";

    DoublyCell* toDelete = head->next;
    T data = toDelete->data;
    head->next = toDelete->next;
    if (toDelete->next != nullptr) {
        toDelete->next->prev = head;
    } else {
        tail = head;
    }
    delete toDelete;
    this->size--;
    return data;
}

//O(1)
template<typename T>
T Deque<T>::unqueueRight(){
    if (this->size == 0) throw "ERROR: Empty";
    DoublyCell* toDelete = tail;
    T data = toDelete->data;
    tail = toDelete->prev;
    tail->next = nullptr;
    delete toDelete;
    this->size--;
    return data;

}

//O(n)
template<typename T>
void Deque<T>::clear(){
    DoublyCell* current = head->next;
    while (current != nullptr) {
        DoublyCell* next = current->next;
        delete current;
        current = next;
    }
    tail = head;
    head->next = nullptr; 
    this->size = 0;
}

//////////////////////////////////////////////////////////////

template<typename T>
class ThreadSafeQueue :public Queue<T> {
    private:
    struct Cell {
        T data;
        Cell* next;

        Cell(const T& Data, Cell* Next = nullptr)
            : data(Data), next(Next) {};
    };

    Cell* head_;
    Cell* tail_;
    mutex uniq_acess; //Mutual exclusion

public:
    ThreadSafeQueue() : Queue<T>(), head_(new Cell(T())), tail_(head_) {}

    ~ThreadSafeQueue() {
        lock_guard<mutex> guard(uniq_acess); //Block the thread until is finished

        Cell* current = head_;
        while (current != nullptr) {
            Cell* next = current->next;
            delete current;
            current = next;
        }
    }

    T unqueue() override;
    void enqueue(T obj) override;
    void clear() override;

};

template<typename T>
void ThreadSafeQueue<T>::enqueue(T obj) {
    lock_guard<mutex> guard(uniq_acess); //Block

    tail_->next = new Cell(obj);
    tail_ = tail_->next;
    this->size++;
}

template<typename T>
T ThreadSafeQueue<T>::unqueue() {
    lock_guard<mutex> guard(uniq_acess); //Block

    if (this->size == 0) throw "Error: Empty Queue";
    T obj = head_->next->data;
    Cell* temp = head_->next;
    head_->next = head_->next->next;
    delete temp;
    if (head_->next == nullptr) tail_ = head_;
    this->size--;
    return obj;
}

template<typename T>
void ThreadSafeQueue<T>::clear() {

    lock_guard<mutex> guard(uniq_acess); //Block

    Cell* current = head_->next;
    while (current != nullptr) {
        Cell* next = current->next;
        delete current;
        current = next;
    }
    head_->next = nullptr;
    tail_ = head_;
    this->size = 0;

    
}


#endif