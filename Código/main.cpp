#include"vertice.h"
#include"vertice.cpp"
#include<bits/stdc++.h>

vector<Vertice> nodos;
vector<pair<int,int>> lista;
bool ehPonderado = false;


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


bool checkSubGrafo(vector <pair<int, int> > lista[], vector<int> subGrafo ){
    int x, aux, y;
    bool ehSubGrafo = false;


    //primeiro for serve pra guardar a linha que vai ser verificada, aux recebe o valor do vetor do subgrafo
    //segundo for guarda a posição do valor do vetor do subgrafo pra verificar
    //terceiro for serve pra percorrer toda a linha

    for (int j = 0; j < subGrafo.size(); j++)
    {
        aux = subGrafo[j];
        x = 0;

        for (int k = 0; k < subGrafo.size(); k++)
        {

            for (int l = 0; l < lista[aux-1].size(); l++)
            {   
                
                if(lista[aux-1][l].first == subGrafo[k]){
                    x++;
                }
            }
        }

        if(x > 0){
            ehSubGrafo = true;
        }else{
            ehSubGrafo = false;
            break;
        }
        
    }
    
    return ehSubGrafo;
}

void verificaSubgrafo(vector <pair<int, int> > lista[]){

    vector<int> subGrafo;
    int tam, aux = 0;

    cout << "\nDigite o tamanho do subgrafo: ";
    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cout << "\nDigite o vertice " << i + 1 << ": ";
        cin >> aux;

        subGrafo.push_back(aux);
    }

    if(checkSubGrafo(lista, subGrafo)){
        cout << "\nO subgrafo inserido existe!\n";
    }else
        cout << "\nO subgrafo inserido nao existe!\n";


    for (int i = 0; i < subGrafo.size(); i++)
    {
        printVertice(subGrafo[i]);
    }
    
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
            cout << "\tVertice " << it->first << " com peso da aresta de: "
                 << it->second << "\n";
        }
        cout << "\n";
    }
}


void printCaminho(vector <pair<int, int> > lista[], vector<int> caminho){

    int x;
    int distancia = 0;

    cout << "\n\nCaminho no inicio da funcao" <<  endl;

    for (int i = 0; i < caminho.size(); i++)
    {
        cout << caminho[i] << " - ";
    }


    //laço de repetição invertido pra pegarmos a posição do final e ir até o começo
    for (int i = caminho.size() - 1; i > 0; i--)
    {
        x = 0;

        //for que a condição de parada é o tamanho da linha do vértice atual
        for (int j = 0; j < lista[caminho[i]-1].size(); j++)
        {
            //se na linha do vértice for encontrado o próximo vértice
            if (lista[caminho[i]-1][j].first == caminho[i-1])
            {
                x = 1;
                
            }
            
        }
        
        //se não for encontrado, retira o número do vetor e repete o mesmo número
        if (x == 0)
        {
            caminho.erase(caminho.begin() + i - 1);
            //i++;
        }
        
    }

    cout << "\n\nCaminho percorrido\n\n";

     for (int i = 0; i < caminho.size(); i++)
    {
        cout << caminho[i] << " - ";
    }


    if (ehPonderado)
    {

        for (int i = 1; i <= caminho.size(); i++)
        {

            for (int j = 0; j < lista[caminho[i-1]].size(); j++)
            {

                if (lista[caminho[i-1]][j].first == caminho[i-1])
                {
                    distancia = distancia + lista[caminho[i-1]][j].second;
                }
                
            }
            
        }

    cout << "\nDistancia total: " << distancia << endl;
        
    }

   
    for (int i = 0; i < caminho.size(); i++)
    {
        printVertice(caminho[i]);
    
    }
    
}

//
void checkCaminho(vector <pair<int, int> > lista[], int v1,int v2, int tGrafo)
{

    int aux;
    bool temCaminho = false;
    vector<int> caminhoPercorrido;

	// Base case
	if(v1 == v2){
		temCaminho = true;
	}


	// Mark all the vertices as not visited
	vector<bool> visited(tGrafo,false);

	// Create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[v1]= true;
	q.push(v1);
    caminhoPercorrido.push_back(v1);

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
			if(lista[v1-1][i].first == v2){
				temCaminho = true;
                caminhoPercorrido.push_back(lista[v1-1][i].first);
                break;
            }
			// Else, continue to do BFS		
			if(!visited[lista[v1-1][i].first])
			{
				visited[lista[v1-1][i].first] = true;
				q.push(lista[v1-1][i].first);
                caminhoPercorrido.push_back(lista[v1-1][i].first);
			}
			
		}
	}

    if (temCaminho)
    {

        cout << "\n\nExiste um caminho entre " << caminhoPercorrido[0] << " e " << v2 << endl;
        
        
        for (int i = caminhoPercorrido.size()-1; i > 0; i--)
        {
            if (caminhoPercorrido[i] == v2)
            {
                break;
            }
            else{
                caminhoPercorrido.erase(caminhoPercorrido.begin() + 1);
            }
            
        }
        

        printCaminho(lista, caminhoPercorrido);
    }
    else
        cout << "\n\nNao existe um caminho entre " << caminhoPercorrido[0] << " e " << v2 << endl;

    
    
}

