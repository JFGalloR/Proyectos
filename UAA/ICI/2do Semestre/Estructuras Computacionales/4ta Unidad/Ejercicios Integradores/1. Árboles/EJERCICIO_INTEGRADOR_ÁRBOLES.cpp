/*===========================================================================================================
	EJERCICIO INTEGRADOR UNIDAD IV. Arboles.
  ---------------------------------------------------------------------------------------------------------
	� OBJETIVO:
		Implementar las siguientes operaciones con ABB en un men�, tomando referencia lo revisado en las 
		sesiones de trabajo:
			1. Buscar un elemento.
			2. Insertar un elemento.
			3. Borrar un elemento.
			4. Movimientos a trav�s del �rbol seleccionar uno (inorden, postorden, preorden):
				> Izquierda.
				> Derecha.
				> Ra�z.
		    5. Informaci�n:
				> Comprobar si un �rbol est� vac�o.
				> Calcular el n�mero de nodos.
				> Comprobar si el nodo es hoja.
				> Calcular la altura de un nodo.
				> Calcular la altura de un �rbol.
  ---------------------------------------------------------------------------------------------------------
    � ELABORADORES:
	 - Alejandro Castillo Mota
 	 - Luis Manuel Flores Jim�nez
	 - Juan Francisco Gallo Ram�rez
  ---------------------------------------------------------------------------------------------------------
	18 de Mayo de 2023
	I.C.I. U.A.A.
===========================================================================================================*/
#include <conio.h>
#include <cctype>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Constantes que representan s�mbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la funci�n 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
const int LEN = 100;

//===================================================== ESTRUCTURA PARA LOS NODOS DEL �RBOL ==================
/*-----------------------------------------------------------------------------------------------------------
	Contienen los elementos de cada nodo del �rbol binario.
  ---------------------------------------------------------------------------------------------------------*/
struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
}*arbol = NULL;
// Aqu� establecemos nuestro �rbol.

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

//====================================================== FUNCI�N DE APOYO PARA POSICIONAMIENTO DE CURSOR =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a posicionar el cursor a trav�s de la consola de ejecuci�n.
  ---------------------------------------------------------------------------------------------------------*/
void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

//========================================================================= FUNCI�N PARA CREAR UN NODO =======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos crea el espacio donde se guarda el nodo.
  ---------------------------------------------------------------------------------------------------------*/
Nodo *crearNodo(int n, Nodo *padre)
{
	Nodo *nuevo_nodo;
	nuevo_nodo = new Nodo(); //Creamos y asignamos espacio en memoria
	//Rellenar campos
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	//Retornamos el nodo
	return nuevo_nodo;
}

//======================================================================= FUNCI�N PARA ALTURRA DEL NODO ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos clacula la altura del nodo. Tambi�n nos es �til para saber si un nodo se encuentra en 
	el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
int alturaNodo(int dato)
{
	// Se establecen las variables necesarias.
	int altura = 0;
	Nodo *nodo = arbol;
	
	// Mientras que el nodo exista se realizar�...
	while(nodo != NULL)
	{
		if(dato == nodo->dato)
		{
			// Si el dato ingresado coincide con alguno del �rbol se retorna el valor de la altura.
			return altura;
		}
		else
		{
			// Se incrementa la altura.
			altura++;
			if(dato < nodo->dato)
			{
				// Se le asigna al nodo el valore izquierda si es menor al dato evaluado.
				nodo = nodo->izq;
			}
			else
			if(dato > nodo->dato)
			{
				// Se le asigna al nodo el valor derecho si es mayor al dato evaluado.
				nodo = nodo->der;
			}
		}
	}
	// Se retorna 1 en caso de no encontrar ninguna coincidencia.
	return -1;
}

//======================================================================= FUNCI�N PARA ALTURA DEL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos calcula la altura del �rbol.
  ---------------------------------------------------------------------------------------------------------*/
int alturaArbol(Nodo *arbol)
{
	// Si el �rbol no tiene elementos se retorna 0.
    if (arbol == NULL) 
	{
        return 0;
    }
	
	// La altura del lado izquierdo es la funci�n misma.
    int alturaIzquierda = alturaArbol(arbol->izq);
    // La altura del lado derecho es la funci�n misma.
    int alturaDerecha = alturaArbol(arbol->der);

	// Finalmente se calcula el tama�o mayor de esas dos alturas.
    return max(alturaIzquierda, alturaDerecha) + 1;
}

