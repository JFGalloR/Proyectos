/*======================================================================================

	Nivel de entendimineto:
		Bueno. Comprendo como funciona el algoritmo, sin embargo a�n no lo podr�a 
		hacer sin ayuda.
	--------------------------------------------------------------------------------
    > Inicializaci�n:
 
	 Se establece la distancia desde el nodo de origen al mismo nodo en 0 y todas 
	 las dem�s distancias se inicializan como infinito.
	 Se utiliza una cola de prioridad (generalmente un mont�culo m�nimo) para 
	 mantener un seguimiento de los nodos no visitados y sus distancias.

    > Selecci�n del nodo m�s cercano:

	 En cada paso, se selecciona el nodo con la distancia m�nima desde el conjunto 
	 de nodos no visitados.

    > Exploraci�n de vecinos:

	 Se exploran todos los nodos vecinos del nodo seleccionado.
	 Se calcula la distancia acumulativa desde el nodo de origen hasta el nodo 
	 vecino a trav�s del nodo seleccionado.
	 Si esta distancia es menor que la distancia actual registrada para el nodo 
	 vecino, se actualiza la distancia registrada.

    > Marcado del nodo seleccionado:

	 Despu�s de explorar todos los vecinos, el nodo seleccionado se marca como visitado 
	 y se elimina de la cola de prioridad.

    > Repetici�n:

	 Se repiten los pasos 2-4 hasta que todos los nodos hayan sido visitados o hasta 
	 que no queden nodos alcanzables con distancias finitas.

    > Resultados:

	 Al final del algoritmo, se habr�n calculado las distancias m�nimas desde el nodo
	 de origen a todos los dem�s nodos en el grafo.

======================================================================================*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinito como valor m�ximo

// Definici�n de una estructura para representar un nodo y su distancia
struct NodoDistancia {
    int nodo; // �ndice del nodo
    int distancia; // Distancia m�nima desde el nodo fuente
    
    NodoDistancia(int n, int d) : nodo(n), distancia(d) {}
    
    bool operator>(const NodoDistancia& otro) const {
        return distancia > otro.distancia;
    }
};

// Funci�n para calcular las distancias m�nimas desde un nodo fuente utilizando el algoritmo de Dijkstra
void dijkstra(vector<vector<pair<int, int> > >& grafo, int fuente, vector<int>& distancia) {
    int n = grafo.size(); // N�mero de nodos en el grafo
    distancia.assign(n, INF); // Inicializa todas las distancias como infinito
    distancia[fuente] = 0; // La distancia desde el nodo fuente a s� mismo es 0
    
    priority_queue<NodoDistancia, vector<NodoDistancia>, greater<NodoDistancia> > pq;
    pq.push(NodoDistancia(fuente, 0)); // Agrega la fuente a la cola de prioridad
    
    // Algoritmo de Dijkstra
    while (!pq.empty()) {
        NodoDistancia actual = pq.top();
        pq.pop();
        
        int nodoActual = actual.nodo; // Nodo actual
        
        // Itera a trav�s de los vecinos del nodo actual
        for (vector<pair<int, int> >::iterator it = grafo[nodoActual].begin(); it != grafo[nodoActual].end(); ++it) {
            int nodoVecino = it->first; // Nodo vecino
            int peso = it->second; // Peso de la arista
            
            // Si encontramos un camino m�s corto hacia el vecino, lo actualizamos
            if (distancia[nodoActual] + peso < distancia[nodoVecino]) {
                distancia[nodoVecino] = distancia[nodoActual] + peso;
                pq.push(NodoDistancia(nodoVecino, distancia[nodoVecino])); // Agrega el vecino a la cola de prioridad
            }
        }
    }
}

int main() {
    int n, m; 
    cout << "Ingrese el n�mero de nodos: ";
    cin >> n;
    cout << "Ingrese el n�mero de aristas: ";
    cin >> m;
    
    vector<vector<pair<int, int> > > grafo(n); // Lista de adyacencia
    
    map<string, int> indiceNodo; // Mapeo de nombres de nodo a �ndices
    
    // Entrada de nombres de nodos y mapeo a �ndices
    for (int i = 0; i < n; i++) {
        string nombreNodo;
        cout << "Ingrese el nombre del nodo " << i+1 << ": ";
        cin >> nombreNodo;
        indiceNodo[nombreNodo] = i; // Asocia el nombre del nodo con su �ndice en el grafo
    }
    
    // Entrada de aristas y construcci�n del grafo
    for (int i = 0; i < m; i++) {
        string nombreNodo1, nombreNodo2;
        int peso;
        cout << "Ingrese el nombre del nodo de origen, nombre del nodo de destino y peso de la arista " << i + 1 << ": ";
        cin >> nombreNodo1 >> nombreNodo2 >> peso;
        int nodo1 = indiceNodo[nombreNodo1];
        int nodo2 = indiceNodo[nombreNodo2];
        grafo[nodo1].push_back(make_pair(nodo2, peso)); // Agrega la arista a la lista de adyacencia
        grafo[nodo2].push_back(make_pair(nodo1, peso)); // Agrega la arista inversa (grafo no dirigido)
    }
    
    // Entrada de nodos fuente y destino
    string nombreFuente, nombreDestino;
    cout << "Ingrese el nombre del nodo fuente: ";
    cin >> nombreFuente;
    cout << "Ingrese el nombre del nodo destino: ";
    cin >> nombreDestino;
    
    int fuente = indiceNodo[nombreFuente]; // Obtiene el �ndice del nodo fuente
    int destino = indiceNodo[nombreDestino]; // Obtiene el �ndice del nodo destino
    
    vector<int> distancia;
    dijkstra(grafo, fuente, distancia); // Calcula las distancias m�nimas desde el nodo fuente
    
    // Salida de distancias m�nimas
    cout << "Distancias m�nimas desde el nodo fuente " << nombreFuente << ":" << endl;
    for (map<string, int>::iterator it = indiceNodo.begin(); it != indiceNodo.end(); ++it) {
        string nombreNodo = it->first; // Nombre del nodo
        int indice = it->second; // �ndice del nodo
        cout << "Nodo " << nombreNodo << ": " << distancia[indice] << endl;
    }

    cout << "Distancia m�nima desde el nodo fuente " << nombreFuente << " al nodo destino " << nombreDestino << ": " << distancia[destino] << endl;
    
    return 0;
}

