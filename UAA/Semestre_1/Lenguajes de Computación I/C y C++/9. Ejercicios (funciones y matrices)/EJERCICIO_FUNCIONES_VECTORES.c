/*=========================================================
 N�MERO MAYOR Y MENOR (Con funciones).
-----------------------------------------------------------
 OBJETIVO:
 Pedir al usuario 10 n�meros enteros, para ordenar esa 
 serie un acomodo de mayor a menor, y de menor a mayor 
 (usando funciones).
-----------------------------------------------------------
 AUTORES:
 -Luis Manuel Flores Jim�nez
 -Aldo Ra�l Fern�ndez Aguilar
 -Juan Francisco Gallo Ram�rez
 04/11/2022 I.C.I.
=========================================================*/
#include <stdio.h>
#include <locale.h>

#define MAX 10

void lectura(int num[]);
void escritura(int num[]);
void acomodo(int num[]);

int main()
{
	int i=0, num[MAX];
	
	setlocale(LC_ALL, "");
	
	printf("====== SERIE DE N�MEROS ======\n");
	lectura(num);
	printf("==============================\n");
	printf(" SERIE INGRESADA: \n");
	for(i;i<MAX;i++)
	{
		printf(" %i", num[i]);
	}
	acomodo(num);
	escritura(num);
	printf("\n==============================\n");
}

void lectura(int num[])
{
	int i=0;
	
	for(i;i<MAX;i++)
	{
		printf(" � Ingresa el n�mero #%i: ", i+1);
		scanf("%i", &num[i]);
	}
}

void acomodo(int num[])
{
	int n, i, j;
	
	for(i=0;i<MAX-1;i++)
	{
		for(j=0;j<MAX-1;j++)
		{
			if(num[j]>num[j+1])
			{
				n=num[j];
				num[j]=num[j+1];
				num[j+1]=n;
			}
		}
	}
}

void escritura(int num[])
{
	int i=0;
	printf("\n------------------------------");
	printf("\n N�MEROS DE MENOR A MAYOR: \n");
	for(i;i<MAX;i++)
	{
		printf(" %i", num[i]);
	}
	printf("\n------------------------------");
	printf("\n N�MEROS DE MAYOR A MENOR: \n");
	for(i=MAX-1;i>=0;i--)
	{
		printf(" %i", num[i]);
	}
}
