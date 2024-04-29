#ifndef LIST
#define LIST

#define static const int MAXTAM 1000

template<typename T>
class List {

    protected:
        int size;
        
    public:
        List(): size(0) {};
        int getSize() { return size;} const;
        bool empty() { return size == 0;} const;

        virtual T getObject(int pos) const = 0;
        virtual T removeBegin() = 0;
        virtual T removeEnd() = 0;
        virtual T removePos(int pos) = 0;
        virtual void setObject(T object, int pos) = 0;
        virtual void insertBegin(T object) = 0;
        virtual void insertEnd(T object) = 0;
        virtual void insertPos(T object, int pos) = 0;
        virtual void print() const = 0;
        virtual void clear() = 0;
};
 
template<typename T>
class ArrayList : List<T>
{
    private:
        T objects[MAXTAM];

    public:
        ArrayList(): List() {};
        T getObject(int pos) const override;
        T removeBegin() override;
        T removeEnd() override;
        T removePos(int pos) override;
        void setObject(T item, int pos) override;
        void insertBegin(T object) override;
        void insertEnd(T object) override;
        void insertPos(T object, int pos) override;
        void print() override;
        void clear() override;

    
};

template<typename T>
class LinkedList : List<T> {

};

template<typename T>
class DualLinkedList : List<T> {

};

template<typename T>
class LinkedListOrdered : List<T> {

};







#endif