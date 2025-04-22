/*=====================================================================
 NÚMERO ARÁBIGO A ROMANO 
=======================================================================
 OBJETIVO: Convertir un número arábigo a romano e indicar cuando sea
 mayor a 10 o menor a 1 error.
=======================================================================
 ENTRADAS: Un número arábigo.
=======================================================================
 SALIDAS: El número romano correspindiente.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
	Un número          n        Entero     x           -         -
	Opción final       c        Entero     x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
 -------------------------------------------
 INICIO.
	Var: 
		Enteras: n, c
	Repetir
		Repetir
			Escribir ("Ingresa un número ")
			Leer (n)
			Si n < 1 || n > 10 entonces
				Escrbir ("Número incorreto")
			Fin_Si
		Hasta que n > 1 || n < 10
		Según_sea n Hacer:
			1: Escribir ("I")
			2: Escribir ("II")
			3: Escribir ("III")
			4: Escribir ("IV")
			5: Escribir ("V")
			6: Escribir ("VI")
			7: Escribir ("VII")
			8: Escribir ("VIII")
			9: Escribir ("IX")
			10: Escribir ("X")
		Fin_Según
	Hasta que c != 1
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ramírez
 28/09/2022 I.C.I.
=====================================================================*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	int n, um, c, d, u;
	
	setlocale(LC_ALL, "");
	
	do
	{
		do
		{
			system("cls");
			printf("======= NÚMEROS ARÁBIGOS A ROMANOS =======\n");
			printf("- Ingresa un número arábigo (de 1 a 10): \n");
			scanf("%i", &n);
			if(n<1 || n>10)
			{
				system("cls");
				printf("--------------------------\n");
				printf("### NÚMERO INCORRECTO ###\n");
				printf("--------------------------\n");
				getch();
			}
		}
		while(n<1 || n>10);
		
		
		printf("---------------------\n");
		printf(" NÚMERO ARÁBIGO: %i\n", n);
		printf(" NÚMERO ROMANO:  ");
	
		switch(n)
		{
			case 1:
				printf("I");
				break;
			case 2:
				printf("II");
				break;
			case 3:
				printf("III");
				break;
			case 4:
				printf("IV");
				break;
			case 5:
				printf("V");
				break;
			case 6:
				printf("VI");
				break;
			case 7:
				printf("VII");
				break;
			case 8:
				printf("VIII");
				break;
			case 9:
				printf("IX");
				break;
			case 10:
				printf("X");
				break;
		}
		printf("\n---------------------\n");
		printf("==========================================\n");
		printf("-Digite 1 para voler a ejecutar.\n");
		printf("-Digite otro número para terminar.\n");
		scanf("%i", &c);
	}
	while(c == 1);
		
	
	
	return 0;
}
