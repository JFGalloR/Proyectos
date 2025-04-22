/*===================================================
  EJERCICIO #1. Arreglos unidimensionales.
 --------------------------------------------------
  OBJETIVO:
	Elaborar un programa donde se defina un arreglo 
	de cualquier tipo de dato y buscar un elemento
	dentro de un arreglo que nosotros le pedimos 
	por teclado. Indicar las posiciones donde se 
	encuentra. Si hay más de uno, indicar 
	igualmente la posición. 
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
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

// Definimos nuestros parámetros máximos de cadenas de carateres.
#define MAX 6
#define MAX_1 12

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

//________ FUNCIÓN DE APOYO PARA VALIDAR NÚMEROS _____
/*----------------------------------------------------
	Función que nos ayuda a validar números mediante
	una comparación del rango de caracteres. Retorna 
	error si la cadena no es numérica.
  --------------------------------------------------*/
bool validacionNum(char *num)
{
	for(;*num;++num)
	if( '0' > *num || '9' < *num )
	{
		return 1;
	}
	return 0;
}

//________ FUNCIÓN DE APOYO PARA VALIDAR LETRAS ______
/*----------------------------------------------------
	Función que nos ayuda a validar cadenas mediante
	una comparación del rango de caracteres. Retorna 
	error si la cadena es numérica.
  --------------------------------------------------*/
bool validacionCar(char *car)
{
	for(;*car;++car)
	if( '0' < *car && '9' > *car )
	{
		return 1;
	}
	return 0;
}

//________ FUNCIÓN DE BÚSQUEDA (Vector de Números)____
/*----------------------------------------------------
	Función de busqueda de un número en un vector de
	números.
  --------------------------------------------------*/
void busquedaNum()
{
	// Se establecen las variables necesarias.
	bool error=false;
	char num[MAX];
	int cadenaNum[MAX-1];
	int numB, cont=0;
	
	// Un ciclo 'for' para el ingreso de la cadena numérica.
	for(int i=0;i<MAX-1;i++)
	{
		// Ciclo 'do-while' para validar datos.
		do
		{
			system("cls");error=false; 
			color(azu,gric);cout<<"                BÚSQUEDA EN CADENA DE NÚMEROS                \n\n";
			color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa un número de posición #"<<i+1<<": ";
			fflush(stdin);color(gric,azu);gets(num);
			// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
			if(validacionNum(num)==1)
			{
				// Se valida que sea una cadena númerica.
				color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NUMÉRICOS # # # ";
				error=true;
				getch();
			}else
			if(strlen(num)>MAX-1)
			{
				// Se valida que sea de la longitud adecuada.
				color(gric,roj);cout<<"\n\t# # # INGRESA NÚMERO MENOR A "<<MAX-1<<" DÍGITOS # # # ";
				error=true;
				getch();
			}else
			{
				// Finalmente, si se ingresó adecuadamente, se convierte a numérica.
				cadenaNum[i]=atoi(num);
			}
		}while(error==true);
	}
	// Se repiten los cilos y validaciones para ingresar el digito buscado.
	do
	{
		system("cls");error=false; 
		color(azu,gric);cout<<"                BÚSQUEDA EN CADENA DE NÚMEROS                \n\n";
		color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa el dígio a buscar: ";
		fflush(stdin);color(gric,azu);gets(num);
		if(validacionNum(num)==1)
		{
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NUMÉRICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(num)>MAX-1)
		{
			color(gric,roj);cout<<"\n\t# # # INGRESA NÚMERO MENOR A "<<MAX-1<<" DÍGITOS # # # ";
			error=true;
			getch();
		}else
		{
			numB=atoi(num);
		}
	}while(error==true);
	// Se imprimen los resultados obtenidos.
	system("cls");
	color(azu,gric);cout<<"                BÚSQUEDA EN CADENA DE NÚMEROS                \n\n";
	// Se imprime dígito a buscar.
	color(gric,azu);cout<<" > Número a buscar: \n";
	color(gric,neg);cout<<"\t"<<numB<<endl<<endl;
	// Se imprime la cadena numérica.
	color(gric,azu);cout<<" > Cadena Numérica: \n";
	color(gric,ama);
	for(int i=0;i<MAX-1;i++)
	{
		cout<<"\t|"<<i+1<<"|";
	}
	cout<<endl<<endl;
	color(gric,neg);
	for(int i=0;i<MAX-1;i++)
	{
		cout<<"\t "<<cadenaNum[i];
	}
	// Se imprime la cantidad de coincidencias.
	cout<<endl<<endl;
	color(gric,azu);cout<<" > Número de coincidencias: \n";
	color(gric,neg);
	for(int i=0;i<MAX-1;i++)
	{
		if(numB==cadenaNum[i])
		{
			cont++;
		}
	}
	// Se imprimen las posiciones si hay alguna, de lo contrario, no se imprimirá nada.
	cout<<"\t"<<cont<<endl<<endl;
	if(cont>0)
	{
		color(gric,azu);cout<<" > Posiciones: \n";
		color(gric,neg);
		for(int i=0;i<MAX-1;i++)
		{
			if(numB==cadenaNum[i])
			{
				cout<<"\t"<<i+1;
			}
		}
	}
	cout<<endl<<endl<<" ";
	color(gric,roj);
	system("pause");
}

