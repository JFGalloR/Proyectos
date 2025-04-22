//SUMA DE LOS NÚMEROS PARES E IMPARES DEL 100 AL 400
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 28/08/2022
Algoritmo SUMA_DE_NÚMEROS_PARES_E_IMPARES_DEL_100_AL_400
	Definir C, P, I Como Entero
	P = 0
	I = 0
	
	Escribir "*** SUMA DE LOS NÚMEROS PARES E IMPARES DEL 100 AL 400 ***"
	Para C = 100 Hasta 400 Con Paso 1 Hacer
		Si C%2 = 0
			P = P + C
		SiNo
			I = I + C
		FinSi
	Fin Para
	Escribir "________________________"
	Escribir "SUMA DE PARES: ", P
	Escribir "________________________"
	Escribir "SUMA DE IMPARES: ", I
	Escribir "________________________"
FinAlgoritmo
