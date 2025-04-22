/*=========================================================================
	PR�CTICA #2
	 Conversi�n de sistema num�rico decimal a base �.
  --------------------------------------------------------------------
	OBJETIVO
 	 Mediante el desarrollo de esta pr�ctica, el alumno desarrollar� 
	 un programa para la conversi�n mediante punto fijo de cantidades 
	 decimales positivos a cantidades en base � (2<=�<=9).
  --------------------------------------------------------------------
	Juan Francisco Gallo Ram�rez
	I.C.I 4to Semestre UAA
=========================================================================*/

#include <conio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include <vector>
#include <windows.h>

using namespace std;

const char C = 2, FF = 187;

const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
const float GRAV = 9.81;

//---------------------------- FUNCI�N PARA MANIPULAR EL COLOR DE LOS CARACTRES ---//
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//------------------------------------- FUNCI�N PARA CONVERSI�N DE PARTE ENTERA ---//
vector<int> integerConvertion(int integer, int base)
{
	vector<int> num;
	
	do{
		num.insert(num.begin(), integer%base);
		integer /= base;
	}
	while(integer!=0 && num.size() < 10);
	
	return num;
}

//------------------------------------ FUNCI�N PARA CONVERSI�N DE PARTE DECIMAL ---//
vector<int> decimalConvertion(float decimal, int base)
{
	vector<int> num;
	
	do{
		decimal = (decimal-(int)decimal)*base;
		num.push_back((int)decimal);
	}
	while(decimal-(int)decimal!=0 && num.size() < 10);
	
	return num;
}

//------------------------------------------------ FUNCI�N PARA IMPRIMIR VECTOR ---//
void imprimirVector(vector<int> vector)
{
	for(int i=0; i<vector.size(); i++) cout << vector[i];
}

//----------------------------------------------------------- FUNCI�N PRINCIPAL ---//
int main() {
	
	float num;
	int base;
	vector<int> p_int;
	vector<int> p_dec;
	
	setlocale(LC_ALL, "");system("color F0");
	
	system("cls");
	color(ROJ, GRIC);  cout << "                                       PR�CTICA #2                                       " << endl;
	color(ROJC, GRIC); cout << "                     Conversi�n de sistema num�rico decimal a base �                     " << endl << endl;
	
	color(GRIC, ROJ); cout << "\t===== Ingreso de par�metros =================================" << endl << endl;
	
	color(GRIC, ROJ); cout << "\t\t" << FF; color(GRIC, NEG); cout << " Ingresa n�mero a convetir (decimal): ";
	color(GRIC, ROJ); cin >> num;
	color(GRIC, ROJ); cout << "\t\t" << FF; color(GRIC, NEG); cout << " Ingresa la base a convertir (2<=�<=9): ";
	color(GRIC, ROJ); cin >> base;
	
	color(GRIC, ROJ); cout << endl << "\t===== Resultados obtenidos ==================================" << endl << endl;
	
	p_int = integerConvertion((int)num, base);
	p_dec = decimalConvertion(num-(int)num, base);

	color(ROJ, GRIC);  cout << "\t  N�mero convertido  \t"; color(GRIC, NEG); imprimirVector(p_int); cout << "."; imprimirVector(p_dec); cout << endl << endl;
	color(ROJC, GRIC); cout << "\t    Parte entera     \t"; color(GRIC, NEG); imprimirVector(p_int); cout << endl << endl;
	color(ROJC, GRIC); cout << "\t    Parte decimal    \t"; color(GRIC, NEG); imprimirVector(p_dec); cout << endl << endl;
	
	getch();
	
	return 0;
} 

