/*=========================================================
 SUMA, RESTA Y MULTIPLICACIÓN
-----------------------------------------------------------
 OBJETIVO: Obtener la suma, resta y multiplicación de dos
 números otorgados por el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float n1, n2, s, r, m = 0;
	
	printf("===== SUMA, RESTA Y MULTIPLICACION =====\n");
	printf("- Ingresa dos numeros:\n");
	scanf("%f %f", &n1, &n2);

	s=n1+n2;
	r=n1-n2;
	m=n1*n2;
		
	printf("========================================\n");
	printf("%.2f + %.2f = %.2f\n", n1, n2, s);
	printf("%.2f - %.2f = %.2f\n", n1, n2, r);
	printf("%.2f * %.2f = %.2f\n", n1, n2, m);
	printf("========================================\n");
	
	 
	return 0;
}

