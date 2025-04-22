/*=========================================================================
	PRÁCTICA #4
	 Aproximaciones y errores.
  --------------------------------------------------------------------
	OBJETIVO
 	 Mediante el desarrollo de esta práctica, el alumno verificará el 
	 concepto de error por truncamiento (de la serie) y por redondeo 
	 (precisión de la computadora).
  --------------------------------------------------------------------
	Juan Francisco Gallo Ramírez
	I.C.I 4to Semestre UAA
=========================================================================*/

#include <conio.h>
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <windows.h>

const char FF = 187;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;

//---------------------------- FUNCIÓN PARA MANIPULAR EL COLOR DE LOS CARACTRES ---//
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//----------------------------------------------------------- FUNCIÓN PRINCIPAL ---//
int main() {
	
	int i = 0;
	float x, suma = 0, term = 1;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  printf("                                       PRÁCTICA #4                                       \n");
	color(ROJC, GRIC); printf("                                 Aproximaciones y errores                                \n\n");

	color(GRIC, ROJ);  printf("\t===== Ingreso de parámetros =================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor de \"x\": ");
	color(GRIC, ROJ);  scanf("%f", &x);
	
	color(GRIC, ROJ);  printf("\n\t===== Valores de la serie ===================================\n\n");
	color(ROJ, GRIC);  printf("\t   i   \t    Término    \t     Suma      \n\n");
	
	while(suma != suma+term)
	{
		color(GRIC, ROJ); printf("\t%d", i);
		color(GRIC, NEG); printf("\t%.9f", term);
		suma += term;
		printf("\t%.9f\n", suma);
		i++;
		term *= x / (float)i;
	}
	
	color(GRIC, ROJ);  printf("\n\t--------------------------------------------------------------\n");
	color(GRIC, ROJ);  printf("\t%c Valor real (e^x):\t", FF); color(GRIC, NEG); printf("%.9f\n", exp(x));
	color(GRIC, ROJ);  printf("\t%c Valor aproximado:\t", FF); color(GRIC, NEG); printf("%.9f\n", suma);
	color(GRIC, ROJ);  printf("\t--------------------------------------------------------------\n");
	color(GRIC, ROJ);  printf("\t%c Error absoluto:\t", FF); color(GRIC, NEG); printf("%.9f\n", fabs(exp(x)-suma));
	color(GRIC, ROJ);  printf("\t%c Error relativo:\t", FF); color(GRIC, NEG); printf("%.9f%%\n", fabs(1-suma/exp(x))*100);
	color(GRIC, ROJ);  printf("\t--------------------------------------------------------------\n");
	
	getch();
	
	return 0;
}
