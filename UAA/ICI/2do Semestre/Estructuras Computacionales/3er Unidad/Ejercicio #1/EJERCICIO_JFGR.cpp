/*===================================================
  EJERCICIO. Implementación de Pilas.
 --------------------------------------------------
  OBJETIVO:
	Realizar la implementación de las operaciones 
	de insertar y sacar e imprimir elementos de 
	una Pila utilizando un arreglo.
	Consideraciones
	 • Declarar un arreglo máximo de 10 posiciones.
	 • Presentar las opciones solicitadas en un menú 
	  (1. InsertarPush elemento,2. Sacar-Pop 
	  elemento, 3. Imprimir la cola).
	 • Organizar el código en funciones y/o 
	  procedimientos.
 --------------------------------------------------
	Juan Francisco Gallo Ramírez
	22 de Marzo de 2023
	I.C.I. U.A.A.
====================================================*/
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
using namespace std;
const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

#define MAX_PILA 5

//========================================== FUNCIÓN DE APOYO PARA COLOR =====
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//========================================= FUNCIÓN PARA MOSTRAR LA PILA =====
void mostrar(int &cima, int pila_a[])
{
	color(gric,azu);cout<<"\n\t- Pila:"<<endl;
	if(cima==-1)
	{
		color(gric,roj);cout<<endl<<"\t# # # STACK UNDERFLOW # # #"<<endl<<endl;
	}else
	{
		cout<<endl;
		for(int i=cima;i>=0;i--)
		{
			color(gric,roj);cout<<"\t"<<i<<". ";
			color(gric,negc);cout<<"| ";color(gric,neg);cout<<pila_a[i]<<"\t";
			color(gric,negc);cout<<"|"<<endl;
		}
	}
}

//===================================== FUNCIÓN PARA INSERTAR EN LA PILA =====
void push(int &cima, int pila_a[])
{
	int valor;
	
	system("cls");
	color(roj,gric);cout<<"                           MENÚ PILAS CON ARREGLOS                           "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Insertar en pila."<<endl<<endl;
	if(cima==MAX_PILA-1)
	{
		color(gric,roj);cout<<endl<<"\t# # # STACK OVERFLOW # # #"<<endl<<endl;
	}else
	{
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa dato: ";
		color(gric,roj);cin>>valor;
		cima++;
		pila_a[cima]=valor;
		mostrar(cima, pila_a);
		color(gric,ver);cout<<endl<<"\t(+) Número "<<valor<<" agregado correctamente a la pila..."<<endl<<endl;
	}
	getch();
}

//===================================== FUNCIÓN PARA ELIMINAR DE LA PILA =====
void pop(int &cima, int pila_a[])
{
	
	system("cls");
	color(roj,gric);cout<<"                           MENÚ PILAS CON ARREGLOS                           "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Eliminar en pila."<<endl;
	if(cima==-1)
	{
		color(gric,roj);cout<<endl<<endl<<"\t# # # STACK UNDERFLOW # # #"<<endl;
	}else
	{
		cima--;
		mostrar(cima, pila_a);
		color(gric,roj);cout<<endl<<"\t(-) Número "<<pila_a[cima+1]<<" eliminado correctamente de la pila..."<<endl<<endl;
	}
	getch();
}

//======================================== FUNCIÓN PARA IMPRIMIR LA PILA =====
void imprimir(int &cima, int pila_a[])
{
	
	system("cls");
	color(roj,gric);cout<<"                           MENÚ PILAS CON ARREGLOS                           "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Mostrar  pila."<<endl;
	mostrar(cima, pila_a);
	getch();
}

//==================================================== FUNCIÓN PRINCIPAL =====
main()
{
	int cima = -1;
	int opc=0;
	int pila_a[MAX_PILA];
	
	setlocale(LC_ALL, "");system("color F0");
	do
	{
		system("cls");
		color(roj,gric);cout<<"                           MENÚ PILAS CON ARREGLOS                           "<<endl<<endl;
		color(gric,roj);cout<<"\t  1) ";color(gric,neg);cout<<"Insertar elemento."<<endl;
		color(gric,roj);cout<<"\t  2) ";color(gric,neg);cout<<"Eliminarar elemento."<<endl;
		color(gric,roj);cout<<"\t  3) ";color(gric,neg);cout<<"Mostrar pila."<<endl;
		color(gric,roj);cout<<"\t  4) <- Salir."<<endl<<endl;
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
		color(gric,roj);cin>>opc;
		switch(opc)
		{
			case 1:
				push(cima, pila_a);
				break;
			case 2:
				pop(cima, pila_a);
				break;
			case 3:
				imprimir(cima, pila_a);
				break;
			case 4:
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";getch();
				break;
			default:
				cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";getch();
				break;		
		}
	}while(opc!=4);
	color(gric,gric);
}
