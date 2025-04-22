/*=========================================================================
	PR�CTICA #8
	 Newton-Raphson.
  --------------------------------------------------------------------
	OBJETIVO
 	 Con el desarrollo de esta pr�ctica se pretende que el alumno:
	  � Implemente el algoritmo de Newton-Raphson en lenguaje C para 
	    una funci�n previamente establecida.
	  � Compruebe el desempe�o de su implementaci�n en la 
	    determinaci�n de una ra�z.
  --------------------------------------------------------------------
	Juan Francisco Gallo Ram�rez
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

//---------------------------- FUNCI�N PARA MANIPULAR EL COLOR DE LOS CARACTRES ---//
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//----------------------------------------------- FUNCI�N PARA CALCULAR SU RA�Z ---//
float f(float x)
{
	return pow(x, 4) - 6 * pow(x, 3) + 12 * pow(x, 2) - 10 * x + 3;
}

//----------------------------------- DERIVADA DE FUNCI�N PARA CALCULAR SU RA�Z ---//
float devf(float x)
{
	return 4 * pow(x, 3) - 18 * pow(x, 2) + 24 * x - 10;
}


//--------------------------------------- FUNCI�N PARA M�TODO DE FALSA POSICI�N ---//
void NewRap(float x0, float es, int itr)
{
	int i = 0;
	float xr = x0, xrold, ea = 100;
	
	color(ROJ, GRIC);  printf("\t   i   \t  Aprox. (xr)  \t  Error (ea)  \n\n");
	color(GRIC, ROJC); printf("\t%i", i);	
	color(GRIC, NEG);  printf("\t%f\t%f\t\n", xr, ea);
	
	do
	{
		xrold = xr;
		xr = xrold - ( f(xrold) / devf(xrold) );
		i++;
		
		if(xr != 0) 
			ea = fabs( (xr - xrold) / xr) * 100;
			
		color(GRIC, ROJC); printf("\t%i", i);	
		color(GRIC, NEG);  printf("\t%.8f\t%.8f\t\n", xr, ea);
		
	}
	while(i < itr && ea > es);
	
	color(ROJ, GRIC);  printf("\n\t    Ra�z obtenida    "); color(GRIC, NEG); printf("\t%f.8", xr);
	color(ROJC, GRIC); printf("\n\t    Valor en f(x)    "); color(GRIC, NEG); printf("\t%.8f", f(xr));
	
}

//----------------------------------------------------------- FUNCI�N PRINCIPAL ---//
int main() 
{
	int itr;
	float x0, es;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  printf("                                       PR�CTICA #8                                       \n");
	color(ROJC, GRIC); printf("                                     Newton-Raphson                                      \n\n");

	color(GRIC, ROJ);  printf("\t===== Ingreso de par�metros =================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del punto de partida (x0): ");
	color(GRIC, ROJ);  scanf("%f", &x0);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa la tolerancia de error (es%%): ");
	color(GRIC, ROJ);  scanf("%f", &es);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el n�mero m�ximo de interaciones: ");
	color(GRIC, ROJ);  scanf("%i", &itr);
	
	color(GRIC, ROJ);  printf("\n\t===== Iteraciones obtenidas =================================\n\n");
	
	NewRap(x0, es, itr);
	
	getch();
	
	return 0;
}
