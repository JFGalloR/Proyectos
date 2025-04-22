/*=========================================================
 CUADRADO DE UN NÚMERO
-----------------------------------------------------------
 OBJETIVO: Calcular el cuadrado de un número otorgado por 
 el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float n, c = 0;
	
	printf("=== CUADRADO DE UN NÚMERO ===\n");
	printf("- Ingresa un numero:\n");
	scanf("%f", &n);
	
	c=n*n;
		
	printf("=============================\n");
	printf("%.2f^2 = %.2f\n", n, c);
	printf("=============================\n");
	
	 
	return 0;
}

