/*==================================================================================
	MÉTODO DE ORDENACIÓN POR SELECCIÓN
==================================================================================*/

#include <iostream>
using namespace std;

#define TAM 5

void imprimir(char arreglo[])
{
	// Recorremos todo el arreglo e imprimimos.
	for(int i = 0; i < TAM; i++)
	{
		cout << arreglo[i] << "  ";
	}
}

int main()
{
	char arreglo[TAM] = {'e', 'c', 'a', 'd', 'b'};
	int min, aux;
	
	// Imprimimos el arreglo.
	cout << "ARREGLO INICIAL: ";
	imprimir(arreglo);
	cout << endl;
	
	// Ciclo que recorre cada índice.
	for(int i = 0; i < TAM - 1; i++)
	{
		min = i;
		// Ciclo que recorre cada elemento a partir del índice.
		for(int j = i + 1; j < TAM; j++)
		{
			// Si el número del índice es menor al mínimo se asigna el índice a "min".
			if(arreglo[j] < arreglo[min])
			{
				min = j;
			}
		}
		// Intercambiamos.
		aux = arreglo[i];
		arreglo[i] = arreglo[min];
		arreglo[min] = aux;
	}
	
	// Imprimimos el arreglo.
	cout << "ARREGLO ORDENADO: ";
	imprimir(arreglo);
	
}
