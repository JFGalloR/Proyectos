/*=========================================================
 PER�METRO Y �REA DE UN RECT�NGULO
-----------------------------------------------------------
 OBJETIVO: Calcular el �rea y per�metro de un rect�ngulo
 con los datos otorgados por el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float b, h, a, p = 0;
	
	printf("=== �REA Y PRE�METRO DE RECTANGULO ===\n");
	printf("- Ingresa la base del rectangulo:\n");
	scanf("%f", &b);
	printf("- Ingresa la altura del retangulo:\n");
	scanf("%f", &h);
	
	a=b*h;
	p=2*(b+h);
		
	printf("======================================\n");
	printf("PERIMETRO: %.2f\n",p);
	printf("AREA: %.2f\n", a);
	printf("======================================\n");
	
	 
	return 0;
}

