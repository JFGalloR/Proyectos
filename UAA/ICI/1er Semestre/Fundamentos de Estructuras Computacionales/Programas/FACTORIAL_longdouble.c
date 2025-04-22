/*=========================================================
 ALGORITMO PARA C�LCULO DE FACTORIAL (con long double)
===========================================================
 OBJETIVO: Obtener el factorial de un n�mero utilizando 
 long double.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 28/09/2022 I.C.I.
===========================================================
 RESPUESTAS DE ACTIVIDAD:
--------------------------
 1. �Hasta que n�mero el algoritmo mostr� correcto el 
    factorial usando long double?

    NO ES POSIBLE USAR "long double" EN DEV C++

=========================================================*/


#include <stdio.h>

int main ()
{
	long double i=0, n=0, a=1;
	
	printf("======= CALCULADORA DE FACTORIAL =======\n");
	printf("- INGRESA UN NUMERO: \n");
	scanf("%Lf", &n);
	printf("%.Lf! = ", n);
	
	for(i=n; i>0; i--)
	{
		a*=i;
		
		if (i==n)
		{
			printf("%.Lf", n);	
		}
		else
		{
			printf(" * %.Lf", i);
		}
	}
	
	printf(" = %.Lf \n", a);
	printf("========================================\n");
	
	return 0;
}
