/*=========================================================================
	PRÁCTICA #1
	 Comparación de modelo exacto y aproximado.
  --------------------------------------------------------------------
	OBJETIVO
 	 Mediante el desarrollo de esta práctica, el alumno comprobará la 
	 eficiencia de los métodos	aproximados, teniendo presentes sus 
	 limitaciones.
  --------------------------------------------------------------------
	Juan Francisco Gallo Ramírez
	I.C.I 4to Semestre UAA
=========================================================================*/

#include <conio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include <windows.h>

using namespace std;

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

//---------------------------------------------- FUNCIÓN PARA LA FÓRMULA EXACTA ---//
float exactModel(float t, float m, float c)
{
	return (GRAV*m/c)*(1-exp(-c/m*t));
}

//------------------------------------------ FUNCIÓN PARA LA FÓRMULA APROXIMADA ---//
float aproxModel(float t, float m, float c, float ti, float vti)
{
	return (GRAV-(c*vti/m))*(t-ti)+vti;
}

//----------------------------------------------------------- FUNCIÓN PRINCIPAL ---//
int main() {
	
	float mass, res, tot_time, var_time;
	float ti=0, vti=0;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  cout << "                                       PRÁCTICA #1                                       " << endl;
	color(ROJC, GRIC); cout << "                        Comparación de modelo exacto y aproximado                        " << endl << endl;
	
	color(GRIC, ROJ); cout << "\t===== Ingreso de variables ==================================" << endl << endl;
	
	color(GRIC, ROJ); cout << "\t\t" << FF; color(GRIC, NEG); cout << " Ingresa la masa del objeto: ";
	color(GRIC, ROJ); cin >> mass;
	color(GRIC, ROJ); cout << "\t\t" << FF; color(GRIC, NEG); cout << " Ingresa el coeficiente de resistencia: ";
	color(GRIC, ROJ); cin >> res;
	color(GRIC, ROJ); cout << "\t\t" << FF; color(GRIC, NEG); cout << " Ingresa el tiempo total de caída: ";
	color(GRIC, ROJ); cin >> tot_time;
	color(GRIC, ROJ); cout << "\t\t" << FF; color(GRIC, NEG); cout << " Ingresa el incremento del tiempo: ";
	color(GRIC, ROJ); cin >> var_time;
	
	color(GRIC, ROJ); cout << endl << "\t===== Resultados obtenidos ==================================" << endl << endl;

	color(ROJ, GRIC); cout << "\t   Tiempo (t)  \t  V(x) Exacta  \t  V(x) Aprox.  \t     Error     " << endl << endl;
	
	for(float i=0; i<=tot_time; i+=var_time)
	{
		float v = exactModel(i, mass, res);
		vti = aproxModel(i, mass, res, ti, vti);
		
		color(GRIC, NEG);
		cout << "\t" << i << "\t\t";
		cout << v << "\t\t";
		cout << vti << "\t\t";
		cout << vti - v << "\t" << endl;
		
		ti=i;
	}
	
	getch();
	
	return 0;
}
