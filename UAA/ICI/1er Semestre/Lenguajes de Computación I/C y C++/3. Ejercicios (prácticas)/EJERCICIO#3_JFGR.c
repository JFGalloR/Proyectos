/*=====================================================================
 CONVERSOR DE PULGADAS A CENTÍMETROS
=======================================================================
 OBJETIVO: Obtener la conversión de pulgadas a centímetros con los 
 datos proporcionados por el usuario.
=======================================================================
 ENTRADAS: Valor de pulgadas en centímetros y cantidad de pulgadas.
=======================================================================
 SALIDAS: Centímetros que equivalen las pulgadas antes ingresadas..
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
   cm en un in        CM         Real      -          x         2.54
    Pulgadas          in         Real      x          -          -
   Centímetros        cm         Real      x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
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
 AUTOR: Juan Francisco Gallo Ramírez
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
	
	cout << "==== CONVERSOR DE PULGADAS A CENTÍMETROS ====" << ednl;
	cout << "- Ingresa pulgadas: " << endl;
	cin >> in;
	
	cm = in * CM;
	cout << in << " pulgadas = " << cm << "centímetros." << endl;
	cout << "=============================================" << endl;
	
	
	return 0;
}
