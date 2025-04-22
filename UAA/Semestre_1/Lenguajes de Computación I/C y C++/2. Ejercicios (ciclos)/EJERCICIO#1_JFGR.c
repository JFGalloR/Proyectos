/*=========================================================
 SUMA DE LOS NÚMEROS PARES DEL 1 AL 100
-----------------------------------------------------------
 OBJETIVO: Obtener la suma de los números pares del 1 al 
 100.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 27/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main ()
{
	int a=0;
	int b=0;
	int c=0;
	
	printf("=== SUMA DE LOS PARES DEL 1 AL 100 ===\n");
	for(c; c<=100; c+=2)
	{
		a = b + c;
		printf(" %i + %i = %i \n", b, c, a);
		b = a;
	}
	printf("======================================\n");
	printf("LA SUMA DE LOS PARES ES: %i \n", a);
	printf("======================================\n");
	
	
	return 0;
}
