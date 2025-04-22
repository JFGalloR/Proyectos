#include <iostream>
#include <cstdlib>

using namespace std;

// Estructura para la lista enlazada
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para imprimir la lista enlazada
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo* cabeza = NULL; // Inicializar la lista enlazada como vacía
    Nodo* actual = NULL; // Inicializar el nodo actual como vacío
    int opcion, valor;
    do {
        // Mostrar el menú
        system("cls");
        cout << "======== MENU DE LISTA ENLAZADA ========" << endl;
        cout << "    1. Agregar elemento" << endl;
        cout << "    2. Imprimir lista" << endl;
        cout << "    3. Salir" << endl;
        cout << "> Ingrese su opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1: // Agregar elemento a la lista
                cout << "Ingrese el valor del elemento: ";
                cin >> valor;
                if (cabeza == NULL) { // Si la lista está vacía
                    cabeza = new Nodo;
                    cabeza->dato = valor;
                    cabeza->siguiente = NULL;
                    actual = cabeza;
                } else { // Si la lista ya tiene elementos
                    Nodo* nuevo = new Nodo;
                    nuevo->dato = valor;
                    nuevo->siguiente = NULL;
                    actual->siguiente = nuevo;
                    actual = nuevo;
                }
                break;
            case 2: // Imprimir la lista
                cout << "La lista es: ";
                imprimirLista(cabeza);
                break;
            case 3: // Salir del programa
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
        system("pause");
    } while (opcion != 3);
    // Liberar la memoria de la lista enlazada
    Nodo* temp = cabeza;
    while (temp != NULL) {
        cabeza = cabeza->siguiente;
        delete temp;
        temp = cabeza;
    }
    return 0;
}

