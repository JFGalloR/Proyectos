/*=========================================================
 MENÚ DE MATERIAS
-----------------------------------------------------------
 OBJETIVO: Mostrar un menú de materias el cual según la 
 opción elegida mostrar el nombre de la materia, si da una
 opción incorrecta que marque error, y si elige salir,
 finalizar el programa.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 27/09/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	int opc;
	
	setlocale(LC_ALL, "Spanish");
	
	do
	{
		system("cls");
		printf("===== MENÚ DE MATERIAS =====\n");
		printf("1. Matemáticas \n");
		printf("2. Español \n");
		printf("3. Historia \n");
		printf("4. Salir \n");
		printf("============================\n");
		printf("- Selecciona una opción\n");
		scanf("%i", &opc);
		system("cls");
		
		switch(opc)
		{
			case 1:
				printf("=== MATERIA MATEMÁTICAS ===\n");
				break;
			case 2:
				printf("=== MATERIA ESPAÑOL ===\n");
				break;
			case 3:
				printf("=== MATERIA HISTORIA ===\n");
				break;
			case 4:
				printf("######## SALIR ########\n");
				break;
			default:
				printf("------------------------\n");
				printf("*** OPCIÓN NO VÁLIDA ***\n");
				printf("------------------------\n");
		}
		printf("\nPresione una tecla...");
		getch();
	}
	while(opc!=4);
	
	
	return 0;
}
