#ifndef vertice_h
#define vertice_h

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Vertice {
    public:
    Vertice(){};
    Vertice(int x, string y, string z);
    int id;
    string nome;
    string categoria;

    void print();
};

#endif