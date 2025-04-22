/*======================================================================
	EJERCICIO. Implementación de colas con arreglos.
  --------------------------------------------------------------------
	• OBJETIVO:
		Implementar operaciones de insertar y eliminar elementos de
		una Cola con el uso de arreglos.
  --------------------------------------------------------------------
    • ELABORADORES:
	 - Juan Francisco Gallo Ramírez
  --------------------------------------------------------------------
	7 de Abril de 2023
	I.C.I. U.A.A.
========================================================================*/
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

#define TAM 7
const char C = 2, F = 16, FF = 187;

void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

void insertar(string cola_1[], int &cabeza, int &cola, string cadena)
{
	if(cola == TAM-1 && cabeza == 0)
	{
		color(15, 4);cout<<endl<<"\t# # # COLA LLENA # # #"<<endl;
		getch();
	}else
	{
		if(cola == TAM-1)
		{
			cola = 0;
		}else
		{
			cola++;
		}
		cola_1[cola] = cadena;
		if(cola == 0 && cabeza  == -1)
		{
			cabeza = 0;
		}
	}
}

void eliminar(string cola_1[], int &cabeza, int &cola)
{
	if(cabeza == -1)
	{
		color(15, 4);cout<<endl<<"\t# # # COLA VACÍA # # #"<<endl;
		getch();
	}else
	{
		cola_1[cabeza] = "";
		if(cabeza == cola)
		{
			cabeza = -1;
			cola = -1;
		}else
		{
			if(cabeza == TAM-1)
			{
				cabeza = 0;
			}else
			{
				cabeza++;
			}
		}
	}
}

main()
{
	string opc;
	int cabeza = -1;
	int cola = -1;
	string cadena;
	string cola_1[TAM];
	
	system("color F0");
	setlocale(LC_ALL, "");
	
	do
	{
		system("cls");
		color(4, 15);cout<<"                     COLAS (Implementación con arreglos)                     "<<endl<<endl;
		color(15, 4);cout<<"           ------------ COLA (Simulación del arreglo) ------------"<<endl<<endl;
		for(int i =0; i < TAM; i++)
		{
			color(15, 4);cout<<"\t\t\t\t"<<i;color(15, 0);cout<<" | ";color(15, 2);cout<<cola_1[i]<<endl;
		}
		color(15, 4);cout<<endl<<"               CABEZA: ";color(15, 0);cout<<cabeza;
		color(15, 4);cout<<endl<<"               COLA: ";color(15, 0);cout<<cola<<endl;
		color(15, 4);cout<<endl<<"           -------------------------------------------------------"<<endl<<endl;
		color(15, 4);cout<<"\t   ====== MENÚ ==========================================="<<endl<<endl;
		color(15, 4);cout<<"\t\t   a) ";color(15, 0);cout<<"Insertar elemento."<<endl;
		color(15, 4);cout<<"\t\t   b) ";color(15, 0);cout<<"Eliminar elemento"<<endl;
		color(15, 4);cout<<"\t\t   c) <- Salir."<<endl<<endl;
		color(15, 4);cout<<"\t   ======================================================="<<endl<<endl;
		color(15, 4);cout<<"\t"<<FF;color(15, 0);cout<<" Ingresa una opción: ";
		color(15, 4);cin>>opc;
		
		if(opc=="a" || opc=="A")
		{
			color(15, 4);cout<<"\t"<<FF;color(15, 0);cout<<" Ingresa palabra: ";
			color(15, 4);cin>>cadena;
			insertar(cola_1, cabeza, cola, cadena);
		}else
		if(opc=="b" || opc=="B")
		{
			eliminar(cola_1, cabeza, cola);
		}else
		if(opc=="c" || opc=="C")
		{
			color(15, 6);cout<<"\n\t "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
			getch();
		}else
		{
			cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
			getch();
		}
	}while(opc!="c");
	
	
	
	
}
