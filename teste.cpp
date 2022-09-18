#include"vertice.h"
#include"vertice.cpp"

vector<Vertice> nodos;

void criaVertice(int tam){

    for (int i = 0; i < tam; i++)
    {
        Vertice v;
        cout << endl << "Digite nome: ";
        cin.ignore();
        getline(cin, v.nome);
        cout << endl << "Digite ID: ";
        cin >> v.id;
        cout << endl << "Digite categoria: ";
        cin.ignore();
        getline(cin, v.categoria);

        nodos.push_back(v);

    }
    
};

void printVetor(){
    cout << "\n\nImprimindo informacoes\n";

    for (int i = 0; i < nodos.size(); i++)
    {
        cout << "\nVertice " << i << ":\n";
        nodos[i].print();
    }
    
}

int main()
{
    int tMatriz;

    cout << "Tamanho do grafo: ";
    cin >> tMatriz;

    int matriz[tMatriz][tMatriz];

    //inicializar a matriz em 0
    for (int i = 0; i < tMatriz; i++)
    {
        for (int j = 0; j < tMatriz; j++)
        {
            matriz[i][j] = 0;
        }
    }

    criaVertice(tMatriz);
    printVetor();
    
}