//============================================================================ FUNCI�N MOSTRAR EL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos calcula la altura del �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void mostrarArbol(Nodo *nodo, string prefijo, bool esUltimo) 
{
	// Si el nodo actual est� vacio termina la funci�n.
	if(nodo == NULL)
	{
		return;
	}
	else
	{
		// Se imrprime el prefijo.
		color(GRIC, NEG); cout << prefijo;
		
		// Si es el �ltimo nodo se imprime la rama correspondiente.
	    if (esUltimo) 
		{
	        cout << "L--";
	        prefijo += "     ";
	    } 
		else 
		{
	        cout << "�--";
	        prefijo += "�     ";
	    }
	
		// Se imprime el nodo.
	    cout<< " ";color(GRIC, AZU); cout<<nodo->dato<<endl;
		
		// Si el nodo izquierdo existe se llama a la funci�n.
	    if (nodo->izq != NULL) 
		{
	        mostrarArbol(nodo->izq, prefijo, nodo->der == NULL);
	    }
		
		// Si el nodo derecho existe se llama a la funci�n.
	    if (nodo->der != NULL) 
		{
	        mostrarArbol(nodo->der, prefijo, true);
	    }
	}
	    
}

//========================================================================== FUNCI�N BUSCAR EN EL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos busca en el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void buscar()
{
	// Se establecen las variables necesarias.
	string aux;
	bool error = false;
	
	// Ciclo para validar entrada.
	do
	{
		error = false;
		system("cls");
		color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Buscar elemento."<<endl<<endl;
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento a buscar: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, aux);
		// Se valida el string ingresado.
		if(!validarNum(aux))
		{
			// Si no es un n�mero se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA S�LO NUMEROS # # #";
			getch();
			error = true;
		}
		else
		{
			// Se valida que est� dentro del rango de n�meros.
			if(stoi(aux) > 99 || stoi(aux) < 0)
			{
				// Si no es un n�mero se imprime un mensaje.
				color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
				error = true;
				getch();
			}
		}
	}while(error);
	// Se imprime los resultados.
	system("cls");
	color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Buscar elemento."<<endl<<endl;
	// Mostramos el �rbol.
	mostrarArbol(arbol, "", true);
	// Calculamos la altura del nodo, ya que si tiene altura significa que se encuentra en el �rbol.
	if(alturaNodo(stoi(aux)) > -1)
	{
		color(GRIC, VER);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") SE ENCUENTRA EN EL �RBOL + + +";
	}
	else
	{
		color(GRIC, ROJ);cout<<endl<<endl<<"\t- - - EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL �RBOL - - -";
	}
	getch();
}

//=================================================================== FUNCI�N PARA INSERTAR EN EL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n para insertar un nodo en el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void insertarNodo(Nodo *&nodo, int n, Nodo *padre)
{
	// Si el nodo est� vac�o se crea el espacio para el nodo.
	if (nodo == NULL)
	{ 
		nodo = crearNodo(n, padre);
	}
	else
	{
		// Si el numero a ingresar es menor se llama a la funci�n con el puntero hacia la izquierda.
		if (n < nodo->dato)
		{
			insertarNodo(nodo->izq, n, arbol);
		}
		else
		// Si el numero a ingresar es mayor se llama a la funci�n con el puntero hacia la derecha.
		if (n > nodo->dato)
		{
			insertarNodo(nodo->der, n, arbol);
		}
	}
}

//=================================================================== FUNCI�N PARA INSERTAR EN EL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n men� para insertar en el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void insertar()
{
	// Se establecen las variables necesarias.	
	string aux;
	bool error = false;
	
	// Ciclo para validar entrada.
	do
	{
		error = false;
		system("cls");
		color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Insertar elemento."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, aux);
		if(!validarNum(aux))
		{
			// Si no es un n�mero se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA S�LO NUMEROS # # #";
			getch();
			error = true;
		}
		else
		{
			if(stoi(aux) > 99 || stoi(aux) < 0)
			{
				// Si no es un n�mero se imprime un mensaje.
				color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
				error = true;
				getch();
			}
		}
	}while(error);
	
	// Se muestran los resultados.
	system("cls");
	color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Insertar elemento."<<endl<<endl;
	// Se busca si el elemento no est� en el �rbol.
	if(alturaNodo(stoi(aux)) > -1)
	{
		// Si es as� se muestra el mensaje.
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t# # # EL ELEMENTO ("<<aux<<") YA SE ENCUENTRA EN EL �RBOL # # #";
	}
	else
	{
		// Si no se inserta en el �rbol.
		insertarNodo(arbol, stoi(aux), NULL);
		mostrarArbol(arbol, "", true);
		color(GRIC, VER);cout<<endl<<endl<<"\t+ + + ELEMENTO ("<<aux<<") INGRESADO CORRECTAMENTE + + +";
	}
	getch();
}

