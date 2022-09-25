#include"vertice.h"

Vertice::Vertice(int x, string y, string z){
    id = x;
    nome = y;
    categoria = z;
};


void Vertice::print(){
    cout << "\nID: " << id << endl
            << "Nome: " << nome << endl
            << "Categoria: " << categoria << endl;
}