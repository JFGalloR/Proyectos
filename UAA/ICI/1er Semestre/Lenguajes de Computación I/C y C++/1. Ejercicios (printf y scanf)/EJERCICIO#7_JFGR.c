/*=========================================================
 CAMBIO POR COMPRA
-----------------------------------------------------------
 OBJETIVO: Calcular el cambio que se le debe otorgar a un 
 cliente por su compra, con el precio y cantidad de 
 artículos.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 20/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main() {
	float pr, pa, co, ca, tco = 0;
	
	printf("=========== CAMBIO POR COMPRA ===========\n");
	printf("- Ingresa el costo por unidad:\n");
	scanf("%f", &co);
	printf("- Ingresa la cantidad de articulos:\n");
	scanf("%f", &ca);
	printf("- Ingresa el pago del cliente:\n");
	scanf("%f", &pa);
	
	tco=ca*co;
	ca=pa-tco;
		
	printf("==========================================\n");
	printf("- TOTAL DE COMPRA: $%.2f\n", tco);
	printf("- EL CAMBIO ES: $%.2f\n", ca); 
	printf("==========================================\n");
	
	 
	return 0;
}