//_____ FUNCIÓN DE BÚSQUEDA (Cadena de Caracteres)____
/*----------------------------------------------------
	Función de busqueda de un caracter en una cadena
	de del mismo tipo.
  --------------------------------------------------*/
void busquedaCar()
{
	// Se establecen las variables necesarias.
	bool error=false;
	char car[MAX_1];
	char cadenaCar[MAX_1];
	int cont=0;
	
	// Ciclo 'do-while' para validar datos.
	do
	{
		system("cls");error=false;
		color(ver,gric);cout<<"              BÚSQUEDA EN CADENA DE CARACTERES               \n\n";
		color(gric,ver);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa la cadena donde buscar: ";
		fflush(stdin);color(gric,ver);gets(car);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionCar(car)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA CARACTERES ALFABÉTICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(car)>MAX_1-2)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA CADENA MENOR A "<<MAX_1-1<<" CARACTERES# # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingresó adecuadamente, se copia a la cadena donde se buscará.
			strcpy(cadenaCar, car);
		}
	}while(error==true);
	// Se repiten los cilos y validaciones para ingresar el caracter buscado.
	do
	{
		system("cls");error=false; 
		color(ver,gric);cout<<"              BÚSQUEDA EN CADENA DE CARACTERES               \n\n";
		color(gric,ver);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa el caracter a buscar: ";
		fflush(stdin);color(gric,ver);gets(car);
		if(validacionCar(car)==1)
		{
			color(gric,roj);cout<<"\n\t# # # INGRESA CARACTERES ALFABÉTICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(car)>1)
		{
			color(gric,roj);cout<<"\n\t# # # INGRESA SOLO UN CARACTER # # # ";
			error=true;
			getch();
		}
	}while(error==true);
	// Se imprimen los resultados obtenidos.
	system("cls");
	color(ver,gric);cout<<"              BÚSQUEDA EN CADENA DE CARACTERES               \n\n";
	// Se imprime caracter a buscar.
	color(gric,ver);cout<<" > Caracter a buscar: \n";
	color(gric,neg);cout<<"\t"<<car<<endl<<endl;
	// Se imprime la cadena de caracteres.
	color(gric,ver);cout<<" > Cadena de Caracteres: \n";
	color(gric,ama);
	for(int i=0;i<strlen(cadenaCar);i++)
	{
		cout<<"\t|"<<i+1<<"|";
	}
	cout<<endl<<endl;
	color(gric,neg);
	for(int i=0;i<strlen(cadenaCar);i++)
	{
		cout<<"\t "<<cadenaCar[i];
	}
	// Se imprime la cantidad de coincidencias.
	cout<<endl<<endl;
	color(gric,ver);cout<<" > Número de coincidencias: \n";
	for(int i=0;i<strlen(cadenaCar);i++)
	{
		if(car[0]==cadenaCar[i])
		{
			cont++;
		}
	}
	// Se imprimen las posiciones si hay alguna, de lo contrario, no se imprimirá nada.
	color(gric,neg);cout<<"\t"<<cont<<endl<<endl;
	if(cont>0)
	{
		color(gric,ver);cout<<" > Posiciones: \n";
		color(gric,neg);
		for(int i=0;i<strlen(cadenaCar);i++)
		{
			if(car[0]==cadenaCar[i])
			{
				cout<<"\t"<<i+1;
			}
		}
	}
	cout<<endl<<endl<<" ";
	color(gric,roj);
	system("pause");
}
//____________________________ FUNCIÓN PRINCIPAL _____
main()
{
	// Se establecen una variable del tipo 'string' donde se guardará la opción.
	string opc;
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");system("color F0");
	// Menú inicial.
	do
	{
		// Tomando opción para evaluarla en un switch.
		system("cls");
		color(roj,gric);cout<<"             BÚSQUEDA DE UN ELEMENTO EN UN VECTOR            \n\n";
		color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Buscar elemento en vector de números.\n";
		color(gric,roj);cout<<"\t  b.";color(gric,neg);cout<<" Buscar elemento en cadena de caracteres.\n";
		color(gric,roj);cout<<"\t  c. <- Salir.\n\n";
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
		color(gric,roj);cin>>opc;
		// Tomando opción para evaluarla.
		if(opc=="a")
		{	// Llama a la función para buscar un número en un array de números.
			busquedaNum();
		}else
		if(opc=="b")
		{	// Llama a la función para buscar un caracter en una cadena de caractes.
			busquedaCar(); 
		}else
		if(opc=="c")
		{
			color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
		}else
		{
			cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
		}
		getch();
	}while(opc!="c");
	// Fin del programa.
}
