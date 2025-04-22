/*=========================================================
 DIVISIÓN DE NÚMEROS
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 8 números enteros, para después
 pedir otros 8 números y dividirlos, finalmente mostar 
 al resultado.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main()
{
	const int cnum = 8;
	int num1[cnum], num2[cnum];
	float num1f[cnum], num2f[cnum], res[cnum];
	int i;
	
	setlocale(LC_ALL, "");
	
	printf("==== DIVISIÓN DE DOS NÚMEROS ====\n");
	printf("PRIMEROS %i NÚMEROS\n", cnum);
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el número entero #%i: ", i+1);
		scanf("%i", &num1[i]);
	}
	
	printf("---------------------------------\n");
	printf("SEGUNDOS %i NÚMEROS\n", cnum);
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el número entero #%i: ", i+1);
		scanf("%i", &num2[i]);
	}
	
	printf("=================================\n");
	printf(" RESULTADOS: \n");
	
	for(i=0;i<cnum;i++)
	{
		num1f[i]=num1[i];
		num2f[i]=num2[i];
		res[i]=num1f[i]/num2f[i];
		printf(" %i.  %i / %i = %.2f\n", i+1, num1[i], num2[i], res[i]);
	}
	printf("=================================\n");
	
	
	return 0;
}