//=============================================================== FUNCI�N PARA ENCONTRAR EL NODO M�NIMO ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n men� para insertar en el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
Nodo* encontrarMinimo(Nodo* nodo) 
{
	// Se establecen las variables necesarias.
    Nodo* actual = nodo;
    // Mientras el lado izquierdo est� en el �rbol se recorre.
    while (actual->izq) 
	{
        actual = actual->izq;
    }
    // Devuelve la direcci�n de memoria.
    return actual;
}

//============================================================= FUNCI�N PARA ELIMINAR EL NODO DEL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n para eliminar el nodo del �rbol.
  ---------------------------------------------------------------------------------------------------------*/
Nodo* eliminarNodo(Nodo* raiz, int valor) 
{
    if (raiz == NULL) 
	{
		// Cuando la ra�z sea null se retorna el mismo espacio.
        return raiz;
    }
    if (valor < raiz->dato) 
	{
		// Si el valor a eliminar es menor a el dato de la ra�z se vuelve a llamar a la funci�n.
        raiz->izq = eliminarNodo(raiz->izq, valor);
        // Se env�a el puntero a la izquierda.
    }
    else if (valor > raiz->dato)
	{
		// Si el valor a eliminar es mayor a el dato de la ra�z se vuelve a llamar a la funci�n.
        raiz->der = eliminarNodo(raiz->der, valor);
        // Se env�a el puntero a la derecha.
    }
    else 
	{
		// Cunado se haya encontrado el nodo.
        if (raiz->izq == NULL) 
		{
			// Se elimina.
            Nodo* temp = raiz->der;
            delete raiz;
            // Se retorna el nodo a la derecha.
            return temp;
        }
        else if (raiz->der == NULL) 
		{
			// Se elimina.
            Nodo* temp = raiz->izq;
            delete raiz;
            // Se retorna el nodo a la izquierda.
            return temp;
        }
		
		// Se encuentra el m�nimo nodo y se le asigna.
        Nodo* temp = encontrarMinimo(raiz->der);
        // Se le asigna el valor.
        raiz->dato = temp->dato;
        // Se elimina el nodo derecho.
        raiz->der = eliminarNodo(raiz->der, temp->dato);
    }
    // Retornamos la ra�z.
    return raiz;
}

//===================================================================== FUNCI�N PARA BORRAR EN EL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n men� para insertar en el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void borrar()
{
	// Se establecen las variables necesarias.
	string aux;
	// Ciclo para validar la entrada.
	bool error = false;
	do
	{
		error = false;
		system("cls");
		color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Borrar elemento."<<endl<<endl;
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento a eliminar: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, aux);
		if(!validarNum(aux))
		{
			// Si no es un n�mero se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA S�LO NUMEROS # # #";
			getch();
			error = true;
		}
		else
		{
			if(stoi(aux) > 99 || stoi(aux) < 0)
			{
				// Si no es un n�mero se imprime un mensaje.
				color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
				error = true;
				getch();
			}
		}
	}while(error);
	// Se muestran los resultados.
	system("cls");
	color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Borrar elemento."<<endl<<endl;
	// Si se encuentra el nodo se elimina.
	if(alturaNodo(stoi(aux)) > -1)
	{
		// Se procede a eliminar.
		arbol = eliminarNodo(arbol, stoi(aux));
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t- - - EL ELEMENTO ("<<aux<<") SE ELIMIN� CORRECTAMENTE - - -";
	}
	else
	{
		// Caso contrario se muestra un mensaje.
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL �RBOL + + +";	
	}
	getch();
}

//==================================================================== FUNCI�N PARA ORDENAR EN PREORDEN ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n	que imprime el �rbol en manera de preorden.
  ---------------------------------------------------------------------------------------------------------*/
void preorden(Nodo *nodo)
{
	// Si nodo es NULL se termina la funci�n.
	if(nodo == NULL)
	{
		return;
	}
	else
	{
		// Se imprime el dato del nodo.
		color(GRIC, NEG);cout<<"|";color(GRIC, AZU);cout<<nodo->dato;color(GRIC, NEG);cout<<"|";
		// Primero se va a la izquierda.
		preorden(nodo->izq);
		// Despu�s a la derecha.
		preorden(nodo->der);
	}
}

