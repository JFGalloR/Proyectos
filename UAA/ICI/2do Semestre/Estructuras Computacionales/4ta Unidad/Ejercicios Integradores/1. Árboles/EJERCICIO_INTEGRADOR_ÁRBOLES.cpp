/*===========================================================================================================
	EJERCICIO INTEGRADOR UNIDAD IV. Arboles.
  ---------------------------------------------------------------------------------------------------------
	• OBJETIVO:
		Implementar las siguientes operaciones con ABB en un menú, tomando referencia lo revisado en las 
		sesiones de trabajo:
			1. Buscar un elemento.
			2. Insertar un elemento.
			3. Borrar un elemento.
			4. Movimientos a través del árbol seleccionar uno (inorden, postorden, preorden):
				> Izquierda.
				> Derecha.
				> Raíz.
		    5. Información:
				> Comprobar si un árbol está vacío.
				> Calcular el número de nodos.
				> Comprobar si el nodo es hoja.
				> Calcular la altura de un nodo.
				> Calcular la altura de un árbol.
  ---------------------------------------------------------------------------------------------------------
    • ELABORADORES:
	 - Alejandro Castillo Mota
 	 - Luis Manuel Flores Jiménez
	 - Juan Francisco Gallo Ramírez
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

// Constantes que representan símbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la función 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;
const int LEN = 100;

//===================================================== ESTRUCTURA PARA LOS NODOS DEL ÁRBOL ==================
/*-----------------------------------------------------------------------------------------------------------
	Contienen los elementos de cada nodo del árbol binario.
  ---------------------------------------------------------------------------------------------------------*/
struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
}*arbol = NULL;
// Aquí establecemos nuestro árbol.

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

//====================================================== FUNCIÓN DE APOYO PARA POSICIONAMIENTO DE CURSOR =====
/*-----------------------------------------------------------------------------------------------------------
	Función que nos ayuda a posicionar el cursor a través de la consola de ejecución.
  ---------------------------------------------------------------------------------------------------------*/
void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

//========================================================================= FUNCIÓN PARA CREAR UN NODO =======
/*-----------------------------------------------------------------------------------------------------------
	Función que nos crea el espacio donde se guarda el nodo.
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

//======================================================================= FUNCIÓN PARA ALTURRA DEL NODO ======
/*-----------------------------------------------------------------------------------------------------------
	Función que nos clacula la altura del nodo. También nos es útil para saber si un nodo se encuentra en 
	el árbol.
  ---------------------------------------------------------------------------------------------------------*/
