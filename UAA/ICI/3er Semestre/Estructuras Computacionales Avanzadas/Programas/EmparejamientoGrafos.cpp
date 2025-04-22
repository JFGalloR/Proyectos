/*==================================================================
	PROGRAMA DE EMPAREJAMIENTO DE GRAFOS
	----------------------------------------------------------
	Juan Francisco Gallo Ramírez
	I.C.I.
==================================================================*/
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(int u, vector<bool>& visited, vector<int>& match) {
        visited[u] = true;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (match[v] == -1 || (!visited[match[v]] && dfs(match[v], visited, match))) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        vector<int> match(V, -1);
        int matching = 0;
        for (int u = 0; u < V; u++) {
            if (match[u] == -1) {
                vector<bool> visited(V, false);
                if (dfs(u, visited, match)) {
                    matching++;
                }
            }
        }
        return matching;
    }

    vector<pair<int, int> > getPairs() {
        vector<pair<int, int> > pairs;
        for (int u = 0; u < V; u++) {
            if (match[u] != -1) {
                pairs.push_back(make_pair(u, match[u]));
            }
        }
        return pairs;
    }

private:
    int V;
    vector<vector<int> > adj;
    vector<int> match;
};

int main() {
    // Ejemplo de uso
    int V = 6; // Número de nodos en el grafo
    Graph graph(V);

    // Agregar aristas al grafo
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    int maxMatching = graph.maxMatching();
    cout << "El emparejamiento máximo es: " << maxMatching << endl;

    vector<pair<int, int> > pairs = graph.getPairs();
    cout << "Pares emparejados:" << endl;
    for (int i = 0; i < pairs.size(); i++) {
        cout << "Nodo " << pairs[i].first << " emparejado con Nodo " << pairs[i].second << endl;
    }

    return 0;
}