//=================================================================== FUNCI�N PARA ORDENAR EN POSTORDEN ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n	que imprime el �rbol en manera de postorden.
  ---------------------------------------------------------------------------------------------------------*/
void postorden(Nodo *nodo)
{
	// Si nodo es NULL se termina la funci�n.
	if(nodo == NULL)
	{
		return;
	}
	else
	{
		// Se imrpime la parte izquierda primero.
		postorden(nodo->izq);
		// Despu�s la parte derecha.
		postorden(nodo->der);
		// Se imprime el dato del nodo.
		color(GRIC, NEG);cout<<"|";color(GRIC, AZU);cout<<nodo->dato;color(GRIC, NEG);cout<<"|";
	}
}

//===================================================================== FUNCI�N PARA ORDENAR EN INORDEN ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n	que imprime el �rbol en manera de inorden.
  ---------------------------------------------------------------------------------------------------------*/
void inorden(Nodo *nodo)
{
	// Si nodo es NULL se termina la funci�n.
	if(nodo == NULL)
	{
		return;
	}
	else
	{
		// Se imprime la parte izquierda primero.
		inorden(nodo->izq);
		// Se imprime el dato del nodo.
		color(GRIC, NEG);cout<<"|";color(GRIC, AZU);cout<<nodo->dato;color(GRIC, NEG);cout<<"|";
		// Despu�s la parte derecha.
		inorden(nodo->der);
	}
}

//=================================================================== FUNCI�N PARA INSERTAR EN EL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n men� para insertar en el �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void movimientos()
{
	// Se establecen las variables necesarias.
	string opc;
	bool error = false;
	
	// Ciclo para validar la entrada.
	do
	{
		error = true;
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimientos."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MEN� =========================================="<<endl<<endl;
		// Se muestran las opciones del men�.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Izquierda (Preorden)."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Derecha (Postorden)."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Ra�z (Inorden)."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, VER);cout<<"<< Regresar."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t======================================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opci�n: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opci�n "a".
		if(opc =="A" || opc =="a")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimiento en preorden."<<endl<<endl;
			cout<<"\t";
			// Se imrpime en preorden.
			preorden(arbol);
			getch();
		}else
		// Si se elige la opci�n "b".
		if(opc =="B" || opc =="b")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimiento en postorden."<<endl<<endl;
			cout<<"\t";
			// Se imrpime en postorden.
			postorden(arbol);
			getch();
		}else
		// Si se elige la opci�n "c".
		if(opc =="C" || opc =="c")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimiento en inorden."<<endl<<endl;
			cout<<"\t";
			// Se imrpime en inorden.
			inorden(arbol);
			getch();
		}else
		// Si se elige la opci�n "d".
		if(opc =="D" || opc =="d")
		{
			// Salimos el ciclo.
			error = false;
		}else
		// Si la opci�n no es ninguna de las anteriores salta un mensaje de "Opci�n Inv�lida". 
		{
			cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
			getch();
		}
	}while(error); // El ciclo se ejecutar� mientras la opci�n no haya sido "salir".
	
}

//============================================================= FUNCI�N PARA CONTRA LOS NODOS DEL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n men� para contar los nodos del �rbol.
  ---------------------------------------------------------------------------------------------------------*/
int contarNodos(Nodo* arbol) 
{
	// Si el �rbol es null se retorna 0.
    if (arbol == NULL)
	{
        return 0;
    }
    // Si no se retorna 1 y la misma funci�n, que calcula los nodos de la izquierda como de la derecha.
    return 1 + contarNodos(arbol->izq) + contarNodos(arbol->der);
}

//======================================================= FUNCI�N PARA MOSTRAR LA INFORMACI�N DEL �RBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Funci�n mostrar la informaci�n del �rbol.
  ---------------------------------------------------------------------------------------------------------*/
