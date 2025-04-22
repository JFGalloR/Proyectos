#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int hashFunction(string); //Declaramos la funcion "hashFunction" que nos ayudara a obtener la posicion en la que guardaremos los datos
void addPerson(string, string); // Declaramos la funcion "addPerson" que nos ayudara a añadir la informacion de una persona a la tabla hash
int numberOfItemsInIndex(int); // Declaramos la funcion "numberOfItemsInIndex" que nos ayudara a contar cuantas personas hay en un Índice
void printTable(); // Declaramos la funcion "printTable" que imprimira la primera persona guardada en cada Índice y el numero de personas que hay en cada Índice
void printItemsInIndex(int); // Declaramos la funcion "printItemsInIndex", funcion que nos ayudara a imprimir todas las personas que tenemos guardadas en un Índice
void findDrink(string); // Funcion que recibe como parametro el nombre de una persona y si esa persona existe en la tabla hash nos devuelve su bebida
void removePerson(string); // Funcion que recibe como parametro el nombre de una persona si la persona a buscar existe la borrara de la tabla hash, si no existe nos indicara que la persona a borrar no existe en la tabla hash

const int tableSize = 10; //Definimos el tamaño de la tabla hash

struct person 
{
	string name;
	string drink;
	person* next;
};

person* HashTable[tableSize]; // Creamos la tabla hash de tipo "person" como arreglo y apuntador, le indicamos que sera de tamaño "tableSize"

// -------------------------------------------------------------------int main()---------------------------------------------------------------------------------

int main()
{
	for(int i = 0; i < tableSize; i++) //Ciclo for para inicializar todos los indices vacios
	{
		HashTable[i] = new person;
		HashTable[i]->name = "vacio";
		HashTable[i]->drink = "vacio";
		HashTable[i]->next = NULL;
	}
	
	setlocale(LC_ALL,"");
	string name = "", drink = ""; // Variable para elegir que persona borrar de algun Índice, o bebida y persona a ingresar
	int opc; // Variable para elegir la opcion del menú
	int index; // Variable para que el usuario eliga que Índice mostrar
	
	addPerson("Paul", "Café americano");
	addPerson("Kim", "Café negro");
	addPerson("Emma", "Smoothie de Frambuesa");
	addPerson("Ana", "Chocolate Caliente");
	addPerson("Sara", "Te Pasión");
	addPerson("Javier", "Caramel Mocha");
	addPerson("Miguel", "Te Chai");
	addPerson("Haniel", "Cidra de manzana");
	addPerson("Brandon", "Cerveza de raiz");
	addPerson("Maria", "Latte Macchiato");
	addPerson("Susana", "Agua");
	addPerson("José", "Te Verde");
	
	
	do
	{    
		system("cls"); 
		cout << "-------------- Menú --------------\n\n";   
		cout << "1) Imprimir Tabla Hash\n";  
		cout << "2) Imprimir personas de un Índice\n";  
		cout << "3) Añadir persona\n";
		cout << "4) Borrar persona\n";  
		cout << "5) Encontrar bebida\n";  
		cout << "6) Salir\n\n";
		cout << "¿Qué opción desea elegir? ";
		cin >> opc;
		
		switch(opc)
		{
			case 1:
				system("cls");
				printTable();
				cout << "\n";
				system("pause");
				break;
			
			case 2:
				system("cls");
				do{
					cout << "¿Qué índice desea mostrar? ";
					cin >> index;
					if((index < 0 )|| (index >= tableSize ))
					{
						cout << "\nIngrese un Índice entre 0 y " << tableSize-1 << endl;
						system("pause");
						system("cls");
					}
				}while((index < 0 ) || (index >= tableSize ));
				
				cout << "\n";
				printItemsInIndex(index);
				cout << "\n";
				system("pause");
				break;
				
			case 3:
				system("cls");
				cout << "Persona a agregar: ";
				cin >> name;
				cout << "Bebida favorita: ";
				cin >> drink;
				addPerson(name, drink);
				cout << "\n";
				system("pause");
				
				break;
				
			case 4:
				system("cls");
				cout << "Persona a borrar: ";
				cin >> name;
				removePerson(name);
				cout << "\n";
				system("pause");
				break;
				
			case 5:
				system("cls");
				cout << "Buscar a: ";
				cin >> name;
				findDrink(name);
				cout << "\n";
				system("pause");
				break;
				
			case 6:
				system("cls");
				cout << "Salida exitosa\n";
				break;		
		}
	}while(opc != 6);
}

