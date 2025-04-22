/*===========================================================================================================
	EXÁMEN PARCIAL UNIDAD II. Programa #1:
		Programa de Pilas. Trabajando con los vagones de un tren.
  ---------------------------------------------------------------------------------------------------------
	• OBJETIVO:
		Utilizando pilas con vectores, realizar una simulación de vagones de tren en donde se controle el 
		programa con un menú con las opciones:
			1. Ingresar vagones.
				Se agregarán vagones de 5 en 5.
			2. Eliminar vagones.
				Se pedirá ingresar qu vagón se desea eliminar, para buscarlo y eliminarlo.
			3. Salir.
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
#include <locale.h>
#include <time.h>
#include <windows.h>

using namespace std;

#define TAM 15
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

//========================================================================== FUNCIÓN PARA VALIDAR STRING =====
/*-----------------------------------------------------------------------------------------------------------
	Función que valida si un string contiene valores numericos, es decir, si el string ingresado es un 
	número.
  ---------------------------------------------------------------------------------------------------------*/
bool validarNum(string aux)
{
	// Ciclo para recorrer todo el string.
	for(int i = 0; i < aux.length(); i++)
	{
		// Se evalua si el caracter no es de tipo numérico.
		if(!isdigit(aux[i]))
		// Se devuelve false si no lo es.
		return false;
	}
	// Se devuelve true si el string es un número.
	return true;
}

//=============================================================== FUNCIÓN PARA CONVERTIR STRING A ENTERO =====
/*-----------------------------------------------------------------------------------------------------------
	Función que valida si un string contiene valores numéricos, es decir, si el string ingresado es un 
	número.
  ---------------------------------------------------------------------------------------------------------*/
int stoi(string aux)
{
	// Cadena del tipo 'char' de longitud igual a la ingresada más el caracter final.
	char auxC[aux.length()+1];
	
	// Ciclo para recorrer todo el string.
	for(int i = 0; i <= aux.length(); i++)
	{
		// Se asigna todo rl string a la cadena de caracteres.
		auxC[i] = aux[i];
	}
	
	// Se devuelve la conversión.
	return atoi(auxC);
}

//============================================================= FUNCIÓN GENERADORA DE ENTEROS ALEATORIOS =====
/*-----------------------------------------------------------------------------------------------------------
	Función que genera enteros aleatorios según los valores que reciba, lo cuales funcionan como límite 
	superior e inferior para generar el número.
  ---------------------------------------------------------------------------------------------------------*/
int enteroAleatorio(int lim_inf, int lim_sup)
{
	// Fórmula donde a partir del límite inferior genera la diferencia de los límites más uno.
	int num = lim_inf + rand() % (lim_sup - lim_inf + 1);
	// Retorna el número que se generó.
	return num;
}

//=================================================================== FUNCIÓN MOSTRAR ELEMENTOS DEL TREN =====
/*-----------------------------------------------------------------------------------------------------------
	Función para mostrar todos los elementos del arreglo que simula el tren.
  ---------------------------------------------------------------------------------------------------------*/
