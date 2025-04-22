/*=========================================================
 CALCULADORA
-----------------------------------------------------------
 OBJETIVO:
 Crear un programa que simule una calculadora, en la que, 
 introduciendo dos n�meros, muestre un men� de la siguiente 
 manera:
	1.- Suma
	2.- Resta
	3.- Multiplicaci�n
	4.- Divisi�n
	5.- Potencia
	6.- Factorial
	7.- Salir.
 Seg�n la opci�n elegida realizar la operaci�n indicada
 (utilizando los 4 tipos de funciones).

-----------------------------------------------------------
 AUTOR: 
 -Juan Francisco Gallo Ram�rez
 -Luis Manuel Flores Jim�nez
 27/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

//FUNCIONES Con paso de par�metro y sin valor:
void suma(float n1, float n2);
void resta(float n1, float n2);
//FUNCIONES Con paso de par�metro y con valor:
float mult(float n1, float n2);
float div(float n1, float n2);
//FUNCI�N Sin paso de par�metro y sin valor:
void pot();
//FUNCI�N Sin paso de par�metro y con valor:
float fac();

int main ()
{
	int opc;
	float n1;
	float n2;
	float res;
	
	setlocale(LC_ALL, "");
	
	do
	{
		system("cls");
		printf("======== CALCULADORA ========\n");
		printf("- Elija opci�n:\n\n");
		printf("  1. Suma\n");
		printf("  2. Resta\n");
		printf("  3. Multiplicaci�n\n");
		printf("  4. Divisi�n\n");
		printf("  5. Potencia\n");
		printf("  6. Factorial\n");
		printf("  7. <-SALIR\n\n");
		printf("=============================\n");
		scanf("%i", &opc);
		system("cls");
		
		switch(opc)
		{
			case 1:
			case 2:
			case 3:
			case 4:
				printf("=============================\n");
				printf("- Ingresa el n�mero 1: ");
				scanf("%f", &n1);
				printf("- Ingresa el n�mero 2: ");
				scanf("%f", &n2);
				printf("=============================\n");
				switch(opc)
				{
					case 1:
						suma(n1, n2);
						break;
					case 2:
						resta(n1, n2);
						break;
					case 3:
						printf("--- MULTIPLICACI�N ----------\n");
						res = mult(n1, n2);
						printf(" %.2f * %.2f = %.2f\n", n1, n2, res);
						break;
					case 4:
						printf("--- DIVISI�N ----------------\n");
						res = div(n1, n2);
						printf(" %.2f / %.2f = %.2f\n", n1, n2, res);
						break;
				}
				printf("=============================\n");
				break;
			case 5:
				pot();
				break;
			case 6:
				res = fac();
				printf(" = %.f\n", res);
				printf("=============================\n");
				break;
			case 7:
				printf("\n    ------------------\n");
				printf("\n---------- SALIR ----------\n");
				printf("\n    ------------------\n\n\n\n");
				break;
			default:
				printf("\n### OPCI�N NO V�LIDA ###\n\n");
		}
		system("pause");
	}
	while (opc!=7);
	
}

void suma(float n1, float n2)
{
	float suma;
	suma = n1 + n2;
	printf("--- SUMA --------------------\n");
	printf(" %.2f + %.2f = %.2f\n", n1, n2, suma);
}

void resta(float n1, float n2)
{
	float resta;
	resta = n1 - n2;
	printf("--- RESTA -------------------\n");
	printf(" %.2f - %.2f = %.2f\n", n1, n2, resta);
}

float mult(float n1, float n2)
{
	float mult;
	mult = n1 * n2;
	return(mult);
}

float div(float n1, float n2)
{
	float div;
	div = n1 / n2;
	return(div);
}

void pot()
{
	float pot;
	float n1;
	float n2;
	
	printf("=============================\n");
	printf("- Ingresa el n�mero base: ");
	scanf("%f", &n1);
	printf("- Ingresa la potencia: ");
	scanf("%f", &n2);
	printf("=============================\n");
	printf("--- POTENCIA ----------------\n");
	pot = pow(n1,n2);
	printf(" %.2f ^ %.2f = %.2f\n", n1, n2, pot);
	printf("=============================\n");
}

float fac()
{
	float n;
	int i, a=1;
	
	printf("=============================\n");
	printf("- Ingresa un n�mero: ");
	scanf("%f", &n);
	for(i=n; i>0; i--)
	{
		a*=i;
	}
	printf("=============================\n");
	printf("--- FACTORIAL ---------------\n");
	printf(" %.f!", n);
	
	return(a);
}