// -------------------------------------------------------------------void printItemsInIndex(int index)--------------------------------------------------------

void printItemsInIndex(int index)
{
	person* Ptr = HashTable[index]; // Puntero que apuntara al primer item que tengamos en el index
	
	if(Ptr->name == "vacio") // Si el nombre del primer Índice es igual a "vacio" podemos decir que el Índice esta vacio
	{
		cout << "Índice " << index << " está vacio"; // Por lo tanto imprimiremos que el inidice esta vacio
	}
	else
	{
		cout << "Índice " << index << " contiene a las siguientes personas\n";
		while(Ptr != NULL)
		{
			cout << "-----------------------\n";
			cout << Ptr->name << endl; // imprimimos el nombre de la persona
			cout << Ptr->drink << endl; // Imprimimos la bebida de la persona
			cout << "-----------------------\n";
			Ptr = Ptr->next;
		}
	}
}

// -------------------------------------------------------------------int numberOfItemsInIndex(int index)--------------------------------------------------

int numberOfItemsInIndex(int index) // Funcion para obtener el numero de personas en un Índice
{
	int count = 0; // Inicializamos el contador en 0
	
	if(HashTable[index]->name == "vacio") // Si el nombre del primer Índice es igual a "vacio" podemos decir que el Índice esta vacio y por lo tanto retornaremos un 0 
	{
		return count; // Regresamos el contador
	}
	else // Sino
	{
		count ++; // Sumamos al contador 1 ya que el index no esta vacio
		person* Ptr = HashTable[index]; // Creamos Ptr que nos ayudara a recorrer toda la lista de personas que hay en el Índice indicado
		while(Ptr->next != NULL) // Ciclo while para recorrer y contar todas las personas que estan guardadas en un Índice
		{
			count ++; // Si es diferente de NULL sumamos 1 al contador
			Ptr = Ptr->next; // Y recorremos el puntero a puntero siguiente
		}	
	}
	return count; // Por ultimo regresamos el contador
	
}

// -------------------------------------------------------------------void addPerson(string name, string drink)----------------------------------------------

void addPerson(string name, string drink) // Funcion para añadir una nueva persona a la tabla hash
{
	int index = hashFunction(name); // Con ayuda de la funcion "hashFunction" obtenemos el Índice donde guardaremos toda la informacion de la persona de acuerdo a su nombre
	
	if(HashTable[index]->name == "vacio") //Si el Índice esta vacio o en este caso tiene el string "vacio" que nos indica que esta vacio, sobrescribimos los valores predefinidos por los nuevos valores
	{
		HashTable[index]->name = name; // Sobrescribimos el nombre
		HashTable[index]->drink = drink; //Sobrescribimos la bebida
	}
	else // Si no esta vacio
	{
		person* Ptr = HashTable[index]; // Creamos un nuevo puntero de tipo "person" que apuntara al inicio del "index" seleccionado de la tabla hash
		person* n = new person; // Creamos una nueva persona de tipo puntero y la llamaremos "n", aqui ingresaremos la informacion dada por el usuario
		n->name = name; // Agregamos el nombre a la nueva persona
		n->drink = drink; // Agregamos la bebida a la nueva persona
		n->next = NULL; // Hacemos que siguiente de la nueva persona apunte a NULL
		
		while(Ptr->next != NULL) // Mientras el puntero a siguiente sea diferente de null recorremos toda la lista 
		{
			Ptr = Ptr->next; // Puntero va a ser igual a puntero siguiente, esto nos sirve para avanzar en la lista
		}
		Ptr->next = n; // Y por ultimo hacemos que puntero siguiente ahora en vez de apuntar a NULL apunte a "n", esto nos ayuda a enlazar la nueva persona a la lista
	}
}

