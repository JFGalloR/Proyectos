/*===================================================
  EJERCICIO. Apuntadores - Arreglos.
 --------------------------------------------------
  OBJETIVO:
	Implementar en una función o procedimiento, la 
	lectura del  nombre y los dos apellidos de una 
	persona (en tres cadenas de caracteres 
	diferentes) y presentarlo  en una única cadena.
 --------------------------------------------------
  ELABORADORES:
	- Alejandro Castillo Mota
	- Luis Manuel Flores Jiménez
	- Juan Francisco Gallo Ramírez
 --------------------------------------------------
	17 de Febrero de 2023
	I.C.I. U.A.A.
====================================================*/
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
using namespace std;

// Se declaran las constantes necesarias.
#define MAX 11
// Definimos constantes para el uso de la función 'color()'.
const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

//__________________ FUNCIÓN DE APOYO PARA COLOR _____
/*----------------------------------------------------
	Función que nos ayuda a modificar los colores 
	del texto en la consola.
  --------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//________ FUNCIÓN DE APOYO PARA VALIDAR LETRAS ______
/*----------------------------------------------------
	Función que nos ayuda a validar cadenas mediante
	una comparación del rango de caracteres. Retorna 
	error si la cadena es numérica.
  --------------------------------------------------*/
bool validacionCar(char *aux)
{
	for(;*aux;++aux)
	if( '0' < *aux && '9' > *aux )
	{
		return 1;
	}
	return 0;
}

//____________________________ FUNCIÓN PRINCIPAL _____
main()
{
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");system("color F0");
	// Se declaran la variable necesaria.
	char nombre[MAX];
	char apellido1[MAX];
	char apellido2[MAX];
	char nombreC[MAX*3];
	char *p_cad = nombreC;
	char aux[MAX+5];
	int cant;
	bool error=false;
	do
	{
		error=false;
		system("cls");
		color(roj,gric);cout<<"                       NOMBRE COMPLETO                        \n\n";color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa nombre: ";
		fflush(stdin);color(gric,azu);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionCar(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NO NUMÉRICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)>25)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA CADENA MENOR A 11 CARACTERES # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
			strcpy(nombre,aux);
		}
	}while(error==true);
	do
	{
		error=false;
		system("cls");
		color(roj,gric);cout<<"                       NOMBRE COMPLETO                        \n\n";color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa apellido #1: ";
		fflush(stdin);color(gric,azu);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionCar(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NO NUMÉRICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)>25)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA CADENA MENOR A 11 CARACTERES # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
			strcpy(apellido1,aux);
		}
	}while(error==true);
	do
	{
		error=false;
		system("cls");
		color(roj,gric);cout<<"                       NOMBRE COMPLETO                        \n\n";color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa apellido #2: ";
		fflush(stdin);color(gric,azu);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionCar(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NO NUMÉRICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)>25)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA CADENA MENOR A 11 CARACTERES # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
			strcpy(apellido2,aux);
		}
	}while(error==true);
	
	// Concatenar el nombre y los dos apellidos en una única cadena
    p_cad = strcpy(p_cad, nombre);
    p_cad += strlen(nombre);
    *p_cad++ = ' ';
    p_cad = strcpy(p_cad, apellido1);
    p_cad += strlen(apellido1);
    *p_cad++ = ' ';
    p_cad = strcpy(p_cad, apellido2);
    p_cad += strlen(apellido2);
    *p_cad++ = '\0';

    // Imprimir el nombre completo
    system("cls");
	color(roj,gric);cout<<"                       NOMBRE COMPLETO                        \n\n";
	color(gric,azu);cout<<"\tEl nombre completo es: ";color(gric,neg);cout<< nombreC << endl;
	color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
	getch();
	// Fin del programa.
}
