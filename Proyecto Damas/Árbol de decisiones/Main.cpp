#include <iostream>

using namespace std;

#define N 8 //dimensión del tablero

enum tipo_nodo{RAIZ, INTERMEDIO, HOJA}; //primer nodo, nodo intermedio y nodo final de un árbol
struct nodo
{
	//datos del nodo
	int matriz[N][N]; //se supone que esto sería el tablero con las fichas
	int peso; //el peso que otorga el algoritmo minmax

	tipo_nodo tipo;
	int generacion; //inicialmente a cero porque el primer nodo que se crea es el padre de todos

	//enlaces con otros nodos
	nodo* padre; //nodo del que proviene
	nodo** hijos; //nodos que salen de este nodo
};

nodo* allocate(int matriz[N][N], int peso, nodo* padre); //crea nodos de tipo intermedio y hoja
nodo allocate_root(int matriz[N][N], int peso); //crea al nodo raiz de todo un arbol
nodo** NewVectorHijos(int n);

void MatrizRandom(int matriz[N][N]); //Crea una matriz en la que cada elemento contiene la suma de sus indices (i+j)
void Visualizar(nodo nodo); //Muestra el contenido del nodo que le pasas

nodo* allocate(int matriz[N][N], int peso, nodo* padre)
{
	int n=0; //VARIABLE QUE SIMULA LA CREACION DE NODOS HIJOS (SUSTITUIR POR FUNCION QUE CALCULA LOS ESTADOS POSIBLES)
	nodo* NewNode=NULL; //creo un puntero que apunta a un nuevo nodo
	
	//ASIGNACION DE DATOS AL NODO

	//vuelvo la matriz del estado del tablero a la matriz que dentro del nuevo nodo creado
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			NewNode->matriz[i][j] = matriz[i][j];
		}
	}
	NewNode->peso = peso;
	NewNode->padre = padre;
	NewNode->generacion = (padre->generacion) + 1; //toma la generacion del padre y le suma 1
	NewNode->hijos = NewVectorHijos(n);
	return NewNode;
}

nodo allocate_root(int matriz[N][N], int peso)
{
	int n=0; //VARIABLE QUE SIMULA LA CREACION DE NODOS HIJOS (SUSTITUIR POR FUNCION QUE CALCULA LOS ESTADOS POSIBLES)
	nodo RootNode; //creo un nodo raiz
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			RootNode.matriz[i][j] = matriz[i][j]; //asignamos igual que en allocate pero en este caso se trata de una estructura y no de un puntero a estructura
		}
	}
	RootNode.peso = peso;
	RootNode.tipo = RAIZ;
	RootNode.generacion = 0;
	RootNode.padre = NULL; //al ser el nodo raiz no tiene padre por tanto apunta a 0
	RootNode.hijos = NewVectorHijos(n);
	return RootNode; //devuelvo el contenido del nodo raiz
}

nodo** NewVectorHijos(int n)
{
	nodo** VectorHijos = new nodo * [n];

	return VectorHijos;
}

void MatrizRandom(int matriz[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matriz[i][j] = i + j;
		}
	}
}

void Visualizar(nodo nodo)
{
	//sacamos por consola los datos que hemos metido en el nodo
	cout << "DATOS DEL NODO:" << endl;
	cout << "Matriz:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << nodo.matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Peso:" << nodo.peso << endl;
	cout << "Tipo:" << nodo.tipo << endl;
	cout << "Generacion:" << nodo.generacion << endl;
	cout << "Padre:" << nodo.padre << endl;
}


int main()
{
	int matriz[N][N];
	int peso = 12;
	MatrizRandom(matriz);
	nodo NodoRaiz = allocate_root(matriz, peso);
	Visualizar(NodoRaiz);
}
