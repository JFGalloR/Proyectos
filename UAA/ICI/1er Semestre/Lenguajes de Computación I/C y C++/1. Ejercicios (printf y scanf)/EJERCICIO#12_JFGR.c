/*=========================================================
 DESCUENTO EN COMPRA CON IVA
-----------------------------------------------------------
 OBJETIVO: Calcular la cantidad a pagar por compra, donde
 el usuario otorga cantidad de articulos y precio por cada 
 uno y aplicarle un descuento del 10% tomando en cuenta 16% 
 de IVA.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float co, ca, tco, tcoi, dco = 0;
	
	printf("=========== TOTAL POR COMPRA ===========\n");
	printf("- Ingresa el costo por unidad:\n");
	scanf("%f", &co);
	printf("- Ingresa la cantidad de articulos:\n");
	scanf("%f", &ca);
	
	tco=ca*co;
	tcoi=tco*1.16;
	dco=tcoi*.9;
		
	printf("========================================\n");
	printf("- COMPRA: $%.2f\n", tco);
	printf("- COMPRA + IVA: $%.2f\n", tcoi);
	printf("----------------------------------------\n");
	printf("TOTAL DE COMPRA (-10%%): $%.2f\n", dco);
	printf("========================================\n");
	
	 
	return 0;
}
