//=============================================================================
///EJERCICIOS CON CICLOS #2: FACTORIAL
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Obtener el factorial de un número otorgado por el usuario. 
//=============================================================================
///DATOS DE ENTRADA: 
//Un número.
//=============================================================================
///DATOS DE SALIDA: 
//El factorial del número otorgado por el usuario.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripción = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//     Número           N         Entero       X          -         -
//    Contador          I         Entero       X          -         -
//  Acum. Números       AN        Entero       X          -         -
// ----------------------------------------------------------------------
//=============================================================================


Algoritmo FACTORIAL
	Definir N, I, AN Como Entero
	N = 0
	I = 0
	AN = 1
	
	Escribir "*** CALCULADORA DE FACTORIAL ***"
	Escribir "________________________________"
	Escribir "- Ingresa número: "
	Leer N
	Escribir "________________________________"
	Escribir Sin Saltar N, "! = "
	Para I = N Hasta 1
		AN = AN * I
		Si I = N
			Escribir Sin Saltar I
		SiNo
			Escribir Sin Saltar " * ", I
		FinSi
	FinPara
	Escribir " = ", AN
	
FinAlgoritmo
