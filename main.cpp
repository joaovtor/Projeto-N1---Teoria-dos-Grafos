#include"vertice.h"
#include"vertice.cpp"

vector<Vertice> nodos;


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

void printVetor(){
    cout << "\n\nImprimindo informacoes\n";

    for (int i = 0; i < nodos.size(); i++)
    {
        cout << "\nVertice " << i << ":\n";
        nodos[i].print();
    }
    
}

void printVertice(int vertice){
    for (int i = 0; i < nodos.size(); i++)
    {
        if (i == vertice)
        {
            cout << "\nNodo " << i << ":";
            nodos[i].print();
        }
        
    }
    
}

void addAresta(int matriz[][10]){

    int x, y;

    cout << "\nDigite primeiro vertice que deseja conectar: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja conectar: ";
    cin >> y;
    matriz[x][y] = 1;
    matriz[y][x] = 1;

    cout << "\nInformacao dos vertices conectados: ";

    printVertice(x);
    printVertice(y);
}

void removeAresta(int matriz[][10]){
    int x, y;

    cout << "\nDigite primeiro vertice que deseja remover da conexao: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja remover da conexao: ";
    cin >> y;
    matriz[x][y] = 0;
    matriz[y][x] = 0;

    cout << "\nInformacao dos vertices desconectados: ";

    printVertice(x);
    printVertice(y);
}

void printMatriz(int matriz[][10]){
    for (int i = 0; i < nodos.size(); i++)
    {
        for (int j = 0; j < nodos.size(); j++)
        {
            cout << matriz[i][j];
        }
        
    }
    
}

void menu(int matriz[10][10]){
    int op;    

    cout << "\n\nMENU PRINCIPAL\n\n";
    while (op != 0)
    {
        cout    << "\n1 - Adicionar arestas;" << endl
                << "2 - Remover arestas;"   << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            addAresta(matriz[10][10]);
            break;
        case 2:
            removeAresta(matriz[10][10]);
            break;
        case 3:
            printMatriz(matriz[10][10]);
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

    menu(matriz);
    
}