int alturaNodo(int dato)
{
	// Se establecen las variables necesarias.
	int altura = 0;
	Nodo *nodo = arbol;
	
	// Mientras que el nodo exista se realizará...
	while(nodo != NULL)
	{
		if(dato == nodo->dato)
		{
			// Si el dato ingresado coincide con alguno del árbol se retorna el valor de la altura.
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

//======================================================================= FUNCIÓN PARA ALTURA DEL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función que nos calcula la altura del árbol.
  ---------------------------------------------------------------------------------------------------------*/
int alturaArbol(Nodo *arbol)
{
	// Si el árbol no tiene elementos se retorna 0.
    if (arbol == NULL) 
	{
        return 0;
    }
	
	// La altura del lado izquierdo es la función misma.
    int alturaIzquierda = alturaArbol(arbol->izq);
    // La altura del lado derecho es la función misma.
    int alturaDerecha = alturaArbol(arbol->der);

	// Finalmente se calcula el tamaño mayor de esas dos alturas.
    return max(alturaIzquierda, alturaDerecha) + 1;
}

//============================================================================ FUNCIÓN MOSTRAR EL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función que nos calcula la altura del árbol.
  ---------------------------------------------------------------------------------------------------------*/
void mostrarArbol(Nodo *nodo, string prefijo, bool esUltimo) 
{
	// Si el nodo actual está vacio termina la función.
	if(nodo == NULL)
	{
		return;
	}
	else
	{
		// Se imrprime el prefijo.
		color(GRIC, NEG); cout << prefijo;
		
		// Si es el último nodo se imprime la rama correspondiente.
	    if (esUltimo) 
		{
	        cout << "L--";
	        prefijo += "     ";
	    } 
		else 
		{
	        cout << "¦--";
	        prefijo += "¦     ";
	    }
	
		// Se imprime el nodo.
	    cout<< " ";color(GRIC, AZU); cout<<nodo->dato<<endl;
		
		// Si el nodo izquierdo existe se llama a la función.
	    if (nodo->izq != NULL) 
		{
	        mostrarArbol(nodo->izq, prefijo, nodo->der == NULL);
	    }
		
		// Si el nodo derecho existe se llama a la función.
	    if (nodo->der != NULL) 
		{
	        mostrarArbol(nodo->der, prefijo, true);
	    }
	}
	    
}

//========================================================================== FUNCIÓN BUSCAR EN EL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función que nos busca en el árbol.
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
		color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Buscar elemento."<<endl<<endl;
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento a buscar: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, aux);
		// Se valida el string ingresado.
		if(!validarNum(aux))
		{
			// Si no es un número se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
			getch();
			error = true;
		}
		else
		{
			// Se valida que esté dentro del rango de números.
			if(stoi(aux) > 99 || stoi(aux) < 0)
			{
				// Si no es un número se imprime un mensaje.
				color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
				error = true;
				getch();
			}
		}
	}while(error);
	// Se imprime los resultados.
	system("cls");
	color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Buscar elemento."<<endl<<endl;
	// Mostramos el árbol.
	mostrarArbol(arbol, "", true);
	// Calculamos la altura del nodo, ya que si tiene altura significa que se encuentra en el árbol.
	if(alturaNodo(stoi(aux)) > -1)
	{
		color(GRIC, VER);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") SE ENCUENTRA EN EL ÁRBOL + + +";
	}
	else
	{
		color(GRIC, ROJ);cout<<endl<<endl<<"\t- - - EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL ÁRBOL - - -";
	}
	getch();
}

//=================================================================== FUNCIÓN PARA INSERTAR EN EL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función para insertar un nodo en el árbol.
  ---------------------------------------------------------------------------------------------------------*/
void insertarNodo(Nodo *&nodo, int n, Nodo *padre)
{
	// Si el nodo está vacío se crea el espacio para el nodo.
	if (nodo == NULL)
	{ 
		nodo = crearNodo(n, padre);
	}
	else
	{
		// Si el numero a ingresar es menor se llama a la función con el puntero hacia la izquierda.
		if (n < nodo->dato)
		{
			insertarNodo(nodo->izq, n, arbol);
		}
		else
		// Si el numero a ingresar es mayor se llama a la función con el puntero hacia la derecha.
		if (n > nodo->dato)
		{
			insertarNodo(nodo->der, n, arbol);
		}
	}
}

//=================================================================== FUNCIÓN PARA INSERTAR EN EL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función menú para insertar en el árbol.
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
		color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Insertar elemento."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, aux);
		if(!validarNum(aux))
		{
			// Si no es un número se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
			getch();
			error = true;
		}
		else
		{
			if(stoi(aux) > 99 || stoi(aux) < 0)
			{
				// Si no es un número se imprime un mensaje.
				color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
				error = true;
				getch();
			}
		}
	}while(error);
	
	// Se muestran los resultados.
	system("cls");
	color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Insertar elemento."<<endl<<endl;
	// Se busca si el elemento no esté en el árbol.
	if(alturaNodo(stoi(aux)) > -1)
	{
		// Si es así se muestra el mensaje.
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t# # # EL ELEMENTO ("<<aux<<") YA SE ENCUENTRA EN EL ÁRBOL # # #";
	}
	else
	{
		// Si no se inserta en el árbol.
		insertarNodo(arbol, stoi(aux), NULL);
		mostrarArbol(arbol, "", true);
		color(GRIC, VER);cout<<endl<<endl<<"\t+ + + ELEMENTO ("<<aux<<") INGRESADO CORRECTAMENTE + + +";
	}
	getch();
}