// -------------------------------------------------------------------int hashFunction(string key)---------------------------------------------------

int hashFunction(string key) //Funcion para obtener el index donde guardaremos la informacion de la persona
{
	int hash = 0; // Variable que mas adelante nos ayudara para sumar y obtener el valor total de la suma de todas las letras del nombre de una persona en codigo ASCII
	int index; // Variable que nos ayudara para guardar y calcular el Índice en el que se guardara la informacion, esta variable sera retornada
	
	for(int i = 0; i < key.length(); i++) // Ciclo para recorrer y calcular el valor del nombre enviado por el usuario
	// key.lenght calcula la longitud del nombre por ejemplo, "Haniel" tendra una longitud de 6
	{
		hash = hash + (int)key[i]; // Vamos sumando y guardando los valores de cada letra en la variable hash
		// Podemos cambiar el orden en el que se acomodan las personas en los Índices modificando la formula
		// Por ejemplo, hash = (hash + (int)key[i]) * 14;
	}
	
	index = hash % tableSize; // Calculamos el Índice obteniendo el residuo de dividir "hash" entre "tableSize", 
	// que seria el valor total obtenido por el nombre entre la longitud de la tabla hash
	
	return index; // Retornamos el Índice
}

// -------------------------------------------------------------------void printTable()-----------------------------------------------------------------------

void printTable()
{
	int number; // Variable para obtener el numero de elementos en cada Índice
	
	for(int i = 0; i < tableSize; i++) //Ciclo for para imprimir la primera de cada persona de cada Índice y cuantas hay en cada uno
	{
		number = numberOfItemsInIndex(i); // Con ayuda de la funcion "numberOfItemsInIndex" obtenemos el numero de persona en el Índice "i" y lo guardamos en "number"
		cout << "-----------------------\n";
		cout << "Índice = " << i << endl; //Imprimimos en cual index estamos
		cout << HashTable[i]->name << endl; // Nombre de la primera persona
		cout << HashTable[i]->drink << endl; // Bebida de la primera persona
		cout << "Número de personas = " << number << endl; // Imprimimos cuantas personas hay en el Índice "i"
		cout << "-----------------------\n";
	}
	
}

// ----------------------------------------------------------void findDrink(string name)-----------------------------------------------------------------------

void findDrink(string name) // Funcion para encontrar la bebida favorita de una persona
{
	int index = hashFunction(name); // Llamamos a la funcion "hashFunction" para obtener el Índice de donde estaria ubicado el nombre
	bool foundName = false; // Variable booleana para saber si fue encontrado el nombre o no
	string drink; // Variable donde guardaremos la bebida
	
	person* Ptr = HashTable[index]; // Creamos un nuevo puntero de tipo "person" que apuntara al inicio del "index" seleccionado de la tabla hash
	while(Ptr != NULL) // Mientras el puntero sea diferente de NULL, o sea que haya personas en el Índice 
	{
		if (Ptr->name == name) // Si el nombre del puntero es igual al nombre buscado
		{
			foundName = true; // Declaramos la funcion "foundName" como true, ya que, ya fue encontrado
			drink = Ptr->drink; // Y guardamos la bebida de la persona encontrada en la variable "drink"
		}
		Ptr = Ptr->next; // Puntero va a ser igual a puntero siguiente, esto nos sirve para avanzar en la lista
	}
	if(foundName == true) // Si "foundName" es igual a true significa que si encontramos a una persona con el nombre ingresado a la funcion
	{
		cout << "Bebida favorita = " << drink << endl; // Y por lo tanto imprimiremos su bebida
	}
	else // Sino
	{
		cout << "La informacion de " << name << " no fue encontrada en la Tabla Hash\n"; // Imprimiremos que el nombre de la persona a buscar no existe en la tabla hash
	}
}

