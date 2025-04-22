/*===========================================================================================================
	EJERCICIO INTEGRADOR UNIDAD III. Conversión se Notación de Infijo - Postfijo.
  ---------------------------------------------------------------------------------------------------------
	• OBJETIVO:
		Realizar un algoritmo para la conversión de expresión de Notación de Infijo-Postfijo implementado 
		en PILAS.
  ---------------------------------------------------------------------------------------------------------
    • ELABORADORES:
	 - Alejandro Castillo Mota
 	 - Luis Manuel Flores Jiménez
	 - Juan Francisco Gallo Ramírez
  ---------------------------------------------------------------------------------------------------------
	8 de Abril de 2023
	I.C.I. U.A.A.
===========================================================================================================*/
#include <conio.h>
#include <cctype>
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
using namespace std;

// Constantes que representan símbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la función 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;


//================================================================= ESTRUCTURA PARA LOS NODOS DE LA PILA =====
/*-----------------------------------------------------------------------------------------------------------
	Contienen los elementos de cada nodo para realizar una PILA.
  ---------------------------------------------------------------------------------------------------------*/
struct Nodo
{
	char dato;
	Nodo *anterior;
};

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

//================================================================= FUNCIÓN PARA INSERTAR EN PILA "Push" =====
/*-----------------------------------------------------------------------------------------------------------
	Función que nos ayuda a insertar un nodo en la estructura PILA.
  ---------------------------------------------------------------------------------------------------------*/
void push(Nodo *&pila, char valor)
{
	Nodo *nodo = new Nodo;
	// Una vez asignado el espacio enlazamos el nodo en la cima de la pila, en este caso llamada "pila".
	if(pila==NULL)
	{
		// Si es el primer elemento, "pila" se enlazará a NULL.
		nodo->anterior = NULL;
	}else
	{
		// Si no es el primer elemento, simplemente lo enlazamos al anterior.
		nodo->anterior = pila;
	}
	// Asignamos el caracter a nuestro nodo.
	nodo->dato = valor;
	// Pila ahora apunta al recién nodo agregado.
	pila = nodo;
}

//================================================================== FUNCIÓN PARA ELIMINAR DE PILA "Pop" =====
/*-----------------------------------------------------------------------------------------------------------
	Función que nos ayuda a eliminar un nodo de la estructura PILA.
  ---------------------------------------------------------------------------------------------------------*/
void pop(Nodo *&pila)
{
	// Se apunta una variable auxiliar "aux" a pila.
	Nodo *aux = pila;
	// Pila se apunta el nodo anterior.
	pila = aux->anterior;
	// Se borra el nodo quie apunta "aux".
	delete aux;
}

//====================================================================== FUNCIÓN CONVERSORA A MAYÚSCULAS =====
/*-----------------------------------------------------------------------------------------------------------
	Función que recibe una cadena y la convierte a mayúsculas.
  ---------------------------------------------------------------------------------------------------------*/
string cadMayus(string cad) 
{
	// Recorre el string y convierte cada caracter en mayusculas.
    for(int i = 0; i < cad.size(); i++)
    {
    	cad[i] = toupper(cad[i]);
	}
	// Retorna la cadena en mayúsculas.
	return cad;
}

//===================================================================== FUNCIÓN PARA COMPROBAR EXPRESIÓN =====
/*-----------------------------------------------------------------------------------------------------------
	Función que comprueba si la cadena ingresada es de letras o incluye los operadores (+, -, *, \, ^).
  ---------------------------------------------------------------------------------------------------------*/
