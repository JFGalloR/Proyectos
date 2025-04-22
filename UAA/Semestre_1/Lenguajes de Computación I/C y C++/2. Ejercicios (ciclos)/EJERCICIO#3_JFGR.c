/*=========================================================
 SULEDO DE 10 TRABAJADORES
-----------------------------------------------------------
 OBJETIVO: Obtener el total a pagar a 10 trabajadores con
 los sueldos otorgados por el usuario.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 27/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>

int main ()
{
	int c=1;
	float s=0;
	float as=0;
	
	printf("=== SUELDO DE 10 TRABAJADORES ===\n");
	printf("_____________________________\n");
	for(c; c<=10; c++)
	{
		printf("TRABAJADOR #%i \n", c);
		printf("- Ingresa sueldo: ");
		scanf("%f", &s);
		as = as + s;
		printf("SUELDO ACUMULADO: $%.2f\n", as);
		printf("_____________________________\n");
	}
	printf("==================================\n");
	printf("EL TOTAL A PAGAR ES: $%.2f \n", as);
	printf("==================================\n");
	
	
	return 0;
}
