/*======================================================
  EJERCICIO. Colas con listas enlazadas.
 -----------------------------------------------------
  OBJETIVO:
	Realizar con listas enlazadas de las operaciones 
	de insertar y sacar e imprimir elementos de una
	Cola.
 -----------------------------------------------------
	Juan Francisco Gallo Ramírez
	12 de Abril de 2023
	I.C.I. U.A.A.
=======================================================*/
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
using namespace std;

const char C=2, F=17, FF=187;
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
	string dato;
	Nodo *anterior;
};

//========================================= FUNCIÓN PARA MOSTRAR LA PILA =====
void mostrar(Nodo *&cabeza)
{
	Nodo *aux = cabeza;
	
	color(gric,azu);cout<<"\n\t- Cola:"<<endl;
	if(cabeza==NULL)
	{
		color(gric,roj);cout<<endl<<"\t# # # NO HAY ELEMENTOS # # #"<<endl<<endl;
	}else
	{
		cout<<endl;
		while(aux!=NULL)
		{
			color(gric,roj);cout<<"\t";
			color(gric,negc);cout<<"| ";color(gric,neg);cout<<aux->dato<<endl;
			aux = aux->anterior;
		}
	}
}

//===================================== FUNCIÓN PARA INSERTAR EN LA COLA =====
void push(Nodo *&cabeza, Nodo *&cola)
{
	Nodo *nodo = new Nodo;
	string valor;
	
	system("cls");
	color(roj,gric);cout<<"                                MENÚ DE COLAS                                "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Insertar en cola."<<endl<<endl;
	color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa dato: ";
	color(gric,roj);cin>>valor;
	if(cabeza==NULL)
	{
		cabeza = nodo;
	}else
	{
		cola->anterior = nodo;
	}
	nodo->anterior = NULL;
	nodo->dato = valor;
	cola = nodo;
	mostrar(cabeza);	
	color(gric,ver);cout<<endl<<"\t(+) Dato \""<<valor<<"\" agregado correctamente a la cola..."<<endl<<endl;
	getch();
}

//===================================== FUNCIÓN PARA ELIMINAR DE LA COLA =====
void pop(Nodo *&cabeza, Nodo *&cola)
{
	Nodo *aux = cabeza;
	
	system("cls");
	color(roj,gric);cout<<"                                MENÚ DE COLAS                                "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Eliminar en cola."<<endl;
	if(cabeza==NULL)
	{
		color(gric,roj);cout<<endl<<endl<<"\t# # # STACK UNDERFLOW # # #"<<endl;
	}else
	{
		cabeza = cabeza->anterior;
		mostrar(cabeza);
		color(gric,roj);cout<<endl<<"\t(-) Dato \""<<aux->dato<<"\" eliminado correctamente de la cola..."<<endl<<endl;
		delete aux;
	}
	getch();
}

//======================================== FUNCIÓN PARA IMPRIMIR LA COLA =====
void imprimir(Nodo *&cabeza)
{
	
	system("cls");
	color(roj,gric);cout<<"                                MENÚ DE COLAS                                "<<endl<<endl;
	color(gric,neg);cout<<"\t"<<F<<" Mostrar  cola."<<endl;
	mostrar(cabeza);
	getch();
}

//==================================================== FUNCIÓN PRINCIPAL =====
main()
{
	int opc = 0;
	Nodo *cabeza = NULL;
	Nodo *cola = NULL;
	
	setlocale(LC_ALL, "");system("color F0");
	do
	{
		system("cls");
		color(roj,gric);cout<<"                                MENÚ DE COLAS                                "<<endl<<endl;
		color(gric,roj);cout<<"\t  1) ";color(gric,neg);cout<<"Insertar elemento."<<endl;
		color(gric,roj);cout<<"\t  2) ";color(gric,neg);cout<<"Eliminar elemento."<<endl;
		color(gric,roj);cout<<"\t  3) ";color(gric,neg);cout<<"Mostrar cola."<<endl;
		color(gric,roj);cout<<"\t  4) <- Salir."<<endl<<endl;
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
		color(gric,roj);cin>>opc;
		switch(opc)
		{
			case 1:
				push(cabeza, cola);
				break;
			case 2:
				pop(cabeza, cola);
				break;
			case 3:
				imprimir(cabeza);
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
