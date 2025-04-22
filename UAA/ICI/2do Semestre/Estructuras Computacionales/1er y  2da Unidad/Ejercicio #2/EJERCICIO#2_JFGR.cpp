/*==================================================
  EJERCICIO #1. Arreglos Matriz Simétrica
 ------------------------------------------------
 OBJETIVO:
 Elabore un programa que lea una matriz cuadrada 
 por teclado e imprima si es o no es simétrica.
 ------------------------------------------------
 Juan Francisco Gallo Ramírez
 2/Febrero/2023
 I.C.I. 
==================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 99

int main()
{
	int i,j,n,aux=0,a[MAX][MAX];
	
	setlocale(LC_ALL,"");
	printf("--------------------------------\n");
	printf("     MATRIZ SIMÉTRICA (n*n)     \n");
	printf("--------------------------------\n");
	printf("\n > Ingresa el valor de 'n': ");
	scanf("%i", &n);
	system("cls");
	printf("--------------------------------\n");
	printf("     MATRIZ SIMÉTRICA (n*n)     \n");
	printf("--------------------------------\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\n > Ingresa el valor de (%i,%i):\t",i+1,j+1);
			scanf("%i", &a[i][j]);
		}
	}
	system("cls");
	printf("--------------------------------\n");
	printf(" >> MATRIZ INGRESADA:     \n");
	printf("--------------------------------\n\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=a[j][i])
			{
				aux=1;
			}
			printf("\t%i",a[i][j]);
		}
		printf("\n\n");
	}
	if(aux==1)
	{
		printf(" >> MATRIZ NO SIMÉTRICA\n");
		printf("    No hay coincidencias en:\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=a[j][i])
				{
					printf("\t(%i,%i)\n",i+1,j+1);
				}
			}
		}
	}else
	{
		printf(" >> MATRIZ SIMÉTRICA\n");
	}
}
