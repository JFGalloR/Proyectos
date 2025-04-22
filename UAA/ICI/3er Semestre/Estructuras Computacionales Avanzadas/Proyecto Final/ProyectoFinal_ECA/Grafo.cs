using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProyectoFinal_ECA
{
    public class Grafo
    {
        public Dictionary<String, Dictionary<String, int>> listaAdyacencia;
        public int[,] matrizAdyacencia;
        public List<String> nodos;

        // Constructor.
        public Grafo()
        {
            listaAdyacencia = new Dictionary<String, Dictionary<String, int>>();
            nodos = new List<String>();
        }

        // Método para agregar aristas.
        public bool AgregarArista(String origen, String destino, int peso, bool dirigido)
        {
            if(!listaAdyacencia.ContainsKey(origen))
            {
                listaAdyacencia[origen] = new Dictionary<String, int>();
                nodos.Add(origen);
            }
            else if(listaAdyacencia[origen].ContainsKey(destino))
            {
                return false;
            }

            if (!listaAdyacencia.ContainsKey(destino))
            {
                listaAdyacencia[destino] = new Dictionary<String, int>();
                nodos.Add(destino);
            }

            if (!dirigido)
            {
                if (listaAdyacencia[destino].ContainsKey(origen))
                {
                    return false;
                }

                listaAdyacencia[destino][origen] = peso;
            }

            listaAdyacencia[origen][destino] = peso;

            GenerarMatriz();
            return true;
        }

        // Método para generar la Matriz de Adyacencia.
        private void GenerarMatriz()
        {
            matrizAdyacencia = new int[nodos.Count, nodos.Count];

            foreach (String aux1 in listaAdyacencia.Keys)
            {
                int i = nodos.IndexOf(aux1);
                foreach (String aux2 in listaAdyacencia[aux1].Keys)
                {
                    int j = nodos.IndexOf(aux2);
                    matrizAdyacencia[i, j] = listaAdyacencia[aux1][aux2];
                }
            }
        }

        // Método para realizar la búsqueda en anchura.
        public List<String> BusquedaAnchura(String v)
        {
            List<String> anchura = new List<String>();
            Queue<String> queue = new Queue<String>();

            anchura.Add(v);
            queue.Enqueue(v);
            while (queue.Count > 0)
            {
                v = queue.Peek();
                queue.Dequeue();
                foreach(String aux in listaAdyacencia[v].Keys)
                {
                    if(!anchura.Contains(aux))
                    {
                        queue.Enqueue(aux);
                        anchura.Add(aux);
                    }
                }
            }

            return anchura;
        }

        // Método para realizar la búsqueda en anchura.
        public List<string> BusquedaProfundidad(string v)
        {
            List<string> profundidad = new List<string>();
            Stack<string> stack = new Stack<string>();

            stack.Push(v);

            while (stack.Count > 0)
            {
                v = stack.Pop();

                if (!profundidad.Contains(v))
                {
                    profundidad.Add(v);

                    foreach (string aux in listaAdyacencia[v].Keys)
                    {
                        if (!profundidad.Contains(aux))
                        {
                            stack.Push(aux);
                        }
                    }
                }
            }

            return profundidad;
        }


        // Métodos para obtener los componentes conexos ---
        private void MatrizCaminos(int[,] matriz)
        {
            int n = nodos.Count;

            for (int i = 0; i < n; i++)
            {
                bool cambio = true;
                while (cambio)
                {
                    cambio = false;
                    for (int j = 0; j < n; j++)
                    {
                        if (matriz[i, j] == 1 && i != j)
                        {
                            for (int l = 0; l < n; l++)
                            {
                                if (matriz[j, l] == 1 && matriz[i, l] != 1)
                                {
                                    cambio = true;
                                    matriz[i, l] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }

        private void OrdenarMatriz(int[,] matriz, string[] nod)
        {
            int n = nod.Length;

            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (SumaFila(matriz, i) < SumaFila(matriz, j))
                    {
                        SwapFila(matriz, i, j);
                        SwapString(nod, i, j);
                    }
                }
            }
        }

        private int SumaFila(int[,] matriz, int fila)
        {
            int suma = 0;
            int n = matriz.GetLength(0);

            for (int i = 0; i < n; i++)
            {
                suma += matriz[fila, i];
            }

            return suma;
        }

        private void SwapFila(int[,] matriz, int fila1, int fila2)
        {
            int n = matriz.GetLength(0);

            for (int i = 0; i < n; i++)
            {
                int temp = matriz[fila1, i];
                matriz[fila1, i] = matriz[fila2, i];
                matriz[fila2, i] = temp;
            }
        }

        private void SwapString(string[] arreglo, int i, int j)
        {
            string temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
        }

        public List<string> ComponentesConexos()
        {
            List<string> componentes = new List<string>();
            bool nuevo = true;
            bool coma = false;

            int[,] matriz = matrizAdyacencia;
            String[] aux = nodos.ToArray();
            
            MatrizCaminos(matriz);
            OrdenarMatriz(matriz, aux);

            for (int i = 0; i < aux.Length; i++)
            {
                if (nuevo)
                    componentes.Add("{ ");
                if (i < aux.Length - 1)
                {
                    if (matriz[i + 1, i] == 1)
                    {
                        if (coma)
                            componentes[componentes.Count - 1] += ",";
                        componentes[componentes.Count - 1] += aux[i];
                        coma = true;
                        nuevo = false;
                    }
                    else
                    {
                        if (coma)
                            componentes[componentes.Count - 1] += ",";
                        componentes[componentes.Count - 1] += aux[i] + " }";
                        coma = false;
                        nuevo = true;
                    }
                }
                else
                {
                    if (coma)
                        componentes[componentes.Count - 1] += ",";
                    componentes[componentes.Count - 1] += aux[i] + " }";
                    coma = false;
                    nuevo = true;
                }
            }
            return componentes;
        }
        //-------------------------------------------------

        // Métodos para Camino más corto ------------------
        public List<string> Dijkstra(string origen, string destino)
        {
            Dictionary<string, int> distancia = new Dictionary<string, int>();
            Dictionary<string, string> predecesor = new Dictionary<string, string>();
            List<string> nodosNoVisitados = new List<string>();

            // Inicializar las distancias y predecesores
            foreach (string nodo in nodos)
            {
                distancia[nodo] = int.MaxValue;
                predecesor[nodo] = null;
                nodosNoVisitados.Add(nodo);
            }

            distancia[origen] = 0;

            while (nodosNoVisitados.Count > 0)
            {
                string nodoActual = EncontrarNodoConMenorDistancia(distancia, nodosNoVisitados);
                nodosNoVisitados.Remove(nodoActual);

                if(nodoActual == null)
                {
                    return null;
                }

                if (nodoActual == destino)
                {
                    return ConstruirCamino(origen, destino, predecesor);
                }

                if (listaAdyacencia.ContainsKey(nodoActual))
                {
                    foreach (var vecino in listaAdyacencia[nodoActual])
                    {
                        int distanciaTotal = distancia[nodoActual] + vecino.Value;
                        if (distanciaTotal < distancia[vecino.Key])
                        {
                            distancia[vecino.Key] = distanciaTotal;
                            predecesor[vecino.Key] = nodoActual;
                        }
                    }
                }
            }

            return null; // No se encontró un camino
        }

        private string EncontrarNodoConMenorDistancia(Dictionary<string, int> distancia, List<string> nodosNoVisitados)
        {
            int minDistancia = int.MaxValue;
            string nodoMinimo = null;

            foreach (string nodo in nodosNoVisitados)
            {
                if (distancia[nodo] < minDistancia)
                {
                    minDistancia = distancia[nodo];
                    nodoMinimo = nodo;
                }
            }

            return nodoMinimo;
        }

        private List<string> ConstruirCamino(string origen, string destino, Dictionary<string, string> predecesor)
        {
            List<string> camino = new List<string>();
            string nodoActual = destino;

            while (nodoActual != null)
            {
                camino.Insert(0, nodoActual);
                nodoActual = predecesor[nodoActual];
            }

            return camino;
        }

        public int PesoCamino(List<String> camino)
        {
            int peso = 0;

            for(int i = 1; i < camino.Count; i++)
            {
                peso += listaAdyacencia[camino[i - 1]][camino[i]];
            }

            return peso;
        }
        // ------------------------------------------------

        // Método para pareo de grafo normal --------------
        public Dictionary<string, string> PareoNormal()
        {
            Dictionary<string, string> emparejamiento = new Dictionary<string, string>();
            List<string> nodosIzquierda = new List<string>();
            List<string> nodosDerecha = new List<string>();

            foreach (var nodo in nodos)
            {
                if (emparejamiento.ContainsKey(nodo))
                {
                    nodosDerecha.Add(nodo);
                }
                else
                {
                    nodosIzquierda.Add(nodo);
                }
            }

            foreach (var nodoIzquierda in nodosIzquierda)
            {
                HashSet<string> visitados = new HashSet<string>();
                EncuentraCaminoAumento(nodoIzquierda, emparejamiento, visitados);
            }

            return emparejamiento;
        }

        private bool EncuentraCaminoAumento(string nodo, Dictionary<string, string> emparejamiento, HashSet<string> visitados)
        {
            foreach (var vecino in ObtenerVecinos(nodo))
            {
                if (!visitados.Contains(vecino))
                {
                    visitados.Add(vecino);

                    if (!emparejamiento.ContainsKey(vecino) || EncuentraCaminoAumento(emparejamiento[vecino], emparejamiento, visitados))
                    {
                        emparejamiento[nodo] = vecino;
                        emparejamiento[vecino] = nodo;
                        return true;
                    }
                }
            }

            return false;
        }

        private IEnumerable<string> ObtenerVecinos(string nodo)
        {
            if (listaAdyacencia.ContainsKey(nodo))
            {
                foreach (var vecino in listaAdyacencia[nodo].Keys)
                {
                    yield return vecino;
                }
            }
        }
        // ------------------------------------------------

        // Métodos para pareo de grafo biparito -----------
        public Dictionary<string, string> PareoBipartito()
        {
            int totalNodos = nodos.Count;
            int[,] grafoResidual = new int[totalNodos, totalNodos];

            foreach (var nodo1 in listaAdyacencia.Keys)
            {
                foreach (var nodo2 in listaAdyacencia[nodo1].Keys)
                {
                    int indiceNodo1 = nodos.IndexOf(nodo1);
                    int indiceNodo2 = nodos.IndexOf(nodo2);
                    grafoResidual[indiceNodo1, indiceNodo2] = listaAdyacencia[nodo1][nodo2];
                }
            }

            int[] pareja = new int[totalNodos];
            for (int i = 0; i < totalNodos; i++)
            {
                pareja[i] = -1;
            }

            Dictionary<string, string> emparejamientos = new Dictionary<string, string>();
            for (int i = 0; i < totalNodos; i++)
            {
                bool[] visitado = new bool[totalNodos];
                AumentarCamino(i, grafoResidual, pareja, visitado, emparejamientos);
            }

            return emparejamientos;
        }

        private bool AumentarCamino(int nodo, int[,] grafoResidual, int[] pareja, bool[] visitado, Dictionary<string, string> emparejamientos)
        {
            int totalNodos = nodos.Count;

            for (int i = 0; i < totalNodos; i++)
            {
                if (grafoResidual[nodo, i] > 0 && !visitado[i])
                {
                    visitado[i] = true;

                    if (pareja[i] == -1 || AumentarCamino(pareja[i], grafoResidual, pareja, visitado, emparejamientos))
                    {
                        pareja[i] = nodo;
                        emparejamientos[nodos[i]] = nodos[nodo];
                        return true;
                    }
                }
            }

            return false;
        }
        // ------------------------------------------------
        
    }
}
