/*======================================================================================

	Nivel de entendimineto:
		Bueno. Comprendo como funciona el algoritmo, sin embargo aún no lo podría 
		hacer sin ayuda.
	--------------------------------------------------------------------------------
    > Inicialización:
 
	 Se establece la distancia desde el nodo de origen al mismo nodo en 0 y todas 
	 las demás distancias se inicializan como infinito.
	 Se utiliza una cola de prioridad (generalmente un montículo mínimo) para 
	 mantener un seguimiento de los nodos no visitados y sus distancias.

    > Selección del nodo más cercano:

	 En cada paso, se selecciona el nodo con la distancia mínima desde el conjunto 
	 de nodos no visitados.

    > Exploración de vecinos:

	 Se exploran todos los nodos vecinos del nodo seleccionado.
	 Se calcula la distancia acumulativa desde el nodo de origen hasta el nodo 
	 vecino a través del nodo seleccionado.
	 Si esta distancia es menor que la distancia actual registrada para el nodo 
	 vecino, se actualiza la distancia registrada.

    > Marcado del nodo seleccionado:

	 Después de explorar todos los vecinos, el nodo seleccionado se marca como visitado 
	 y se elimina de la cola de prioridad.

    > Repetición:

	 Se repiten los pasos 2-4 hasta que todos los nodos hayan sido visitados o hasta 
	 que no queden nodos alcanzables con distancias finitas.

    > Resultados:

	 Al final del algoritmo, se habrán calculado las distancias mínimas desde el nodo
	 de origen a todos los demás nodos en el grafo.

======================================================================================*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinito como valor máximo

// Definición de una estructura para representar un nodo y su distancia
struct NodoDistancia {
    int nodo; // Índice del nodo
    int distancia; // Distancia mínima desde el nodo fuente
    
    NodoDistancia(int n, int d) : nodo(n), distancia(d) {}
    
    bool operator>(const NodoDistancia& otro) const {
        return distancia > otro.distancia;
    }
};

// Función para calcular las distancias mínimas desde un nodo fuente utilizando el algoritmo de Dijkstra
void dijkstra(vector<vector<pair<int, int> > >& grafo, int fuente, vector<int>& distancia) {
    int n = grafo.size(); // Número de nodos en el grafo
    distancia.assign(n, INF); // Inicializa todas las distancias como infinito
    distancia[fuente] = 0; // La distancia desde el nodo fuente a sí mismo es 0
    
    priority_queue<NodoDistancia, vector<NodoDistancia>, greater<NodoDistancia> > pq;
    pq.push(NodoDistancia(fuente, 0)); // Agrega la fuente a la cola de prioridad
    
    // Algoritmo de Dijkstra
    while (!pq.empty()) {
        NodoDistancia actual = pq.top();
        pq.pop();
        
        int nodoActual = actual.nodo; // Nodo actual
        
        // Itera a través de los vecinos del nodo actual
        for (vector<pair<int, int> >::iterator it = grafo[nodoActual].begin(); it != grafo[nodoActual].end(); ++it) {
            int nodoVecino = it->first; // Nodo vecino
            int peso = it->second; // Peso de la arista
            
            // Si encontramos un camino más corto hacia el vecino, lo actualizamos
            if (distancia[nodoActual] + peso < distancia[nodoVecino]) {
                distancia[nodoVecino] = distancia[nodoActual] + peso;
                pq.push(NodoDistancia(nodoVecino, distancia[nodoVecino])); // Agrega el vecino a la cola de prioridad
            }
        }
    }
}

int main() {
    int n, m; 
    cout << "Ingrese el número de nodos: ";
    cin >> n;
    cout << "Ingrese el número de aristas: ";
    cin >> m;
    
    vector<vector<pair<int, int> > > grafo(n); // Lista de adyacencia
    
    map<string, int> indiceNodo; // Mapeo de nombres de nodo a índices
    
    // Entrada de nombres de nodos y mapeo a índices
    for (int i = 0; i < n; i++) {
        string nombreNodo;
        cout << "Ingrese el nombre del nodo " << i+1 << ": ";
        cin >> nombreNodo;
        indiceNodo[nombreNodo] = i; // Asocia el nombre del nodo con su índice en el grafo
    }
    
    // Entrada de aristas y construcción del grafo
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
    
    int fuente = indiceNodo[nombreFuente]; // Obtiene el índice del nodo fuente
    int destino = indiceNodo[nombreDestino]; // Obtiene el índice del nodo destino
    
    vector<int> distancia;
    dijkstra(grafo, fuente, distancia); // Calcula las distancias mínimas desde el nodo fuente
    
    // Salida de distancias mínimas
    cout << "Distancias mínimas desde el nodo fuente " << nombreFuente << ":" << endl;
    for (map<string, int>::iterator it = indiceNodo.begin(); it != indiceNodo.end(); ++it) {
        string nombreNodo = it->first; // Nombre del nodo
        int indice = it->second; // Índice del nodo
        cout << "Nodo " << nombreNodo << ": " << distancia[indice] << endl;
    }

    cout << "Distancia mínima desde el nodo fuente " << nombreFuente << " al nodo destino " << nombreDestino << ": " << distancia[destino] << endl;
    
    return 0;
}

