/*=========================================================
 NÚMERO MAYOR Y MENOR (Con funciones).
-----------------------------------------------------------
 OBJETIVO:
 Mostrar un menú donde según la opción y con base a dos 
 matrices de datos otorgados por el usuario realizar:
 	Opción #1:
 	  Sumar las matrices y mostrarlas en una tercera.
 	Opción #2:
 	  Restar las matrices y mostrarlas en una tercera.
 	Opción #3:
 	  Multiplicar las matrices y mostrarlas en una tercera.
 	Opción #4:
 	  Dividir las matrices y mostrarlas en una tercera.
 	Opción #5:
 	 Salir.
 Al ingresar una opción fuera de las indicadas mostrar
 error.
-----------------------------------------------------------
 AUTORES:
 -Luis Manuel Flores Jiménez
 -Aldo Raúl Fernández Aguilar
 -Juan Francisco Gallo Ramírez
 04/11/2022 I.C.I.
=========================================================*/
#include <stdio.h>
#include <locale.h>

#define MAX_F 30
#define MAX_C 30

void lectura(int num[][MAX_C], int fil, int col);
void escritura_int(int num[][MAX_C], int fil, int col);
void escritura_float(float num[][MAX_C], int fil, int col);
void suma(int num1[][MAX_C], int num2[][MAX_C], int res[][MAX_C], int fil, int col);
void resta(int num1[][MAX_C], int num2[][MAX_C], int res[][MAX_C], int fil, int col);
void multi(int num1[][MAX_C], int num2[][MAX_C], int res[][MAX_C], int fil, int col);
void div(int num1[][MAX_C], int num2[][MAX_C], float res[][MAX_C], int fil, int col);

