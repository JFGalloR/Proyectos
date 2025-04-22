//=============================================================================
///EJERCICIOS CON CICLOS #1: RIFA
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Calcular la cantidad recaudada por venta de boletos para rifa, la cantidad 
//que recibirá el premiado, y las ganancias obtenidas por la rifa. 
//=============================================================================
///DATOS DE ENTRADA: 
//Cantidad de boletos impresos.
//=============================================================================
///DATOS DE SALIDA: 
//Dinero recaudado, dinero para el premiado y ganancias obtenida por realizar 
//la rifa.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripción = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//  Cant. Boletos       CB        Entero       X          -         -
//    Contador          I         Entero       X          -         -
// Dinero Recaudado     DR        Entero       X          -         -
//     Premio           P          REAL        X          -         -
//    Ganancias         G          REAL        X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo RIFA
	Definir CB, I, DR Como Entero
	Definir P, G Como Real
	CB = 0
	I = 0
	DR = 0
	P = 0
	G = 0
	
	Escribir "*** RIFA ENTRE AMIGOS ***"
	Escribir "_________________________"
	Escribir "- Ingresa cantidad de boletos impresos: "
	Leer CB
	Para I = 1 Hasta CB
		DR = DR + I
	FinPara
	P = DR * 0.3
	G = DR * 0.7
	Escribir "_________________________"
	Escribir "DINERO RECAUDADO: $", DR
	Escribir "PREMIO A OTORGAR: $", P
	Escribir "GANANCIA DE RIFA: $", G
	
FinAlgoritmO
