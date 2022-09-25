#include"vertice.h"
#include"vertice.cpp"
#include<bits/stdc++.h>

vector<Vertice> nodos;
vector<vector<int>> lista;


// preenche o vetor de vertices
void criaVertice(int tam){
    //recebe o tamanho e faz a atribuição aqui dentro
    for (int i = 0; i < tam; i++)
    {
        Vertice v;
        cin.ignore();
        cout << endl << "Digite nome: ";
         // getline() e cin() tavam pulando as linhas por causa do que estava sendo inserido, o ignore() milagrosamente resolveu
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

void addEdge(int v1,int v2)
{
    if(v1 != v2){
        lista[v1-1].push_back(v2);
        lista[v2-1].push_back(v1);
    }else{
	    lista[v1-1].push_back(v2);
    }
}

void addAresta(vector<vector<int>> & lista){

    int x, y;

    cout << "\nDigite primeiro vertice que deseja conectar: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja conectar: ";
    cin >> y;


    addEdge(x,y);

    cout << "\nInformacao dos vertices conectados";

    printVertice(x);
    printVertice(y);
}

//recebe dois vertices e retorna 1 caso eles estejam conectados, fiz assim porque daí podemos usar nas outras funções pra alertar que já existe conexão
int checkAresta(vector<vector<int>> & lista,int v1, int v2){
    int x = 0;

    for (int i = 0; i < lista[v1].size(); i++)
    {
        if(lista[v1-1][i] == v2){
            x = 1;
        }
    }
   
    return x;    
}

int checkLaco(int v1){

    int x = 0;

    cout << "Tamanho da linha: " << lista[v1-1].size();
    for (int i = 0; i < lista[v1-1].size(); i++)
    {
        if(lista[v1-1][i] == v1){
            cout << "X eh igual a 1 na posicao i: " << i;
            x = 1;
        }
    }
    cout << "\nX: " << x;
    return x;
}


void verificaLaco(){
    int x;

    cout << "\nDigite o vertice que deseja checar a existencia de laco: ";
    cin >> x;

    if(checkLaco(x) == 1){
        cout << "\nExiste um laco";
    }else{
        cout << "\nNao existe um laco";
    }

    printVertice(x);
}

//checa se dois vertices estao conectados
void verificaAdj(vector<vector<int>> & m){
    int v1, v2;
    
    cout << "\nDigite o primeiro vertice para checar adjacencia: ";
    cin >> v1;
    cout << "\nDigite o segundo vertice para checar adjacencia: ";
    cin >> v2;

    if (checkAresta(m,v1,v2) == 1)
    {
        cout << "\nExiste conexao entre os vertices";

        printVertice(v1);
        printVertice(v2);
    }else
        cout << "\nNao existe conexao";
    
}

void removeAresta(vector<vector<int>> & lista){

    int x, y;

    cout << "\nDigite primeiro vertice que deseja desconectar: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja desconectar: ";
    cin >> y;

    if(x !=y){

    for (int i = 0; i < lista[x].size(); i++) {
        if (lista[x][i] == y) {
            lista[x].erase(lista[x].begin() + i);
            break;
        }
    }
 
    // Traversing through the second vector list
    // and removing the first element from it
    for (int i = 0; i < lista[y].size(); i++) {
        if (lista[y][i] == x) {
            lista[y].erase(lista[y].begin() + i);
            break;
        }
    }
    }else{
       for (int i = 0; i < lista[x].size(); i++) {
        if (lista[x][i] == y) {
            lista[x].erase(lista[x].begin() + i);
            break;
        }
    } 
    }

    cout << "\nInformacao dos vertices desconectados: ";

    printVertice(x);
    printVertice(y);
}

//imprime a matriz de adjacencia
void printLista(vector<vector<int>> & lista, int V){

    cout << "\n\nImprimindo matriz de adjacencia\n";
    for (int d = 0; d < lista.size(); ++d) {
    cout << "\n Vertex "
       << d+1 << ":";
    for (auto x : lista[d])
      cout << "-> " << x;
    printf("\n");
  }
}

bool checkCaminho(int v1,int v2)
{
	// Base case
	if(v1 == v2)
		return true;

	int n = (int)lista.size();
	
	// Mark all the vertices as not visited
	vector<bool> visited(n,false);

	// Create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[v1]= true;
	q.push(v1);

	while(!q.empty())
	{
		// Dequeue a vertex from queue and print it
		v1=q.front();
		q.pop();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it
		// visited and enqueue it	
		for(auto x:lista[v1])
		{

			// If this adjacent node is the destination node,
			// then return true
			if(x == v2)
				return true;

			// Else, continue to do BFS		
			if(!visited[x])
			{
				visited[x] = true;
				q.push(x);
			}
		}
	}

// If BFS is complete without visiting d
	return false;
}

void verificaCaminho(){
    int x,y;

    cout << "Digite o primeiro vertice para checar o caminho: ";
    cin >> x;
    cout << "Digite o segundo vertice para checar o caminho: ";
    cin >> y;

    if(checkCaminho(x,y)){
        cout << "Existe um caminho entre " << x << " e " << y;
    }else{
        cout << "Nao existe um caminho entre " << x << " e " << y;
    }

    printVertice(x);
    printVertice(y);


}

void teste(){
    Vertice v1 (1, "Predio 1", "Academico");
    Vertice v2 (2, "Bar", "Comercial");
    Vertice v3 (3, "Predio 3", "Academico");
    Vertice v4 (4, "ADM", "Administrativo");
    Vertice v5 (5, "Biblioteca", "Pesquisa");
    Vertice v6 (6, "Predio 6", "Academico");
    Vertice v7 (7, "Predio 7", "Academico");
    Vertice v8 (8, "Estacionamento Norte", "Estacionamento");
    Vertice v9 (9, "Estacionamento Leste", "Estacionamente");
    Vertice v10(10, "Estacionaemento Sudeste", "Estacionamento");

    cout << "\nCriou objs";

    nodos.push_back(v1);
    nodos.push_back(v2);
    nodos.push_back(v3);
    nodos.push_back(v4);
    nodos.push_back(v5);
    nodos.push_back(v6);
    nodos.push_back(v7);
    nodos.push_back(v8);
    nodos.push_back(v9);
    nodos.push_back(v10);
    
    cout << "\nInseriu no vetor";

    addEdge(1,2);
	addEdge(1,3);
	addEdge(2,3);
	addEdge(2,4);
    addEdge(3,4);
	addEdge(3,5);
    addEdge(4,6);
    addEdge(6,7);
    addEdge(6,6);

    cout << "Criou arestas";
}

void menu(vector<vector<int>> & matriz, int tam){
    int op, x, y;    

    cout << "\n\nMENU PRINCIPAL\n\n";
    
    while (op != 0)
    {
        cout    << "\n1 - Adicionar arestas;" << endl
                << "2 - Remover arestas;"   << endl
                << "3 - Imprimir matriz de adjacencia" << endl
                << "4 - Verificar se dois vertices sao adjacentes" << endl
                << "5 - Checa se existe um caminho entre dois vertices" << endl
                << "6 - Cecha se existe um vertice possui laco" << endl
                << "0 - Sair" << endl
                << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            addAresta(matriz);
            break;
        case 2:
            removeAresta(matriz);
            break;
        case 3:
            printLista(matriz, tam);
            break;
        case 4: 
            verificaAdj(matriz);
            break;
        case 5:
            verificaCaminho();
            break;
        case 6:
            verificaLaco();
            break;
        
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

    lista = vector<vector<int>>(tMatriz);

    //inicializar a matriz em 0
    //initMatriz(matriz, tMatriz);

    int x;

    cout << "Deseja inicar teste ou normalmente\n1 - Teste\nElse - Normal\nOpcao: ";
    cin >> x;
    if(x == 1){
        cout << "\nEntrou na condicao";
        teste();
        cout << "\nPassou no teste";
        menu(lista, tMatriz);
    }else{
    criaVertice(tMatriz);
    printVetorVert();

    menu(lista, tMatriz);
    }
    
}