int mostrarElementos(int tren[], int &cima)
{
	// Se imprime el número que se encuentra en la cima de la pila si es que hay vagones.
	color(GRIC, ROJ);cout<<endl<<"\tVagón de la cima: ";color(GRIC, AZU);
	if(cima > -1)
	{
		// Si hay vagones se imprime el de la cima.
		cout<<tren[cima]<<endl;
	}else
	{
		// Si no hay vagones se imprime un mensaje.
		cout<<"No hay vagones."<<endl;
	}
	// Se imprime el número del vagón.
	color(GRIC, ROJ);cout<<endl<<"\tVagón:   ";color(GRIC, AZU);
	for(int i = 0; i <= cima; i++)
	{
		// Se imprimen el número de vagón corrspondiente al momento de inserción.
		cout<<i + 1;
		if(i + 1 > 9)
		{
			cout<<"    ";
		}else
		{
			cout<<"     ";
		}
	}
	
	// Se imprime el tren con sus vagones con ayuda de caracteres.
	color(GRIC, ROJ);cout<<endl<<"          ____";
	for(int i = 0; i <= cima; i++)
	{
		cout<<" _____";
	}
	
	// Se imprimen los caracteres para simular un tren y sus vagones.
	color(GRIC, ROJ);cout<<endl<<"    ][";color(GRIC, NEG);cout<<"__";color(GRIC, AMA);cout<<",";
	color(GRIC, NEG);cout<<"_|";color(GRIC, AMA);cout<<"()";color(GRIC, NEG);cout<<"|";
	for(int i = 0; i <= cima; i++)
	{
		// En esta parte es donde se imprimme el número de identificación del vagón.
		cout<<" |";color(GRIC, NEG);cout<<tren[i];color(GRIC, NEG);cout<<"|";
	}
	
	// Se imprimen los caracteres para simular un tren y sus vagones.
	cout<<endl<<"   {";color(GRIC, AMA);cout<<"|";color(GRIC, NEG);cout<<"_";color(GRIC, AMA);cout<<"|";
	color(GRIC, NEG);cout<<"_";color(GRIC, AMA);cout<<"|";color(GRIC, NEG);cout<<"_";
	color(GRIC, NEG);cout<<"|";color(GRIC, ROJ);cout<<"--";color(GRIC, AMA);color(GRIC, NEG);cout<<"|";
	for(int i = 0; i <= cima; i++)
	{
		// Se imprimen los caracteres para simular un tren y sus vagones.
		cout<<"_|";color(GRIC, ROJ);cout<<"---";color(GRIC, NEG);cout<<"|";
	}
	
	// Se imprimen los caracteres para simular un tren y sus vagones.
	color(GRIC, ROJ);cout<<endl<<"  //";color(GRIC, NEG);cout<<"oo";color(GRIC, NEGC);cout<<"---";
	color(GRIC, NEG);cout<<"OO";color(GRIC, NEGC);cout<<"=";color(GRIC, NEG);cout<<"OO";
	for(int i = 0; i <= cima; i++)
	{
		// Se imprimen los caracteres para simular un tren y sus vagones.
		cout<<"  o";color(GRIC, NEGC);cout<<"=";color(GRIC, NEG);cout<<"o ";
	}
}

//======================================================================== FUNCIÓN PARA INGRESAR VAGONES =====
/*-----------------------------------------------------------------------------------------------------------
	Función para ingresar vagones de 5 en 5 en la pila, asignandole un número aleatorio entre 100 y 999 con
	ayuda de la funcion "enteroAleatorio()".
  ---------------------------------------------------------------------------------------------------------*/
void pushVagones(int tren[], int &cima)
{
	// Variable contador.
	int i = 0;
	// Variable para repeticiones.
	bool rep = true;
	
	// Texto de control.
	system("cls");
	color(ROJ, GRIC);cout<<"                                             VAGONES DE TREN                                             "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F<<" Insertar vagones."<<endl;
	
	// Ciclo de inserción de 5 en 5, inserta mientras no se llegue al limite de vagones.
	while(cima < TAM - 1 && i < 5)
	{
		cima++;
		rep = true;
		// Ciclo que nos verifica que no existan números repetidos en los vagones.
		while(rep)
		{
			// Se asigna el número generado a la pila.
			tren[cima] = enteroAleatorio(LIM_INF, LIM_SUP);
			rep = false;
			// Se recorre la pila en busca de números repetidos.
			for(int j = 0; j < cima; j++)
			{
				// Si hay algún repetido se sale del ciclo para volver a asignar un nuevo valor.
				if(tren[cima] == tren[j])
				{
					rep = true;
					j = cima;
				}
			}
		}
		i++;
	}
	// Se llama a la función para mostrar el tren.
	mostrarElementos(tren, cima);
	// Mensaje de generación de vagones exitoso.
	color(GRIC, VER);cout<<endl<<endl<<endl<<"\t+ + + VAGON(ES) GENERADOS CORRECTAMENTE + + +";
}

//======================================================================== FUNCIÓN PARA ELIMINAR VAGONES =====
/*-----------------------------------------------------------------------------------------------------------
	Función para eliminar vagones según su búsqueda. Contrario a la función de insertar, sólo se eliminará 
	de 1 en 1.
  ---------------------------------------------------------------------------------------------------------*/
