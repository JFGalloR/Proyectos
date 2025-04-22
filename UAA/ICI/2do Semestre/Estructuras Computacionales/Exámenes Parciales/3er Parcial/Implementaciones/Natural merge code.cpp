/*
Elaboró:
- OLga Daniela Calderón Amezcua
- Yaretzi Castillo Morales
- David Iván Gándara Vazquez
*/

#include <iostream>
using namespace std;

// Función para mezclar naturalmente dos subarreglos ordenados
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
	
	//Para rastrear las posiciones en los subarreglos left, right y el arreglo principal arr
    int i = 0, j = 0, k = 0;

//Compara los elementos actuales de left y right.
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

// Para copiar los elementos restantes en arr
    while (i < leftSize)
        arr[k++] = left[i++];

    while (j < rightSize)
        arr[k++] = right[j++];
}

// Función principal para la mezcla natural
void naturalMergeSort(int arr[], int n) {
    if (n <= 1)
        return;
        
// Esta variable se utilizará para determinar si el arreglo está ordenado o no
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int start = 0; // posición inicial de la secuencia
        
// Para encontrar secuencias ordenadas en el arreglo.
        while (start < n - 1) {
            int mid = start + 1;
            while (mid < n && arr[mid - 1] <= arr[mid])
                mid++;

            int end = mid + 1; //end representaría el final de la secuencia
            while (end < n && arr[end - 1] <= arr[end])
                end++;
                
//Después de encontrar una secuencia ordenada, se verifica si hay más elementos después de la secuencia
            if (end <= n) {
                int leftSize = mid - start; //contiene los elementos desde start hasta mid
                int rightSize = end - mid; //que contiene los elementos desde mid hasta end

                int left[leftSize], right[rightSize];

                for (int i = 0; i < leftSize; i++)
                    left[i] = arr[start + i];
                for (int i = 0; i < rightSize; i++)
                    right[i] = arr[mid + i];
// Se llama a la función merge para combinar los subarreglos left y right en el arreglo principal arr
                merge(arr + start, left, leftSize, right, rightSize);
                
                //se establece sorted = false para indicar que el arreglo no está completamente ordenado.
                sorted = false;
            }

            start = end;
        }
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Ejemplo de uso
int main() {
    int arr[] = {9, 5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: ";
    printArray(arr, n);

    naturalMergeSort(arr, n);

    cout << "Arreglo ordenado: ";
    printArray(arr, n);

    return 0;
}
