/*=========================================================================
	PRÁCTICA #7
	 Falsa Posición Modificado.
  --------------------------------------------------------------------
	OBJETIVO
 	 Con el desarrollo de esta práctica se pretende que el alumno:
	  • Implemente el algoritmo mostrado (falsa posición modificado) 
		en lenguaje C para una función previamente establecida.
	  • Compruebe el desempeño de su implementación en la determinación 
	    de una raíz para una función difícil para éste método sin 
		modificación.
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

//------------------------------------------------ FUNCIÓN PARA CALCULAR SU RAÍZ---//
float f(float x)
{
	return pow(x, 6) - 1;
}

//--------------------------------------- FUNCIÓN PARA MÉTODO DE FALSA POSICIÓN ---//
void FalPosMod(float xl, float xu, float es, int itr)
{
	int i = 0, il = 0, iu = 0;
	float ea = 0, xr = 0, test = 0;
	float fl = f(xl), fu = f(xu);
	
	color(ROJ, GRIC);  printf("\t   i   \t Lím. inf (xL) \t Lím. sup (xU) \t  Aprox. (xr)  \t  Error (ea)  \n\n");
	
	do
	{
		float xrold = xr;
		xr = xu - (fu * (xl - xu)) / (fl - fu);
		i++;
		
		if(xr != 0)
			ea = fabs((xr - xrold) / xr * 100);
		
		if(fl * f(xr) < 0)
		{
			xu = xr;
			fu = f(xu);
			iu = 0;
			il++;
			
		}
		else if(fl * f(xr) > 0)
		{
			xl = xr;
			fl = f(xl);
			il = 0;
			iu++;
			
		}
		else
			ea = 0;
			
		color(GRIC, ROJC); printf("\t%i", i);	
		color(GRIC, NEG);  printf("\t%f\t%f\t%f\t%f\t\n", xl, xu, xr, ea);
		
	}
	while(i < itr && ea > es);
	
	color(ROJ, GRIC);  printf("\n\t    Raíz obtenida    "); color(GRIC, NEG); printf("\t%f", xr);
	color(ROJC, GRIC); printf("\n\t    Valor en f(x)    "); color(GRIC, NEG); printf("\t%f", f(xr));
	
}

//----------------------------------------------------------- FUNCIÓN PRINCIPAL ---//
int main() 
{
	int itr;
	float xl, xu, es;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  printf("                                       PRÁCTICA #7                                       \n");
	color(ROJC, GRIC); printf("                                Falsa Posición Modificado                                \n\n");

	color(GRIC, ROJ);  printf("\t===== Ingreso de parámetros =================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del límite inferior (xl): ");
	color(GRIC, ROJ);  scanf("%f", &xl);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del límite superior (xu): ");
	color(GRIC, ROJ);  scanf("%f", &xu);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa la tolerancia de error (es%): ");
	color(GRIC, ROJ);  scanf("%f", &es);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el número máximo de interaciones: ");
	color(GRIC, ROJ);  scanf("%i", &itr);
	
	color(GRIC, ROJ);  printf("\n\t===== Iteraciones obtenidas =================================\n\n");
	
	FalPosMod(xl, xu, es, itr);
	
	getch();
	
	return 0;
}
