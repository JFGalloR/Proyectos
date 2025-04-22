/*===================================================
  EJERCICIO. Recursividad.
 --------------------------------------------------
  OBJETIVO:
	Implementar un c�digo cn casos recursivos de 
	acuerdo a los puntos revisados del tema en 
	clase.
 --------------------------------------------------
  ELABORADOR:
    Juan Francisco Gallo Ram�rez
 --------------------------------------------------
	15 de Abril de 2023
	I.C.I. U.A.A.
====================================================*/
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <limits>
#include <string.h>
#include <windows.h>
using namespace std;

#define TAM 8

const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

void color(int, int);
void menu(int);
void imprimirFrase(string, int, int);
void leerVector(int [], int);
void imprimirVector(int [], int);
void imprimirCadena(string, int);
int factorial(int, int);

//___________________________________ FUNCI�N PRINCIPAL _______
int main()
{
	setlocale(LC_ALL, "");
	system("color F0");
	menu(0);
	getch();
	return 0;
}

//____________________________________ FUNCI�N DE COLOR _______
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//________________________________________ FUNCI�N MEN� _______
void menu(int opc)
{
	if(opc != 5)
	{
		system("cls");
		color(roj, gric);cout<<"                 MEN� DE FUNCIONES (Implementando recursividad)                 "<<endl<<endl;
		color(gric, roj);cout<<"\t\t1. ";color(gric, neg);cout<<"Imprimir \"n\" veces una frase."<<endl;
		color(gric, roj);cout<<"\t\t2. ";color(gric, neg);cout<<"Mostrar datos de vector."<<endl;
		color(gric, roj);cout<<"\t\t3. ";color(gric, neg);cout<<"Imprimir cadena al rev�s."<<endl;
		color(gric, roj);cout<<"\t\t4. ";color(gric, neg);cout<<"Calcular factorial."<<endl;
		color(gric, roj);cout<<"\t\t5. <- Salir."<<endl<<endl;
		color(gric, roj);cout<<"\t"<<FF;color(gric, neg);cout<<" Ingresa una opci�n: ";
		color(gric, roj);cin>>opc;
		
		string frase = "";
		int n;
		string cadena = "";
		int fact = 1;
		switch(opc)
		{
			case 1:
				system("cls");
				color(roj, gric);cout<<"                 MEN� DE FUNCIONES (Implementando recursividad)                 "<<endl<<endl;
				color(gric, negc);cout<<"\t"<<F<<" Imprimir frase \"n\" veces."<<endl<<endl;
				
				color(gric, roj);cout<<"\t"<<FF;color(gric, neg);cout<<" Ingresa una frase: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				color(gric, roj);getline(cin, frase);
				color(gric, roj);cout<<"\t"<<FF;color(gric, neg);cout<<" Ingresa la cantidad de veces: ";
				color(gric, roj);cin>>n;
				cout<<endl;
				//Funci�n recursiva para imprimir frase.
				imprimirFrase(frase, n, 0);
				getch();
				break;
			case 2:
				system("cls");
				color(roj, gric);cout<<"                 MEN� DE FUNCIONES (Implementando recursividad)                 "<<endl<<endl;
				color(gric, negc);cout<<"\t"<<F<<" Mostrar un vector."<<endl<<endl;
				int vector[TAM];
				
				//Funci�n para recursiva para leer vector.
				leerVector(vector, 0);
				
				system("cls");
				color(roj, gric);cout<<"                 MEN� DE FUNCIONES (Implementando recursividad)                 "<<endl<<endl;
				color(gric, negc);cout<<"\t"<<F<<" Mostrar un vector."<<endl<<endl;
				
				//Funci�n para recursiva para imprimir vector.
				imprimirVector(vector, 0);
				getch();
				break;
			case 3:
				system("cls");
				color(roj, gric);cout<<"                 MEN� DE FUNCIONES (Implementando recursividad)                 "<<endl<<endl;
				color(gric, negc);cout<<"\t"<<F<<" Imprimir cadena al rev�s."<<endl<<endl;
				color(gric, roj);cout<<"\t"<<FF;color(gric, neg);cout<<" Ingresa una cadena: ";
				color(gric, roj);cin>>cadena;
				cout<<endl;
				color(gric, roj);cout<<"\tCadena al rev�s: ";color(gric, azu);
				
				//Funci�n recursiva para imprimir frase.
				imprimirCadena(cadena, cadena.size());
				getch();
				break;
			case 4:
				system("cls");
				color(roj, gric);cout<<"                 MEN� DE FUNCIONES (Implementando recursividad)                 "<<endl<<endl;
				color(gric, negc);cout<<"\t"<<F<<" Factorial."<<endl<<endl;
				color(gric, roj);cout<<"\t"<<FF;color(gric, neg);cout<<" Ingresa un n�mero: ";
				color(gric, roj);cin>>n;
				cout<<endl;
				
				//Funci�n recursiva para obtener factorial.
				cout<<"\t"<<n<<"! = ";color(gric, azu);cout<<factorial(fact, n);
				getch();
				break;
			case 5:
				color(gric, ama);cout<<"\n\t "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
				break;
			default:
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
				getch();
		}
		menu(opc);
	}
}

//_________________________ FUNCI�N PARA IMRPIMIR FRASE _______
void imprimirFrase(string frase, int n, int c)
{
	if(c < n)
	{
	color(gric, roj);cout<<"\t"<<c+1<<".";color(gric, azu);cout<<"\t"<<frase<<endl;
		imprimirFrase(frase, n, c+1);
	}
}

//____________________________ FUNCI�N PARA LEER VECTOR _______
void leerVector(int vector[], int n)
{
	if(n < TAM)
	{
		color(gric, roj);cout<<"\t"<<FF;color(gric, neg);cout<<" Ingresa n�mero de la posici�n "<<n<<": ";
		color(gric, roj);cin>>vector[n];
		leerVector(vector, n+1);
	}
}

//_________________________ FUNCI�N PARA IMPRMIR VECTOR _______
void imprimirVector(int vector[], int n)
{
	if(n < TAM)
	{
		color(gric, roj);cout<<"\tvector["<<n<<"] = ";color(gric, neg);cout<<vector[n]<<endl;
		imprimirVector(vector, n+1);
	}
}

//_______________ FUNCI�N PARA IMPRIMIR CADENA AL REV�S _______
void imprimirCadena(string cadena, int n)
{
	if(n >= 0)
	{
		cout<<cadena[n];
		imprimirCadena(cadena, n-1);
	}
}

//______________________ FUNCI�N PARA OBTENER FACTORIAL _______
int factorial(int num, int n)
{
	if(n > 1)
	{
		num *= n;
		factorial(num, n-1);
	}else
	{
		return num;
	}
	
}












