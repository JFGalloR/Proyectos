/*==================================================================================
	MÉTODO DE BÚSQUEDA SECUENCIAL
==================================================================================*/

#include <iostream>
using namespace std;

#define TAM 5

// Función de búsqueda.
int buscar(char arreglo[], char dato)
{
	for(int i = 0; i < TAM; i++)
	{
		if(arreglo[i] == dato)
		{
			return i;
		}
	}
	return -1;
}

// Función principal.
int main()
{
	char arreglo[TAM] = {'e', 'c', 'a', 'd', 'b'};
	char dato = 'c';
	int pos;
	
	pos = buscar(arreglo, dato);
	
	// Según el valor retornado por la función.
	if(pos == -1)
	{
		cout << "DATO NO ENCONTRADO";
	}
	else
	{
		cout << "DATO ENCONTRRADO EN LA POSCICION " << pos << " DEL ARREGLO.";
	}
}
