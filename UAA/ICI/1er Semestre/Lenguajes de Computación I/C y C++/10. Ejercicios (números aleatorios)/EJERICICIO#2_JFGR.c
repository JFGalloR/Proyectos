/*=========================================================
 EJERCICIOS CON NÚMEROS ALEATORIOS (Heladería).
-----------------------------------------------------------
 OBJETIVO:
 Mostrar los boletos ganadores de una rifa donde el usuario
 otorgará la cantidad de boletos vendidos y la cantidad
 de boletos ganadores; generando números aleatorios los 
 cuáles serán los boletos ganadores.
-----------------------------------------------------------
 AUTOR:
 -Juan Francisco Gallo Ramírez
 08/11/2022 I.C.I.
=========================================================*/
#include <stdio.h>
#include <locale.h>
#include <time.h>

#define MAX 9999

int main()
{
	int ganador[MAX];
	int i, j, rep, opc;
	int cant_b, cant_g;
	
	setlocale(LC_ALL, "");
	srand(time(NULL));
	do
	{
		system("cls");
		printf("================ BOLETOS DE RIFA ================\n");
		printf("» Ingresa la cantidad de boletos vendidos: ");
		scanf("%i", &cant_b);
		printf("» Ingresa la cantidad de boletos ganadores: ");
		scanf("%i", &cant_g);
		printf("=================================================\n");
		printf("  CANTIDAD DE BOLETOS VENDIDOS: %i\n", cant_b);
		printf("-------------------------------------------------\n");
		printf("  BOLETOS GANADORES:\n");
		
		for(i=0;i<cant_g;i++)
		{
			ganador[i] = 1 + rand() % cant_b;
			
			do
			{
				rep=0;
				for(j=i;j>0;j--)
				{
					if(ganador[i]==ganador[j-1])
					{
						rep++;
						ganador[i] = 1 + rand() % cant_b;
					}
				}	
			}
			while(rep>0);	
		}
		
		for(i=0;i<cant_g;i++)
		{
			printf("  %i)\t#%i\n", i+1, ganador[i]);
		}
		printf("=================================================\n");
		system("pause");
		do
		{
			system("cls");
			printf("» ¿Volver a ejecutar?\n");
			printf("	1. Sí\n");
			printf("	2. No, terminar.\n");
			scanf("%i", &opc);
			if(opc!=1 && opc!=2)
			{
				printf(" ### OPCIÓN NO VÁLIDA ###\n");
				system("pause");
			}
		}while(opc!=2 && opc!=1);
	}while(opc!=2);
	
}
