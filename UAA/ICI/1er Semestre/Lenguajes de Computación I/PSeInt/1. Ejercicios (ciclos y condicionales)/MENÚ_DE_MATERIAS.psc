//MEN� DE MATERIAS
//AUTOR: Juan Francisco Gallo Ram�rez
//Universidad Aut�noma de Aguascalientes
//I.C.I 28/08/2022
Algoritmo MEN�_DE_MATERIAS
	Definir A Como Entero
	A = 0
	
	Mientras A <> 4 Hacer
		Limpiar Pantalla
		Escribir "*** MEN� DE MATERIAS ***"
		Escribir "-Selecciona una opci�n:"
		Escribir "________________________"
		Escribir "1. MATEM�TICAS"
		Escribir "2. ESPA�OL"
		Escribir "3. HISTORIA"
		Escribir "4. Salir"
		Escribir "________________________"
		Leer A
		Segun A Hacer
			1:
				Escribir "--- MATERIA MATEM�TICAS ---"
			2:
				Escribir "--- MATERIA ESPA�OL ---"
			3:
				Escribir "--- MATERIA HISTORIA ---"
			4:
				Escribir "-------- SALIR --------"
			De Otro Modo:
				Escribir "*** OPCI�N NO V�LIDA ***"
				Escribir "*** INTENTA DE NUEVO ***"
		Fin Segun
		Esperar 2 Segundos
	Fin Mientras
FinAlgoritmo