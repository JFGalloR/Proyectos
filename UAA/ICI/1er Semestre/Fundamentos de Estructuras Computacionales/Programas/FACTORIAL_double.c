/*=========================================================
 ALGORITMO PARA C�LCULO DE FACTORIAL (con double)
===========================================================
 OBJETIVO: Obtener el factorial de un n�mero utilizando 
 double.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 28/09/2022 I.C.I.
===========================================================
 RESPUESTAS DE ACTIVIDAD:
--------------------------
 1. �Hasta que n�mero el algoritmo mostr� correcto el 
    factorial usando double?

    Hasta el n�mero 170 calcula corractamente 170!, ya que
    al calcular 171! muestra un resultado err�neo.

=========================================================*/


#include <stdio.h>

int main ()
{
	double i=0, n=0, a=1;
	
	printf("======= CALCULADORA DE FACTORIAL =======\n");
	printf("- INGRESA UN NUMERO: \n");
	scanf("%lf", &n);
	printf("%.lf! = ", n);
	
	for(i=n; i>0; i--)
	{
		a*=i;
		
		if (i==n)
		{
			printf("%.lf", n);	
		}
		else
		{
			printf(" * %.lf", i);
		}
	}
	
	printf(" = %.lf \n", a);
	printf("========================================\n");
	
	return 0;
}
