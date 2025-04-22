/*==================================================
  EJERCICIO #1. Apuntadores.
 ------------------------------------------------
 OBJETIVO:
 Capturar datos de alumnos, y dependiendo el 
 tipo de alumnos, caoturar porcentaje de beca, 
 o deporte en el que cursa; adem�s mostrar 
 alumnos becarios y deportistas; adicionalmente,
 mostrar alumnos deportistas de entre 20 y 25.
 ------------------------------------------------
 Juan Francisco Gallo Ram�rez
 20/Febrero/2023
 I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <windows.h>
using namespace std;

const char F=16, FF=187;

main()
{
	double num1 = 7.3;
	double num2;
	double *fPtr = NULL;
	
	system("color F0");
	setlocale(LC_ALL, "");
	
	// Asignar la direcci�n de la variable numero1 a la variable apuntador "fPtr".
	fPtr = &num1;
	// Imprimir el valor del objeto al que apunta "fPtr".
	cout << FF << " El valor del objeto al que apunta 'fPtr' es:\t" << *fPtr << endl;
	// Asignar a la variable numero2 el valor del objeto al que apunta "fPtr".
	num2 = *fPtr;
	// Imprimir el valor de numero2.Imprimir el valor de "num2".
	cout << FF << " El valor del objeto al que apunta 'num2' es:\t" << num2 << endl;
	// Imprimir la direcci�n de "num1".
	cout << FF << " La direcci�n de memoria de 'num1' es:\t\t" << &num1 << endl;
	// Imprimir la direcci�n almacenada en "fPtr".
	cout << FF << " La direcci�n almacenada en 'fPtr' es:\t\t" << fPtr << endl;
	
}

/*
========================================================================
 1. �El valor que se imprime es el mismo que la direcci�n de numero1?
  
   >> S�, es la misma direcci�n de memoria.
========================================================================

 2. De acuerdo con los conceptos revisados, de los siguientes casos de 
    c�digo propuestos en los que se involucra apuntadores identifica 
	los posibles errores y com�ntalo en la caja de respuesta:
	
-----------------------------------------------------------------------
    Casos                       Respuesta
-----------------------------------------------------------------------
							 
	int a = 10;                 
	int *ptri = NULL;		 
	double x = 5.0;           No detecto alg�n posible error.
	double *ptrf = NULL;
	ptri = &a;
	ptrf = &x;

-----------------------------------------------------------------------

	char *ptr;                No detecto alg�n posible error.
	*ptr = 'a';
	
-----------------------------------------------------------------------

	int n;                    Al momento de asignar un valor y no 
	int *ptr = &n;            una direcci�n de memoria al puntero 
	ptr = 9;                  es necesario anteponer al puntero "*".

-----------------------------------------------------------------------

	int *aptre;               Al momento de asignar la direci�n de
	char *aptrc;              un puntero a otro puntero, es necesario
	int e = 5;                que sean del mismo tipo, en este caso,
	aptre = &e;               se asigna la direcci�n de memoria de una
	aptrc = aptre;            variable tipo int a una tipo char, error.
	
-----------------------------------------------------------------------

========================================================================
*/










