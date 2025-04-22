/*=========================================================================
	PRÁCTICA #6
	 Método de Bisección.
  --------------------------------------------------------------------
	OBJETIVO
 	 Con el desarrollo de esta práctica se pretende que el alumno:
	  • Desarrolle la implementación del método de Bisección para 
		la determinación de una raíz para una función preestablecida.
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

//------------------------------------- FUNCIÓN PARA COEFICIENTE DE RESIST5ENCIA---//
float f(float x)
{
	return (668.061/x)*(1-pow(M_E, -0.146843*x))-40;
}

//-------------------------------------------- FUNCIÓN PARA MÉTODO DE BISECCIÓN ---//
void Bisect(float xl, float xu, float es, int itr)
{
	int i = 0;
	float ea = 0, xa = 0, test = 0;
	
	color(ROJ, GRIC);  printf("\t   i   \t  Aprox. (xa)  \t  Error (ea)  \n\n");
	
	do
	{
		i++;
		xa = (xl+xu)/2;
		
		if(xa != 0)
			ea = fabs((xu-xl)/(xu+xl))*100;
		
		test = f(xl)*f(xa);
		
		if(test < 0)
			xu = xa;
		else if(test > 0)
			xl = xa;
		else 
			ea = 0;
			
		color(GRIC, ROJC); printf("\t%i", i);
		color(GRIC, NEG);  printf("\t%f\t%f\n", xa, ea);
	}
	while(i < itr && ea > es);
	
	color(ROJ, GRIC);  printf("\n\t    Raíz obtenida    "); color(GRIC, NEG); printf("\t%f", xa);
	color(ROJC, GRIC); printf("\n\t    Valor en f(x)    "); color(GRIC, NEG); printf("\t%f", f(xa));
	
}

//----------------------------------------------------------- FUNCIÓN PRINCIPAL ---//
int main() 
{
	int itr;
	float xl, xu, es;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  printf("                                       PRÁCTICA #6                                       \n");
	color(ROJC, GRIC); printf("                                   Método de Bisección                                   \n\n");

	color(GRIC, ROJ);  printf("\t===== Ingreso de parámetros =================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del límite inferior (xl): ");
	color(GRIC, ROJ);  scanf("%f", &xl);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del límite superior (xu): ");
	color(GRIC, ROJ);  scanf("%f", &xu);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa la tolerancia de error (es): ");
	color(GRIC, ROJ);  scanf("%f", &es);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el número máximo de interaciones: ");
	color(GRIC, ROJ);  scanf("%i", &itr);
	
	color(GRIC, ROJ);  printf("\n\t===== Iteraciones obtenidas =================================\n\n");
	
	Bisect(xl, xu, es, itr);
	
	getch();
	
	return 0;
}
