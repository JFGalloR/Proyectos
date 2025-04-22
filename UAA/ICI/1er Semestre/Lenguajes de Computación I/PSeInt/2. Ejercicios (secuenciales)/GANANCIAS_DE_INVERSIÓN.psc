//=============================================================================
///EJERCICIOS SECUENCIALES #1: GANANCIAS DE INVERSI�N
//AUTOR: Juan Francisco Gallo Ram�rez
//Universidad Aut�noma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Obtener el capital ganado en un mes por una inversi�n en banco.
//=============================================================================
///DATOS DE ENTRADA: 
//Cantidad invertida en banco.
//=============================================================================
///DATOS DE SALIDA: 
//Total de capital ganado por inversi�n al cabo de un mes.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//     Capital          C          Real       X          -         -    
//    Ganancias         G          Real       X          -         -
//  Capital total       CT         Real       X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo GANANCIAS_DE_INVERSI�N
	Definir C, G, CT Como Real
	C = 0
	G = 0
	CT = 0
	
	Escribir "*** GANANCIAS POR INVERSI�N ***"
	Escribir "_______________________________"
	Escribir "- Ingresa capital invertrido: "
	Leer C
	G = C * 0.02
	CT = C + G
	Escribir "_______________________________"
	Escribir "- GANANCIAS POR INVERSI�N: $", G
	Escribir "- CAPITAL TOTAL: $", CT
	
	
FinAlgoritmo
