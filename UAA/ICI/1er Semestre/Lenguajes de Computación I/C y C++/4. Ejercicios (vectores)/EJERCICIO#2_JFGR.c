/*=========================================================
 N�MEROS REPETIDOS
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 10 n�meros enteros, para depu�s 
 pedir otros 2 n�meros, y determinar si estos 2 �ltimos se
 encuentran en los 10 primeros, adem�s de mostrar su 
 posici�n.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
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
	
	printf("======== N�MEROS REPETIDOS ========\n");
	
	for(i=0;i<cnum1;i++)
	{
		printf("- Ingresa el n�mero entero #%i: ", i+1);
		scanf("%i", &num1[i]);
	}
	
	printf("===================================\n");
	
	
	printf("  LOS N�MEROS SON:\n");
	
	for(i=0;i<cnum1;i++)
	{
		printf("  %i", num1[i]);
	}
	
	printf("\n===================================\n");
	
	printf("Ingresa %i n�meros m�s: \n", cnum2);
	
	for(i=0;i<cnum2;i++)
	{
		printf("- Ingresa el n�mero #%i: ", i+1);
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
				printf("\n - EL N�MERO %i SE REPITE %i VECES.\n", num2[i], anr[i]);
			}
			else
			{
				printf("\n - EL N�MERO %i SE REPITE %i VEZ.\n", num2[i], anr[i]);
			}
			
			printf("   SU POSICI�N ES: ");
				
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
			printf("\n - EL N�MERO %i NO SE REPITE.", num2[i]);
		}
	}
	printf("\n===================================\n");
	
	
	
	return 0;
}
