/*=========================================================
 MEN� DE MATERIAS
-----------------------------------------------------------
 OBJETIVO: Mostrar un men� de materias el cual seg�n la 
 opci�n elegida mostrar el nombre de la materia, si da una
 opci�n incorrecta que marque error, y si elige salir,
 finalizar el programa.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
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
		printf("===== MEN� DE MATERIAS =====\n");
		printf("1. Matem�ticas \n");
		printf("2. Espa�ol \n");
		printf("3. Historia \n");
		printf("4. Salir \n");
		printf("============================\n");
		printf("- Selecciona una opci�n\n");
		scanf("%i", &opc);
		system("cls");
		
		switch(opc)
		{
			case 1:
				printf("=== MATERIA MATEM�TICAS ===\n");
				break;
			case 2:
				printf("=== MATERIA ESPA�OL ===\n");
				break;
			case 3:
				printf("=== MATERIA HISTORIA ===\n");
				break;
			case 4:
				printf("######## SALIR ########\n");
				break;
			default:
				printf("------------------------\n");
				printf("*** OPCI�N NO V�LIDA ***\n");
				printf("------------------------\n");
		}
		printf("\nPresione una tecla...");
		getch();
	}
	while(opc!=4);
	
	
	return 0;
}
