/*===================================================
   CONJUNTOS POTENCIA CON TABLAS BINARIAS.
  ------------------------------------------------
    Programa que obtiene los conjunto potencia 
	(2^n) de n elementos otorgados por el usuario.
  ------------------------------------------------
   Alumno
	Juan Francisco Gallo Ramírez
   18 de agosto de 2023                   I.C.I.
===================================================*/
#include <iostream>
#include <math.h>
#include <locale.h>
#include <windows.h>

using namespace std;

const char C = 2, FF = 187;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;

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

//--------------------------------- FUNCIÓN PARA CONVERTIR DE DECIMAL A BINARIO ---//
string decimalBinario(int num, int n)
{
	int res;
	string aux = "";
	string bin = "";
	
	while (num!=0)
	{
		aux += (num % 2 == 0)? "0" : "1";
		num /= 2;
	}
	
	for(int i=n-1; i>=0; i--)
		bin += (i>=aux.length())? '0' : aux[i];
		
	return bin;
}

//------------------------------------------------------------ FUNCIÓN PRINCIPAL ---//
main()
{
	char *elementos = NULL;
	string aux = "";
	bool impreso = false;
	int n, r;
	
	setlocale(LC_ALL, "");system("color F0");
	
	color(AZU, GRIC);  cout << "                                 CONJUNTOS POTENCIA                                 " << endl;
	color(AZUC, GRIC); cout << "                               De \"n\" elementos (2^n)                               " << endl << endl;
	
	color(GRIC, AZU); cout << "\t" << FF; color(GRIC, NEG); cout << " Ingresa el número de elementos \"n\": ";
	color(GRIC, AZU); cin >> n;
	
	elementos = new char(n+1);
	
	ingresarElementos(n, elementos);
	
	system("cls");
	color(AZU, GRIC);  cout << "                                 CONJUNTOS POTENCIA                                 " << endl;
	color(AZUC, GRIC); cout << "                               De \"n\" elementos (2^n)                               " << endl << endl;
	color(NEGC, GRIC);  cout << "\t\t\t\t " << elementos << " \t Subconjuntos " << endl << endl;
	color(GRIC, NEG);
	
	for(int i=0; i<pow(2,n); i++)
	{
		aux = decimalBinario(i, n);
		cout << "\t\t\t" << i << "\t " << aux << "\t { ";
		impreso = false;
		for(int j=0; j<n; j++)
		{
			if(aux[j] == '1')
			{
				if(impreso)
					cout << ",";
				cout << elementos[j];
				impreso = true;
			}
		}
		cout << " }" << endl;
	}
	
	delete[] elementos;
}