//=============================================================== FUNCIÓN PARA ENCONTRAR EL NODO MÍNIMO ======
/*-----------------------------------------------------------------------------------------------------------
	Función menú para insertar en el árbol.
  ---------------------------------------------------------------------------------------------------------*/
Nodo* encontrarMinimo(Nodo* nodo) 
{
	// Se establecen las variables necesarias.
    Nodo* actual = nodo;
    // Mientras el lado izquierdo esté en el árbol se recorre.
    while (actual->izq) 
	{
        actual = actual->izq;
    }
    // Devuelve la dirección de memoria.
    return actual;
}

//============================================================= FUNCIÓN PARA ELIMINAR EL NODO DEL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función para eliminar el nodo del árbol.
  ---------------------------------------------------------------------------------------------------------*/
Nodo* eliminarNodo(Nodo* raiz, int valor) 
{
    if (raiz == NULL) 
	{
		// Cuando la raíz sea null se retorna el mismo espacio.
        return raiz;
    }
    if (valor < raiz->dato) 
	{
		// Si el valor a eliminar es menor a el dato de la raíz se vuelve a llamar a la función.
        raiz->izq = eliminarNodo(raiz->izq, valor);
        // Se envía el puntero a la izquierda.
    }
    else if (valor > raiz->dato)
	{
		// Si el valor a eliminar es mayor a el dato de la raíz se vuelve a llamar a la función.
        raiz->der = eliminarNodo(raiz->der, valor);
        // Se envía el puntero a la derecha.
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
		
		// Se encuentra el mínimo nodo y se le asigna.
        Nodo* temp = encontrarMinimo(raiz->der);
        // Se le asigna el valor.
        raiz->dato = temp->dato;
        // Se elimina el nodo derecho.
        raiz->der = eliminarNodo(raiz->der, temp->dato);
    }
    // Retornamos la raíz.
    return raiz;
}

//===================================================================== FUNCIÓN PARA BORRAR EN EL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función menú para insertar en el árbol.
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
		color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Borrar elemento."<<endl<<endl;
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa elemento a eliminar: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, aux);
		if(!validarNum(aux))
		{
			// Si no es un número se imprime un mensaje.
			color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
			getch();
			error = true;
		}
		else
		{
			if(stoi(aux) > 99 || stoi(aux) < 0)
			{
				// Si no es un número se imprime un mensaje.
				color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
				error = true;
				getch();
			}
		}
	}while(error);
	// Se muestran los resultados.
	system("cls");
	color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Borrar elemento."<<endl<<endl;
	// Si se encuentra el nodo se elimina.
	if(alturaNodo(stoi(aux)) > -1)
	{
		// Se procede a eliminar.
		arbol = eliminarNodo(arbol, stoi(aux));
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t- - - EL ELEMENTO ("<<aux<<") SE ELIMINÓ CORRECTAMENTE - - -";
	}
	else
	{
		// Caso contrario se muestra un mensaje.
		mostrarArbol(arbol, "", true);
		color(GRIC, ROJ);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL ÁRBOL + + +";	
	}
	getch();
}

//==================================================================== FUNCIÓN PARA ORDENAR EN PREORDEN ======
/*-----------------------------------------------------------------------------------------------------------
	Función	que imprime el árbol en manera de preorden.
  ---------------------------------------------------------------------------------------------------------*/
void preorden(Nodo *nodo)
{
	// Si nodo es NULL se termina la función.
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
		// Después a la derecha.
		preorden(nodo->der);
	}
}

//=================================================================== FUNCIÓN PARA ORDENAR EN POSTORDEN ======
/*-----------------------------------------------------------------------------------------------------------
	Función	que imprime el árbol en manera de postorden.
  ---------------------------------------------------------------------------------------------------------*/
void postorden(Nodo *nodo)
{
	// Si nodo es NULL se termina la función.
	if(nodo == NULL)
	{
		return;
	}
	else
	{
		// Se imrpime la parte izquierda primero.
		postorden(nodo->izq);
		// Después la parte derecha.
		postorden(nodo->der);
		// Se imprime el dato del nodo.
		color(GRIC, NEG);cout<<"|";color(GRIC, AZU);cout<<nodo->dato;color(GRIC, NEG);cout<<"|";
	}
}

