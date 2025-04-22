#include <iostream>
using namespace std;

int Maximo(int arr[], int numElementos){
    int max = arr[0];
    for (int i = 1; i < numElementos; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Metodo de ordenamiento Counting Sort modificado
void CountingSort(int vector[], int numElementos, int pesoDigito, int max){
    
	int aux[10][numElementos];	// Matriz auxiliar para la colocacion de los numeros segun el i-esimo digito
    int pos = 0;		// Variable que nos ayuda a colocar los numeros en el arreglo inicial cuando los vayamos a mover
    int contadores[10];	// Arreglo que usamos para los contadores de los digitos del 0-9
    
	// Inicializacion de los contadores en 0
    for(int i = 0; i < 10; i++){
        contadores[i] = 0;
    }
	// Movemos los datos a la matriz auxiliar
	for(int i=0; i<numElementos; i++){
		aux[(vector[i] / pesoDigito) % 10][contadores[(vector[i] / pesoDigito) % 10]] = vector[i];
		contadores[(vector[i] / pesoDigito) % 10]++; // Realizamos el conteo por digito
	}
	// Regresamos los valores pero ordenamos al arreglo inicial
	for(int i=0; i<10; i++){
   		for(int j=0; j<contadores[i]; j++){
   			vector[pos] = aux[i][j];
   			pos++;
		}
 	}
}

// Metodo de ordenamiento Radix Sort LSD
void RadixSort(int vector[], int numElementos){
	
    int max = Maximo(vector, numElementos);
    for (int pesoDigito = 1; max / pesoDigito > 0; pesoDigito *= 10){
        CountingSort(vector, numElementos, pesoDigito, max);
	}
}


int main() {

    int n;
	
	cout<<"Ingrese el numero de elementos a insertar: ";
	cin>>n;
	int vector[n];
	
	system("cls");
	for(int i = 0; i< n ; i++){
		cout<<"Ingrese valor " <<i+1 <<": ";
		cin>>vector[i];
	}
	
	system("cls");
	cout<<"Arreglo Inicial: ";
	for(int i = 0; i < n; i++){
		cout<<vector[i] <<"  ";
	}
	
	cout<<"\n\n";
    RadixSort(vector, n);
    cout << "\nArreglo Ordenado: ";
    for(int i = 0; i < n; i++){
        cout<<vector[i] << " ";
    }
    
    cout<<"\n\n";
    return 0;
}
