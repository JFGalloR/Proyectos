//=============================================================================
///EJERCICIOS CON CONDICIONALES #1: APROBACI�N O REPROBACI�N DE ALUMNOS
//AUTOR: Juan Francisco Gallo Ram�rez
//Universidad Aut�noma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Determinar con el promedio de las calificaci�nes otorgadas si un alumno 
//aprueba o reprueba un curso. 
//=============================================================================
///DATOS DE ENTRADA: 
//Tres calificaciones.
//=============================================================================
///DATOS DE SALIDA: 
//Promedio de tres calificaciones y si aprueba o no.
//=============================================================================
///TABLA DE CONSTANTES Y VARIABLES:
// ----------------------------------------------------------------------
// = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//   Calificaci�n       C          Real       X          -         -
//     Contador         I         Entero      X          -         -
//    Acum. Cal.        AC         Real       X          -         -
//     Promedio         P          Real       X          -         -
//    Situaci�n         S         Cadena      X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo APROBACI�N_O_REPROBACI�N_DE_ALUMNOS
	Definir C, AC, P Como Real
	Definir I Como Entero
	Definir S Como Caracter
	C = 0
	AC = 0
	S = ""
	
	Escribir "*** APROBACI�N O REPROBACI�N DE ALUMNOS ***"
	Escribir "___________________________________________"
	Para I = 1 Hasta 3
		Escribir "- Ingresa calificaci�n # ", I, ":"
		Leer C
		AC = AC + C
	FinPara
	P = AC / 3
	Si P >= 7
		S = "APROBADO"
	SiNo
		S = "REPROBADO"
	FinSi
	Escribir "___________________________________________"
	Escribir "PROMEDIO: ", P
	Escribir "*** ALUMNO ", S, " ***"
FinAlgoritmo
