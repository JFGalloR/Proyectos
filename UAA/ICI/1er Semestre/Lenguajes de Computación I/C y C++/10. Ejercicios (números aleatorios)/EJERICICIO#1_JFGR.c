/*=========================================================
 EJERCICIOS CON N�MEROS ALEATORIOS (Helader�a).
-----------------------------------------------------------
 OBJETIVO:
 Mostrar mediante el uso de n�meros aleatorios tres 
 variables que muestren la cantidad de sabores en una
 helader�a, y la cantidad de conos vendidios en el d�a
 de sabores pistache y galleta correspondientemente.
-----------------------------------------------------------
 AUTOR:
 -Juan Francisco Gallo Ram�rez
 08/11/2022 I.C.I.
=========================================================*/
#include <stdio.h>
#include <locale.h>
#include <time.h>

int main()
{
	int helados, pistache, galleta, opc;
	
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	do
	{
		helados = 15 + rand() % (31 - 15);
		pistache = 25 + rand() % (50 - 25);
		galleta = 25 + rand() % (41 - 25);
		system("cls");
		printf("======================== HELADER�A ========================\n");
		printf("--------------------------------------------------------\n");
		printf("  TOTAL DE SABOR DE HELADOS EN LA TIENDA ES DE: %i\n", helados);
		printf("--------------------------------------------------------\n");
		printf("  Los m�s vendidos son los de pistache y galleta.\n");
		printf("  Hoy se vendieron:\n");
		printf("  - PISTACHE: %i\n", pistache);
		printf("  - GALLETA: %i\n", galleta);
		printf("===========================================================\n");
		system("pause");
		do
		{
			system("cls");
			printf("� �Volver a ejecutar?\n");
			printf("	1. S�\n");
			printf("	2. No, terminar.\n");
			scanf("%i", &opc);
			if(opc!=1 && opc!=2)
			{
				printf(" ### OPCI�N NO V�LIDA ###\n");
				system("pause");
			}
		}while(opc!=2 && opc!=1);
	}while(opc!=2);
		
}
