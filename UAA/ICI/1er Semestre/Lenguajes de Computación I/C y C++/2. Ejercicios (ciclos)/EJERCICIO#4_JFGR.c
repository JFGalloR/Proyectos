/*=========================================================
 SISTEMA DE CAJA
-----------------------------------------------------------
 OBJETIVO: Agradecer por la compra si el pago es exacto, 
 indicar el cambio si el pago supera la cantidad de la 
 compra, o indicar si falta más dinero si el pago no 
 alcanza la cantidad a pagar por la compra.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 27/09/2022 I.C.I.
=========================================================*/

#include<stdio.h>

int main() 
{
	float c=0;
	float p=0;
	
	printf("======= SISTEMA DE COMPRA ========\n");
	printf("-Ingresa total de la compra:\n");
	scanf("%f",&c);
	printf("-Ingresa cantidad pagada:\n");
	scanf("%f",&p);
	if (c>p) 
	{
		c = c-p;
		printf("---------------------------\n");
		printf("FALTA PAGAR $%,2f\n",c);
		printf("---------------------------\n");
	} 
	else 
	{
		if (c<p) 
		{
			p = p-c;
			printf("----------------------------\n");
			printf("TU CAMBIO ES DE $%.2f\n",p);
			printf("----------------------------\n");
		} 
		else 
		{
			printf("-----------------------------\n");
			printf("*** GRACIAS POR TU COMPRA ***\n");
			printf("-----------------------------\n");
		}
	}
	printf("=================================\n");
	
	
	return 0;
}
