//
// Created by Jonathan Panchana Rodríguez on 19/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Crea una función que reciba una lista enlazada de números enteros y elimine
* todos los nodos que contengan números pares. La función debe retornar la cantidad de
* nodos eliminados y mostrar la lista resultante. */

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Algoritmo de eliminación
int eliminarPares (Nodo*& cabeza) {
    int eliminados = 0;
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->dato % 2 == 0) { // Verificar si el número es par
            Nodo* temp = actual;
            if (anterior == nullptr) { // Eliminar cabeza
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            actual = actual->siguiente;
            delete temp;
            eliminados++;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
    return eliminados;
}

// Función para mostrar la lista
void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " → ";
        actual = actual->siguiente;
    }
    cout << "nullptr" << endl;
}

// Función principal
int main () {
    Nodo* cabeza = new Nodo{3, nullptr};
    cabeza->siguiente = new Nodo{4, nullptr};
    cabeza->siguiente->siguiente = new Nodo{7, nullptr};
    cabeza->siguiente->siguiente->siguiente = new Nodo{10, nullptr};
    cabeza->siguiente->siguiente->siguiente->siguiente = new Nodo{15, nullptr};

    cout << "Lista original: ";
    mostrarLista(cabeza);

    int eliminados = eliminarPares(cabeza);
    cout << "Cantidad de nodos eliminados: " << eliminados << endl;

    cout << "Lista resultante: ";
    mostrarLista(cabeza);

    // Liberar memoria restante
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}