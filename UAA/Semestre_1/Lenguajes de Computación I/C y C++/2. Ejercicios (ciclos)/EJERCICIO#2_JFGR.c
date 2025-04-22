/*=========================================================
 SUMA DE LOS NÚMEROS PARES E IMPARES DEL 100 AL 400
-----------------------------------------------------------
 OBJETIVO: Obtener la suma de los números pares e impares
 del 100 al 400.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 27/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main ()
{
	int c=100;
	int p=0;
	int i=0;
	
	printf("=== SUMA DE LOS PARES E IMPARES DEL 100 AL 400 ===\n");
	for(c; c<=400; c++)
	{
		if(c%2==0)
		{
			p = p + c;
		} 
		else 
		{
			i = i + c;
		}
	}
	printf("==================================================\n");
	printf("LA SUMA DE LOS PARES ES: %i \n", p);
	printf("--------------------------------------------------\n");
	printf("LA SUMA DE LOS IMPARES ES: %i \n", i);
	printf("==================================================\n");
	
	
	return 0;
}
