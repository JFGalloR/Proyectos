//SISTEMA DE COMPRA
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 28/08/2022
Algoritmo SISTEMA_DE_COMPRA
	Definir C, P Como Real
	C = 0
	P = 0
	
	Escribir "*** SISTEMA DE COMPRA ***"
	Escribir "-Ingresa total de la compra:"
	Leer C
	Escribir "-Ingresa cantidad pagada:"
	Leer P
	Si C > P
		C = C - P
		Escribir "_______________________"
		Escribir "FALTA PAGAR $", C
		Escribir "_______________________"
	SiNo
		Si C < P
			P = P - C
			Escribir "_______________________"
			Escribir "TU CAMBIO ES DE $", P
			Escribir "_______________________"
		SiNo
			Escribir "_____________________________"
			Escribir "*** GRACIAS POR TU COMPRA ***"
			Escribir "_____________________________"
		FinSi
	FinSi
FinAlgoritmo
