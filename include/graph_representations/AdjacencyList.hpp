#ifndef ADJ_LIST
#define ADJ_LIST

#define Vertex int;

#include "iostream"
using std::cout;
#include "Container.hpp"
#include "tools.hpp"

struct Adjacency_List{

    LinkedList<int>* adj_list;
    int numberOfV;

    
    Adjacency_List(int Vert);
    ~Adjacency_List();
    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    void print();

};

Adjacency_List::Adjacency_List(int Vert){
    numberOfV = Vert;

    adj_list = new LinkedList<int>[numberOfV]();
} 

Adjacency_List::~Adjacency_List(){
    delete[] adj_list;
}

void Adjacency_List::addEdge(int i, int j){
    adj_list[i].insertEnd(j);
}

void Adjacency_List::removeEdge(int i, int j){
    for(int k = 0; k < adj_list[i].getSize(); k++){
        if(adj_list[i].getObject(k) == j){
            adj_list[i].removePos(k);
            break;
        }
    }
}

void Adjacency_List::print(){
   
    for(int i = 0; i < numberOfV; i++){
        cout << i << " : ";
        for(int k = 0; k < adj_list[i].getSize(); k++){
            cout << adj_list[i].getObject(k) << " ";
        }
        cout << "\n";
    }
}

#endif