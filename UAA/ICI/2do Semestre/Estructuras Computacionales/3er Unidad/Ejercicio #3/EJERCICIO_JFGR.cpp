/*===================================================
  EJERCICIO. Ejercicio de Pilas.
 --------------------------------------------------
  OBJETIVO:
	Dada una expresión guardada en una cadena que
	se maneja como dato de entrada, verificar que 
	todos los paréntesis de una expresión estén 
	correctos, es decir, que por cada paréntesis 
	que abre exista otro que cierre.
 --------------------------------------------------
	Juan Francisco Gallo Ramírez
	30 de Marzo de 2023
	I.C.I. U.A.A.
====================================================*/
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
using namespace std;

#define MAX 100

const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

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
	char dato;
	Nodo *anterior;
};
//===================================== FUNCIÓN PARA INSERTAR EN LA PILA =====
void push(Nodo *&pila, char valor)
{
	Nodo *nodo = new Nodo;
	
	if(pila==NULL)
	{
		nodo->anterior = NULL;
	}else
	{
		nodo->anterior = pila;
	}
	nodo->dato = valor;
	pila = nodo;
}
//===================================== FUNCIÓN PARA ELIMINAR DE LA PILA =====
void pop(Nodo *&pila)
{
	Nodo *aux = pila;
	
	if(pila==NULL)
	{
		
	}else
	{
		pila = aux->anterior;
		delete aux;
	}
}
//==================================================== FUNCIÓN PRINCIPAL =====
main()
{
	char cadena[MAX];
	Nodo *pila = NULL;
	bool error=false;
	
	setlocale(LC_ALL, ""); system("color F0");
	do
	{
		system("cls");
		color(azu,gric);cout<<"                    CORRESPONDENCIA DE PARÉNTESIS                    "<<endl<<endl;
		color(gric,negc);cout<<"\t< Ingresa \"0\" para terminar ejecución >"<<endl<<endl;
		color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una expresión: ";
		color(gric,azu);cin.getline(cadena, MAX-1);
		
		if(strcmp(cadena, "0")!=0)
		{
			for(int i=0;i<strlen(cadena);i++)
			{
				if(cadena[i]=='(')
				{
					push(pila,'(');
				}else 
				if(cadena[i]==')')
				{
					if(pila==NULL)
					{
						error=true;
					}
					pop(pila);
				}
			}
			if(error==false && pila==NULL)
			{
				cout<<"\n\t>>> EXPRESIÓN VALIDA <<<"<<endl;
			}else
			{
				cout<<"\n\t>>> EXPRESIÓN INVALIDA <<<"<<endl;
			}
			getch();
		}
	}while(strcmp(cadena, "0")!=0);
	
	color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";getch();
}
