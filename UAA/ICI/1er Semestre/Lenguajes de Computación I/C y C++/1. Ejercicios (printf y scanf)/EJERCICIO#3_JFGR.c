/*=========================================================
 PROMEDIO DE CALIFICACIONES
-----------------------------------------------------------
 OBJETIVO: Obtener el promedio de cinco alificaciones
 otorgadas por el usuario además de mostrar su matrícula.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float c1, c2, c3, c4 ,c5, prom = 0;
	int mat = 0;
	
	printf("===== PROMEDIO DE CALIFICACIONES =====\n");
	printf("- Ingresa tu matricula:\n");
	scanf("%i", &mat);
	printf("- Ingresa las cinco calificaciones:\n");
	scanf("%f %f %f %f %f", &c1, &c2, &c3, &c4, &c5);
	
	prom = (c1+c2+c3+c4+c5)/5;
	
	printf("========================================\n");
	printf("MATRICULA: %i \n", mat);
	printf("PROMEDIO: %.2f \n", prom);
	printf("========================================\n");
	
	 
	return 0;
}

