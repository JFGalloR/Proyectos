/*===========================================================================================================
	EJERCICIO INTEGRADOR UNIDAD III. Conversi�n se Notaci�n de Infijo - Postfijo.
  ---------------------------------------------------------------------------------------------------------
	� OBJETIVO:
		Realizar un algoritmo para la conversi�n de expresi�n de Notaci�n de Infijo-Postfijo implementado 
		en PILAS.
  ---------------------------------------------------------------------------------------------------------
    � ELABORADORES:
	 - Alejandro Castillo Mota
 	 - Luis Manuel Flores Jim�nez
	 - Juan Francisco Gallo Ram�rez
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

// Constantes que representan s�mbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la funci�n 'color()'.
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

//================================================================= FUNCI�N PARA INSERTAR EN PILA "Push" =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a insertar un nodo en la estructura PILA.
  ---------------------------------------------------------------------------------------------------------*/
void push(Nodo *&pila, char valor)
{
	Nodo *nodo = new Nodo;
	// Una vez asignado el espacio enlazamos el nodo en la cima de la pila, en este caso llamada "pila".
	if(pila==NULL)
	{
		// Si es el primer elemento, "pila" se enlazar� a NULL.
		nodo->anterior = NULL;
	}else
	{
		// Si no es el primer elemento, simplemente lo enlazamos al anterior.
		nodo->anterior = pila;
	}
	// Asignamos el caracter a nuestro nodo.
	nodo->dato = valor;
	// Pila ahora apunta al reci�n nodo agregado.
	pila = nodo;
}

//================================================================== FUNCI�N PARA ELIMINAR DE PILA "Pop" =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a eliminar un nodo de la estructura PILA.
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

//====================================================================== FUNCI�N CONVERSORA A MAY�SCULAS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que recibe una cadena y la convierte a may�sculas.
  ---------------------------------------------------------------------------------------------------------*/
string cadMayus(string cad) 
{
	// Recorre el string y convierte cada caracter en mayusculas.
    for(int i = 0; i < cad.size(); i++)
    {
    	cad[i] = toupper(cad[i]);
	}
	// Retorna la cadena en may�sculas.
	return cad;
}

//===================================================================== FUNCI�N PARA COMPROBAR EXPRESI�N =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que comprueba si la cadena ingresada es de letras o incluye los operadores (+, -, *, \, ^).
  ---------------------------------------------------------------------------------------------------------*/
int comprobar(string exp)
{
	// Se recorre toda la cadena.
	for(int i = 0; i < exp.size(); i++)
	{
		// Se valora si es que es una letra o alguno de los operadores v�lidos.
		if(isalpha(exp[i]) || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' || exp[i] == '(' || exp[i] == ')' || exp[i] == ' ')
		// Si es as� retorna verdadero.
		return 1;
	}
	// Caso contrario retorna falso.
	return 0;
}

//================================================ FUNCI�N PARA COMPROBAR LA PRIORIDAD DE LOS OPERADORES =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que comprueba la prioridad de dos operadores.
  ---------------------------------------------------------------------------------------------------------*/
int prioridad(char car1, char car2)
{
	int valor1, valor2;
	
	// Si el primer valor es suma o resta le asigna el menor valor.
	if(car1 == '+' || car1 == '-')
	{
		valor1 = 1;
	}
	// Si el primer valor es multiplicaci�n o divisi�n le asigna valor de 2.
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
	// Si el segundo valor es multiplicaci�n o divisi�n le asigna valor de 2.
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
		// Si es as� retorna verdadero.
		return 1;
	}else
	{
		// Caso contrario retorna falso.
		return 0;
	}
}

//======================================================= FUNCI�N PARA CONVERTIR LA EXPRESI�N A POSTFIJO =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos hace el proceso de convertir una expresi�n en infija a postijo.
  ---------------------------------------------------------------------------------------------------------*/
string conversion(Nodo *&pila, string &exp)
{
	// Se inizializa una cadena auxiliar.
	string cad_aux = "";
	
	// Se recorre toda la expresi�n ingresada por el usuario.
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
					// Si tampoco es el s�mbolo de ')' pero es un caracter alfab�tico, es un operando.
					if(isalpha(exp[i]))
					{
						// Se concatena a la cadena aux.
						cad_aux += exp[i];
					}else
					{
						// Si no es un caracter alfab�tico, es un operador.
						// Si la pila esta vac�a o la cima tinene el caracter de '(', se a�ade a la pila.
						if(pila == NULL || pila->dato == '(')
						{
							push(pila, exp[i]);
						}else
						{
							/* Si no, mientras la pila no est� vac�a, la cima no sea '(' y el operador sea de 
							menor prioridad que el dato de la cima, se concatena a la cadena auxiliar �a cima 
							y se borra la cima. */
							while((pila != NULL) && (pila->dato != '(') && prioridad(exp[i], pila->dato))
							{
								cad_aux += pila->dato;
								pop(pila);
							}
							// Se a�ade el operador a la pila.
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
	
	// Se retorna la cadena "exp" que es la conversi�n realizada.
	return exp;
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCI�N PRINCIPAL =====
main()
{
	Nodo *pila = NULL;
	string exp;
	setlocale(LC_ALL, "");
	system("color F0");
	// Ciclo para el men� de ejecuci�n.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                    CONVERSI�N (Infijo a Postfijo)                                   "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t> Ingresa \"Salir\" para finalizar ejecuci�n <"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa la expresi�n: ";
		color(GRIC, ROJ);
		// Se lee la expresi�n.
		getline(cin, exp);
		// Si la cadena ingresada no indica salir...
		if(cadMayus(exp) != "SALIR")
		{
			// Comprueba que la cadena sea v�lida con ayuda de nuestra funci�n "comprobar()".
			if(comprobar(exp))
			{
				// Se imprime la expresi�n en infijo sin espacios.
				color(GRIC, ROJ);cout<<endl<<"\t==== INFIJO   ====================================="<<endl<<endl;
				color(GRIC, NEG);cout<<"\t     ";
				// Se recorre la expresi�n.
				for(int i = 0; i < exp.size(); i++)
				{
					// Si es distinto a espacio se imprime el caracter, sino no se imprime nada.
					if(exp[i] != ' ')
					{
						cout<<exp[i];
					}
				}
				// Se imprime la expresi�n en postfijo.
				color(GRIC, ROJ);cout<<endl<<endl<<"\t==== POSTFIJO ====================================="<<endl<<endl;
				// Aqu� se llama a la funci�n de conversi�n.
				color(GRIC, VER);cout<<"\t     "<<conversion(pila, exp);
				color(GRIC, AMA);cout<<endl<<endl<<endl<<"\t "<<C<<" CONVERSI�N REALIZADA "<<C<<"  ";
			}
			// Si no es v�lida se muestra un mensaje.
			else
			{
				cout<<endl<<"\t# # # EXPRESI�N INV�LIDA # # #";
			}
		}
		// Caso contrario se muestra un mensaje.
		else
		{
			// Se muestra el mensaje de ejecuci�n finalizada.
			color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
		}
		getch();
	}while(cadMayus(exp) != "SALIR"); // El ciclo se ejecutar� mientrasno se haya ingresado "salir".
	
	// FIN DEL PROGRAMA.
}


