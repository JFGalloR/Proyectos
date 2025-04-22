/*=========================================================
 NÚMERO MAYOR Y MENOR
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 5 números y con base a ello 
 mostrar el número mayor y menor además de su posición 
 (utilizando vectores).
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 06/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	const int cnum = 5;
	int num[cnum];
	int i, nma, nme;
	
	setlocale(LC_ALL, "");
	
	printf("======== NÚMERO MAYOR Y MENOR ========\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el número #%i: ", i+1);
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
	}
	printf("======================================\n");
	printf("- LOS NÚMEROS SON:\n");
	
	for(i=0;i<cnum;i++)
	{
		printf(" %i\t", num[i]);
	}
	printf("\n======================================\n");
	printf("  EL NÚMERO MAYOR ES: %i\n", nma);
	printf("  SU POSICIÓN ES: ");
	for(i=0;i<cnum;i++)
	{
		if(nma==num[i])
		{
			printf("%i  ", i+1);
		}
	}
	
	printf("\n--------------------------------------\n");
	printf("  EL NÚMERO MENOR ES: %i\n", nme);
	printf("  SU POSICIÓN ES: ");
	for(i=0;i<cnum;i++)
	{
		if(nme==num[i])
		{
			printf("%i  ", i+1);
		}
	}
	printf("\n======================================\n");
	
	
	return 0;
}
