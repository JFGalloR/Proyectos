/*===========================================================================================================
	EJERCICIO INTEGRADOR UNIDAD III. Evaluaci�n se Notaci�n de Prefijo.
  ---------------------------------------------------------------------------------------------------------
	� OBJETIVO:
		Realizar un algoritmo para la evaluaci�n de expresi�n de Notaci�n de Prefijo implementado 
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
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

// Constantes que representan s�mbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la funci�n 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;


//========================================================= ESTRUCTURA PARA LOS NODOS DE LA PILA =============
/*-----------------------------------------------------------------------------------------------------------
	Contienen los elementos de cada nodo para realizar una PILA que almacena s�lo n�meros.
  ---------------------------------------------------------------------------------------------------------*/
struct Nodo
{
	float valor;
	Nodo *anterior;
};

//=============================================== ESTRUCTURA PARA LOS NODOS DE LA LISTA DE VARIABLES =========
/*-----------------------------------------------------------------------------------------------------------
	Contienen los elementos de cada nodo para realizar una LISTA que almacena las variables y sus valores.
	Nos es �til para comparar con la cadena y as� a�adir solo n�mero a la PILA para evaluarlos.
  ---------------------------------------------------------------------------------------------------------*/
struct Valor
{
	char dato;
	float valor;
	Valor *anterior;
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
	Funci�n que nos ayuda a insertar un nodo en la estructura PILA s�lo recibe valores flotantes.
  ---------------------------------------------------------------------------------------------------------*/
void push(Nodo *&pila, Valor *&inicio, char dato)
{
	bool encontrado = false;
	// Establecemos las variables necesarias.
	Valor *aux = inicio;
	// Se crea espacio para un nuevo nodo.
	Nodo *nodo = new Nodo;
	
	if(pila==NULL)
	{
		// Si es el primer elemento, "pila" se enlazar� a NULL.
		nodo->anterior = NULL;
	}else
	{
		// Si no es el primer elemento, simplemente lo enlazamos al anterior.
		nodo->anterior = pila;
	}
	// Se busca entre nuestra lista de variables el caracter, para as� su valor agregar a la pila.
	while(!encontrado)
	{
		// Se evalu� si se ha encontrado.
		if(dato == aux->dato)
		{
			// Se le asigna el valor a la pila.
			nodo->valor = aux->valor;
			encontrado = true;
		}
		aux = aux->anterior;
	}
	pila = nodo;
}

//================================================================= FUNCI�N PARA INSERTAR EN PILA "Push" =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a insertar un nodo en la estructura PILA, sin embargo esta no busca entre las
	variables el valor, ya que es otorgado entre los par�metros.
  ---------------------------------------------------------------------------------------------------------*/
void push_res(Nodo *&pila, float valor)
{
	bool encontrado = false;
	// Se crea espacio para un nuevo nodo.
	Nodo *nodo = new Nodo;
	
	if(pila==NULL)
	{
		// Si es el primer elemento, "pila" se enlazar� a NULL.
		nodo->anterior = NULL;
	}else
	{
		// Si no es el primer elemento, simplemente lo enlazamos al anterior.
		nodo->anterior = pila;
	}
	// Se asigna a la pila el valor otorgado.
	nodo->valor = valor;
	pila = nodo;
}

//================================================================= FUNCI�N PARA INSERTAR EN PILA "Push" =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a insertar un nodo en la estructura PILA.
  ---------------------------------------------------------------------------------------------------------*/
void push_valores(Valor *&inicio, char dato, float valor)
{
	Valor *literal = new Valor;
	// Una vez asignado el espacio enlazamos el nodo en la cima de la pila, en este caso llamada "pila".
	if(inicio==NULL)
	{
		// Si es el primer elemento, "pila" se enlazar� a NULL.
		literal->anterior = NULL;
	}else
	{
		// Si no es el primer elemento, simplemente lo enlazamos al anterior.
		literal->anterior = inicio;
	}
	// Asignamos el caracter a nuestro nodo.
	literal->dato = dato;
	literal->valor = valor;
	// Pila ahora apunta al reci�n nodo agregado.
	inicio = literal;
}

//================================================================== FUNCI�N PARA ELIMINAR DE PILA "Pop" =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a eliminar un nodo de la estructura PILA.
  ---------------------------------------------------------------------------------------------------------*/
float pop(Nodo *&pila, Valor *&inicio)
{
	Valor *variable = inicio;
	Nodo *aux = pila;
	float valor;
	// Pila se apunta el nodo anterior.
	pila = aux->anterior;
	// Se guarda el valor del nodo en la variable a retornar.
	valor = aux->valor;
	// Se borra el nodo que apunta "aux".
	delete aux;
	// Se retorna el valor para operar con �l.
	return valor;
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

//========================================================================= FUNCI�N PARA VALIDAR N�MEROS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a validar si un string es num�rico.
  ---------------------------------------------------------------------------------------------------------*/
int validacionNum(string cad) 
{
	// Recorre el string.
    for(int i = 0; i < cad.size(); i++)
    {
    	if(!isdigit(cad[i]))
    	{
    		// Si un caracter no es n�merico retorna "falso".
    		return 0;
		}
		// Si toda la cadena es num�rica retorna "verdadero".
		return 1;
	}
}

//======================================================================== FUNCI�N CONVERSORA A FLOTANTE =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos convierte a flotante un string.
  ---------------------------------------------------------------------------------------------------------*/
float numFlotante(string cad) 
{
	float num;
	char aux[cad.size()];
	
	// Se recoore la cadena.
	for(int i = 0; i < cad.size(); i++)
    {
    	// Se le asigna cada caracter de la variable tipo 'string' a una cadena de caracteres.
    	aux[i] = cad[i];
    	// Es necesaria la asignaci�n porque "atof()" no recibe variables 'string', s�lo array de caracteres.
	}
	// Se retorna la conversi�n de cadena de caracteres a string.
	return atof(aux);;
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

//============================================ FUNCI�N PARA ASIGNAR VALORES A NUESTRA LISTA DE VARIABLES =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos asigna a la lista un nodo con la literal de la expresi�n adem�s de su valor.
  ---------------------------------------------------------------------------------------------------------*/
void asignacion(string exp, Valor *&inicio)
{
	bool rep = false;
	string aux;
	Valor *ax = inicio;
	
	// Se recorre toda la cadena.
	for(int i = 0; i < exp.size(); i++)
	{
		// Se inizializa la lista de variables.
		ax = inicio;
		// Consicional que se cumple si el d�gito es una letra.
		if(isalpha(exp[i]))
		{
			rep = false;
			// Buscamos si ya est� en nuestra lista el caracter.
			while(ax != NULL && !rep)
			{
				if(exp[i] == ax->dato)
				{
					// Si hay repetido "rep" se vuelve verdadero.
					rep = true;
				}
				ax = ax->anterior;
			}
			// Si no hay repetidos se ejecuta la asgnaci�n.
			if(!rep)
			{
				bool error = false;
				// Ciclo que nos ayuda a validar la entrada num�rica.
				do
				{
					error = false;
					system("cls");
					color(ROJ, GRIC);cout<<"                                       EVALUACI�N (Prefijo)                                       "<<endl<<endl<<endl;
					color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa valor de ";color(GRIC, VER);cout<<exp[i];color(GRIC, NEG);cout<<": ";
					color(GRIC, ROJ);
					// Pedimos el valor de la literal.
					getline(cin, aux);
					// validamos que sea n�mero.
					if(validacionNum(aux))
					{
						push_valores(inicio, exp[i], numFlotante(aux));
					}
					// Si no lo �s se imprime el mensaje y "error" se vuelve verdadero.
					else
					{
						color(GRIC, ROJ);cout<<endl<<"\t# # # D�GITO INV�LIDO # # #";
						error = true;
						getch();
					}
				}while(error);
			}
		}
	}
}

//========================================================== FUNCI�N PARA EVALUAR LA EXPRESI�N A PREFIJO =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos hace el proceso de evaluaci�n de la expresi�n en prefijo.
  ---------------------------------------------------------------------------------------------------------*/
void evaluacion(Nodo *&pila, Valor *&inicio, string &exp)
{
	float res;
	// Se recorre toda la expresi�n ingresada por el usuario de final a inicio.
	for(int i = exp.size() - 1; i >=0; i--)
	{
		// Si el caracter es distinto al caracter de espacio entonces hacer el proceso requerido.
		if(exp[i] != ' ')
		{
			if(isalpha(exp[i]))
			{
				// Si se trata de una variable entoces la a�adimos a la pila.
				push(pila, inicio, exp[i]);
			}else
			{
				// Cuando es un operador de saca de la pila y el valor retornado se asigna a una variable.
				float a = pop(pila, inicio);
				float b = pop(pila, inicio);
				// Seg�n el operador se realiza la operaci�n correspondiente y se asigna a resultado.
				switch(exp[i])
				{
					case '+': // Suma
						res = a + b;
						break;
					case '-': // Resta
						res = a - b;
						break;
					case '*': // Multiplicaci�n
						res = a * b;
						break;
					case '/': // Divisi�n
						res = a / b;
						break;
					case '^': // Potencia
						res = pow(a, b);
						break;
				}
				// Se ingresa el resultado a la pila.
				push_res(pila, res);
			}
		}
	}
}

//================================================================== FUNCI�N PARA ELIMINAR TODA LA LISTA =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos elimina cada nodo de la estructura, esta es especial para pila.
  ---------------------------------------------------------------------------------------------------------*/
void eliminarLista1(Nodo *&pila)
{
	Nodo *aux=pila;
	
	// Se recorre roda la lista y se eliminar cada nodo.
	while(pila != NULL)
	{
		aux=pila->anterior;
		delete pila;
		pila = aux;
	}

}

//================================================================== FUNCI�N PARA ELIMINAR TODA LA LISTA =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos elimina cada nodo de la estructura, esta es especial para la lista de variables.
  ---------------------------------------------------------------------------------------------------------*/
void eliminarLista2(Valor *&inicio)
{
	Valor *aux=inicio;
	
	// Se recorre roda la lista y se eliminar cada nodo.
	while(inicio != NULL)
	{
		aux=inicio->anterior;
		delete inicio;
		inicio = aux;
	}

}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCI�N PRINCIPAL =====
main()
{
	Nodo *pila = NULL;
	Valor *inicio = NULL;
	string exp = "";
	setlocale(LC_ALL, "");
	system("color F0");
	
	// Ciclo para el men� de ejecuci�n.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                       EVALUACI�N (Prefijo)                                       "<<endl<<endl<<endl;
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
				// Se ejecuta la funci�n para pedir el valor de las variables.
				asignacion(exp, inicio);
				// Se ejecuta la evaluaci�n de la expresi�n.
				evaluacion(pila, inicio, exp);
				system("cls");
				color(ROJ, GRIC);cout<<"                                       EVALUACI�N (Prefijo)                                       "<<endl<<endl<<endl;
				// Se imprime la expresi�n en infijo sin espacios.
				color(GRIC, ROJ);cout<<endl<<"\t==== PREFIJO    ===================================="<<endl<<endl;
				color(GRIC, NEG);cout<<"\t     ";
				for(int i = 0; i < exp.size(); i++)
				{
					// Si es distinto a espacio se imprime el caracter, sino no se imprime nada.
					if(exp[i] != ' ')
					{
						cout<<exp[i];
					}
				}
				// Se imprime el resultado.
				color(GRIC, ROJ);cout<<endl<<endl<<"\t==== RESULTADO ====================================="<<endl<<endl;
				color(GRIC, VER);cout<<"\t     "<<pila->valor;
				color(GRIC, AMA);cout<<endl<<endl<<endl<<"\t "<<C<<" EVALUACI�N REALIZADA "<<C<<"  ";
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
		eliminarLista1(pila);
		eliminarLista2(inicio);
		getch();
	}while(cadMayus(exp) != "SALIR"); // El ciclo se ejecutar� mientrasno se haya ingresado "salir".
	
	// FIN DEL PROGRAMA.
}


