//
// Created by Jonathan Panchana Rodríguez on 19/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/*
 * Problema: Implementa una función que reciba una lista enlazada de números enteros y elimine
 * todos los nodos que contengan números duplicados, dejando sola la primera aparición de cada
 * número. La función debe retornar de nodos eliminados y mostrar la lista resultante.
 */

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Algoritmo de eliminación
int eliminarDuplicados (Nodo*& cabeza) {
    int eliminados = 0;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        Nodo* runner = actual;
        while (runner->siguiente != nullptr) {
            if (runner->siguiente->dato == actual->dato) {
                Nodo* temp = runner->siguiente;
                runner->siguiente = runner->siguiente->siguiente;
                delete temp;
                eliminados++;
            } else {
                runner = runner->siguiente;
            }
        }
        actual = actual->siguiente;
    }
    return eliminados;
}

// Función para mostrar la lista
void mostrarLista (Nodo*& cabeza) {
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
    cabeza->siguiente = new Nodo{5, nullptr};
    cabeza->siguiente->siguiente = new Nodo{3, nullptr};
    cabeza->siguiente->siguiente->siguiente = new Nodo{2, nullptr};
    cabeza->siguiente->siguiente->siguiente->siguiente = new Nodo{5, nullptr};
    cabeza->siguiente->siguiente->siguiente->siguiente->siguiente = new Nodo{7, nullptr};

    cout << "Lista original: ";
    mostrarLista(cabeza);

    int eliminados = eliminarDuplicados(cabeza);
    cout << "Nodos eliminados: " << eliminados << endl;

    cout << "Lista resultante: ";
    mostrarLista(cabeza);

    // Liberar memoria
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
