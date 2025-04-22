//SUELDO A PAGAR DE 10 TRABAJADORES
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 28/08/2022
Algoritmo SUELDO_A_PAGAR_DE_10_TRABAJADORES
	Definir C Como Entero
	Definir S, P Como Real
	C = 0
	S = 0
	P = 0
	
	Escribir "*** SUELDOS A PAGAR ***"
	Para I = 1 Hasta 10 Con Paso 1 Hacer
		Escribir "-Ingresa sueldo del trabajador #", I
		Leer S
		P = P + S
		Escribir "SUELDO ACUMULADO: $", P
	Fin Para
	Escribir "_________________________"
	Escribir "TOTAL A PAGAR: $", P
	Escribir "_________________________"
FinAlgoritmo
