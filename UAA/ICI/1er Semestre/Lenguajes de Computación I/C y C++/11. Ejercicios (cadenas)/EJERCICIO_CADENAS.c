/*=========================================================
 NÚMERO MAYOR Y MENOR (Con funciones).
-----------------------------------------------------------
 OBJETIVO:
 Pedir al usuario ingresar dos cadenas de caracteres, y 
 según la opción hacer:
   -OPCIÓN #1:
      Mostrar el tamaño de las cadenas.
   -OPCIÓN #2:
      Mostrar la longitud de las cadenas.
   -OPCIÓN #3:
      Pedir una cadena para copiarlas en las dos ingresadas
      inicialmente. Mostrar el resultado.
   -OPCIÓN #4:
      Mostrar el concatenado de las cadenas.
   -OPCIÓN #5:
      Mostrar las cadenas en minúsculas.
   -OPCIÓN #6:
      Mostrar las cadenas en mayúsculas.
   -OPCIÓN #7:
      Mostrar qué cadena es mayor.
   -OPCIÓN #8:
      Ordenar alfabéticamente las dos cadenas.
   -OPCIÓN #9:
      Reintroducir cadenas (volver a pedirlas).
   -OPCIÓN #10:
	  Terminar la ejecución.
 Al ingresar una opción fuera de las mostradas mostrar 
 opción inválida.
-----------------------------------------------------------
 AUTORES:
 -Luis Manuel Flores Jiménez
 -Aldo Raúl Fernández Aguilar
 -Juan Francisco Gallo Ramírez
 13/11/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 30

int main()
{
	int opc, i, lim;
	char cadena_1[MAX], cadena_2[MAX];
	char caux[]=" ", caux_1[]=" ", caux_2[]=" ";
	setlocale(LC_ALL, "");
	
	do
	{
		system("cls");
		printf("======== MENÚ DE CADENAS DE CARACTERES ========\n\n");
		printf("» Introduce texto para la cadena #1:\n");
		fflush(stdin);
		gets(cadena_1);
		printf("\n» Introduce texto para la cadena #2:\n");
		fflush(stdin);
		gets(cadena_2);
		do
		{
			system("cls");
			printf("======== MENÚ DE CADENAS DE CARACTERES ========\n\n");
			printf(" 1. Tamaño de las cadenas    (sizeof)\n");
			printf(" 2. Longitud de las cadenas  (strlen)\n");
			printf(" 3. Copiar cadenas           (strcpy)\n");
			printf(" 4. Concatenar cadenas       (strcat)\n");
			printf(" 5. Convertir a minúsculas   (strlwr)\n");
			printf(" 6. Convertir a mayúsculas   (strupr)\n");
			printf(" 7. Comparar cadenas         (strcmp)\n");
			printf(" 8. Ordenar alfabéticamente  (strncmp)\n");
			printf(" 9. « Reintroducir cadenas\n");
			printf(" 10. «« Salir\n");
			printf("\n-- CADENAS INGRESADAS -------------------------\n\n");
			printf("  CADENA #1: %s\n", cadena_1);
			printf("  CADENA #2: %s", cadena_2);
			printf("\n\n===============================================\n");
			printf("» Introduce la opción:\n");
			scanf("%i", &opc);
			system("cls");
			printf("======== MENÚ DE CADENAS DE CARACTERES ========\n\n");
			switch(opc)
			{
				case 1:
					printf("--- SIZEOF ---\n\n");
					printf(" CADENA #1: %i bytes.\n", sizeof(cadena_1));
					printf(" CADENA #2: %i bytes.\n", sizeof(cadena_2));
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 2:
					printf("--- STRLEN ---\n\n");
					printf(" CADENA #1: %i caracteres.\n", strlen(cadena_1));
					printf(" CADENA #2: %i caracteres.\n", strlen(cadena_2));
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 3:
					printf("» Introduce texto que se copiará:\n");
					fflush(stdin);
					gets(caux);
					strcpy(caux_1, caux);
					strcpy(caux_2, caux);
					printf("\n--- STRCPY ---\n\n");
					printf(" CADENA #1: %s\n", caux_1);
					printf(" CADENA #2: %s\n", caux_2);
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 4:
					strcpy(caux, cadena_1);
					strcat(caux, cadena_2);
					printf("\n--- STRCAT ---\n\n");
					printf(" CADENA CONCATENADA  : %s\n", caux);
					sprintf( caux, "%s %s", cadena_1, cadena_2);
					printf(" CADENA (con espacio): %s\n", caux);
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 5:
					strcpy(caux_1, cadena_1);
					strcpy(caux_2, cadena_2);
					printf("--- STRLWR ---\n\n");
					printf(" CADENA #1: %s\n", strlwr(caux_1));
					printf(" CADENA #2: %s\n", strlwr(caux_2));
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 6:
					strcpy(caux_1, cadena_1);
					strcpy(caux_2, cadena_2);
					printf("--- STRUPR ---\n\n");
					printf(" CADENA #1: %s\n", strupr(caux_1));
					printf(" CADENA #2: %s\n", strupr(caux_2));
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 7:
					printf("--- STRCMP ---\n\n");
					if(strcmp(cadena_1, cadena_2)>0)
					{
						printf(" CADENA #1 MAYOR.\n");
						printf(" %s > %s\n", cadena_1, cadena_2);
					}
					else if(strcmp(cadena_1, cadena_2)<0)
					{
						printf(" CADENA #2 MAYOR.\n");
						printf(" %s < %s\n", cadena_1, cadena_2);	
					}
					else
					{
						printf(" CADENA #1 y #2 IGUALES.\n");
						printf(" %s = %s\n", cadena_1, cadena_2);
					}
					printf("\n\n===============================================\n");
					system("pause");
					break;
				case 8:
					printf("--- STRNCMP ---\n\n");
					if(strlen(cadena_1)>strlen(cadena_2))
					{
						lim = strlen(cadena_1);
					}
					else if(strlen(cadena_1)<strlen(cadena_2))
					{
						lim = strlen(cadena_2);	
					}
					else
					{
						lim = strlen(cadena_2);	
					}
					for(i=1; i<=lim; i++)
					{
						if(strncmp(cadena_1, cadena_2, i)>0)
						{
							strcpy(caux_1, cadena_2);
							strcpy(caux_2, cadena_1);
							i=lim+1;
						}
						else if(strncmp(cadena_1, cadena_2, i)<0)
						{
							strcpy(caux_1, cadena_1);
							strcpy(caux_2, cadena_2);
							i=lim+1;	
						}
						else
						{
							strcpy(caux_1, cadena_1);
							strcpy(caux_2, cadena_2);
						}	
					}
					printf(" #1. %s\n", caux_1);
					printf(" #2. %s\n", caux_2);
					
					printf("\n\n===============================================\n");
					system("pause");
					break;	
				case 9:
					break;
				case 10:
					printf("------------------------\n");
					printf("------ FINALIZADO ------\n");
					printf("------------------------\n\n");
					system("pause");
					break;
				default:
					printf("\n\n ¤¤¤ OPCIÓN INVÁLIDA ¤¤¤\n\n\n");
					system("pause");
			}
		}while(opc!=8 && opc!=9); 
	}while(opc!=9);
	
}
