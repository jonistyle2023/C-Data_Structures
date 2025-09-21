//
// Created by Jonathan Panchana Rodríguez on 20/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Dada una lista enlazada de números enteros, invertir los nodos de dos en dos. Si la cantidad
 * de nodos es impar, el último nodo permanece en su posición.
 * Ejemplo:
 * - Lista original: 1 → 2 → 3 → 4 → 5 → nullptr
 * - Lista resultante: 2 → 1 → 4 → 3 → 5 → nullptr
 */

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Algoritmo de inversión
void ivertirNodos (Nodo*& cabeza) {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return; // Lista vacía o con un solo nodo

    Nodo* actual = cabeza;
    Nodo* nuevoCabeza = cabeza->siguiente; // Nueva cabeza será el segundo nodo
    Nodo* prev = nullptr;

    while (actual != nullptr && actual->siguiente != nullptr) {
        Nodo* siguientePar = actual->siguiente->siguiente; // Guardar el nodo después del par
        Nodo* segundo = actual->siguiente;

        // Invertir el par
        segundo->siguiente = actual;
        if (prev != nullptr) {
            prev->siguiente = segundo; // Conectar con el par anterior
        }
        actual->siguiente = siguientePar; // Conectar con el siguiente par

        // Mover los punteros
        prev = actual;
        actual = siguientePar;
    }
    cabeza = nuevoCabeza; // Actualizar la cabeza de la lista
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
    Nodo* cabeza = new Nodo{1, nullptr};
    cabeza->siguiente = new Nodo{2, nullptr};
    cabeza->siguiente->siguiente = new Nodo{3, nullptr};
    cabeza->siguiente->siguiente->siguiente = new Nodo{4, nullptr};
    cabeza->siguiente->siguiente->siguiente->siguiente = new Nodo{5, nullptr};

    mostrarLista(cabeza);
    ivertirNodos(cabeza);
    mostrarLista(cabeza);
    return 0;
}