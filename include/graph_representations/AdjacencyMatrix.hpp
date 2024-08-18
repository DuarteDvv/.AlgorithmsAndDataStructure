#ifndef ADJ_MATRIX
#define ADJ_MATRIX

#define Vertex int;

#include "iostream"
using std::cout;


struct Adjacency_Matrix{

    
        bool** matrix;
        int numberOfV;
        
        Adjacency_Matrix(int Vert);
        ~Adjacency_Matrix();
        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        void print();

};


Adjacency_Matrix::Adjacency_Matrix(int Vert){
    numberOfV = Vert;

    matrix = new bool*[Vert];
    for(int i = 0; i < Vert; i++){
        matrix[i] = new bool[Vert];
    }
}

Adjacency_Matrix::~Adjacency_Matrix(){
    for (int i = 0; i < numberOfV; i++)
      delete[] matrix[i];

    delete[] matrix;

}

void Adjacency_Matrix::addEdge(int i, int j){
    matrix[i][j] = true;
}

void Adjacency_Matrix::removeEdge(int i, int j){
    matrix[i][j] = false;
}

void Adjacency_Matrix::print() {
    for (int i = 0; i < numberOfV; i++) {
      cout << i << " : ";
      for (int j = 0; j < numberOfV; j++)
        cout << matrix[i][j] << " ";
      cout << "\n";
    }
}



#endif