void popVagones(int tren[], int &cima)
{
	// Variables lógica para búsqueda.
	bool encontrado = false;
	// Pila auxiliar.
	int aux[TAM] = {};
	// Variable entera para el número a buscar.
	int num = 0;
	// Indicador de cima de la segunda pila.
	int cimaAux = -1;
	// String que almacena la entrda  de texto.
	string vag;
	
	//Ciclo para validar la entrada de número.
	do
	{
		encontrado = false;
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                             VAGONES DE TREN                                             "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F<<" Eliminar vagones."<<endl;
		mostrarElementos(tren, cima);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una número de vagón: ";
		// Se lee el vagón a elegir.
		color(GRIC, ROJ);getline(cin, vag);
		// Se valida que la cadena ingresada sea un número.
		if(validarNum(vag))
		{
			// Si es así, se comvierte la cadena en un número.
			num = stoi(vag);
			// Se recorre la pila.
			while(cima > -1 && !encontrado)
			{
				// Se evalua si el número buscado se encuentra en el tren, si es así 'encontrado' se vuelve verdadero.
				if(num == tren[cima]) encontrado = true;
				else
				{
					//  Caso contrario se asigna ese vagon a otra pila.
					cimaAux++;
					aux[cimaAux] = tren[cima];
					// Se decrementa la cima de la pila inicial, ya que estamos haciendo "pop".
					cima--;
				}
			}
		}else
		{
			// Si no es un número se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
			getch();
		}
	}while(!validarNum(vag));
	
	if(encontrado)
	{
		// Si se encontroó el vagón se recorre la pila auxiliar.
		while(cimaAux > -1)
		{
			// Se le asigna al vagón encontrado el nuevo valor, simulando una eliminación.
			tren[cima] = aux[cimaAux];
			// Se decrementa la segunda pila, debido a que estamos haciendo "pop"
			cimaAux--;
			// Se aumenta la primer pila, debido a que estamos haciendo "push".
			cima++;
		}
		cima--;
		// Texto e control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                             VAGONES DE TREN                                             "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F<<" Eliminar vagones."<<endl;
		// Se llama a la función para mostrar el tren.
		mostrarElementos(tren, cima);
		// Mensaje de eliminación de vagones exitoso.
		color(GRIC, VER);cout<<endl<<endl<<endl<<"\t+ + + VAGÓN ELIMINADO CORRECTAMENTE + + +";
	}else
	{
		// Si no se encontró, se recorre la segunda pila para volverle a asignarle los valores a la primer pila.
		while(cimaAux > -1)
		{
			// Se aumenta la primer pila, debido a que estamos haciendo "push".
			cima++;
			tren[cima] = aux[cimaAux];
			// Se decrementa la segunda pila, debido a que estamos haciendo "pop"
			cimaAux--;
		}
		// Se muestra mensaje de no coincidencias.
		color(GRIC, ROJ);cout<<"\n\t# # # VAGÓN NO ENCONTRADO # # #";
	}
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCIÓN PRINCIPAL =====
main()
{
	// Se declara la variable que almacena la opción.
	string opc;
	// Se declara el índice de pila.
	int cima = -1;
	// Se declara nuestro arreglo que simula los vagones.
	int tren[TAM] = {};
	
	// Se llama a la función para generar números aleatorios.
	srand(time(NULL));
	// Se llama a la función para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Ciclo para el menú d ejecución.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                             VAGONES DE TREN                                             "<<endl<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MENÚ ================================"<<endl<<endl;
		// Se muestran las opciones del menú.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Ingresar vagones."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Eliminar vagones."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) <- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t============================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opción: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opción "a".
		if(opc =="A" || opc =="a")
		{
			// Se evalúa que no se haya llegado al máximo de vagones.
			if(cima < TAM - 1)
			{
				// Se insertan vagones si hay espacio para ello.
				pushVagones(tren, cima);
			}else
			{
				// Se muestra el mensaje de tren lleno si se llego al máximo.
				color(GRIC, ROJ);cout<<"\n\t# # # EL TREN LLEGÓ A SU MAXIMO DE VAGONES # # #";
			}
		}else
		// Si se elige la opción "b".
		if(opc =="B" || opc =="b")
		{
			// Se evalúa que no se haya llegado al mínimo de vagones.
			if(cima > - 1)
			{
				// Se ejecuta la función para eliminar si hay vagones.
				popVagones(tren, cima);
			}else
			{
				// Se muestra el mensaje de tren vacío si se llego al mínimo.
				color(GRIC, ROJ);cout<<"\n\t# # # EL TREN NO TIENE VAGONES # # #";
			}
		}else
		// Si se elige la opción "c".
		if(opc =="C" || opc =="c")
		{
			// Se muestra el mensaje de ejecución finalizada.
			color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
		}else
		// Si la opción no es ninguna de las anteriores salta un mensaje de "Opción Inválida". 
		{
			color(GRIC, ROJ);cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
		}	
		getch();
	}while(opc !="C" && opc !="c"); // El ciclo se ejecutará mientras la opción no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}