// ------------------------------------------------------void removePerson(string name)--------------------------------------------------------------------

void removePerson(string name)
{
	int index = hashFunction(name); // Llamamos a la funcion "hashFunction" para obtener el Índice de donde estaria ubicado el nombre
	
	person* delPtr; // Puntero para borrar
	person* p1;
	person* p2;
	
	// Caso 0 el Índice en el que estamos buscando esta vacio, no hay ninguna persona guardada
	
	if(HashTable[index]->name == "vacio" && HashTable[index]->drink == "vacio") // Si el nombre y la bebida del primer elemento del Índice estan vacios, entonces la persona no fue encontrada
	{
		cout << name << " no fue encontrado en la Tabla Hash\n"; // Imprimimos que la persona no fue encontrada
	}
	
	// Caso 1 solo hay una persona en el Índice y la persona que esta en el Índice coincide con la persona que estamos buscando
	
	else if(HashTable[index]->name == name && HashTable[index]->next == NULL) // Sino si el primer nombre del Índice es igual al que estamos buscando y siguiente apunta a NULL entonces...
	{
		HashTable[index]->name = "vacio"; // Renombramos el nombre a "vacio"
		HashTable[index]->drink = "vacio"; // Renombramos la bebida a "vacio"
		// Esto se hace ya que estos valores se toman como si estuviera vacio
	
		cout << name << " fue eliminado de la Tabla Hash\n"; // Imprimimos que la persona fue borrada de la tabla hash
	}

	// Caso 2 la persona a borrar se encuentra en la primera posicion del Índice, pero el Índice tiene mas personas adentro

	else if(HashTable[index]->name == name) // Sino si el primer nombre del Índice es igual al que estamos buscando y hay mas personas en el Índice 
	{
		delPtr = HashTable[index]; // Hacemos que "delPtr" apunte a la primer persona del index, que es el item a borrar
		HashTable[index] = HashTable[index]->next; // Hacemos que el segundo item del index se vuelva el primero, ya que vamos a eliminar el primero
		delete delPtr; // Una vez enlazado, podemos borrar el puntero
		
		cout << name << " fue eliminado de la Tabla Hash\n"; // Imprimimos que la persona fue borrada de la tabla hash
	}

	// Caso 3 el Índice tiene varias personas, pero la persona a buscar no se encuentra en la primera posicion del Índice
	
	else
	{
		p1 = HashTable[index]->next; // Hacemos que p1 apunte al segundo item del index
		p2 = HashTable[index]; // Hacemos que p2 apunte al primer item de la lista
		// p2 le seguira el rastro a p1 hasta que encontremos la persona a borrar o hayamos alcanzado el final de la lista
		
		while(p1 != NULL && p1->name != name) // Mientras no sea el final de la lista y el nombre de la persona que estamos buscando no sea el mismo al que estamos apuntando, recorreremos toda la lista
		{
			p2 = p1; // Hacemos que p2 tome la posicion que tenia p1
			p1 = p1->next; // Y avanzamos a p1 al siguiente
		}
		// Caso 3.1 buscamos por todas las personas del Índice, pero ninguna coincidio con la que estamos buscando
		
		if(p1 == NULL)
		{
			cout << name << " no fue encontrado en la Tabla Hash\n"; // Imprimimos que la persona no fue encontrada
		}
		// Caso 3.2 encontramos la persona a borrar
		else
		{
			delPtr = p1; // Hacemos que "delPtr" apunte a lo que esta apuntando p1
			p1 = p1->next; // Hacemos que p1 apunte al siguiente item de la lista
			p2->next = p1; // Hacemos que p2 siguiente apunte a p1
			
			delete delPtr; // Una vez enlazado todo, podemos borrar el puntero en el que habiamos guardado la persona a borrar
			cout << name << " fue eliminado de la Tabla Hash\n"; // Imprimimos que la persona fue borrada de la tabla hash
		}
	}	
// -------------------------------------------------------------------------------------------------------------------------------------------------------------
}


