/*=========================================================
 ALGORITMO PARA CÁLCULO DE FACTORIAL (con double)
===========================================================
 OBJETIVO: Obtener el factorial de un número utilizando 
 double.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 28/09/2022 I.C.I.
===========================================================
 RESPUESTAS DE ACTIVIDAD:
--------------------------
 1. ¿Hasta que número el algoritmo mostró correcto el 
    factorial usando double?

    Hasta el número 170 calcula corractamente 170!, ya que
    al calcular 171! muestra un resultado erróneo.

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
