#include"vertice.h"
#include"vertice.cpp"
#include<bits/stdc++.h>

vector<Vertice> nodos;
vector<pair<int,int>> lista;


void criaVertice(int tam){

    for (int i = 0; i < tam; i++)
    {
        Vertice v;
        cin.ignore();
        cout << endl << "Digite nome: ";
        getline(cin, v.nome); 
        cout << endl << "Digite ID: ";
        cin >> v.id;
        cout << endl << "Digite categoria: ";
        cin.ignore();
        getline(cin, v.categoria);

        nodos.push_back(v); 

    }
    
};

void initGrafo(vector<vector<int>> & v, int tam){
    
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
//
void addEdge(vector <pair<int, int> > lista[],int v1, int v2, int peso)
{
    if (v1 != v2)
    {
        lista[v1-1].push_back(make_pair(v2, peso));
	    lista[v2-1].push_back(make_pair(v1, peso));
    }else
        lista[v1-1].push_back(make_pair(v2, peso));
    
	
}
//
void addAresta(vector <pair<int, int> > lista[]){

    int x, y;

    cout << "\nDigite primeiro vertice que deseja conectar: ";
    cin >> x;
    cout << "\nDigite o segundo vertice que deseja conectar: ";
    cin >> y;


    addEdge(lista, x, y, 0);

    cout << "\nInformacao dos vertices conectados";

    printVertice(x);
    printVertice(y);
}

//
int checkLaco(vector <pair<int, int> > lista[], int v1){

    int x = 0;

    for (auto it = lista[v1-1].begin(); it!=lista[v1-1].end(); it++)
    {
        if(it->first == v1){
            x = 1;
        }
    }
    return x;
}

//
void verificaLaco(vector <pair<int, int> > lista[]){
    int v1;

    cout << "\nDigite o vertice que deseja checar a existencia de laco: ";
    cin >> v1;

    if(checkLaco(lista, v1) == 1){
        cout << "\nExiste um laco";
    }else{
        cout << "\nNao existe um laco";
    }

    printVertice(v1);
}

//recebe dois vertices e retorna 1 caso eles estejam conectados, fiz assim porque daí podemos usar nas outras funções pra alertar que já existe conexão
int checkAresta(vector <pair<int, int> > lista[],int v1, int v2){
    int x = 0;

    for (auto it = lista[v1-1].begin(); it!=lista[v1-1].end(); it++)
    {
        if(it->first == v2){
            x = 1;
        }
    }
   
    return x;    
}

//checa se dois vertices estao conectados
void verificaAdj(vector <pair<int, int> > lista[]){
    int v1, v2;
    
    cout << "\nDigite o primeiro vertice para checar adjacencia: ";
    cin >> v1;
    cout << "\nDigite o segundo vertice para checar adjacencia: ";
    cin >> v2;

    if (checkAresta(lista, v1, v2) == 1)
    {
        cout << "\nExiste conexao entre os vertices";

        printVertice(v1);
        printVertice(v2);
    }else
        cout << "\nNao existe conexao";
    
}

//
void delEdge(vector <pair<int, int> > lista[], int v1, int v2){
	
    if (v1 != v2)
    {
        for (auto it = lista[v1-1].begin(); it!=lista[v1-1].end(); it++)
	    {
            
		    if (it->first == v2)
		    {
                
			    lista[v1-1].erase(it);	
                break;
		    }
		
	    }
	    for (auto it = lista[v2-1].begin(); it!=lista[v2-1].end(); it++)
	    {
            
		    if (it->first == v1)
		    {
                
			    lista[v2-1].erase(it);	
                break;
		    }
	    }
    }
    else
    {
        for (auto it = lista[v1-1].begin(); it!=lista[v1-1].end(); it++)
	    {

	        if (it->first == v2)
		    {
		        lista[v1-1].erase(it);
                break;	
	        }
		
	    }
    }
}

//
void removeAresta(vector <pair<int, int> > lista[]){

    int v1, v2;

    cout << "\nDigite primeiro vertice que deseja desconectar: ";
    cin >> v1;
    cout << "\nDigite o segundo vertice que deseja desconectar: ";
    cin >> v2;

    delEdge(lista, v1, v2);

    cout << "\nInformacao dos vertices desconectados: ";

    printVertice(v1);
    printVertice(v2);
}

//imprime a matriz de adjacencia
void printLista(vector<pair<int,int> > adj[], int tGrafo)
{
    int v, w;
    for (int u = 0; u < tGrafo; u++)
    {
        cout << "Vertice " << u+1 << " esta conectado com \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tVertice " << it->first << " com peso da aresta de: "
                 << it->second << "\n";
        }
        cout << "\n";
    }
}

