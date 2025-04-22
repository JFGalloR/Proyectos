/*=========================================================
 NÚMEROS REPETIDOS
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 10 números enteros, para depués 
 pedir otros 2 números, y determinar si estos 2 últimos se
 encuentran en los 10 primeros, además de mostrar su 
 posición.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	const int cnum1 = 10, cnum2 = 2;
	int num1[cnum1], num2[cnum2], anr[cnum2];
	int i, j;
	
	for(i=0;i<cnum2;i++)
	{
		anr[i]=0;
	}
	
	setlocale(LC_ALL, "");
	
	printf("======== NÚMEROS REPETIDOS ========\n");
	
	for(i=0;i<cnum1;i++)
	{
		printf("- Ingresa el número entero #%i: ", i+1);
		scanf("%i", &num1[i]);
	}
	
	printf("===================================\n");
	
	
	printf("  LOS NÚMEROS SON:\n");
	
	for(i=0;i<cnum1;i++)
	{
		printf("  %i", num1[i]);
	}
	
	printf("\n===================================\n");
	
	printf("Ingresa %i números más: \n", cnum2);
	
	for(i=0;i<cnum2;i++)
	{
		printf("- Ingresa el número #%i: ", i+1);
		scanf("%i", &num2[i]);
		
		for(j=0;j<cnum1;j++)
		{
			if(num2[i]==num1[j])
			{
				anr[i] ++;
			}
		}
	}
	printf("===================================");
	
	for(i=0;i<cnum2;i++)
	{
		if(anr[i]>0)
		{
			if(anr[i]>1)
			{
				printf("\n - EL NÚMERO %i SE REPITE %i VECES.\n", num2[i], anr[i]);
			}
			else
			{
				printf("\n - EL NÚMERO %i SE REPITE %i VEZ.\n", num2[i], anr[i]);
			}
			
			printf("   SU POSICIÓN ES: ");
				
			for(j=0;j<cnum1;j++)
			{
				if(num2[i]==num1[j])
				{
					printf("  %i", j+1);
				}
			}
		}
		else
		{
			printf("\n - EL NÚMERO %i NO SE REPITE.", num2[i]);
		}
	}
	printf("\n===================================\n");
	
	
	
	return 0;
}
