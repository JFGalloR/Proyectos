/*==================================================
  EJERCICIO #1. Arreglos 2D
 ------------------------------------------------
 OBJETIVO:
 Crea un arreglo o array bidimensional que 
 contenga 3 columnas y las filas que t� quieras, 
 las dos primeras columnas tendr�n n�meros 
 (generados aleatoriamente o introducidos por 
 teclado) y en la 3 columna ser� el resultado de 
 sumar el n�mero de la primera y segunda columna. 
 Por �ltimo, desplegar o mostrar el array.
 ------------------------------------------------
 Juan Francisco Gallo Ram�rez
 2/Febrero/2023
 I.C.I. 
==================================================*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int FIL=5, COL=3;

int main()
{
	int i,j,aux,a[FIL][COL];
	
	srand(time(NULL));
	
	for(i=0;i<FIL;i++)
	{
		aux=0;
		for(j=0;j<COL-1;j++)
		{
			a[i][j]= rand()%10;
			aux+=a[i][j];
		}
		a[i][2]=aux;
	}
	for(i=0;i<FIL;i++)
	{
		printf("  %i + %i = %i\n", a[i][0],a[i][1],a[i][2]);
	}
}
