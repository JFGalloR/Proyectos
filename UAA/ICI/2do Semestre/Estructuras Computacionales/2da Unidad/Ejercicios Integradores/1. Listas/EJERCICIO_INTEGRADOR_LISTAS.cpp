/*===========================================================================================================
	EJERCICIO FINAL UNIDAD II. Supermercado.
  ---------------------------------------------------------------------------------------------------------
	� OBJETIVO:
		Un supermercado nos pide que hagamos una aplicaci�n que almacene los productos pasados por el 
		esc�ner. La aplicaci�n debe almacenar Productos, que contenga la siguiente estructura.
			Productos
			 > Nombre
			 > Cantidad
			 > Precio
		1. El n�mero de productos a insertarse en la lista ser� aleatorio entre 1 y 8 productos.
		2. El nombre del producto puede ser un identificador b�sico como: producto1, producto2, producto3, 
		   producto4, producto5, producto6, producto7, producto8 o implementarlo como se considere. 
		   (integrarse aleatoriamente o ingresarlo por teclado seg�n sea su elecci�n).
		3. Cada producto al insertarse en la lista contiene una cantidad y un precio (estos dos generados 
			aleatoriamente).
			 a. El precio ya viene con los impuestos incluidos.
		4. Calcular el precio total de la lista de productos ingresados en la nota (productos entre 1 y 8)
		5. Mostrar una nota o ticket con todo lo vendido y el total a pagar de la nota como se hacen en los 
			supermercados.
		6. Una vez que se muestre el ticket con todo lo vendido y el total a pagar, dar la posibilidad de
		poder borrar un producto1 (ingresar el producto a borrar por teclado) y mostrar de nueva cuenta la 
		nota como qued� despu�s de haber ejecutado la operaci�n de borrado del producto.
  ---------------------------------------------------------------------------------------------------------
    � ELABORADORES:
	 - Alejandro Castillo Mota
 	 - Luis Manuel Flores Jim�nez
	 - Juan Francisco Gallo Ram�rez
  ---------------------------------------------------------------------------------------------------------
	6 de Abril de 2023
	I.C.I. U.A.A.
===========================================================================================================*/
#include <conio.h>
#include <cctype>
#include <iostream>
#include <limits>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

// Se definen las constantes de cantidad de productos, necesarias para generar la cantidad aleatoria.
const int MIN_PROD = 1, MAX_PROD = 8;
// Se define u arreglo con los nombres de los productos para acceder aleatoriamente a ellos.
const string PROD[34] = {"Coca Cola", "Sprite", "Fanta", "Fresca", "Pepsi", "Mirinda", "7up", "Dr Pepper",
						 "Oreo", "Chokis", "Principe", "Emperador", "Marias", "Crackets", "Chips Ahoy",
						 "Fruit Loops", "Choco Krispis", "Zucaritas", "Gansito", "Pinguinos", "Choco Roles",
						 "Sabritas", "Doritos", "Cheetos", "Ruffles", "Fritos", "Rancheritos", "Tostitos",
						 "Bacardi", "Jaggermeister", "Don Julio", "Buchanans", "Absolut", "Centenario"};
// Constante que nos ayudar� para el sub�ndice del arreglo de 'string'.
const int CAD = 33;
// Se definen las constantes para el precio m�ximo y el precio m�nimo.					 
const int PREC_MIN = 10, PREC_MAX = 500, DEC = 100;
// Se definen las constantes para la cantidad m�xima y la m�nima.	
const int CANT_MIN = 1, CANT_MAX = 15;
// Constantes que representan s�mbolos, del tipo 'caracter'.
const char C = 2, F = 16, FF = 187;
// Constantes cuyo valor representan los colores para la funci�n 'color()'.
const int NEG = 0, AZU = 1, VER = 2, CEL=3, ROJ = 4, MOR = 5, AMA = 6, GRI = 7;
const int NEGC = 8, AZUC = 9, VERC = 10, CELC = 11, ROJC = 12, MORC = 13, AMAC = 14, GRIC = 15;

