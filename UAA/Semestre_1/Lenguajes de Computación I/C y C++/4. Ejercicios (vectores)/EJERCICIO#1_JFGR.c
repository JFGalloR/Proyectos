/*=========================================================
 NÚMERO MAYOR, MENOR Y PARES
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 10 números y con base a ello 
 mostrar el número mayor, menor y la cantidad de números 
 pares.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	const int cnum = 10;
	int num[cnum];
	int i, nma, nme, anp=0;
	
	setlocale(LC_ALL, "");
	
	printf("===== NÚMERO MAYOR, MENOR Y PARES =====\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el número entero #%i: ", i+1);
		scanf("%i", &num[i]);
		
		if(i==0)
		{
			nma = num[i];
		}else
		{
			if(nma<num[i])
			{
				nma = num[i];
			}
		}
		if(i==0)
		{
			nme = num[i];
		}else
		{
			if(nme>num[i])
			{
				nme = num[i];
			}
		}
		if(num[i]%2==0)
		{
			anp ++;
		}
	}
	printf("=======================================\n");
	printf("  LOS NÚMEROS SON:\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("  %i", num[i]);
	}
	printf("\n=======================================\n");
	printf("  EL NÚMERO MAYOR ES: %i\n", nma);
	printf("  SU POSICIÓN ES: ");
	for(i=0;i<cnum;i++)
	{
		if(nma==num[i])
		{
			printf("%i ", i+1);
		}
	}
	
	printf("\n---------------------------------------\n");
	printf("  EL NÚMERO MENOR ES: %i\n", nme);
	printf("  SU POSICIÓN ES: ");
	for(i=0;i<cnum;i++)
	{
		if(nme==num[i])
		{
			printf("%i ", i+1);
		}
	}
	
	printf("\n---------------------------------------\n");
	printf("  CANTIDAD DE NÚMEROS PARES: %i", anp);
	if(anp>0)
	{
		printf("\n  NÚMEROS PARES: ");
		for(i=0;i<cnum;i++)
		{
			if(num[i]%2==0)
			{
				printf("%i ", num[i]);
			}
		}
		printf("\n  SU POSICIÓN ES: ");
		for(i=0;i<cnum;i++)
		{
			if(num[i]%2==0)
			{
				printf("%i ", i+1);
			}
		}
	}
	
	printf("\n=======================================\n");
	
	
	return 0;
}