int main()
{
	int opc, fil, col;
	int num1[MAX_F][MAX_C], num2[MAX_F][MAX_C], res[MAX_F][MAX_C];
	float resf[MAX_F][MAX_C];
	
	setlocale(LC_ALL, "");
	do
	{
		system("cls");
		printf("====== OPERACIONES DE MATRICES ======\n\n");
		printf(" 1. Suma de matrices.\n");
		printf(" 2. Resta de matrices.\n");
		printf(" 3. Multiplicación de matrices.\n");
		printf(" 4. División de matrices.\n");
		printf(" 5. « Salir.\n");
		printf("\n=====================================\n");
		printf(" » Ingresa una opción: ");
		scanf("%i", &opc);
		if(opc<5 && opc>0)
		{
			printf("=====================================\n");
			printf(" » Ingresa la cantidad filas: ");
			scanf("%i", &fil);
			printf(" » Ingresa la cantidad columnas: ");
			scanf("%i", &col);
		}
		system("cls");
		switch (opc)
		{
			case 1:
				printf("====== OPERACIONES DE MATRICES ======\n\n");
				printf("»» Suma de matrices »»»»»»»»»»»»»»»»»\n\n");
				printf("-- MATRIZ #1 ------------------------\n");
				lectura(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n");
				lectura(num2, fil, col);
				system("cls");
				printf("== Suma de matrices =================\n\n");
				printf("»» RESULTADOS »»»»»»»»»»»»»»»»»»»»»»»\n");
				
				suma(num1, num2, res, fil, col);
				
				printf("\n-- MATRIZ #1 ------------------------\n\n");
				escritura_int(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n\n");
				escritura_int(num2, fil, col);
				printf("\n-- RESULTADOS -----------------------\n\n");
				escritura_int(res, fil, col);
				printf("\n-------------------------------------\n\n");
				system("pause");
				break;
			case 2:
				printf("====== OPERACIONES DE MATRICES ======\n\n");
				printf("»» Resta de matrices »»»»»»»»»»»»»»»»\n\n");
				printf("-- MATRIZ #1 ------------------------\n");
				lectura(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n");
				lectura(num2, fil, col);
				system("cls");
				printf("== Resta de matrices ================\n\n");
				printf("»» RESULTADOS »»»»»»»»»»»»»»»»»»»»»»»\n");
				
				resta(num1, num2, res, fil, col);
				
				printf("\n-- MATRIZ #1 ------------------------\n\n");
				escritura_int(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n\n");
				escritura_int(num2, fil, col);
				printf("\n-- RESULTADOS -----------------------\n\n");
				escritura_int(res, fil, col);
				printf("\n-------------------------------------\n\n");
				system("pause");
				break;
			case 3:
				printf("====== OPERACIONES DE MATRICES ======\n\n");
				printf("»» Multiplicación de matrices »»»»»»»\n\n");
				printf("-- MATRIZ #1 ------------------------\n");
				lectura(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n");
				lectura(num2, fil, col);
				system("cls");
				printf("== Multiplicación de matrices =======\n\n");
				printf("»» RESULTADOS »»»»»»»»»»»»»»»»»»»»»»»\n");
				
				multi(num1, num2, res, fil, col);
				
				printf("\n-- MATRIZ #1 ------------------------\n\n");
				escritura_int(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n\n");
				escritura_int(num2, fil, col);
				printf("\n-- RESULTADOS -----------------------\n\n");
				escritura_int(res, fil, col);
				printf("\n-------------------------------------\n\n");
				system("pause");
				break;
			case 4:
				printf("====== OPERACIONES DE MATRICES ======\n\n");
				printf("»» División de matrices »»»»»»»»»»»»»\n\n");
				printf("-- MATRIZ #1 ------------------------\n");
				lectura(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n");
				lectura(num2, fil, col);
				system("cls");
				printf("== División de matrices =============\n\n");
				printf("»» RESULTADOS »»»»»»»»»»»»»»»»»»»»»»»\n");
				
				div(num1, num2, resf, fil, col);
				
				printf("\n-- MATRIZ #1 ------------------------\n\n");
				escritura_int(num1, fil, col);
				printf("\n-- MATRIZ #2 ------------------------\n\n");
				escritura_int(num2, fil, col);
				printf("\n-- RESULTADOS -----------------------\n\n");
				escritura_float(resf, fil, col);
				printf("\n-------------------------------------\n\n");
				system("pause");
				
				break;
			case 5:
				printf("------------------------\n");
				printf("------ FINALIZADO ------\n");
				printf("------------------------\n\n");
				system("pause");
				break;
			default:
				printf("\n\n ¤¤¤ OPCIÓN INVÁLIDA ¤¤¤\n\n\n");
				system("pause");
		}
	}while(opc!=5);
}

void lectura(int num[][MAX_C], int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" » Valor de FILA #%i COLUMNA #%i: ", i+1, j+1);
			scanf("%i", &num[i][j]);
		}
	}
}

void escritura_int(int num[][MAX_C], int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %i\t", num[i][j]);
		}
		printf("\n");
	}
}

void escritura_float(float num[][MAX_C], int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %.2f\t", num[i][j]);
		}
		printf("\n");
	}
}

void suma(int num1[][MAX_C], int num2[][MAX_C], int res[][MAX_C], int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			res[i][j]=num1[i][j]+num2[i][j];
		}
	}
}

void resta(int num1[][MAX_C], int num2[][MAX_C], int res[][MAX_C], int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			res[i][j]=num1[i][j]-num2[i][j];
		}
	}
}

void multi(int num1[][MAX_C], int num2[][MAX_C], int res[][MAX_C], int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			res[i][j]=num1[i][j]*num2[i][j];
		}
	}
}

void div(int num1[][MAX_C], int num2[][MAX_C], float resf[][MAX_C], int fil, int col)
{
	int i, j;
	float numf1[MAX_F][MAX_C], numf2[MAX_F][MAX_C];
	
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			numf1[i][j]=num1[i][j];
			numf2[i][j]=num2[i][j];
			resf[i][j]=numf1[i][j]/numf2[i][j];
		}
	}
}
