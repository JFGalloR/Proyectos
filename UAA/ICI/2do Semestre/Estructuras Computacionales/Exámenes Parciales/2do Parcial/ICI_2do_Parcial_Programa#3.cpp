/*===========================================================================================================
	EXÁMEN PARCIAL UNIDAD II. Programa #3:
		Programa con Recursividad.
  ---------------------------------------------------------------------------------------------------------
	• OBJETIVO:
		Implementar un algoritmo, usando una función recursiva, que resuelva la siguiente sumatoria:
			K (n, p) = p * 1 + p *2 +p *3 +p * … + p*n
				- El programa debe pedir al usuario que ingrese un número n, y un número p.
				- Luego debe calcular el valor de K(n, p) usando una función recursiva.
				- Debe imprimir el resultado de K(n, p).
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
	Función que valida si un string contiene valores numericos, es decir, si el string ingresado es un 
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

//===================================================================== FUNCIÓN RECURSIVA PARA SUMATORIA =====
/*-----------------------------------------------------------------------------------------------------------
	Función recursiva para resolver la sumatoria propuesta.
  ---------------------------------------------------------------------------------------------------------*/
double sumatoria(int n, int p)
{
	// Condición de paro.
	if(n > 1)
	{
		// Se imprime la operación indicada.
		color(GRIC, NEG);cout<<p;color(GRIC, ROJ);cout<<"*";color(GRIC, NEG);cout<<n;color(GRIC, ROJ);cout<<" + ";
		// Se vuelve a llamar la función, aquí la recursividad.
		return sumatoria(n - 1, p) + p * n;
	}else
	{
		// Se termina de imprimir la operación indicada.
		color(GRIC, NEG);cout<<p;color(GRIC, ROJ);cout<<"*";color(GRIC, NEG);cout<<n;
		// Se finaliza la recursividad retornando el valor de 'p'.
        return p;
    }
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCIÓN PRINCIPAL =====
main()
{
	string opc;
	string num;
	int n = 0;
	int p = 0;
	
	// Se llama a la función para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Ciclo para el menú d ejecución.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                      SUMATORIA CON FUNCIÓN RECURSIVA                                    "<<endl<<endl<<endl;
		color(GRIC, AZU);cout<<"\t<<<<<<<<<<<<<< SUMATORIA A RESOLVER >>>>>>>>>>>>>>"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t\tK(n, p) = ";color(GRIC, NEG);cout<<"p*1 + p*2 + p*3 ... p*n"<<endl<<endl;
		color(GRIC, AZU);cout<<"\t<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MENÚ ================================"<<endl<<endl;
		// Se muestran las opciones del menú.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Ingresar valores y resolver."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) <- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t============================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opción: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opción "a".
		if(opc =="A" || opc =="a")
		{
			//Ciclo para validar la entrada de número.
			do
			{
				// Texto de control.
				system("cls");
				color(ROJ, GRIC);cout<<"                                      SUMATORIA CON FUNCIÓN RECURSIVA                                    "<<endl<<endl<<endl;
				color(GRIC, NEGC);cout<<"\t"<<F<<" Sumatoria."<<endl<<endl;
				color(GRIC, ROJ);cout<<"\t\tK(n, p) = "<<endl<<endl;
				color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa valor de \"n\": ";
				// Se lee el valor para 'n'.
				color(GRIC, ROJ);getline(cin, num);
				// Se valida que la cadena ingresada sea un número.
				if(validarNum(num))
				{
					// Si es así, se comvierte la cadena en un número.
					n = stoi(num);
				}else
				{
					// Si no es un número se imprime un mensaje.
					color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
					getch();
				}
			}while(!validarNum(num));
			
			//Ciclo para validar la entrada de número.
			do
			{
				// Texto de control.
				system("cls");
				color(ROJ, GRIC);cout<<"                                      SUMATORIA CON FUNCIÓN RECURSIVA                                    "<<endl<<endl<<endl;
				color(GRIC, NEGC);cout<<"\t"<<F<<" Sumatoria."<<endl<<endl;
				color(GRIC, ROJ);cout<<"\t\tK(";color(GRIC, NEG);cout<<n;color(GRIC, ROJ);cout<<", p) = "<<endl<<endl;
				color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa valor de \"p\": ";
				// Se lee el valor para 'p'.
				color(GRIC, ROJ);getline(cin, num);
				// Se valida que la cadena ingresada sea un número.
				if(validarNum(num))
				{
					// Si es así, se comvierte la cadena en un número.
					p = stoi(num);
				}else
				{
					// Si no es un número se imprime un mensaje.
					color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
					getch();
				}
			}while(!validarNum(num));
			
			// Texto de control.
			system("cls");
			color(ROJ, GRIC);cout<<"                                      SUMATORIA CON FUNCIÓN RECURSIVA                                    "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F<<" Sumatoria."<<endl<<endl;
			// Se imprime la sumatoria con los valores ingresados.
			color(GRIC, ROJ);cout<<"\t\tK("<<n<<", "<<p<<") = ";
			// Se llama a la función de sumatoria, además se guarda en una variable.
			double aux = sumatoria(n, p);
			color(GRIC, ROJ);cout<<endl<<"\t\tK("<<n<<", "<<p<<") = ";color(GRIC, NEG);cout<<aux<<endl<<endl;
			color(GRIC, VER);cout<<"\t================================================"<<endl;
			// Se imprime el resultado.
			cout<<"\t\tEl resultado es: ";color(GRIC, NEG);cout<<aux<<endl;
			color(GRIC, VER);cout<<"\t================================================"<<endl;
		}else
		// Si se elige la opción "c".
		if(opc =="B" || opc =="b")
		{
			// Se muestra el mensaje de ejecución finalizada.
			color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
		}else
		{
			// Si la opción no es ninguna de las anteriores salta un mensaje de "Opción Inválida". 
			color(GRIC, ROJ);cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
		}
		getch();
	}while(opc !="B" && opc !="b"); // El ciclo se ejecutará mientras la opción no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}
