/*=========================================================
 RESULTADO DE UNA EXPRESIÓN
-----------------------------------------------------------
 OBJETIVO: Obtener el resultado de dividir entre 3 el
 cuadrado de la suma de dos números otorgados por el 
 usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float a, b, c = 0;
	
	printf("======== CALCULO DE EXPRESION ========\n");
	printf("- Ingresa dos numeros enteros:\n");
	scanf("%f %f", &a, &b);
	
	c=((a+b)*(a+b)/3);
	
	printf("======================================\n");
	printf("El resultado de (%.f+%.f)^2/3 = %.4f\n", a, b, c);
	printf("======================================\n");
	
	 
	return 0;
}

