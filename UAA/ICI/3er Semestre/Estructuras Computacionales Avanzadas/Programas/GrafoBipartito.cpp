/*========================================================
  Grafo Bipartito >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  -------------------------------
  Juan Francisco Gallo Ramírez
  3er Semestre I.C.I.
========================================================*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esBipartido(vector<vector<int> >& grafo, int v) 
{
    vector<int> colores(v, -1);  // Inicializamos todos los nodos con el color -1 (no coloreado).
    queue<int> cola;

    for (int i = 0; i < v; i++) 
	{
        if (colores[i] != -1)  // Si el nodo ya está coloreado, continuamos.
            continue;

        colores[i] = 0;  // Coloreamos el primer nodo con el color 0.
        cola.push(i);

        while (!cola.empty()) 
		{
            int nodo = cola.front();
            cola.pop();

            for (int j = 0; j < grafo[nodo].size(); j++) 
			{
                int vecino = grafo[nodo][j];
                if (colores[vecino] == -1) 
				{
                    colores[vecino] = 1 - colores[nodo];  // Asignamos el color opuesto al nodo actual.
                    cola.push(vecino);
                } else if (colores[vecino] == colores[nodo]) 
				{
                    return false;  // Si dos nodos adyacentes tienen el mismo color, no es bipartido.
                }
            }
        }
    }

    return true;  // Si hemos coloreado todo el grafo sin conflictos, es bipartido.
}

int main() 
{
    int v, e;
    cout << "Ingrese el numero de vertices y aristas del grafo: ";
    cin >> v >> e;

    vector<vector<int> > grafo(v);
    cout << "Ingrese las aristas (por ejemplo, para la arista 0-1, ingrese '0 1'):" << endl;
    for (int i = 0; i < e; i++) 
	{
        int u, w;
        cin >> u >> w;
        grafo[u].push_back(w);
        grafo[w].push_back(u);  // El grafo es no dirigido, por lo que agregamos aristas en ambas direcciones.
    }

    if (esBipartido(grafo, v)) 
	{
        cout << "El grafo es bipartido." << endl;
    } else 
	{
        cout << "El grafo no es bipartido." << endl;
    }

    return 0;
}
