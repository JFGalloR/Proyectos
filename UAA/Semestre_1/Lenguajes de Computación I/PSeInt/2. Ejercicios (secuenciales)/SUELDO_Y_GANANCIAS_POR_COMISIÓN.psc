//=============================================================================
///EJERCICIOS SECUENCIALES #2: SUELDO Y GANANCIAS POR COMISI�N
//AUTOR: Juan Francisco Gallo Ram�rez
//Universidad Aut�noma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Obtener el dinero ganado por comisi�n de ventas y el total que recibir� en el
//mes.
//=============================================================================
///DATOS DE ENTRADA: 
//Sueldo base, Cantidad de ventas realizadas y Precio de cada una de las ventas.
//=============================================================================
///DATOS DE SALIDA: 
//Total ganado por las ventas realizadas y sueldo total a recibir en el mes.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//     Sueldo           S          Real       X          -         -    
// Cantidad Ventas      CV        Entero      X          -         -
//     Ventas           V          Real       X          -         -
//   Acum. Ventas       AV         Real       X          -         -
//    Contador          C         Entero      X          -         -
//   Sueldo final       SF         Real       X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo SUELDO_Y_GANANCIAS_POR_COMISI�N
	Definir S, V, AV, SF Como Real
	Definir C, CV Como Entero
	S = 0
	V = 0
	AV = 0
	SF = 0
	C = 0
	CV = 0
	
	Escribir "*** SUELDO Y GANANCIAS POR COMOSI�N ***"
	Escribir "_______________________________________"
	Escribir "- Ingresa sueldo base: "
	Leer S
	Escribir "- Ingresa cantidad de ventas realizadas:"
	Leer CV
	Para C = 1 Hasta CV Hacer
		Escribir "- Ingresa el total de la venta #", C
		Leer V
		AV = AV + (V * 0.1)
	FinPara
	SF = S + AV
	Escribir "_______________________________________"
	Escribir "GANANCIAS POR COMISI�N DE ", C-1," VENTAS: $", AV  
	Escribir "SUELDO TOTAL DEL MES: $", SF
	
FinAlgoritmo
