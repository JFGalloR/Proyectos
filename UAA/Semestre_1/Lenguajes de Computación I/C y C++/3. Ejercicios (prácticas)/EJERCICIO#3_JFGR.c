/*=====================================================================
 CONVERSOR DE PULGADAS A CENT�METROS
=======================================================================
 OBJETIVO: Obtener la conversi�n de pulgadas a cent�metros con los 
 datos proporcionados por el usuario.
=======================================================================
 ENTRADAS: Valor de pulgadas en cent�metros y cantidad de pulgadas.
=======================================================================
 SALIDAS: Cent�metros que equivalen las pulgadas antes ingresadas..
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
   cm en un in        CM         Real      -          x         2.54
    Pulgadas          in         Real      x          -          -
   Cent�metros        cm         Real      x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACI�N (Pseudoc�digo):
  INICIO.
	Var: 
		Reales: in, cm
	Const:
		Reales: CM = 2.54
	Escribir ("Ingresa las pulgadas")
	Leer (in)
	Hacer:
		cm = in * CM
	Escribir ("Equivale en cm a ", cm)
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ram�rez
 28/09/2022 I.C.I.
=====================================================================*/

#include <iostream>
#include <locale.h>
using namespace std;

int main ()
{
	#define CM 2.54
	
	float in, cm;
	
	setlocale(LC_ALL ,"");
	
	cout << "==== CONVERSOR DE PULGADAS A CENT�METROS ====" << ednl;
	cout << "- Ingresa pulgadas: " << endl;
	cin >> in;
	
	cm = in * CM;
	cout << in << " pulgadas = " << cm << "cent�metros." << endl;
	cout << "=============================================" << endl;
	
	
	return 0;
}
