#include <iostream>
using namespace std;

void merge(int arr[], int left[], int n1, int right[], int n2) {
    int i = 0, j = 0, k = 0;	

    while (i < n1 && j < n2) {		//Realiza un switch para ordenar el arreglo izq o derecho
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)		//Ordena el arreglo original con referencia del arreglo auxiliar izq
        arr[k++] = left[i++];

    while (j < n2)		//Ordena el arreglo original con referencia del arreglo auxiliar der
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int n) {	//Divide en 2 y se habla a si misma y al merge
    if (n < 2)		//Caso base
        return;

    int mid = n / 2;	//Division del arreglo en dos, el izq y el derecho
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)	//Recorrido del izquierdo
        left[i] = arr[i];

    for (int i = mid; i < n; i++)	//Recorrido del derecho
        right[i - mid] = arr[i];

    mergeSort(left, mid);		//Llamada de la funcion para cada mitad
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);	//Llamada a la funcion de ordenacion
}

int main() {
    int arr[] = { 5, 9, 1, 3, 6, 2, 7 };	//Ingreso manual del arreglo
    int n = sizeof(arr) / sizeof(arr[0]);	//Deteccion del tamaño

    cout << "Lista original: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, n);		//Llamada de la funcion

    cout << "\nLista ordenada: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

