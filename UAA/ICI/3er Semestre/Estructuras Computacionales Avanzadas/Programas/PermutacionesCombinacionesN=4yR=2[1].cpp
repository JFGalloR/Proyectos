/*===================================================
   PERMUTACIONES Y COMBINACIONES DE "n" ELEMENTOS 
   PARA "r" ELEMENTOS.
  ------------------------------------------------
    Programa que realiza las combinaciones y 
    permutaciones de "n" de elementos para "r" 
	elementos, se muestran las permutaciones y 
	combinaciones.
  ------------------------------------------------
   Alumnos:
     > Juan Francisco Gallo Ramírez
     > Luis Pablo Esparza Terrones
     > Luis Manuel Flores Jiménez
   14 de agosto de 2023                   I.C.I.
===================================================*/
#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;


const char C = 2, F = 16, FF = 187;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;

int c=0, p=0;

//---------------------------- FUNCIÓN PARA MANIPULAR EL COLOR DE LOS CARACTÉRES ---//
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//------------------------------------------ FUNCIÓN PARA INGRESAR LOS ELEMENTOS ---//
void ingresarElementos(int n, char array[])
{
	for(int i=0; i<n; i++)
	{
		color(GRIC, AZUC); cout << "\t   " << FF << " Ingresa el elemento #" << i+1 << ": ";
		color(GRIC, AZU); cin >> array[i];	
	}
}

//-------------------------------- FUNCIÓN PARA OBTENER SI HAY NÚMEROS REPETIDOS ---//
bool elementoRep(char elemento, string aux)
{
	for(int i=0; i<aux.length(); i++)
	{
		if(elemento == aux[i])
		{
			return true;
		}
	}
	return false;
}

//------------------------------------- FUNCIÓN PARA IMPRIMIR LAS PERMUTACIONES ---//
void permutaciones(char array[], int n, int r, string aux)
{
	if(r==1)
	{
		for(int i=0; i<n; i++)
		{
			if(!elementoRep(array[i], aux))
			{
				cout << "\t\t" << aux << array[i] << endl;
				p++;
			}
		}
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			if(!elementoRep(array[i], aux))
			{
				permutaciones(array, n, r-1, aux+array[i]);
			}
		}
	}
}

//------------------------------------- FUNCIÓN PARA IMPRIMIR LAS COMBINACIONES ---//

void combinaciones(char array[], int n, int r, int a, string aux)
{
	if(r==1)
	{
		for(int i=a; i<n; i++)
		{
			cout << "\t\t" << aux << array[i] << endl;
			c++;
		}
	}
	else
	{
		for(int i=a; i<n; i++)
		{
			combinaciones(array, n, r-1, i+1, aux+array[i]);
		}
	}
}

//----------------------------------------------------------- FUNCIÓN PRINCIPAL ---//
int main()
{
	char *array = NULL;
	int n, r;
	
	setlocale(LC_ALL, "");system("color F0");
	
	color(AZU, GRIC);  cout << "                              PERMUTACIONES Y COMBINACIONES                              " << endl;
	color(AZUC, GRIC); cout << "                                    (Dado \"n\" y \"r\")                                     " << endl << endl;
	
	color(GRIC, AZU); cout << "\t" << FF; color(GRIC, NEG); cout << " Ingresa el número de elementos \"n\": ";
	color(GRIC, AZU); cin >> n;
	
	array = new char(n);
	
	ingresarElementos(n, array);
	
	color(GRIC, AZU); cout << endl << "\t" << FF; color(GRIC, NEG); cout << " Ingresa la cantidad a elegir \"r\": ";
	color(GRIC, AZU); cin >> r;
	
	system("cls");
	
	color(AZU, GRIC);  cout << "                              PERMUTACIONES Y COMBINACIONES                              " << endl;
	color(AZUC, GRIC); cout << "                                                                                         " << endl << endl;
	
	color(GRIC, AZU); cout << "\t" << FF << " Permutaciones (" << n << "P" << r << "): " << endl << endl;
	color(GRIC, NEG); permutaciones(array, n, r, "");
	color(GRIC, ROJ); cout << endl << "\tTotal " << p << " de permutaciones." << endl << endl;
	
	color(GRIC, AZU); cout << endl << "\t" << FF << " Combinaciones (" << n << "C" << r << "): " << endl << endl;
	color(GRIC, NEG);combinaciones(array, n, r, 0, "");
	color(GRIC, ROJ); cout << endl << "\tTotal " << c << " de combinaciones." << endl << endl;
	
	cout << endl << endl; system("pause");
	
}
