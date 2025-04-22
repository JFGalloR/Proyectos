//=============================================================================
///EJERCICIOS CON CONDICIONALES #1: APROBACIÓN O REPROBACIÓN DE ALUMNOS
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 31/08/2022
//=============================================================================
///OBJETIVO: 
//Determinar con el promedio de las calificaciónes otorgadas si un alumno 
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
// = Descripción = Identificador = Tipo = Variable = Constante = Valor =
// ----------------------------------------------------------------------
//   Calificación       C          Real       X          -         -
//     Contador         I         Entero      X          -         -
//    Acum. Cal.        AC         Real       X          -         -
//     Promedio         P          Real       X          -         -
//    Situación         S         Cadena      X          -         -
// ----------------------------------------------------------------------
//=============================================================================

Algoritmo APROBACIÓN_O_REPROBACIÓN_DE_ALUMNOS
	Definir C, AC, P Como Real
	Definir I Como Entero
	Definir S Como Caracter
	C = 0
	AC = 0
	S = ""
	
	Escribir "*** APROBACIÓN O REPROBACIÓN DE ALUMNOS ***"
	Escribir "___________________________________________"
	Para I = 1 Hasta 3
		Escribir "- Ingresa calificación # ", I, ":"
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
