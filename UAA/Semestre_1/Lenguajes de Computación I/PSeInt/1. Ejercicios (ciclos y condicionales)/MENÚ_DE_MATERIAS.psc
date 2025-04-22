//MENÚ DE MATERIAS
//AUTOR: Juan Francisco Gallo Ramírez
//Universidad Autónoma de Aguascalientes
//I.C.I 28/08/2022
Algoritmo MENÚ_DE_MATERIAS
	Definir A Como Entero
	A = 0
	
	Mientras A <> 4 Hacer
		Limpiar Pantalla
		Escribir "*** MENÚ DE MATERIAS ***"
		Escribir "-Selecciona una opción:"
		Escribir "________________________"
		Escribir "1. MATEMÁTICAS"
		Escribir "2. ESPAÑOL"
		Escribir "3. HISTORIA"
		Escribir "4. Salir"
		Escribir "________________________"
		Leer A
		Segun A Hacer
			1:
				Escribir "--- MATERIA MATEMÁTICAS ---"
			2:
				Escribir "--- MATERIA ESPAÑOL ---"
			3:
				Escribir "--- MATERIA HISTORIA ---"
			4:
				Escribir "-------- SALIR --------"
			De Otro Modo:
				Escribir "*** OPCIÓN NO VÁLIDA ***"
				Escribir "*** INTENTA DE NUEVO ***"
		Fin Segun
		Esperar 2 Segundos
	Fin Mientras
FinAlgoritmo