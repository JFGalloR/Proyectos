/*=========================================================
 CUADRADO Y CUBO DE UN NÚMERO
-----------------------------------------------------------
 OBJETIVO: Obtener el cuadrado y el cubo de un número 
 otorgado por el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <math.h>

int main() {
	int n, p2, p3 = 0;
	
	printf("====== CUADRADO Y CUBO ======\n");
	printf("- Ingresa un numero entero:\n");
	scanf("%i", &n);
	
	p2=pow(n, 2);
	p3=pow(n, 3);
		
	printf("=============================\n");
	printf("%i^2 = %i\n", n, p2);
	printf("%i^3 = %i\n", n, p3);
	printf("=============================\n");
	
	 
	return 0;
}