//===================================================== ESTRUCTURA PARA LOS NODOS DE LA LISTA ================
/*-----------------------------------------------------------------------------------------------------------
	Contienen los elementos requeridos para los productos, nombre, cantidad y precio.
  ---------------------------------------------------------------------------------------------------------*/
struct Nodo
{
	Nodo *anterior;
	string nombre;
	int cantidad;
	float precio;
	
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

//================================================================= FUNCI�N DE POSICIONAMIENTO DE CURSOR =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos ayuda a posicionar el cursor de escritura.
  ---------------------------------------------------------------------------------------------------------*/
void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//====================================================================== FUNCI�N CONVERSORA A MAY�SCULAS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que que recibe una cadena y la convierte a may�sculas.
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

//============================================================= FUNCI�N GENERADORA DE ENTEROS ALEATORIOS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que genera enteros aleatorios seg�n los valores que reciba, lo cuales funcionan como l�mite 
	superior e inferior para generar el n�mero.
  ---------------------------------------------------------------------------------------------------------*/
int enteroAleatorio(int lim_inf, int lim_sup)
{
	// F�rmula donde a partir del l�mite inferior genera la diferencia de los l�mites m�s uno.
	int num = lim_inf + rand() % (lim_sup - lim_inf + 1);
	// Retorna el n�mero que e gener�.
	return num;
}

//=========================================================== FUNCI�N GENERADORA DE FLOTANTES ALEATORIOS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que genera flotantes aleatorios seg�n los valores que reciba, lo cuales funcionan como l�mite 
	superior e inferior para generar el n�mero.
  ---------------------------------------------------------------------------------------------------------*/
float flotanteAleatorio(int lim_inf, int lim_sup)
{
	/* F�rmula donde a partir del l�mite inferior genera la diferencia de los l�mites m�s uno. Se multiplica 
	   por cien los l�mites para despu�s dividir entre cien, de esta fomra obtener n�meros flotantes.*/
	float aux = lim_inf * DEC + rand() % ((lim_sup - lim_inf) * DEC + 1);
	float num = aux / DEC;
	// Retorna el n�mero que e gener�.
	return num;
}

//==================================================== FUNCI�N PARA INSETAR PRODUCTO A LA LISTA ENLAZADA =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que inserta un nuevo nodo y lo enlaza correspondientemente a la lista.
  ---------------------------------------------------------------------------------------------------------*/
void insertarProducto(Nodo *&lista)
{
	// VAriables para insertar el nodo.
	Nodo *nodo = new Nodo;
	Nodo *aux1 = lista, *aux2;
	bool rep = true;
	
	// Ciclo qu valida que el nombre asignado no haya sido puesto antes, de ser as� vuelve a cambiar y validar.
	while(rep)
	{
		// Se asigna el nombre.
		int num = enteroAleatorio(0, CAD);
		rep = false; 
		nodo->nombre = PROD[num];
		aux1 = lista;
		// Se compara con toda la lista para validar que no existe.
		while(aux1 != NULL && !rep)
		{
			// Si ya est� repetido, bool 'rep' se vuelve verdadero y rompe el ciclo.
			if(aux1->nombre == nodo->nombre && !rep)rep = true;
			else aux1 = aux1->anterior;
		}
		/* Llegado a este punto si bool 'rep' fue verdadero, vuelve a repetir el ciclo, por lo tanto vuelve a 
		   asignarse un nuevo nombre y a v�lidar, hatsa que no se haya repetido, caso contrario, termina. */
	}
	// Se vuelve a inizializar 'aux1' con el valor de la lista.
	aux1 = lista;
	// Se asignan los precios y cantidades aleatorias con ayuda de las funciones elbaoradas.
	nodo->precio = flotanteAleatorio(PREC_MIN, PREC_MAX);
	nodo->cantidad = enteroAleatorio(CANT_MIN, CANT_MAX);
	// Ciclo que no ordena la lista conforme al precio del producto.
	while(aux1 != NULL && aux1->precio > nodo->precio)
	{
		aux2 = aux1;
		aux1 = aux1->anterior;
	}
	// Seg�n sea el valor de 'aux1' es en d�nde se asignar�n los valores de enlazamiento.
	if(lista==aux1)
	{
		lista = nodo;
	}else
	{
		aux2->anterior = nodo;
	}
	nodo->anterior = aux1;
}

//================================================================== FUNCI�N PARA ELIMINAR TODA LA LISTA =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos elimina todos los nodos existentes de la lista.
  ---------------------------------------------------------------------------------------------------------*/
void eliminarLista(Nodo *&lista)
{
	Nodo *aux=lista;
	
	// Se recorre roda la lista y se eliminar cada nodo.
	while(lista != NULL)
	{
		aux=lista->anterior;
		delete lista;
		lista = aux;
	}

}

//======================================================================= FUNCI�N PARA GENERAR PRODUCTOS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos genera las lista de productos seg�n los valores correspondientes. De ya existir 
	productos, vuelve a generar otros nuevos.
  ---------------------------------------------------------------------------------------------------------*/
void generarProductos(Nodo *&lista)
{
	Nodo *aux = lista;
	int prod = 0;
	
	// Texto de control.
	system("cls");
	color(ROJ, GRIC);cout<<"                                         SUPERMERCADO                                         "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Generar productos."<<endl;
	// Se elimina toda la lista primero, ya que esta opci�n genera o regenera lista de productos.
	eliminarLista(lista);
	// Se obtiene un n�mero aleatorio entre las constantes inicialmente establecidas.
	prod = enteroAleatorio(MIN_PROD, MAX_PROD);
	/* Seg�n la cantidad de productos, se genera un nodo y se inserta a la lista con la ayuda de nuestra funci�n
	'insertarProducto()'. */
	for(int i = 0; i < prod; i++)
	{
		insertarProducto(lista);
	}
	// Nos muestra el texto que seg�n el estado de la lista imprime "GENERADOS" o "REGENERADOS".	
	color(GRIC, VER);cout<<endl<<"\t+ + + PRODUCTOS ";if(aux!=NULL)cout<<"RE";cout<<"GENERADOS + + +"<<endl;
		
}

//======================================================================= FUNCI�N PARA ELIMINAR PRODUCTOS =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos elimina productos con la b�squeda de losmismos..
  ---------------------------------------------------------------------------------------------------------*/
void eliminarProducto(Nodo *&lista)
{
	Nodo *aux1=lista, *aux2 = aux1;
	string aux;
	bool encontrado=false;
	int c = 0;
	
	// Texto de control.
	system("cls");
	color(ROJ, GRIC);cout<<"                                         SUPERMERCADO                                         "<<endl<<endl<<endl;
	color(GRIC, NEGC);cout<<"\t"<<F;color(GRIC, NEG);cout<<" Eliminar producto."<<endl<<endl;
	color(GRIC, ROJ);gotoxy(15,5);cout<<"Producto";gotoxy(40,5);cout<<"Cantidad";gotoxy(58,5);cout<<"Precio";gotoxy(74,5);
	
	// Ciclo que no recorre la lista e imprime los productos y sus datos como referencia de b�squeda.
	while(aux1 != NULL)
	{
		color(GRIC, NEGC);gotoxy(15,c+7);cout<<aux1->nombre;
		color(GRIC, NEGC);gotoxy(40,c+7);cout<<aux1->cantidad;
		color(GRIC, NEGC);gotoxy(58,c+7);cout<<"$"<<aux1->precio;
		aux1 = aux1->anterior;
		c++;
	}
	// Se lee el texto a buscar entre los nombres de los productos.
	color(GRIC, ROJ);cout<<endl<<endl<<endl<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa producto para buscar: ";
	color(GRIC, ROJ);getline(cin, aux);
	
	aux1 = lista;
	// Cliclo que nos recorre los elementos de la lista, es el ciclo de b�squeda.
	while(aux1 != NULL && !encontrado)
	{
		/* Se compara entre todos los nombres de la lista, para ello se convierte a mayusculas tanto la de 
		la ingresada comomel nombre del producto, para as� permitir el uso de min�sculas o may�sculas en la 
	    entrada. */
		if(cadMayus(aux1->nombre) == cadMayus(aux))
		{
			// Si hay coincidencias bool 'encontrado' se vuelve verdadero.
			encontrado = true;
		}else
		{
			aux2 = aux1;
			aux1 = aux1->anterior;	
		}
		/* Si 'encontrado' es verdadero se rompe el ciclo, caso contrario se sigue recorriendo la lista hasta 
		   que se encuentre el producto o acabe la lista anterior */
	}
	
	if(encontrado)
	{
		/* Si 'encontrado' es verdadero el producto se elimina y si es en un extremo de la lista se le asigna un 
		   nuevo valor a lista. */
		if(cadMayus(lista->nombre) == cadMayus(aux))
		{
			lista = lista->anterior;
		}
		aux2->anterior = aux1->anterior;
		color(GRIC, ROJ);cout<<endl<<"\t(-) Producto ("<<aux1->nombre<<") eliminado correctamente..."<<endl<<endl;
		// Se elimina el nodo.
		delete aux1;
	}else
	{
		// Si 'encontrado' es falso, es decir, no hay coincidencias, se escribe que no se encontr� el producto.
		color(GRIC, ROJ);cout<<endl<<"\t# # # PRODUCTO "<<cadMayus(aux)<<" NO ENCONTRADO # # #"<<endl<<endl;
	}
}

//======================================================================= FUNCI�N PARA GENERAR EL TICKET =====
/*-----------------------------------------------------------------------------------------------------------
	Funci�n que nos elimina productos con la b�squeda de losmismos..
  ---------------------------------------------------------------------------------------------------------*/
void generarTicket(Nodo *&lista)
{
	// Para el ticket en necesario unnacumulador que nos guarde el valor total de la compra.
	int c = 0;
	// Aqu� intriducimos nuestro acumulador.
	float compra;
	Nodo *aux = lista;
	
	// Texto de control.
	system("cls");
	color(ROJ, GRIC); cout<<"                                         SUPERMERCADO                                         "<<endl<<endl<<endl;
	color(GRIC, NEG);cout<<"        <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< TICKET DE COMPRA >>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
	color(GRIC, NEGC);cout<<"       --------------------------------------------------------------------------------"<<endl;
	color(GRIC, ROJ);gotoxy(15,5);cout<<"Producto";gotoxy(40,5);cout<<"Cantidad";gotoxy(58,5);cout<<"Precio";gotoxy(74,5);cout<<"Total"<<endl;
	color(GRIC, NEGC);cout<<"       --------------------------------------------------------------------------------"<<endl;
	
	// Se recorre toda la lista imprimiendo todos los productos con sus datos.
	while(aux != NULL)
	{
		/* Se a�ade un flotante que nos ayuda a saber el total de cada producto, multiplicando su precio por la 
		   cantidad de los mismos. */
		float tot = aux->cantidad * aux->precio;
		color(GRIC, NEG);gotoxy(15,c+8);cout<<aux->nombre;
		color(GRIC, NEGC);gotoxy(40,c+8);cout<<aux->cantidad;
		color(GRIC, ROJC);gotoxy(58,c+8);cout<<"$"<<aux->precio;
		color(GRIC, ROJ);gotoxy(74,c+8);cout<<"$"<<tot;
		aux = aux->anterior;
		// Se realiza la suma en el acumulador de compra.
		compra += tot;
		c++;
	}
	color(GRIC, NEGC);cout<<endl<<endl<<"       --------------------------------------------------------------------------------"<<endl;
	gotoxy(66,c+10);color(GRIC, NEG);cout<<"TOTAL =";gotoxy(74,c+10);color(GRIC, VER);cout<<"$"<<compra<<endl;
	color(GRIC, NEGC);cout<<"       --------------------------------------------------------------------------------"<<endl;
	color(GRIC, NEG);cout<<"        <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
}

//____________________________________________________________________________________________________________
//==================================================================================== FUNCI�N PRINCIPAL =====
main()
{
	string opc;
	Nodo *lista = NULL;
	
	// Se llama a la funcion para generar n�meros aleatorios.
	srand(time(NULL));
	// Se llama a la funcion para acentos.
	setlocale(LC_ALL, "");
	// Se pone fondo a la consola.
	system("color F0");
	
	// Ciclo para el men� d ejecuci�n.
	do
	{
		// Texto de control.
		system("cls");
		color(ROJ, GRIC);cout<<"                                         SUPERMERCADO                                         "<<endl<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t====== MEN� ================================"<<endl<<endl;
		// Se muestran las opciones del men�.
		color(GRIC, ROJ);cout<<"\t\ta) ";color(GRIC, NEG);cout<<"Generar productos";
		if(lista!=NULL){color(GRIC, VER);cout<<" (Regenerar)";color(GRIC, NEG);}cout<<"."<<endl;
		color(GRIC, ROJ);cout<<"\t\tb) ";color(GRIC, NEG);cout<<"Eliminar un producto."<<endl;
		color(GRIC, ROJ);cout<<"\t\tc) ";color(GRIC, NEG);cout<<"Generar ticket."<<endl;
		color(GRIC, ROJ);cout<<"\t\td) <- Salir."<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t============================================"<<endl<<endl;
		color(GRIC, ROJ);cout<<"\t"<<FF;color(GRIC, NEG);cout<<" Ingresa una opci�n: ";
		// Se lee la opci�n a elegir.
		color(GRIC, ROJ);cin>>opc;
		// Funci�n que nos ayuda a ignorar caracteres, en este caso es �til si se unsa 'cin', y despu�s 'getline'.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		if(lista==NULL && (opc =="B" || opc =="b" || opc =="C" || opc =="c"))
		{
			// Si la lista esta vac�a y se elige las opciones "b" o "c", mostrar� un mensaje de "Lista sin productos".
			color(GRIC,ROJ);cout<<"\n\t# # # LISTA SIN PRODUCTOS # # #"<<endl;
		}else // Caso contrario:
		{
			// Si se elige la opci�n "a".
			if(opc =="A" || opc =="a")
			{
				// Se ejecuta la funci�n para generar productos.
				generarProductos(lista);
			}else
			// Si se elige la opci�n "b".
			if(opc =="B" || opc =="b")
			{
				// Se ejecuta la funci�n para eliminar productos.
				eliminarProducto(lista);
			}else
			// Si se elige la opci�n "c".
			if(opc =="C" || opc =="c")
			{
				// Se ejecuta la funci�n para generar el ticket.
				generarTicket(lista);
			}else
			// Si se elige la opci�n "d".
			if(opc =="D" || opc =="d")
			{
				// Se ejecuta la funci�n para eliminar la listas.
				eliminarLista(lista);
				// Se muestra el mensaje de ejecuci�n finalizada.
				color(GRIC, AMA);cout<<"\n\t "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
			}else
			// Si la opci�n no es ninguna de las anteriores salta un mensaje de "Opci�n Inv�lida". 
			{
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
			}
		}	
		getch();
	}while(opc !="D" && opc !="d"); // El ciclo se ejecutar� mientras la opci�n no haya sido "salir".
	
	// FIN DEL PROGRAMA.
}












