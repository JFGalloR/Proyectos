/*=========================================================
 NÚMEROS MULTIPLICADOS POR DOS
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 8 números enteros para 
 multiplicarlos por 2 y mostrar los resultados.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main()
{
	const int cnum = 10;
	int num[cnum], res[cnum];
	int i;
	
	setlocale(LC_ALL, "");
	
	printf("========== NÚMEROS POR 2 ==========\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el número entero #%i: ", i+1);
		scanf("%i", &num[i]);
		
		res[i]=num[i]*2;
	}
	printf("===================================\n");
	printf(" RESULTADOS: \n");
	
	for(i=0;i<cnum;i++)
	{
		printf(" %i.  %i * 2 = %i\n", i+1,num[i], res[i]);
	}
	printf("===================================\n");
	
	
	return 0;
}
