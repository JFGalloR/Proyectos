/*=========================================================
 RESTA Y DIVISIÓN
-----------------------------------------------------------
 OBJETIVO: Obtener la resta y división de dos números 
 otorgados por el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float n1, n2, r, d = 0;
	
	printf("===== RESTA Y DIVISIÓN =====\n");
	printf("- Ingresa dos numeros:\n");
	scanf("%f %f", &n1, &n2);

	r=n1-n2;
 	d=n1/n2;
		
	printf("============================\n");
	printf("%.2f - %.2f = %.2f\n", n1, n2, r);
	printf("%.2f / %.2f = %.2f\n", n1, n2, d);
	printf("============================\n");
	
	 
	return 0;
}

