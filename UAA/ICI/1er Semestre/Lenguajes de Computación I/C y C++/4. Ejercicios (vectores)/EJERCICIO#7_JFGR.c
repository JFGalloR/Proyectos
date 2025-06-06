/*=========================================================
 SUMA DE N�MEROS
-----------------------------------------------------------
 OBJETIVO: Pedir al usuario 8 n�meros enteros, para despu�s
 pedir otros 8 n�meros y sumarlos, finalmente mostar al 
 resultado.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main()
{
	const int cnum = 8;
	int num1[cnum], num2[cnum], res[cnum];
	int i;
	
	setlocale(LC_ALL, "");
	
	printf("====== SUMA DE DOS N�MEROS ======\n");
	printf("PRIMEROS %i N�MEROS\n", cnum);
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el n�mero entero #%i: ", i+1);
		scanf("%i", &num1[i]);
	}
	
	printf("---------------------------------\n");
	printf("SEGUNDOS %i N�MEROS\n", cnum);
	
	for(i=0;i<cnum;i++)
	{
		printf("- Ingresa el n�mero entero #%i: ", i+1);
		scanf("%i", &num2[i]);
	}
	
	printf("=================================\n");
	printf(" RESULTADOS: \n");
	
	for(i=0;i<cnum;i++)
	{
		res[i]=num1[i]+num2[i];
		printf(" %i.  %i + %i = %i\n", i+1, num1[i], num2[i], res[i]);
	}
	printf("=================================\n");
	
	
	return 0;
}
