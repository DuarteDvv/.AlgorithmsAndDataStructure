#include <List.hpp>

//O(1)
template<typename T>
T ArrayList<T>::getObject(int pos) const{
    if(pos > size || pos < 0) throw "ERROR: Invalid Position";
    return objects[pos];
}

template<typename T>
T ArrayList<T>::removeBegin(){

}

template<typename T>
T ArrayList<T>::removeEnd(){

}

template<typename T>
T ArrayList<T>::removePos(int pos){

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

}

template<typename T>
void ArrayList<T>::print(){

}