//
void verificaCaminho(vector <pair<int, int> > lista[], int tGrafo){
    int v1,v2;

    cout << "Digite o primeiro vertice para checar o caminho: ";
    cin >> v1;
    cout << "Digite o segundo vertice para checar o caminho: ";
    cin >> v2;

    checkCaminho(lista, v1, v2, tGrafo);

}

void addPeso(vector <pair<int, int> > lista[], int v1, int & v2, int peso){
	
	for (int i = 0; i < lista[v1].size(); i++)
	{
		
		if (lista[v1][i].first == v2)
		{
			lista[v1][i].second = peso;	
		}
		
	}

	for (int i = 0; i < lista[v1].size(); i++)
	{
		if (lista[v2-1][i].first == v1+1)
		{
			lista[v2-1][i].second = peso;	
		}
		
	}
}

void ponderado(vector <pair<int, int> > lista[], int tGrafo){

	int peso;

    ehPonderado = true;

	for (int i = 0; i < tGrafo; i++){


		for (int j = 0; j < lista[i].size(); j++){

			if (lista[i][j].second == 0)
			{
				cout << "\nDigite o valor do peso da aresta que liga os vertices " << i + 1 << " e " << lista[i][j].first << ": ";
				cin >> peso;
				addPeso(lista, i, lista[i][j].first, peso);
			}
		
	    }
	}
}


bool isCyclicUtil(vector <pair<int, int> > lista[], int v, bool visited[], int parent)
{
 
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    //list<int>::iterator i;

    for (auto i = lista[v].begin(); i != lista[v].end(); ++i) {
 
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[i->first]) {
            if (isCyclicUtil(lista, i->first, visited, v))
                return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (i->first != parent)
            return true;
    }
    return false;
}
 
// Returns true if the graph contains
// a cycle, else false.
bool isCyclic(vector <pair<int, int> > lista[], int tGrafo)
{
 
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool* visited = new bool[tGrafo];
    for (int i = 0; i < tGrafo; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < tGrafo; u++) {
 
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(lista, u, visited, -1))
                return true;
    }
    return false;
}

void checkCompleto(vector <pair<int, int> > lista[], int tGrafo){

    int aux = 0;

    int parada = 0;

    for (int i = 0; i < tGrafo; i++)
    {
        aux++;
        
        if (lista[i].size() == tGrafo-1)
        {
            for (int j = 0; j < lista[i].size(); j++)
            {
                if (i + 1 != aux)
                {
                    if (lista[i][j].first != aux)
                    {  
                        parada = 1;
                        break;

                    }
                }  
            }

            if (parada == 1)
            {
                break;
            }
            
        }
        else{
            cout << "\n\nGrafo nao eh completo de baixo";
            break;
        }

    }
    
    if (parada == 0)
    {
        cout << "\n\nGrafo eh completo!";
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
    addEdge(lista, 7, 8, 0);
    addEdge(lista, 9, 10, 0);
    
}

//
void menu(vector <pair<int, int> > lista[], int tGrafo){
    int op;    
    
    while (op != 0)
    {
        cout << "\n\nMENU PRINCIPAL\n\n";
        cout    << "\n1 - Adicionar arestas;"                           << endl
                << "2 - Remover arestas;"                               << endl
                << "3 - Imprimir lista de adjacencia"                   << endl
                << "4 - Verificar se dois vertices sao adjacentes"      << endl
                << "5 - Checa se existe um caminho entre dois vertices" << endl
                << "6 - Checa se existe um vertice possui laco"         << endl
                << "7 - Tornar grafo ponderado"                         << endl
                << "8 - Verificar um subgrafo"                          << endl
                << "9 - Checar se o grafo eh completo"                  << endl
                << "10 - Verifica existencia de ciclo"                  << endl
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
        case 8:
            verificaSubgrafo(lista);
            break;
        case 9:
            checkCompleto(lista, tGrafo);
            break;
        case 10:
            if (isCyclic(lista, tGrafo) == true)
            {
                cout << "\n\nExiste um ciclo no grafo";
            }else
                cout << "\n\nNao existe um ciclo no grafo";
            break;
        case 0:
            cout << "\n\nTchauzinho!\n";
            break;
        default:
            cout << "\nValor invalido\n";
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