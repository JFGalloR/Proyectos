/*
////Equipo 4: Algoritmo de Busqueda Binaria/////////////////////////////////////////////////////////////////////////////////////////
Objetivo: 	Un algoritmo de busqueda binaria se caracteriza por buscar un valor proporcionado por un usuario dentro de un array
			Ordenado. Se busca una implementacion recursiva del algoritmo.
			El algoritmo busca el valor mediante revisar el elemento medio del array y si no lo encuentra procede a reducir el 
			tamaño de busqueda en el array por la mitad. Si el valor en mid es mayor al elemento a buscar entonces se busca 
			a la izquierda de mid, de lo contrario se busac en la derecha de mid.
____________________________________________________________________________________________________________________________________
*/
#include <iostream>
#include <windows.h> 
using namespace std;

/*
Declarando la funcion Binary Search
Tipo Int: Se espera que retorne el indice en el que se encuentra el elemento
Paremetros:
	-int array []:		Se espera un array de tipo int mandado desde el main
	-int element []:	Se espera un int que es el valor a buscar en el array
	-int left_index []:	Se espera in int que sea el indice minimo del array para empezar la busqueda 
						[En la primera iteracion es 0]
	-int right_index []:Se espera un int que sea el indice maximo del array en donde detener la busqueda 
						[En la primera iteracion es el indice extremo derecho del array]
	-int &counter:		Se espera un int que representa el contador de iteraciones de la funcion
*/
int binary_search(int array [], int element, int left_index, int right_index, int &counter);

void print_array(int array[], int left_index, int right_index);

int main(){
	//Tamaño deseado del array
	const int TAM = 10000;
	// int response:	es el int en donde se guarda el retorno de la funcion 
	int response=0;
	// int value:	es el int en donde se guarda el numero que se va a buscar en el array
	int value=0;
	// int sorted_array:	es el array de numeros ORDENADOS en el que se va a buscar
	int sorted_array [TAM];
	//Rellenando el array
	for (int i=0; i<TAM; i++){ sorted_array[i] = (i+1)*10; }
	// int left_index:	es el int que representa el indice minimo de busqueda en el array, inicializado en 0
	int left_index=0;
	// int right_index:	es el int que guarda el indice maximo de busqueda en representacion del tamaño del array	
	int right_index=sizeof sorted_array/sizeof(sorted_array[0]) -1;
	// salida del menu
	int salir=0;
	//Contador de iteraciones
	int iteration_counter=0;
	
	//Ciclo while para ingresar datos hasta que se deseé salir
	while( salir != 1){
		//Reseteamos el contador cada que regresemos al while
		iteration_counter=0;
		//Limpiamos pantalla
		system("cls");
		
		//Menu
		cout<<"\t~Busqueda Binaria~"<<endl;
		cout<<"Ingrese el valor a buscar\t";
		fflush(stdin);
		//Tomando valor que ingrese el usuario
		cin>>value;
		fflush(stdin);
		
		//Invocamos la funcion de busqueda binaria, guardamos el resultado en response	
		response=binary_search(sorted_array,value,left_index,right_index, iteration_counter);
		
		//Si response es igual a cero o mayor, entonces se encontro el elemento
		if(response>=0){
			cout<<"Valor "<<value<<" encontrado en la posicion: "<<response<<endl;
		}
		//Si response guarda -1 entonces no se hallo el valor a buscar
		else{
			cout<<"Valor "<<value<<" no ha sido encontrado en ninguna posicion"<<endl;
		}
		getchar();
		
		//Opcion para salir del while
		cout<<"Presione 1 si desea salir del Programa, de otro forma ingrese cualquier tecla"<<endl;
		fflush(stdin);
		cin>>salir;
		fflush(stdin);
			if(salir==1){
				break;
			}	
	}
	cout<<"Gracias por usar el programa :D";
	getchar();
return 0;
}

//Cuerpo de la funcion
int binary_search(int array [], int element, int left_index, int right_index, int &counter){
	//Sumamos al contador en cada iteracion
	counter++;
	//definimos el indice medio del array
	int mid = (left_index + right_index) / 2;	
	//Imprimimos la posicon de los tres indices y el valor al que apuntan
	cout<<"Iteracion: "<<counter<<endl;
	cout<<"Indice\t\tPosicion\tValor"<<endl;
	cout<<"Left_Index\t"<<left_index<<"\t\t"<<array[left_index]<<endl;
	cout<<"Right_Index\t"<<right_index<<"\t\t"<<array[right_index]<<endl;
	cout<<"Mid_Index\t"<<mid<<"\t\t"<<array[mid]<<endl;
	
	//Caso base de retorno
	//Cada vez que se itera se modifican los valores de left index y right index
	//Cuando el left index sobrepase al right index esto significa que ya revisamos el arreglo y no encontramos nada
	if( left_index > right_index){
		return -1;
	}
	
	//Imprimimos el array
	print_array(array,left_index,right_index);
	
	//Si el inidice mid apunta al elemento que etsamos buscando, retornamos el indice mid
	if( array[mid] == element){
		return mid;
	}
	//Si el indice mid apunta a un numero mayor al elemeto al que estamos buscando
	//Volvemos a llamar a la funcion binary_search y ajustamos el campo de busqueda para 
	//reducir el indice de limite de busqueda e ignoramos todos los valores del array a la derecha de mid
	else if( array[mid] > element){
		binary_search(array,element,left_index,mid-1, counter);
	//Si el indice mid apunta a un numero menor al elemeto al que estamos buscando
	//Volvemos a llamar a la funcion binary_search y ajustamos el campo de busqueda para 
	//Ajustamos el indice donde se empieza la busqueda a la derecha de mid e ignoramos los elementos a la izquierda de mid
	}else if (array[mid] < element){
		binary_search(array,element,mid+1,right_index, counter);
	}
}

//Funcion para imprimir el array actual
void print_array(int array[], int left_index, int right_index){
	cout<<"\n~Array Actual~"<<endl;
	for(int i=left_index; i<=right_index; i++){
		if (i % 10 == 0){
			cout<<endl;
		}
		cout<<"["<<array[i]<<"]\t";
	}
	cout<<endl<<"\n";
	getchar();
}
