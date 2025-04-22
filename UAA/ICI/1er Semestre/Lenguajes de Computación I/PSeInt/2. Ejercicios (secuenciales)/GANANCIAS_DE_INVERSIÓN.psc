//=============================================================================
///EJERCICIOS SECUENCIALES #1: GANANCIAS DE INVERSIÓN
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Obtener el capital ganado en un mes por una inversión en banco.
//=============================================================================
///DATOS DE ENTRADA: 
//Cantidad invertida en banco.
//=============================================================================
///DATOS DE SALIDA: 
//Total de capital ganado por inversión al cabo de un mes.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripción = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//     Capital          C          Real       X          -         -    
//    Ganancias         G          Real       X          -         -
//  Capital total       CT         Real       X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo GANANCIAS_DE_INVERSIÓN
	Definir C, G, CT Como Real
	C = 0
	G = 0
	CT = 0
	
	Escribir "*** GANANCIAS POR INVERSIÓN ***"
	Escribir "_______________________________"
	Escribir "- Ingresa capital invertrido: "
	Leer C
	G = C * 0.02
	CT = C + G
	Escribir "_______________________________"
	Escribir "- GANANCIAS POR INVERSIÓN: $", G
	Escribir "- CAPITAL TOTAL: $", CT
	
	
FinAlgoritmo