int comprobar(string exp)
{
	// Se recorre toda la cadena.
	for(int i = 0; i < exp.size(); i++)
	{
		// Se valora si es que es una letra o alguno de los operadores válidos.
		if(isalpha(exp[i]) || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' || exp[i] == '(' || exp[i] == ')' || exp[i] == ' ')
		// Si es así retorna verdadero.
		return 1;
	}
	// Caso contrario retorna falso.
	return 0;
}

//================================================ FUNCIÓN PARA COMPROBAR LA PRIORIDAD DE LOS OPERADORES =====
/*-----------------------------------------------------------------------------------------------------------
	Función que comprueba la prioridad de dos operadores.
  ---------------------------------------------------------------------------------------------------------*/
int prioridad(char car1, char car2)
{
	int valor1, valor2;
	
	// Si el primer valor es suma o resta le asigna el menor valor.
	if(car1 == '+' || car1 == '-')
	{
		valor1 = 1;
	}
	// Si el primer valor es multiplicación o división le asigna valor de 2.
	else if(car1 == '*' || car1 == '/')
	{
		valor1 = 2;
	}
	// Si el primer valor es potencia le asigna el mayor valor.
	else if(car1 == '^')
	{
		valor1 = 3;
	}
	
	// Si el segundo valor es suma o resta le asigna el menor valor.
	if(car2 == '+' || car2 == '-')
	{
		valor2 = 1;
	}
	// Si el segundo valor es multiplicación o división le asigna valor de 2.
	else if(car2 == '*' || car2 == '/')
	{
		valor2 = 2;
	}
	// Si el segundo valor es potencia le asigna el mayor valor.
	else if(car2 == '^')
	{
		valor2 = 3;
	}
	
	// Valoa si el "valor1" es menor que el "valor2".
	if(valor1 <= valor2)
	{
		// Si es así retorna verdadero.
		return 1;
	}else
	{
		// Caso contrario retorna falso.
		return 0;
	}
}

//======================================================= FUNCIÓN PARA CONVERTIR LA EXPRESIÓN A POSTFIJO =====
/*-----------------------------------------------------------------------------------------------------------
	Función que nos hace el proceso de convertir una expresión en infija a postijo.
  ---------------------------------------------------------------------------------------------------------*/
string conversion(Nodo *&pila, string &exp)
{
	// Se inizializa una cadena auxiliar.
	string cad_aux = "";
	
	// Se recorre toda la expresión ingresada por el usuario.
	for(int i = 0; i < exp.size(); i++)
	{
		// Si el caracter es distinto al caracter de espacio entonces hacer el proceso requerido.
		if(exp[i] != ' ')
		{
			// Si el caracter evaluado es '(' entonces se mete a la pila.
			if(exp[i] == '(')
			{
				push(pila, exp[i]);
			}else
			{
				/* Si no lo es, si se trata del caracter ')' mientras la cima sea distinta a '(' se concatena
				a nuestra cadena auxiliar y se saca el elemento de la pila, al final del proceso se vuleve a 
				sacar un elemento de la pila. */
				if(exp[i] == ')')
				{
					while(pila->dato != '(')
					{
						cad_aux += pila->dato;
						pop(pila); 
					}
					pop(pila);
				}else
				{
					// Si tampoco es el símbolo de ')' pero es un caracter alfabético, es un operando.
					if(isalpha(exp[i]))
					{
						// Se concatena a la cadena aux.
						cad_aux += exp[i];
					}else
					{
						// Si no es un caracter alfabético, es un operador.
						// Si la pila esta vacía o la cima tinene el caracter de '(', se añade a la pila.
						if(pila == NULL || pila->dato == '(')
						{
							push(pila, exp[i]);
						}else
						{
							/* Si no, mientras la pila no esté vacía, la cima no sea '(' y el operador sea de 
							menor prioridad que el dato de la cima, se concatena a la cadena auxiliar ña cima 
							y se borra la cima. */
							while((pila != NULL) && (pila->dato != '(') && prioridad(exp[i], pila->dato))
							{
								cad_aux += pila->dato;
								pop(pila);
							}
							// Se añade el operador a la pila.
							push(pila, exp[i]);
						}
					}
				}
			}
		}
	}
	
	// Finalmente se terminan de concatenar los elementos restantes de la pila.
	if(pila != NULL)
	{
		Nodo *aux = pila;
		while(pila != NULL)
		{
			cad_aux += pila->dato;
			aux = pila;
			pila = pila->anterior;
			delete aux;
		}
	}
	
	// Se agina el valor de la cadena auxiliar a "exp".
	exp = cad_aux;
	
	// Se retorna la cadena "exp" que es la conversión realizada.
	return exp;
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCIÓN PRINCIPAL =====
main()
{
	Nodo *pila = NULL;
	string exp;
	setlocale(LC_ALL, "");
	system("color F0");
	// Ciclo para el menú de ejecución.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                    CONVERSIÓN (Infijo a Postfijo)                                   "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t> Ingresa \"Salir\" para finalizar ejecución <"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa la expresión: ";
		color(GRIC, ROJ);
		// Se lee la expresión.
		getline(cin, exp);
		// Si la cadena ingresada no indica salir...
		if(cadMayus(exp) != "SALIR")
		{
			// Comprueba que la cadena sea válida con ayuda de nuestra función "comprobar()".
			if(comprobar(exp))
			{
				// Se imprime la expresión en infijo sin espacios.
				color(GRIC, ROJ);cout<<endl<<"\t==== INFIJO   ====================================="<<endl<<endl;
				color(GRIC, NEG);cout<<"\t     ";
				// Se recorre la expresión.
				for(int i = 0; i < exp.size(); i++)
				{
					// Si es distinto a espacio se imprime el caracter, sino no se imprime nada.
					if(exp[i] != ' ')
					{
						cout<<exp[i];
					}
				}
				// Se imprime la expresión en postfijo.
				color(GRIC, ROJ);cout<<endl<<endl<<"\t==== POSTFIJO ====================================="<<endl<<endl;
				// Aquí se llama a la función de conversión.
				color(GRIC, VER);cout<<"\t     "<<conversion(pila, exp);
				color(GRIC, AMA);cout<<endl<<endl<<endl<<"\t "<<C<<" CONVERSIÓN REALIZADA "<<C<<"  ";
			}
			// Si no es válida se muestra un mensaje.
			else
			{
				cout<<endl<<"\t# # # EXPRESIÓN INVÁLIDA # # #";
			}
		}
		// Caso contrario se muestra un mensaje.
		else
		{
			// Se muestra el mensaje de ejecución finalizada.
			color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
		}
		getch();
	}while(cadMayus(exp) != "SALIR"); // El ciclo se ejecutará mientrasno se haya ingresado "salir".
	
	// FIN DEL PROGRAMA.
}


