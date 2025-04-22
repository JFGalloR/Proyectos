/*=========================================================
 DESCUENTO EN COMPRA
-----------------------------------------------------------
 OBJETIVO: Calcular la cantidad a pagar por compra, donde
 el usuario otorga cantidad de articulos y precio por cada 
 uno y aplicarle un descuento del 10%.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float co, ca, tco, dco = 0;
	
	printf("=========== TOTAL POR COMPRA ===========\n");
	printf("- Ingresa el costo por unidad:\n");
	scanf("%f", &co);
	printf("- Ingresa la cantidad de articulos:\n");
	scanf("%f", &ca);
	
	tco=ca*co;
	dco=tco*.9;
		
	printf("========================================\n");
	printf("- COMPRA: $%.2f\n", tco);
	printf("- TOTAL DE COMPRA: $%.2f\n", dco);
	printf("========================================\n");
	
	 
	return 0;
}
