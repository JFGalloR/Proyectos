/*===========================================================================================================
	EX�MEN PARCIAL UNIDAD II. Programa #1:
		Programa de Pilas. Trabajando con los vagones de un tren.
  ---------------------------------------------------------------------------------------------------------
	� OBJETIVO:
		Utilizando pilas con vectores, realizar una simulaci�n de vagones de tren en donde se controle el 
		programa con un men� con las opciones:
			1. Ingresar vagones.
				Se agregar�n vagones de 5 en 5.
			2. Eliminar vagones.
				Se pedir� ingresar qu vag�n se desea eliminar, para buscarlo y eliminarlo.
			3. Salir.
  ---------------------------------------------------------------------------------------------------------
    � ELABORADOR:
		Juan Francisco Gallo Ram�rez
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
// Constantes que representan s�mbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la funci�n 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
// Constantes l�mites para generar n�meros aleatorios.
const int LIM_INF = 100, LIM_SUP = 999;

//========================================================================== FUNCI�N DE APOYO PARA COLOR =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a modificar los colores del texto en la consola.
  ---------------------------------------------------------------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//========================================================================== FUNCI�N PARA VALIDAR STRING =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que valida si un string contiene valores numericos, es decir, si el string ingresado es un 
	n�mero.
  ---------------------------------------------------------------------------------------------------------*/
bool validarNum(string aux)
{
	// Ciclo para recorrer todo el string.
	for(int i = 0; i < aux.length(); i++)
	{
		// Se evalua si el caracter no es de tipo num�rico.
		if(!isdigit(aux[i]))
		// Se devuelve false si no lo es.
		return false;
	}
	// Se devuelve true si el string es un n�mero.
	return true;
}

//=============================================================== FUNCI�N PARA CONVERTIR STRING A ENTERO =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que valida si un string contiene valores num�ricos, es decir, si el string ingresado es un 
	n�mero.
  ---------------------------------------------------------------------------------------------------------*/
int stoi(string aux)
{
	// Cadena del tipo 'char' de longitud igual a la ingresada m�s el caracter final.
	char auxC[aux.length()+1];
	
	// Ciclo para recorrer todo el string.
	for(int i = 0; i <= aux.length(); i++)
	{
		// Se asigna todo rl string a la cadena de caracteres.
		auxC[i] = aux[i];
	}
	
	// Se devuelve la conversi�n.
	return atoi(auxC);
}

//============================================================= FUNCI�N GENERADORA DE ENTEROS ALEATORIOS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que genera enteros aleatorios seg�n los valores que reciba, lo cuales funcionan como l�mite 
	superior e inferior para generar el n�mero.
  ---------------------------------------------------------------------------------------------------------*/
int enteroAleatorio(int lim_inf, int lim_sup)
{
	// F�rmula donde a partir del l�mite inferior genera la diferencia de los l�mites m�s uno.
	int num = lim_inf + rand() % (lim_sup - lim_inf + 1);
	// Retorna el n�mero que se gener�.
	return num;
}

//=================================================================== FUNCI�N MOSTRAR ELEMENTOS DEL TREN =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n para mostrar todos los elementos del arreglo que simula el tren.
  ---------------------------------------------------------------------------------------------------------*/
