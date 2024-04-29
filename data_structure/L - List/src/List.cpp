#include <List.hpp>

//O(1)
template<typename T>
T ArrayList<T>::getObject(int pos) const{
    if(pos > size || pos < 0) throw "ERROR: Invalid Position";
    return objects[pos];
}


//O(n)
template<typename T>
T ArrayList<T>::removeBegin(){
    if (size == 0) throw "ERROR: Empty";
    T aux = objects[0];
    for(int i = 0; i < size;i++) objects[i] = objects[i+1];

    size--;
    return aux;
} 

//O(1)
template<typename T>
T ArrayList<T>::removeEnd(){
    if (size == 0) throw "ERROR: Empty";
    T aux = objects[size];

    size--;
    return aux;

}

//Best: O(1) Worst: O(n)
template<typename T>
T ArrayList<T>::removePos(int pos){
    if (size == 0) throw "ERROR: Empty";
    if(pos > size || pos < 0) throw "ERROR: Invalid Position";

    T aux = objects[pos];
    for(int i = pos; i > size; i++) objects[i] = objects[i+1];
    
    size--;

    return aux;

}

//O(1)
template<typename T>
void ArrayList<T>::setObject(T obj, int pos){
    if(pos > size || pos < 0) throw "ERROR: Invalid Position";

    objects[pos] = obj;
}

//O(n)
template<typename T>
void ArrayList<T>::insertBegin(T obj){
    if (size == MAXTAM) throw "ERROR: Already full";

    size++;

    for(int i = size; i > 0; i-- ) objects[i] = objects[i-1];
    
    objects[0] = obj;
}

//O(1)
template<typename T>
void ArrayList<T>::insertEnd(T obj){
    if (size == MAXTAM) throw "ERROR: Already full";

    objects[size] = obj;

}

// Best: O(n) Worst: O(1)
template<typename T>
void ArrayList<T>::insertPos(T obj, int pos){
    if (size == MAXTAM) throw "ERROR: Already full!";
    if (pos > size || pos <= 0) throw "ERROR: Invalid Position";

    size++;
    for(int i = size; i > pos; i-- ) objects[i] = objects[i-1];
    objects[pos] = obj;



}

template<typename T>
void ArrayList<T>::clear(){
    size = 0;
}

template<typename T>
void ArrayList<T>::print(){

    for(int i = 0; i < size; i++) std::cout << objects[i] << std::endline;

}





