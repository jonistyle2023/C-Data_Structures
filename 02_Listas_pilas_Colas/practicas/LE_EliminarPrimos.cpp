//
// Created by Jonathan Panchana Rodríguez on 19/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Dada una lista enlazada de números enteros, eliminar todos los nodos que contengan números
 * primos y retornar la cantidad de nodos eliminados
 */

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para verificar si un número es primo
bool esPrimo (int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Algoritmo de eliminación
int eliminarPrimo (Nodo*& cabeza) {
    int eliminados = 0;
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (esPrimo (actual->dato)) {
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
    cout << "NULL" << endl;
}

// Función principal para probar el algoritmo
int main() {
    // Crear la lista: 2 → 4 → 5 → 7 → 9 → NULL
    Nodo* cabeza = new Nodo{2, nullptr};
    cabeza->siguiente = new Nodo{4, nullptr};
    cabeza->siguiente->siguiente = new Nodo{5, nullptr};
    cabeza->siguiente->siguiente->siguiente = new Nodo{7, nullptr};
    cabeza->siguiente->siguiente->siguiente->siguiente = new Nodo{9, nullptr};

    cout << "Lista original: ";
    mostrarLista(cabeza);

    int eliminados = eliminarPrimo(cabeza);

    cout << "Lista resultante: ";
    mostrarLista(cabeza);

    cout << "Nodos eliminados: " << eliminados << endl;

    // Liberar memoria restante
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}