int mostrarElementos(int tren[], int &cima)
{
	// Se imprime el n�mero que se encuentra en la cima de la pila si es que hay vagones.
	color(GRIC, ROJ);cout<<endl<<"\tVag�n de la cima: ";color(GRIC, AZU);
	if(cima > -1)
	{
		// Si hay vagones se imprime el de la cima.
		cout<<tren[cima]<<endl;
	}else
	{
		// Si no hay vagones se imprime un mensaje.
		cout<<"No hay vagones."<<endl;
	}
	// Se imprime el n�mero del vag�n.
	color(GRIC, ROJ);cout<<endl<<"\tVag�n:   ";color(GRIC, AZU);
	for(int i = 0; i <= cima; i++)
	{
		// Se imprimen el n�mero de vag�n corrspondiente al momento de inserci�n.
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
		// En esta parte es donde se imprimme el n�mero de identificaci�n del vag�n.
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

//======================================================================== FUNCI�N PARA INGRESAR VAGONES =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n para ingresar vagones de 5 en 5 en la pila, asignandole un n�mero aleatorio entre 100 y 999 con
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
	
	// Ciclo de inserci�n de 5 en 5, inserta mientras no se llegue al limite de vagones.
	while(cima < TAM - 1 && i < 5)
	{
		cima++;
		rep = true;
		// Ciclo que nos verifica que no existan n�meros repetidos en los vagones.
		while(rep)
		{
			// Se asigna el n�mero generado a la pila.
			tren[cima] = enteroAleatorio(LIM_INF, LIM_SUP);
			rep = false;
			// Se recorre la pila en busca de n�meros repetidos.
			for(int j = 0; j < cima; j++)
			{
				// Si hay alg�n repetido se sale del ciclo para volver a asignar un nuevo valor.
				if(tren[cima] == tren[j])
				{
					rep = true;
					j = cima;
				}
			}
		}
		i++;
	}
	// Se llama a la funci�n para mostrar el tren.
	mostrarElementos(tren, cima);
	// Mensaje de generaci�n de vagones exitoso.
	color(GRIC, VER);cout<<endl<<endl<<endl<<"\t+ + + VAGON(ES) GENERADOS CORRECTAMENTE + + +";
}

//======================================================================== FUNCI�N PARA ELIMINAR VAGONES =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n para eliminar vagones seg�n su b�squeda. Contrario a la funci�n de insertar, s�lo se eliminar� 
	de 1 en 1.
  ---------------------------------------------------------------------------------------------------------*/
void popVagones(int tren[], int &cima)
{
	// Variables l�gica para b�squeda.
	bool encontrado = false;
	// Pila auxiliar.
	int aux[TAM] = {};
	// Variable entera para el n�mero a buscar.
	int num = 0;
	// Indicador de cima de la segunda pila.
	int cimaAux = -1;
	// String que almacena la entrda  de texto.
	string vag;
	
	//Ciclo para validar la entrada de n�mero.
	do
	{
		encontrado = false;
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                             VAGONES DE TREN                                             "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F<<" Eliminar vagones."<<endl;
		mostrarElementos(tren, cima);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una n�mero de vag�n: ";
		// Se lee el vag�n a elegir.
		color(GRIC, ROJ);getline(cin, vag);
		// Se valida que la cadena ingresada sea un n�mero.
		if(validarNum(vag))
		{
			// Si es as�, se comvierte la cadena en un n�mero.
			num = stoi(vag);
			// Se recorre la pila.
			while(cima > -1 && !encontrado)
			{
				// Se evalua si el n�mero buscado se encuentra en el tren, si es as� 'encontrado' se vuelve verdadero.
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
			// Si no es un n�mero se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA S�LO NUMEROS # # #";
			getch();
		}
	}while(!validarNum(vag));
	
	if(encontrado)
	{
		// Si se encontro� el vag�n se recorre la pila auxiliar.
		while(cimaAux > -1)
		{
			// Se le asigna al vag�n encontrado el nuevo valor, simulando una eliminaci�n.
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
		// Se llama a la funci�n para mostrar el tren.
		mostrarElementos(tren, cima);
		// Mensaje de eliminaci�n de vagones exitoso.
		color(GRIC, VER);cout<<endl<<endl<<endl<<"\t+ + + VAG�N ELIMINADO CORRECTAMENTE + + +";
	}else
	{
		// Si no se encontr�, se recorre la segunda pila para volverle a asignarle los valores a la primer pila.
		while(cimaAux > -1)
		{
			// Se aumenta la primer pila, debido a que estamos haciendo "push".
			cima++;
			tren[cima] = aux[cimaAux];
			// Se decrementa la segunda pila, debido a que estamos haciendo "pop"
			cimaAux--;
		}
		// Se muestra mensaje de no coincidencias.
		color(GRIC, ROJ);cout<<"\n\t# # # VAG�N NO ENCONTRADO # # #";
	}
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCI�N PRINCIPAL =====
main()
{
	// Se declara la variable que almacena la opci�n.
	string opc;
	// Se declara el �ndice de pila.
	int cima = -1;
	// Se declara nuestro arreglo que simula los vagones.
	int tren[TAM] = {};
	
	// Se llama a la funci�n para generar n�meros aleatorios.
	srand(time(NULL));
	// Se llama a la funci�n para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Ciclo para el men� d ejecuci�n.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                             VAGONES DE TREN                                             "<<endl<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MEN� ================================"<<endl<<endl;
		// Se muestran las opciones del men�.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Ingresar vagones."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Eliminar vagones."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) <- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t============================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opci�n: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opci�n "a".
		if(opc =="A" || opc =="a")
		{
			// Se eval�a que no se haya llegado al m�ximo de vagones.
			if(cima < TAM - 1)
			{
				// Se insertan vagones si hay espacio para ello.
				pushVagones(tren, cima);
			}else
			{
				// Se muestra el mensaje de tren lleno si se llego al m�ximo.
				color(GRIC, ROJ);cout<<"\n\t# # # EL TREN LLEG� A SU MAXIMO DE VAGONES # # #";
			}
		}else
		// Si se elige la opci�n "b".
		if(opc =="B" || opc =="b")
		{
			// Se eval�a que no se haya llegado al m�nimo de vagones.
			if(cima > - 1)
			{
				// Se ejecuta la funci�n para eliminar si hay vagones.
				popVagones(tren, cima);
			}else
			{
				// Se muestra el mensaje de tren vac�o si se llego al m�nimo.
				color(GRIC, ROJ);cout<<"\n\t# # # EL TREN NO TIENE VAGONES # # #";
			}
		}else
		// Si se elige la opci�n "c".
		if(opc =="C" || opc =="c")
		{
			// Se muestra el mensaje de ejecuci�n finalizada.
			color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
		}else
		// Si la opci�n no es ninguna de las anteriores salta un mensaje de "Opci�n Inv�lida". 
		{
			color(GRIC, ROJ);cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
		}	
		getch();
	}while(opc !="C" && opc !="c"); // El ciclo se ejecutar� mientras la opci�n no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}
