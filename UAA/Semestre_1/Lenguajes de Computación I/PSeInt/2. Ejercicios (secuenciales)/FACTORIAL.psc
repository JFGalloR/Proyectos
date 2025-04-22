//=============================================================================
///EJERCICIOS CON CICLOS #2: FACTORIAL
//AUTOR: Juan Francisco Gallo Ram�rez
//Universidad Aut�noma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Obtener el factorial de un n�mero otorgado por el usuario. 
//=============================================================================
///DATOS DE ENTRADA: 
//Un n�mero.
//=============================================================================
///DATOS DE SALIDA: 
//El factorial del n�mero otorgado por el usuario.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//     N�mero           N         Entero       X          -         -
//    Contador          I         Entero       X          -         -
//  Acum. N�meros       AN        Entero       X          -         -
// ----------------------------------------------------------------------
//=============================================================================


Algoritmo FACTORIAL
	Definir N, I, AN Como Entero
	N = 0
	I = 0
	AN = 1
	
	Escribir "*** CALCULADORA DE FACTORIAL ***"
	Escribir "________________________________"
	Escribir "- Ingresa n�mero: "
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
