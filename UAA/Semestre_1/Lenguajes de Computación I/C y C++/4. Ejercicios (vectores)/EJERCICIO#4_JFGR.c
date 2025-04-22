/*=========================================================
 N�MEROS DE MAYOR A MENOR
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 10 n�meros enteros para 
 mostrarlos de mayor a menor.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main()
{
	const int cnum = 10;
	int num[cnum];
	int i, j, n;
	
	setlocale(LC_ALL, "");
	
	printf("====== N�MEROS DE MAYOR A MENOR ======\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el n�mero entero #%i: ", i+1);
		scanf("%i", &num[i]);
	}
	printf("======================================\n");
	printf(" LOS N�MEROS SON:\n");
	
	for(i=0;i<cnum;i++)
	{
		printf(" %i ", num[i]);
	}
	
	for(i=0;i<cnum-1;i++)
	{
		for(j=0;j<cnum-1;j++)
		{
			if(num[j]<num[j+1])
			{
				n=num[j];
				num[j]=num[j+1];
				num[j+1]=n;
			}
		}
	}
	
	printf("\n======================================\n");
	printf(" LOS N�MEROS DE MAYOR A MENOR SON:\n");
	
	for(i=0;i<cnum;i++)
	{
		printf(" %i ", num[i]);
	}
	
	printf("\n======================================\n");
	
	
	return 0;
}
