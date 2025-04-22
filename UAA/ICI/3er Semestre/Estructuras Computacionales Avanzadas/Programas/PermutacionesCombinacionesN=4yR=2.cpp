/*===================================================
   PERMUTACIONES Y COMBINACIONES DE "n" ELEMENTOS.
  ------------------------------------------------
    Programa que realiza las combinaciones y 
    permutaciones de "n" de elementos 
    para 2 elementos, se muestran las 
	permutaciones y combinaciones.
  ------------------------------------------------
   Juan Francisco Gallo Ramírez
   13 de agosto de 2023
===================================================*/
#include <iostream>
#include <windows.h>

using namespace std;

void ingresarElementos(int n, char array[])
{
	for(int i=0; i<n; i++)
	{
		cout << endl << " > Ingresa el elemento #" << i+1 << ": ";
		cin >> array[i];
	}
}

void permutaciones(char array[], int n)
{
	int c = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i!=j)
			{
				cout << "\t" << array[i] << array[j] << endl;
				c++;
			}
		}
	}
	cout << endl << "  TOTAL: " << c <<" permutaciones." << endl;
}

void combinaciones (char array[], int n)
{
	int c = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			cout << "\t" << array[i] << array[j] << endl;
			c++;
		}
	}
	cout << endl << "  TOTAL: " << c <<" combinaciones." << endl;
}

int main()
{
	char *array = NULL;
	int n, r=2;
	
	cout << "         --- PERMUTACIONES Y COMBINACIONES ---         " << endl;
	cout << "                    (Siendo R = 2)" << endl << endl;
	
	cout << " > Ingresa la cantidad de elementos (\"n\"): ";
	cin >> n;
	
	array = new char(n);
	
	ingresarElementos(n, array);
	
	system("cls");
	cout << "         --- PERMUTACIONES Y COMBINACIONES ---         " << endl;
	cout << "                (Siendo R = 2 y N = " << n << ")" << endl << endl;
	
	cout << " > Permutaciones <" << endl;
	permutaciones(array, n);
	cout << endl << " > Combinaciones <" << endl;
	combinaciones(array, n);

	delete[] array;
	
}
