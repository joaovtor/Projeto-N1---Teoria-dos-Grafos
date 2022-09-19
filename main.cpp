#include"vertice.h"
#include"vertice.cpp"

vector<Vertice> nodos;

// preenche o vetor de vertices
void criaVertice(int tam){
    //recebe o tamanho e faz a atribuição aqui dentro
    for (int i = 0; i < tam; i++)
    {
        Vertice v;
        cout << endl << "Digite nome: ";
        cin.ignore(); // getline() e cin() tavam pulando as linhas por causa do que estava sendo inserido, o ignore() milagrosamente resolveu
        getline(cin, v.nome); //cin pega só a primeira palavra inseriada, getline pega tudo
        cout << endl << "Digite ID: ";
        cin >> v.id;
        cout << endl << "Digite categoria: ";
        cin.ignore();
        getline(cin, v.categoria);

        nodos.push_back(v); //insere o objeto no final do vetor

    }
    
};

void initMatriz(vector<vector<int>> & v, int tam){
    
    for (int i = 0; i < tam; i++)
    {
        vector<int> v1;
        for (int j = 0; j < tam; j++)
        {
            v1.push_back(0);

        }

        v.push_back(v1);
    }
    
}

//imprime o vetor de vertices
void printVetorVert(){
    cout << "\n\nImprimindo informacoes\n";

    for (int i = 0; i < nodos.size(); i++)
    {
        cout << "\nVertice " << i+1 << ":\n";
        nodos[i].print();
    }
    
}

//imprime as informações de um vertice especifico
void printVertice(int vertice){
    
    nodos.at(vertice-1).print();
    
}


void addAresta(vector<vector<int>> & v){

    int x, y;

    cout << "\nDigite primeiro vertice que deseja conectar: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja conectar: ";
    cin >> y;

    v.at(x-1).at(y-1) = 1;
    v.at(y-1).at(x-1) = 1;

    cout << "\nInformacao dos vertices conectados";

    printVertice(x);
    printVertice(y);
}


void removeAresta(vector<vector<int>> & v){

    int x, y;

    cout << "\nDigite primeiro vertice que deseja desconectar: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja desconectar: ";
    cin >> y;

    v.at(x-1).at(y-1) = 0;
    v.at(y-1).at(x-1) = 0;

    cout << "\nInformacao dos vertices desconectados: ";

    printVertice(x);
    printVertice(y);
}

//imprime a matriz de adjacencia
void printMatriz(vector<vector<int>> & vec){

    cout << "\n\nImprimindo matriz de adjacencia\n";
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << " ";

        }
    cout << endl;  
    }
}


void menu(vector<vector<int>> & vec){
    int op;    

    cout << "\n\nMENU PRINCIPAL\n\n";
    while (op != 0)
    {
        cout    << "\n1 - Adicionar arestas;" << endl
                << "2 - Remover arestas;"   << endl
                << "3 - Imprimir matriz de adjacencia" << endl
                << "0 - Sair" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            addAresta(vec);
            break;
        case 2:
            removeAresta(vec);
            break;
        case 3:
            printMatriz(vec);
        default:
            break;
        }
    }
    
}

int main()
{
    int tMatriz;

    cout << "Tamanho do grafo: ";
    cin >> tMatriz;

    vector<vector<int>> matriz;

    //inicializar a matriz em 0
    initMatriz(matriz, tMatriz);

    criaVertice(tMatriz);
    printVetorVert();

    menu(matriz);
    
}