//===================================================================== FUNCIÓN PARA ORDENAR EN INORDEN ======
/*-----------------------------------------------------------------------------------------------------------
	Función	que imprime el árbol en manera de inorden.
  ---------------------------------------------------------------------------------------------------------*/
void inorden(Nodo *nodo)
{
	// Si nodo es NULL se termina la función.
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
		// Después la parte derecha.
		inorden(nodo->der);
	}
}

//=================================================================== FUNCIÓN PARA INSERTAR EN EL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función menú para insertar en el árbol.
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
		color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimientos."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MENÚ =========================================="<<endl<<endl;
		// Se muestran las opciones del menú.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Izquierda (Preorden)."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Derecha (Postorden)."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Raíz (Inorden)."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, VER);cout<<"<< Regresar."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t======================================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opción: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opción "a".
		if(opc =="A" || opc =="a")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimiento en preorden."<<endl<<endl;
			cout<<"\t";
			// Se imrpime en preorden.
			preorden(arbol);
			getch();
		}else
		// Si se elige la opción "b".
		if(opc =="B" || opc =="b")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimiento en postorden."<<endl<<endl;
			cout<<"\t";
			// Se imrpime en postorden.
			postorden(arbol);
			getch();
		}else
		// Si se elige la opción "c".
		if(opc =="C" || opc =="c")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Movimiento en inorden."<<endl<<endl;
			cout<<"\t";
			// Se imrpime en inorden.
			inorden(arbol);
			getch();
		}else
		// Si se elige la opción "d".
		if(opc =="D" || opc =="d")
		{
			// Salimos el ciclo.
			error = false;
		}else
		// Si la opción no es ninguna de las anteriores salta un mensaje de "Opción Inválida". 
		{
			cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
			getch();
		}
	}while(error); // El ciclo se ejecutará mientras la opción no haya sido "salir".
	
}

//============================================================= FUNCIÓN PARA CONTRA LOS NODOS DEL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función menú para contar los nodos del árbol.
  ---------------------------------------------------------------------------------------------------------*/
int contarNodos(Nodo* arbol) 
{
	// Si el árbol es null se retorna 0.
    if (arbol == NULL)
	{
        return 0;
    }
    // Si no se retorna 1 y la misma función, que calcula los nodos de la izquierda como de la derecha.
    return 1 + contarNodos(arbol->izq) + contarNodos(arbol->der);
}

