/*=========================================================================
	PR�CTICA #6
	 M�todo de Bisecci�n.
  --------------------------------------------------------------------
	OBJETIVO
 	 Con el desarrollo de esta pr�ctica se pretende que el alumno:
	  � Desarrolle la implementaci�n del m�todo de Bisecci�n para 
		la determinaci�n de una ra�z para una funci�n preestablecida.
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

//------------------------------------- FUNCI�N PARA COEFICIENTE DE RESIST5ENCIA---//
float f(float x)
{
	return (668.061/x)*(1-pow(M_E, -0.146843*x))-40;
}

//-------------------------------------------- FUNCI�N PARA M�TODO DE BISECCI�N ---//
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
	
	color(ROJ, GRIC);  printf("\n\t    Ra�z obtenida    "); color(GRIC, NEG); printf("\t%f", xa);
	color(ROJC, GRIC); printf("\n\t    Valor en f(x)    "); color(GRIC, NEG); printf("\t%f", f(xa));
	
}

//----------------------------------------------------------- FUNCI�N PRINCIPAL ---//
int main() 
{
	int itr;
	float xl, xu, es;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  printf("                                       PR�CTICA #6                                       \n");
	color(ROJC, GRIC); printf("                                   M�todo de Bisecci�n                                   \n\n");

	color(GRIC, ROJ);  printf("\t===== Ingreso de par�metros =================================\n\n");
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del l�mite inferior (xl): ");
	color(GRIC, ROJ);  scanf("%f", &xl);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el valor del l�mite superior (xu): ");
	color(GRIC, ROJ);  scanf("%f", &xu);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa la tolerancia de error (es): ");
	color(GRIC, ROJ);  scanf("%f", &es);
	
	color(GRIC, ROJ);  printf("\t\t%c", FF); color(GRIC, NEG); printf(" Ingresa el n�mero m�ximo de interaciones: ");
	color(GRIC, ROJ);  scanf("%i", &itr);
	
	color(GRIC, ROJ);  printf("\n\t===== Iteraciones obtenidas =================================\n\n");
	
	Bisect(xl, xu, es, itr);
	
	getch();
	
	return 0;
}
