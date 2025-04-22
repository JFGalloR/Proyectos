/*=========================================================
 N�MERO MAYOR, MENOR Y PARES
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 10 n�meros y con base a ello 
 mostrar el n�mero mayor, menor y la cantidad de n�meros 
 pares.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
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
	
	printf("===== N�MERO MAYOR, MENOR Y PARES =====\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el n�mero entero #%i: ", i+1);
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
	printf("  LOS N�MEROS SON:\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("  %i", num[i]);
	}
	printf("\n=======================================\n");
	printf("  EL N�MERO MAYOR ES: %i\n", nma);
	printf("  SU POSICI�N ES: ");
	for(i=0;i<cnum;i++)
	{
		if(nma==num[i])
		{
			printf("%i ", i+1);
		}
	}
	
	printf("\n---------------------------------------\n");
	printf("  EL N�MERO MENOR ES: %i\n", nme);
	printf("  SU POSICI�N ES: ");
	for(i=0;i<cnum;i++)
	{
		if(nme==num[i])
		{
			printf("%i ", i+1);
		}
	}
	
	printf("\n---------------------------------------\n");
	printf("  CANTIDAD DE N�MEROS PARES: %i", anp);
	if(anp>0)
	{
		printf("\n  N�MEROS PARES: ");
		for(i=0;i<cnum;i++)
		{
			if(num[i]%2==0)
			{
				printf("%i ", num[i]);
			}
		}
		printf("\n  SU POSICI�N ES: ");
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
