//=============================================================================
///EJERCICIOS CON CONDICIONALES #2: UTILIDAD RECIBIDA EN REPARTO ANUAL
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Calcular la utilidad de un trabajador de acuerdo a su utilidad. 
//=============================================================================
///DATOS DE ENTRADA: 
//Salario mensual y tiempo de antigüedad.
//=============================================================================
///DATOS DE SALIDA: 
//Utilidad a recibir.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripción = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//     Sueldo           S          Real       X          -         -
//  T. Antigúedad       A         Entero      X          -         -
//    Utilidad          U          Real       X          -         -
//   Porcentaje         P         Entero      X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo UTILIDAD_RECIBIDA_REPARTO_ANUAL
	Definir S Como Real
	Definir A Como Entero
	S = 0
	A = 0
	
	Escribir "*** UTILIDAD A RECIBIR ***"
	Escribir "__________________________"
	Escribir "- Ingresa sueldo mensual: "
	Leer S
	Escribir "- Ingresa años de antigüedad:"
	Leer A
	Si A < 1
		U = S * 0.05
	FinSi
	Si A >= 1 y A < 2
		U = S * 0.07
	FinSi
	Si A >= 2 y A < 5
		U = S * 0.1
	FinSi
	Si A >= 5 y A < 10
		U = S * 0.15
	FinSi
	Si A >= 10
		U = S * 0.2
	FinSi
	P = (U * 100) / S
	Escribir "__________________________"
	Escribir "TU UTILIDAD ES DEL ", P, "%: $", U
	
FinAlgoritmo
