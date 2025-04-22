/*=========================================================
 ORDEN INVERSO DE CUATRO NÚMEROS ENTEROS
-----------------------------------------------------------
 OBJETIVO: Ordenar de manera inversa cuatro números enteros 
 otorgados por el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	int a, b, c, d = 0;
	
	printf("=== ORDEN INVERSO DE CUATRO NUMEROS ===\n");
	printf("- Ingresa cuatro numeros enteros:\n");
	scanf("%i %i %i %i", &a, &b, &c, &d);
	
	printf("========================================\n");
	printf("SE INGRESARON:\n %i %i %i %i\n", a, b, c, d);
	printf("========================================\n");
	printf("EL ORDEN INVERSO ES:\n %i %i %i %i\n", d, c, b, a);
	printf("========================================\n");
	
	 
	return 0;
}

