//CÁLCULO DE IMC
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 28/08/2022
Algoritmo CÁLCULO_DE_IMC
	Definir E Como Entero
	Definir H, P, I Como Real
	Definir N, C Como Caracter
	
	Escribir "*** CÁLCULO DE IMC ***"
	Escribir "-Ingresa el nombre del paciente:"
	Leer N
	Escribir "-Ingresa la edad de paciente:"
	Leer E
	Escribir "-Ingresa la altura en metros del paciente:"
	Leer H
	Escribir "-Ingresa el peso en kilogramos del paciente:"
	Leer P
	I = P/(H^2)
	Si I < 18.5
		C = "PESO BAJO"
	FinSi
	Si I >= 18.5 y I < 25
		C = "PESO NORMAL"
	FinSi
	Si I >= 25 y I < 30
		C = "SOBREPESO"
	FinSi
	Si I >= 30 y I < 35
		C = "OBESIDAD GRADO I"
	FinSi
	Si I >= 35 y I < 40
		C = "OBESIDAD GRADO II"
	FinSi
	Si I >= 40
		C = "OBESIDAD GRADO III"
	FinSi
	Limpiar Pantalla
	Escribir "*** CÁLCULO DE IMC ***"
	Escribir "______________________"
	Escribir "Paciente: ", Mayusculas(N)
	Escribir "Edad: ", E, " años"
	Escribir "Altura: ", H, " m"
	Escribir "Peso: ", P, " kg"
	Escribir "IMC:", I
	Escribir "El paciente se encuentra en ", C
FinAlgoritmo
