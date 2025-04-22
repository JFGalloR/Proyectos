/*===================================================
  EJERCICIO #2. Memoria Din�mica.
 --------------------------------------------------
  OBJETIVO:
	Dado un arreglo con 10 posiciones, llenarlo 
	con n�meros en forma aleatoria entre <1..10>.
	Realizar un programa con definici�n del arreglo 
	con memoria din�mica, obtener solo los datos 
	que son pares y generar una nueva dimensi�n 
	del arreglo (que sea el mismo identificador).
 --------------------------------------------------
  ELABORADORES:
	- Alejandro Castillo Mota
	- Luis Manuel Flores Jim�nez
	- Juan Francisco Gallo Ram�rez
 --------------------------------------------------
	17 de Febrero de 2023
	I.C.I. U.A.A.
====================================================*/
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

// Se declaran las constantes necesarias.
#define TAM 10
// Definimos constantes para el uso de la funci�n 'color()'.
const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

//__________________ FUNCI�N DE APOYO PARA COLOR _____
/*----------------------------------------------------
	Funci�n que nos ayuda a modificar los colores 
	del texto en la consola.
  --------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//____________________________ FUNCI�N PRINCIPAL _____
main()
{
	// Se llama al comando para uso de acentos y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");srand(time(NULL));system("color F0");
	// Se declaran la variable necesaria.
	int* arreglo = new int[TAM]; // definici�n del arreglo con memoria din�mica
	color(roj,gric);cout<<"                      ARREGLOS DIN�MICOS                      \n\n";color(gric,neg);
    // Llenar el arreglo con n�meros aleatorios entre 1 y 10
    for (int i = 0; i < TAM; i++) 
	{
        arreglo[i] = rand() % 10 + 1;
    }
    color(gric,azu);cout<<"   ARREGLO INICIAL:\n";color(gric,neg);
	for (int i = 0; i < TAM; i++) {
        cout<<"   "<<arreglo[i];
    }
    // Encontrar los n�meros no repetidos y guardarlos en el mismo arreglo
    int nuevo_tam = 0;
    for (int i = 0; i < TAM; i++) 
	{
        if (arreglo[i] % 2 == 0) 
		{
            arreglo[nuevo_tam] = arreglo[i];
            nuevo_tam++;
        }
    }

    // Redimensionar el arreglo
    arreglo = (int*) realloc(arreglo, nuevo_tam * sizeof(int));

    // Imprimir el arreglo
    color(gric,azu);cout<<"\n\n   ARREGLO REDIMENSIONADO (S�lo los pares):\n";color(gric,neg);
    for (int i = 0; i < nuevo_tam; i++) 
	{
        cout <<"   "<<arreglo[i];
    }
    cout << endl;

    // Liberar la memoria
    delete[] arreglo;
    
    color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
    getch();
	// Fin del programa.
}
