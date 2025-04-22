/*===================================================
  EJERCICIO. Implementación de Pilas.
 --------------------------------------------------
  OBJETIVO:
	Realizar la implementación de las operaciones 
	de insertar y sacar e imprimir elementos de 
	una Pila utilizando un arreglo.
	Consideraciones
	 • Presentar las opciones solicitadas en un menú 
	  (1. InsertarPush elemento,2. Sacar-Pop 
	  elemento, 3. Imprimir la cola).
	 • Organizar el código en funciones y/o 
	  procedimientos.
 --------------------------------------------------
	Juan Francisco Gallo Ramírez
	23 de Marzo de 2023
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

//==================================================== ESTRUCTURA "Nodo" =====
struct Nodo
{
	int dato;
	Nodo *anterior;
};

//========================================= FUNCIÓN PARA MOSTRAR LA PILA =====
void mostrar(Nodo *&pila)
{
	Nodo *aux = pila;
	
	color(gric,azu);cout<<"\n\t- Pila:"<<endl;
	if(pila==NULL)
	{
		color(gric,roj);cout<<endl<<"\t# # # STACK UNDERFLOW # # #"<<endl<<endl;
	}else
	{
		cout<<endl;
		while(aux!=NULL)
		{
			color(gric,roj);cout<<"\t";
			color(gric,negc);cout<<"| ";color(gric,neg);cout<<aux->dato<<"\t";
			color(gric,negc);cout<<"|"<<endl;
			aux = aux->anterior;
		}
	}
}

//===================================== FUNCIÓN PARA INSERTAR EN LA PILA =====
void push(Nodo *&pila)
{
	Nodo *nodo = new Nodo;
	int valor;
	
	system("cls");
	color(roj,gric);cout<<"                                MENÚ DE PILAS                                "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Insertar en pila."<<endl<<endl;
	color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa dato: ";
	color(gric,roj);cin>>valor;
	if(pila==NULL)
	{
		nodo->anterior = NULL;
	}else
	{
		nodo->anterior = pila;
	}
	nodo->dato = valor;
	pila = nodo;
	mostrar(pila);	
	color(gric,ver);cout<<endl<<"\t(+) Número "<<valor<<" agregado correctamente a la pila..."<<endl<<endl;
	getch();
}

//===================================== FUNCIÓN PARA ELIMINAR DE LA PILA =====
void pop(Nodo *&pila)
{
	Nodo *aux = pila;
	
	system("cls");
	color(roj,gric);cout<<"                                MENÚ DE PILAS                                "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Eliminar en pila."<<endl;
	if(pila==NULL)
	{
		color(gric,roj);cout<<endl<<endl<<"\t# # # STACK UNDERFLOW # # #"<<endl;
	}else
	{
		pila = aux->anterior;
		mostrar(pila);
		color(gric,roj);cout<<endl<<"\t(-) Número "<<aux->dato<<" eliminado correctamente de la pila..."<<endl<<endl;
		delete aux;
	}
	getch();
}

//======================================== FUNCIÓN PARA IMPRIMIR LA PILA =====
void imprimir(Nodo *&pila)
{
	
	system("cls");
	color(roj,gric);cout<<"                                MENÚ DE PILAS                                "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Mostrar  pila."<<endl;
	mostrar(pila);
	getch();
}

//==================================================== FUNCIÓN PRINCIPAL =====
main()
{
	int opc = 0;
	Nodo *pila = NULL;
	
	setlocale(LC_ALL, "");system("color F0");
	do
	{
		system("cls");
		color(roj,gric);cout<<"                                MENÚ DE PILAS                                "<<endl<<endl;
		color(gric,roj);cout<<"\t  1) ";color(gric,neg);cout<<"Insertar elemento."<<endl;
		color(gric,roj);cout<<"\t  2) ";color(gric,neg);cout<<"Eliminarar elemento."<<endl;
		color(gric,roj);cout<<"\t  3) ";color(gric,neg);cout<<"Mostrar pila."<<endl;
		color(gric,roj);cout<<"\t  4) <- Salir."<<endl<<endl;
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
		color(gric,roj);cin>>opc;
		switch(opc)
		{
			case 1:
				push(pila);
				break;
			case 2:
				pop(pila);
				break;
			case 3:
				imprimir(pila);
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