void informacion()
{
	// Se establecen las variables necesarias.
	string opc;
	bool error = false;
	
	// Ciclo para validar la entrada.
	do
	{
		error = true;
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Informaci�n."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MEN� =========================================="<<endl<<endl;
		// Se muestran las opciones del men�.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Comprobar si el �rbol est� vac�o."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Calcular n�mero de nodos del �rbol."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Comprobar si un nodo es hoja."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, NEG);cout<<"Calcular la altura de un nodo."<<endl;
		color(GRIC, ROJ);cout<<"\t\te) ";color(GRIC, NEG);cout<<"Calcular la altura del �rbol."<<endl;
		color(GRIC, ROJ);cout<<"\t\tf) ";color(GRIC, VER);cout<<"<< Regresar."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t======================================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opci�n: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opci�n "a".
		if(opc =="A" || opc =="a")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Comprobar si el �rbol est� vac�o."<<endl<<endl;
			// Si �rbol apunta a null se muestra que est� vac�o.
			if(arbol == NULL)
			{
				color(GRIC, ROJ);cout<<endl<<endl<<"\t- - - �RBOL VAC�O - - -";	
			}
			// Si no �rbol no apunta a null se muestra que no est� vac�o.
			else
			{
				color(GRIC, VER);cout<<endl<<endl<<"\t+ + + �RBOL CON ELEMENTOS + + +";	
			}
			getch();
		}else
		// Si se elige la opci�n "b".
		if(opc =="B" || opc =="b")
		{
			// Se valida que no est� vac�o.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # �RBOL SIN ELEMENTOS # # #"<<endl;
				getch();
			}
			else
			{
				// Se muestra el total de nodos del �rbol.
				system("cls");
				color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
				color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular n�mero de nodos del �rbol."<<endl<<endl;
				mostrarArbol(arbol, "", true);
				color(GRIC, NEGC);cout<<endl<<"\tEl n�mero total de nodos es de ";color(GRIC, VER);cout<<contarNodos(arbol);color(GRIC, NEGC);cout<<".";
				getch();
			}
		}else
		// Si se elige la opci�n "c".
		if(opc =="C" || opc =="c")
		{
			// Se valida que no est� vac�o.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # �RBOL SIN ELEMENTOS # # #"<<endl;
			}
			else
			{
				string aux;
				bool error_1 = false;
				// Ciclo que valida la entrada.
				do
				{
					error_1 = false;
					system("cls");
					color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Comprobar si un nodo es hoja."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa el nodo: ";
					// Se lee la opci�n a elegir.
					color(GRIC, ROJ);getline(cin, aux);
					// Se valida la entrada.
					if(!validarNum(aux))
					{
						// Si no es un n�mero se imprime un mensaje.
						color(GRIC, ROJ);cout<<"\n\t# # # INGRESA S�LO NUMEROS # # #";
						getch();
						error_1 = true;
					}
					else
					{
						if(stoi(aux) > 99 || stoi(aux) < 0)
						{
							// Si no es un n�mero se imprime un mensaje.
							color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
							error_1 = true;
							getch();
						}
					}
				}while(error_1);
				// Si el elemento que se ingres� est� en el �rbol...
				if(alturaNodo(stoi(aux)) > -1)
				{
					system("cls");
					color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Comprobar si un nodo es hoja."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					
					Nodo* nodo = arbol;
				    while (nodo != NULL) 
					{
						// Ciclo que nos permite recorrer el �rbol en busca del nodo.
				        if (stoi(aux) < nodo->dato) {
				        	
				            nodo = nodo->izq;
				        }
				        else if (stoi(aux)  > nodo->dato) 
						{
				            nodo = nodo->der;
				        }
				        else 
						{
							// Eval�a que el nodo tenga valores y que sus punteros derecho e izquierdo no apunten a nadie. 
				            color(GRIC, NEGC);cout<<endl<<"\tEl elemento " <<stoi(aux)<<" ";color(GRIC, VER);cout<< ((nodo != NULL) && (nodo->izq == NULL) && (nodo->der == NULL) ? "es una hoja" : "no es una hoja");
							color(GRIC, NEGC);cout<<"."<<endl;
				            break;
				        }
				    }
				}
				// Si no se muestra que no est� en el �rbol.
				else
				{
					color(GRIC, ROJ);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL �RBOL + + +";	
				}
			}
			getch();
		}else
		// Si se elige la opci�n "d".
		if(opc =="D" || opc =="d")
		{
			// Se valida que no est� vac�o.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # �RBOL SIN ELEMENTOS # # #"<<endl;
			}
			else
			{
				string aux;
				bool error_1 = false;
				// Ciclo para validar la entrada.
				do
				{
					error_1 = false;
					system("cls");
					color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular la altura de un nodo."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa el nodo: ";
					// Se lee la opci�n a elegir.
					color(GRIC, ROJ);getline(cin, aux);
					// Se valida la entrada.
					if(!validarNum(aux))
					{
						// Si no es un n�mero se imprime un mensaje.
						color(GRIC, ROJ);cout<<"\n\t# # # INGRESA S�LO NUMEROS # # #";
						getch();
						error_1 = true;
					}
					else
					{
						if(stoi(aux) > 99 || stoi(aux) < 0)
						{
							// Si no es un n�mero se imprime un mensaje.
							color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
							error_1 = true;
							getch();
						}
					}
				}while(error_1);
				// Si el nodo seencuenttra en el �rbol...
				if(alturaNodo(stoi(aux)) > -1)
				{
					system("cls");
					color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular la altura de un nodo."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					// Se calcula la altura del nodo.
					color(GRIC, NEGC);cout<<endl<<"\tLa altura del nodo es de ";color(GRIC, VER);cout<<alturaNodo(stoi(aux));color(GRIC, NEGC);cout<<".";
				}
				// Sino se muestra el mensaje.
				else
				{
					color(GRIC, ROJ);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL �RBOL + + +";	
				}
			}
			getch();
		}else
		// Si se elige la opci�n "e".
		if(opc =="E" || opc =="e")
		{
			// Se valida que no est� vac�o.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # �RBOL SIN ELEMENTOS # # #"<<endl;
				getch();
			}
			else
			{
				// Se calcula la altura del �rbol.
				system("cls");
				color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
				color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular la altura del �rbol."<<endl<<endl;
				mostrarArbol(arbol, "", true);
				color(GRIC, NEGC);cout<<endl<<"\tLa altura del arbol es de ";color(GRIC, VER);cout<<alturaArbol(arbol);color(GRIC, NEGC);cout<<".";
				getch();
			}
		}else
		// Si se elige la opci�n "f".
		if(opc =="F" || opc =="f")
		{
			// Salimos del ciclo.
			error = false;
		}else
		// Si la opci�n no es ninguna de las anteriores salta un mensaje de "Opci�n Inv�lida". 
		{
			cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
			getch();
		}
	}while(error); // El ciclo se ejecutar� mientras la opci�n no haya sido "salir".
	
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCI�N PRINCIPAL =====
main()
{
	// Variable del tipo 'string' que almacena nuestra opci�n.
	string opc;
	int dato;
	
	// Se llama a la funcion para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Ciclo para el men� de ejecuci�n.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                      �RBOL BINARIO DE B�SQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MEN� =========================================="<<endl<<endl;
		// Se muestran las opciones del men�.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Buscar un elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Insertar un elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Borrar un elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, NEG);cout<<"Movimientos a trav�s del �rbol."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Izquierda."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Derecha."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Ra�z."<<endl;
		color(GRIC, ROJ);cout<<"\t\te) ";color(GRIC, NEG);cout<<"Informaci�n."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Comprobar si el �rbol est� vac�o."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Calcular n�mero de nodos del �rbol."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Comprobar si un nodo es hoja."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Calcular la altura de un nodo."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Calcular la altura del �rbol."<<endl;
		color(GRIC, ROJ);cout<<"\t\tf) <- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t======================================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opci�n: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		if(arbol==NULL && (opc =="A" || opc =="a" || opc =="C" || opc =="c"|| opc =="D" || opc =="d"))
		{
			// Si el �rbol es nulo y se eligen las opciones que involucren los datos del mismo se muestra un mensaje.
			color(GRIC,ROJ);cout<<"\n\t# # # �RBOL SIN ELEMENTOS # # #"<<endl;
			getch();
		}
		else// Caso contraio:
		{
			// Si se elige la opci�n "a".
			if(opc =="A" || opc =="a")
			{
				buscar();
			}else
			// Si se elige la opci�n "b".
			if(opc =="B" || opc =="b")
			{
				insertar();
			}else
			// Si se elige la opci�n "c".
			if(opc =="C" || opc =="c")
			{
				borrar();
			}else
			// Si se elige la opci�n "d".
			if(opc =="D" || opc =="d")
			{
				movimientos();
			}else
			// Si se elige la opci�n "e".
			if(opc =="E" || opc =="e")
			{
				informacion();
			}else
			// Si se elige la opci�n "f".
			if(opc =="F" || opc =="f")
			{
				// Se muestra el mensaje de ejecuci�n finalizada.
				color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
			}else
			// Si la opci�n no es ninguna de las anteriores salta un mensaje de "Opci�n Inv�lida". 
			{
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
				getch();
			}
		}		
	}while(opc !="F" && opc !="f"); // El ciclo se ejecutar� mientras la opci�n no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}