//
bool checkCaminho(vector <pair<int, int> > lista[], int v1,int v2, int tGrafo)
{
	// Base case
	if(v1 == v2){
		return true;
	}

	// Mark all the vertices as not visited
	vector<bool> visited(tGrafo,false);

	// Create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[v1]= true;
	q.push(v1);

	while(!q.empty())
	{
		// Dequeue a vertex from queue and print it
		v1 = q.front();
		q.pop();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it
		// visited and enqueue it	


		for(int i = 0; i < lista[v1-1].size(); i++)
		{
            
			// If this adjacent node is the destination node,
			// then return true
			if(lista[v1-1][i].first == v2)
				return true;

			// Else, continue to do BFS		
			if(!visited[lista[v1-1][i].first])
			{
				visited[lista[v1-1][i].first] = true;
				q.push(lista[v1-1][i].first);
			}
			
		}
	}

// If BFS is complete without visiting d
	return false;
}

//
void verificaCaminho(vector <pair<int, int> > lista[], int tGrafo){
    int v1,v2;

    cout << "Digite o primeiro vertice para checar o caminho: ";
    cin >> v1;
    cout << "Digite o segundo vertice para checar o caminho: ";
    cin >> v2;

    if(checkCaminho(lista, v1, v2, tGrafo)){
        cout << "\nExiste um caminho entre " << v1 << " e " << v2;
    }else{
        cout << "\nNao existe um caminho entre " << v1 << " e " << v2;
    }

    printVertice(v1);
    printVertice(v2);


}

void addPeso(vector <pair<int, int> > lista[], int v1, int & v2, int peso){
	/*
	cout << "\n\nEntrando no addPeso()";

	cout << "\nValor de V1: " << v1;
	cout << "\nValor de V2: " << v2;*/

	
	for (int i = 0; i < lista[v1].size(); i++)
	{
		//cout << "\nPESO DO ADDPESO()1: " << lista[v1][i].first;
		if (lista[v1][i].first == v2)
		{
			//cout << "\n\nPeso foi aceito no IF 1";

			lista[v1][i].second = peso;	
		}
		
	}

	//cout << endl;

	for (int i = 0; i < lista[v1].size(); i++)
	{
		//cout << "\nIT->FIRST DO ADDPESO()2: " << lista[v2-1][i].first - 1;
		if (lista[v2-1][i].first == v1+1)
		{
			//cout << "\n\nIT->FIRST foi aceito no IF 2";
			lista[v2-1][i].second = peso;	
		}
		
	}
}

void ponderado(vector <pair<int, int> > lista[], int tGrafo){

	int peso;


	for (int i = 0; i < tGrafo; i++){


		for (int j = 0; j < lista[i].size(); j++){
			/*
			cout << "\nLista size: " << lista[i].size();

			cout << "\nIT->FIRST: " << lista[i][j].first;
		
			cout << "\n\nValor antes: " << lista[i][j].second;*/


			if (lista[i][j].second == 0)
			{
				cout << "\nDigite o valor do peso da aresta que liga os vertices " << i + 1 << " e " << lista[i][j].first << ": ";
				cin >> peso;
				addPeso(lista, i, lista[i][j].first, peso);
				

			}

			cout << "\n\nValor depois: " << lista[i][j].second << endl;
		
	}
	
	}
	
	
}
//
void teste(vector <pair<int, int> > lista[]){
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
    

    addEdge(lista, 1, 2, 0);
	addEdge(lista, 1, 3, 0);
    addEdge(lista, 1, 10, 0);
	addEdge(lista, 2, 3, 0);
	addEdge(lista, 2, 4, 0);
    addEdge(lista, 4, 5, 0);
    addEdge(lista, 4, 8, 0);
    addEdge(lista, 6, 7, 0);
    addEdge(lista, 9, 10, 0);
    
}

//
void menu(vector <pair<int, int> > lista[], int tGrafo){
    int op;    

    cout << "\n\nMENU PRINCIPAL\n\n";
    
    while (op != 0)
    {
        cout    << "\n1 - Adicionar arestas;"                           << endl
                << "2 - Remover arestas;"                               << endl
                << "3 - Imprimir lista de adjacencia"                   << endl
                << "4 - Verificar se dois vertices sao adjacentes"      << endl
                << "5 - Checa se existe um caminho entre dois vertices" << endl
                << "6 - Checa se existe um vertice possui laco"         << endl
                << "7 - Tornar grafo ponderado"                         << endl
                << "0 - Sair"                                           << endl
                << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            addAresta(lista);
            break;
        case 2:
            removeAresta(lista);
            break;
        case 3:
            printLista(lista, tGrafo);
            break;
        case 4: 
            verificaAdj(lista);
            break;
        case 5:
            verificaCaminho(lista, tGrafo);
            break;
        case 6:
            verificaLaco(lista);
            break;
        case 7:
            ponderado(lista, tGrafo);
            break;
        default:
            break;
        }
    }
    
}


int main()
{
    int tGrafo, op;

    cout << "Deseja inicar teste ou normalmente\n1 - Teste\nElse - Normal\nOpcao: ";
    cin >> op;
    if(op == 1){
        tGrafo = 10;
        vector<pair<int, int>> lista[tGrafo]; 

        teste(lista);
        
        menu(lista, tGrafo);

    }else{
        cout << "Tamanho do grafo: ";
        cin >> tGrafo;

        vector<pair<int, int>> lista[tGrafo]; 
        
        criaVertice(tGrafo);
        printVetorVert();

        menu(lista, tGrafo);
    }
    
}