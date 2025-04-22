/*=========================================================
 N�MEROS AL CUADRADO
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 10 n�meros enteros para 
 elevarlos al cuadrado y mostrar los resultados.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	const int cnum = 10;
	int num[cnum], res[cnum];
	int i;
	
	setlocale(LC_ALL, "");
	
	printf("====== N�MEROS AL CUADRADO ======\n");
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el n�mero entero #%i: ", i+1);
		scanf("%i", &num[i]);
		
		res[i]=pow(num[i], 2);
	}
	printf("=================================\n");
	printf(" RESULTADOS: \n");
	
	for(i=0;i<cnum;i++)
	{
		printf(" %i.  %i^2 = %i\n", i+1, num[i], res[i]);
	}
	printf("=================================\n");
	
	
	return 0;
}
