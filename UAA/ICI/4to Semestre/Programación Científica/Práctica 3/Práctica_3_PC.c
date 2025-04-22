/*=========================================================================
	PRÁCTICA #3
	 Números de coma flotante.
  --------------------------------------------------------------------
	OBJETIVO
 	 Mediante el desarrollo de esta práctica, el alumno comprobará 
	 a la representación interna de los números reales y algunas 
	 consecuencias de ésta.
  --------------------------------------------------------------------
	Juan Francisco Gallo Ramírez
	I.C.I 4to Semestre UAA
=========================================================================*/

#include <conio.h>
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <windows.h>

const char C = 2, FF = 187;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
const float GRAV = 9.81;

//---------------------------- FUNCIÓN PARA MANIPULAR EL COLOR DE LOS CARACTRES ---//
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//----------------------------- FUNCIÓN PARA MOSTRAR EL EQUIVALENTE HEXADECIMAL ---//
void muestraHexa()
{
	float num;
	unsigned int hex;
	
	color(GRIC, ROJ);  printf("\t===== Equivalente en decimal ================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa un número (decimal): ");
	color(GRIC, ROJ);  scanf("%f", &num);
	
	hex = *(unsigned int*)&num;
	
	color(ROJC, GRIC); printf("\n\t\t   Número obtenido   \t"); color(GRIC, NEG); printf("%X\n\n\n", hex);
}

//---------------------- FUNCIÓN PARA COMPARAR UNA SUMA Y SU RESULTADO NUMÉRICO ---//
void compararIgual()
{
	color(GRIC, ROJ);  printf("\t===== Comparar igualdad =====================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" La suma ");
	color(GRIC, NEGC); printf("20.08");  color(GRIC, NEG); printf(" + ");
	color(GRIC, NEGC); printf("2.01"); 
	
	if(20.08+2.01 == 22.09)
	{
		color(GRIC, VER);  printf(" es igual a ");
	}else
	{
		color(GRIC, ROJ);  printf(" es diferente de ");
	}
	
	color(GRIC, NEGC); printf("22.09\n\n\n");
}

//---------------------------------------- FUNCIÓN PARA SUMAR CON UN ACUMULADOR ---//
void suma()
{
	float acum = 0;
	float sum = pow(10, -5);
	int i;
	
	color(GRIC, ROJ);  printf("\t===== Suma con acumulador ===================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" El resultado de sumar ");
	color(GRIC, NEGC); printf("1x10^-5");  color(GRIC, NEG); printf(" con un acumulador\n");
	color(GRIC, NEGC); printf("\t\t  1x10^8"); color(GRIC, NEG); printf(" veces es: ");
	
	for(i=0; i<pow(10, 8); i++)
	{
		acum += sum;
	}
	
	color(GRIC, ROJ); printf("%f\n\n\n", acum);
	
	printf("\t=============================================================\n\n");

}

//----------------------------------------------------------- FUNCIÓN PRINCIPAL ---//
int main() {
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  printf("                                       PRÁCTICA #3                                       \n");
	color(ROJC, GRIC); printf("                                 Números de coma flotante                                \n\n");
	
	muestraHexa();
	compararIgual();
	suma();
	
	getch();
	
	return 0;
}
