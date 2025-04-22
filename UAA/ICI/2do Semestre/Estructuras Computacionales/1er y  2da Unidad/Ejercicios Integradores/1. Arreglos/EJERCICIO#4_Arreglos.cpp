/*===================================================
  EJERCICIO #4. Arreglos mutidimensionales.
 --------------------------------------------------
  OBJETIVO:
	Sea M una matriz de enteros de 5 filas X 5 columnas.
	Realice un programa que permita:
	 a) Ingresar cada uno de los valores de la matriz.
	 b) Mostrar, para cada fila, la suma de sus valores de esa fila, y el menor
		valor almacenado
	 c) Mostrar, para cada columna, el promedio de sus valores y el mayor
		valor.
	 d) El mayor valor almacenado en toda la Matriz, indicando en que fila
		y columna se encuentra 
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
#include <windows.h>
using namespace std;

// Definimos nuestros parámetros máximos de cadenas de carateres.
#define MAX 5
#define MAX_2 7

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
bool validacionNum(char *cant)
{
	for(;*cant;++cant)
	if( '0' > *cant || '9' < *cant )
	{
		return 1;
	}
	return 0;
}

//___________________ FUNCIÓN DE MOSTRAR MATRIZ ______
/*----------------------------------------------------
	Función encargada de imprimir los valores de la
	matriz generada, además de todos los resultados 
	obtenidos.
  --------------------------------------------------*/
void mostrarMatriz(int matriz[][MAX])
{
	// Se declaran la variables necesarias.
	int sF=0, nm, f=0, c=0;
	int nM[MAX]={0};
	int nMM=matriz[0][0];
	int sC[MAX]={0};
	float pC=0;
	color(gric,gric);cout<<endl<<"   ";
	for(int i=0;i<MAX;i++)
	{
		nM[i]=matriz[0][i];
		color(gric,roj);cout<<"\t"<<i+1;
	}
	cout<<endl<<endl;
	for(int i=0;i<MAX;i++)
	{
		sF=0;
		nm=matriz[i][0];
		color(gric,roj);cout<<"   "<<i+1;
		color(gric,neg);
		for(int j=0;j<MAX;j++)
		{
			sC[j]+=matriz[i][j];
			sF+=matriz[i][j];
			// Sentencia comparatoria para obtener el número de fila menor.
			if(matriz[i][j]<nm)
			{
				nm=matriz[i][j];
			}
			// Sentencia comparatoria para obtener el número de columna mayor.
			if(nM[j]<matriz[i][j])
			{
				nM[j]=matriz[i][j];
			}
			// Sentencia comparatoria para obtener el número mayor de toda la matriz, además de la fila y columna donde se encuentra.
			if(matriz[i][j]>nMM)
			{
				f=i; c=j;
				nMM = matriz[i][j];
			}
			cout<<"\t"<<matriz[i][j];
		}
		// Se imprimen resultados obtenidos.
		color(gric,negc);cout<<"\tSuma Filas = ";color(gric,roj);cout<<sF;color(gric,negc);cout<<" \tN. Men: ";color(gric,roj);cout<<nm;cout<<endl;
	}
	// Se imprimen resultados obtenidos.
	cout<<endl;
	for(int i=0;i<MAX;i++)
	{
		color(gric,negc);cout<<"\tProm.";
	}
	cout<<endl;
	for(int i=0;i<MAX;i++)
	{
		pC=sC[i];
		pC/=MAX;
		color(gric,roj);cout<<"\t"<<pC;
	}
	cout<<endl<<endl;
	for(int i=0;i<MAX;i++)
	{
		color(gric,negc);cout<<"\tN. May:";
	}
	cout<<endl;
	for(int i=0;i<MAX;i++)
	{
		color(gric,roj);cout<<"\t"<<nM[i];
	}
	color(gric,negc);cout<<endl<<endl<<"\t"<<F<<" Mayor Número de la Matriz: ";color(gric,roj);cout<<nMM;
	color(gric,neg);cout<<"\n\t  Se encuentra en ["<<f+1<<","<<c+1<<"]";
}

//___________________________ FUNCIÓN PRINCIPAL ______
main()
{
	char cant[10];
	int matriz[MAX][MAX];
	bool error;
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");system("color F0");
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			do
			{
				system("cls");error=false;
				color(roj,gric);cout<<"                        MATRIZ DE "<<MAX<<"*"<<MAX<<"                         \n\n";
				color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa número de la posición ["<<i+1<<","<<j+1<<"]: ";
				fflush(stdin);color(gric,roj);gets(cant);
				// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
				if(validacionNum(cant)==1)
				{
					// Se valida que sea una cadena númerica.
					color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NUMÉRICOS # # # ";
					error=true;
					getch();
				}else
				if(atoi(cant)>9999 || atoi(cant)<0)
				{
					// Se valida que sea de la longitud adecuada.
					color(gric,roj);cout<<"\n\t# # # INGRESA NÚMERO ENTRE 1 Y 9999 # # # ";
					error=true;
					getch();
				}else
				{
					// Finalmente, si se ingresó adecuadamente, se convierte a numérica.
					matriz[i][j]=atoi(cant);
				}
			}while(error==true);
		}
	}
	// Se muestra la suma de cada fila, adeás de el número menor de la misma.
	system("cls");
	color(roj,gric);cout<<"                        MATRIZ DE "<<MAX<<"*"<<MAX<<"                         \n\n";
	// Se llama a la función para mostrar resultados.
	mostrarMatriz(matriz);
	getch();
	color(gric,ama);cout<<"\n\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
	getch();
	// Fin del programa.	
}
