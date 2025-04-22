/*=========================================================
 CUADRADO DE UN N�MERO
-----------------------------------------------------------
 OBJETIVO: Calcular el cuadrado de un n�mero otorgado por 
 el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float n, c = 0;
	
	printf("=== CUADRADO DE UN N�MERO ===\n");
	printf("- Ingresa un numero:\n");
	scanf("%f", &n);
	
	c=n*n;
		
	printf("=============================\n");
	printf("%.2f^2 = %.2f\n", n, c);
	printf("=============================\n");
	
	 
	return 0;
}

