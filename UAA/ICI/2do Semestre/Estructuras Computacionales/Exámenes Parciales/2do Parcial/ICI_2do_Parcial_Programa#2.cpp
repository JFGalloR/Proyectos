/*===========================================================================================================
	EXÁMEN PARCIAL UNIDAD II. Programa #2:
		Programa de Colas.
  ---------------------------------------------------------------------------------------------------------
	• OBJETIVO:
		Utilizando colas con vectores, simular una la lista en un arreglo para 10 posiciones, que te da la 
		posibilidad de capturar hasta 10 elementos. Mostrar el siguiente menú:
			1. Mostrar la última palabra de la cola.
				Se mostrará el elemento de la cola.
			2. Siguiente.
				Se mostrará el elemento que sigue respecto al actual.
			3. Anterior.
				Se mostrará el elemento que antecede respecto al actual.
			4. Ingresar dato.
				Se pedirá al usuario un dato para ingresar a la cola.
			5. Salir.
  ---------------------------------------------------------------------------------------------------------
    • ELABORADOR:
		Juan Francisco Gallo Ramírez
  ---------------------------------------------------------------------------------------------------------
	5 de Mayo de 2023
	I.C.I. U.A.A.
===========================================================================================================*/
#include <conio.h>
#include <cctype>
#include <iostream>
#include <limits>
#include <locale.h>
#include <time.h>
#include <windows.h>

using namespace std;

#define TAM 10
// Constantes que representan símbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la función 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
// Constantes límites para generar números aleatorios.
const int LIM_INF = 100, LIM_SUP = 999;

//========================================================================== FUNCIÓN DE APOYO PARA COLOR =====
/*-----------------------------------------------------------------------------------------------------------
	Función que nos ayuda a modificar los colores del texto en la consola.
  ---------------------------------------------------------------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//====================================================================== FUNCIÓN PARA INGRESAR ELEMENTOS =====
/*-----------------------------------------------------------------------------------------------------------
	Función para ingresar elementos a la cola.
  ---------------------------------------------------------------------------------------------------------*/
void push(string cola[], int &frente, int &final, string elemento)
{
	// Si frente tiene el valor de inicialización se aumenta a 0.
	if(frente == -1)
	{
		frente++;
	}
	// Como se trata de una inserción, se agrega a la cola, por lo que final aumenta en 1.
	final++;
	// Se asigna el elemento a la cola.
	cola[final] = elemento;
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCIÓN PRINCIPAL =====
main()
{
	// Se declara la variable que almacena la opción.
	string opc;
	// Se declara una variable auxiliar, a la cual se le asignará el elemento a ingresar.
	string aux;
	// Se declara la cabeza y la final de la estructura de cola.
	int frente = -1;
	int final = -1;
	// Se establece el índice, el cual nos ayudará a recorrer la cola.
	int indice = 0;
	
	// Se declara la cola.
	string cola[TAM] = {};
	
	// Se llama a la función para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Se ingresan 6 elementos a la cola inicialmente.
	push(cola, frente, final, "CANCIÓN_1");
	push(cola, frente, final, "CANCIÓN_2");
	push(cola, frente, final, "CANCIÓN_3");
	push(cola, frente, final, "CANCIÓN_4");
	push(cola, frente, final, "CANCIÓN_5");
	push(cola, frente, final, "CANCIÓN_6");
	
	// Ciclo para el menú d ejecución.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                           COLA DE REPRODUCCIÓN                                          "<<endl<<endl<<endl;
		color(GRIC, AZU);cout<<"\t<<<<<<<<<<<<<<<<<<<<<< COLA >>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl;
		// Se muestra el elemento seleccionado por el índice.
		color(GRIC, NEG);cout<<"\t\t"<<F<<" "<<cola[indice]<<endl<<endl;
		color(GRIC, AZU);cout<<"\t<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MENÚ ================================"<<endl<<endl;
		// Se muestran las opciones del menú.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Mostrar último elemento de la cola."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Siguiente";color(GRIC, VER);cout<<" ->"<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, VER);cout<<"<-";color(GRIC, NEG);cout<<" Anterior"<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, NEG);cout<<"Ingresar elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\te) <<- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t============================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opción: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opción "a".
		if(opc =="A" || opc =="a")
		{
			// Se asigna el valor final de la cola al índice, ya que se muestra el último elemento. 
			indice = final;
		}else
		// Si se elige la opción "b".
		if(opc =="B" || opc =="b")
		{
			// Si el índice ha llegado al final, se le asigna el primer valor de la cola, ahí el efecto de cola circular.
			if(indice == final) indice = frente;
			// Caso contrario solo se aumenta en 1, para pasar al siguiente elemento.
			else indice++;
		}else
		// Si se elige la opción "c".
		if(opc =="C" || opc =="c")
		{
			// Si el índice ha llegado al frente, se le asigna el último valor de la cola, ahí el efecto de cola circular.
			if(indice == frente) indice = final;
			// Caso contrario solo se decrementa en 1, para pasar al anterior elemento.
			else indice--;
		}else
		// Si se elige la opción "d".
		if(opc =="D" || opc =="d")
		{
			// Se valora si la cola ya esta llena.
			if(final == TAM - 1 && frente == 0)
			{
				// Si la cola ya contiene los elementos máximo, en este caso 10 se muestra un mensaje de cola llena.
				color(GRIC, ROJ);cout<<"\n\t# # # COLA LLENA # # #";
			}else
			{
				//Caso contrario se pide el elemento a ingresar.
				color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento: ";
				// Se lee la opción a elegir.
				color(GRIC, ROJ);getline(cin, aux);
				// Se añade a la cola mediante la función 'push()'.
				push(cola, frente, final, aux);
				// Se muestra el mensaje de adición a la cola exitoso.
				color(GRIC, VER);cout<<endl<<"\t+ + + ELEMENTO AGREGADO CORRECTAMENTE + + +";
			}
			getch();
		}else
		// Si se elige la opción "e".
		if(opc =="E" || opc =="e")
		{
			// Se muestra el mensaje de ejecución finalizada.
			color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
			getch();
		}else
		{
			// Si la opción no es ninguna de las anteriores salta un mensaje de "Opción Inválida". 
			color(GRIC, ROJ);cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
			getch();
		}
	}while(opc !="E" && opc !="e"); // El ciclo se ejecutará mientras la opción no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}


























