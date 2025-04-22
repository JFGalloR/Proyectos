/*==================================================================================
	M�TODO DE B�SQUEDA SECUENCIAL
==================================================================================*/

#include <iostream>
using namespace std;

#define TAM 5

// Funci�n de b�squeda.
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

// Funci�n principal.
int main()
{
	char arreglo[TAM] = {'e', 'c', 'a', 'd', 'b'};
	char dato = 'c';
	int pos;
	
	pos = buscar(arreglo, dato);
	
	// Seg�n el valor retornado por la funci�n.
	if(pos == -1)
	{
		cout << "DATO NO ENCONTRADO";
	}
	else
	{
		cout << "DATO ENCONTRRADO EN LA POSCICION " << pos << " DEL ARREGLO.";
	}
}