//======================================================= FUNCIÓN PARA MOSTRAR LA INFORMACIÓN DEL ÁRBOL ======
/*-----------------------------------------------------------------------------------------------------------
	Función mostrar la información del árbol.
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
		color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Información."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MENÚ =========================================="<<endl<<endl;
		// Se muestran las opciones del menú.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Comprobar si el árbol está vacío."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Calcular número de nodos del árbol."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Comprobar si un nodo es hoja."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, NEG);cout<<"Calcular la altura de un nodo."<<endl;
		color(GRIC, ROJ);cout<<"\t\te) ";color(GRIC, NEG);cout<<"Calcular la altura del árbol."<<endl;
		color(GRIC, ROJ);cout<<"\t\tf) ";color(GRIC, VER);cout<<"<< Regresar."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t======================================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opción: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		// Si se elige la opción "a".
		if(opc =="A" || opc =="a")
		{
			system("cls");
			color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
			color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Comprobar si el árbol está vacío."<<endl<<endl;
			// Si árbol apunta a null se muestra que está vacío.
			if(arbol == NULL)
			{
				color(GRIC, ROJ);cout<<endl<<endl<<"\t- - - ÁRBOL VACÍO - - -";	
			}
			// Si no árbol no apunta a null se muestra que no está vacío.
			else
			{
				color(GRIC, VER);cout<<endl<<endl<<"\t+ + + ÁRBOL CON ELEMENTOS + + +";	
			}
			getch();
		}else
		// Si se elige la opción "b".
		if(opc =="B" || opc =="b")
		{
			// Se valida que no esté vacío.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # ÁRBOL SIN ELEMENTOS # # #"<<endl;
				getch();
			}
			else
			{
				// Se muestra el total de nodos del árbol.
				system("cls");
				color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
				color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular número de nodos del árbol."<<endl<<endl;
				mostrarArbol(arbol, "", true);
				color(GRIC, NEGC);cout<<endl<<"\tEl número total de nodos es de ";color(GRIC, VER);cout<<contarNodos(arbol);color(GRIC, NEGC);cout<<".";
				getch();
			}
		}else
		// Si se elige la opción "c".
		if(opc =="C" || opc =="c")
		{
			// Se valida que no esté vacío.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # ÁRBOL SIN ELEMENTOS # # #"<<endl;
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
					color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Comprobar si un nodo es hoja."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa el nodo: ";
					// Se lee la opción a elegir.
					color(GRIC, ROJ);getline(cin, aux);
					// Se valida la entrada.
					if(!validarNum(aux))
					{
						// Si no es un número se imprime un mensaje.
						color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
						getch();
						error_1 = true;
					}
					else
					{
						if(stoi(aux) > 99 || stoi(aux) < 0)
						{
							// Si no es un número se imprime un mensaje.
							color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
							error_1 = true;
							getch();
						}
					}
				}while(error_1);
				// Si el elemento que se ingresó está en el árbol...
				if(alturaNodo(stoi(aux)) > -1)
				{
					system("cls");
					color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Comprobar si un nodo es hoja."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					
					Nodo* nodo = arbol;
				    while (nodo != NULL) 
					{
						// Ciclo que nos permite recorrer el árbol en busca del nodo.
				        if (stoi(aux) < nodo->dato) {
				        	
				            nodo = nodo->izq;
				        }
				        else if (stoi(aux)  > nodo->dato) 
						{
				            nodo = nodo->der;
				        }
				        else 
						{
							// Evalúa que el nodo tenga valores y que sus punteros derecho e izquierdo no apunten a nadie. 
				            color(GRIC, NEGC);cout<<endl<<"\tEl elemento " <<stoi(aux)<<" ";color(GRIC, VER);cout<< ((nodo != NULL) && (nodo->izq == NULL) && (nodo->der == NULL) ? "es una hoja" : "no es una hoja");
							color(GRIC, NEGC);cout<<"."<<endl;
				            break;
				        }
				    }
				}
				// Si no se muestra que no está en el árbol.
				else
				{
					color(GRIC, ROJ);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL ÁRBOL + + +";	
				}
			}
			getch();
		}else
		// Si se elige la opción "d".
		if(opc =="D" || opc =="d")
		{
			// Se valida que no esté vacío.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # ÁRBOL SIN ELEMENTOS # # #"<<endl;
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
					color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular la altura de un nodo."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					color(GRIC, ROJ);cout<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa el nodo: ";
					// Se lee la opción a elegir.
					color(GRIC, ROJ);getline(cin, aux);
					// Se valida la entrada.
					if(!validarNum(aux))
					{
						// Si no es un número se imprime un mensaje.
						color(GRIC, ROJ);cout<<"\n\t# # # INGRESA SÓLO NUMEROS # # #";
						getch();
						error_1 = true;
					}
					else
					{
						if(stoi(aux) > 99 || stoi(aux) < 0)
						{
							// Si no es un número se imprime un mensaje.
							color(GRIC, ROJ);cout<<"\n\t# # # INGRESA NUMEROS DE 0 A 99 # # #";
							error_1 = true;
							getch();
						}
					}
				}while(error_1);
				// Si el nodo seencuenttra en el árbol...
				if(alturaNodo(stoi(aux)) > -1)
				{
					system("cls");
					color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
					color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular la altura de un nodo."<<endl<<endl;
					mostrarArbol(arbol, "", true);
					// Se calcula la altura del nodo.
					color(GRIC, NEGC);cout<<endl<<"\tLa altura del nodo es de ";color(GRIC, VER);cout<<alturaNodo(stoi(aux));color(GRIC, NEGC);cout<<".";
				}
				// Sino se muestra el mensaje.
				else
				{
					color(GRIC, ROJ);cout<<endl<<endl<<"\t+ + + EL ELEMENTO ("<<aux<<") NO SE ENCUENTRA EN EL ÁRBOL + + +";	
				}
			}
			getch();
		}else
		// Si se elige la opción "e".
		if(opc =="E" || opc =="e")
		{
			// Se valida que no esté vacío.
			if(arbol == NULL)
			{
				color(GRIC,ROJ);cout<<"\n\t# # # ÁRBOL SIN ELEMENTOS # # #"<<endl;
				getch();
			}
			else
			{
				// Se calcula la altura del árbol.
				system("cls");
				color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
				color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Calcular la altura del árbol."<<endl<<endl;
				mostrarArbol(arbol, "", true);
				color(GRIC, NEGC);cout<<endl<<"\tLa altura del arbol es de ";color(GRIC, VER);cout<<alturaArbol(arbol);color(GRIC, NEGC);cout<<".";
				getch();
			}
		}else
		// Si se elige la opción "f".
		if(opc =="F" || opc =="f")
		{
			// Salimos del ciclo.
			error = false;
		}else
		// Si la opción no es ninguna de las anteriores salta un mensaje de "Opción Inválida". 
		{
			cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
			getch();
		}
	}while(error); // El ciclo se ejecutará mientras la opción no haya sido "salir".
	
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCIÓN PRINCIPAL =====
main()
{
	// Variable del tipo 'string' que almacena nuestra opción.
	string opc;
	int dato;
	
	// Se llama a la funcion para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Ciclo para el menú de ejecución.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                      ÁRBOL BINARIO DE BÚSQUEDA                                      "<<endl<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MENÚ =========================================="<<endl<<endl;
		// Se muestran las opciones del menú.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Buscar un elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Insertar un elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Borrar un elemento."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) ";color(GRIC, NEG);cout<<"Movimientos a través del árbol."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Izquierda."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Derecha."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Raíz."<<endl;
		color(GRIC, ROJ);cout<<"\t\te) ";color(GRIC, NEG);cout<<"Información."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Comprobar si el árbol está vacío."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Calcular número de nodos del árbol."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Comprobar si un nodo es hoja."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Calcular la altura de un nodo."<<endl;
		color(GRIC,NEGC);cout<<"\t\t    - Calcular la altura del árbol."<<endl;
		color(GRIC, ROJ);cout<<"\t\tf) <- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t======================================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opción: ";
		// Se lee la opción a elegir.
		color(GRIC, ROJ);getline(cin, opc);
		
		if(arbol==NULL && (opc =="A" || opc =="a" || opc =="C" || opc =="c"|| opc =="D" || opc =="d"))
		{
			// Si el árbol es nulo y se eligen las opciones que involucren los datos del mismo se muestra un mensaje.
			color(GRIC,ROJ);cout<<"\n\t# # # ÁRBOL SIN ELEMENTOS # # #"<<endl;
			getch();
		}
		else// Caso contraio:
		{
			// Si se elige la opción "a".
			if(opc =="A" || opc =="a")
			{
				buscar();
			}else
			// Si se elige la opción "b".
			if(opc =="B" || opc =="b")
			{
				insertar();
			}else
			// Si se elige la opción "c".
			if(opc =="C" || opc =="c")
			{
				borrar();
			}else
			// Si se elige la opción "d".
			if(opc =="D" || opc =="d")
			{
				movimientos();
			}else
			// Si se elige la opción "e".
			if(opc =="E" || opc =="e")
			{
				informacion();
			}else
			// Si se elige la opción "f".
			if(opc =="F" || opc =="f")
			{
				// Se muestra el mensaje de ejecución finalizada.
				color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
			}else
			// Si la opción no es ninguna de las anteriores salta un mensaje de "Opción Inválida". 
			{
				cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
				getch();
			}
		}		
	}while(opc !="F" && opc !="f"); // El ciclo se ejecutará mientras la opción no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}












