//
// Created by Jonathan Panchana Rodríguez on 21/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Implementar una función que reciba una pila de números enteros y reemplace todos los
 * valores negativos por cero, manteniendo el resto de la pila intacta.
 * Ejemplo:
 * - Pila original (tope a la izquierda): -2 -> 5 -> -3 -> 0 -> 7 -> -1 -> NULL
 * - Pila resultante: 0 -> 5 -> 0 -> 0 -> 7 -> 0 -> NULL
 */

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Pila {
    Nodo* tope;
};

void inicializarPila(Pila& pila) {
    pila.tope = nullptr;
}

bool pilaVacia(Pila& pila) {
    return pila.tope == nullptr;
}

void push(Pila& pila, int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = pila.tope;
    pila.tope = nuevoNodo;
}

int pop(Pila& pila) {
    if (pilaVacia(pila)) {
        cout << "La pila esta vacia." << endl;
        return -1; // Valor de error
    }
    Nodo* nodoTemp = pila.tope;
    int valor = nodoTemp->dato;
    pila.tope = pila.tope->siguiente;
    delete nodoTemp;
    return valor;
}

void reemplazarNegativosPorCero(Pila& pila) {
    Pila pilaAuxiliar;
    inicializarPila(pilaAuxiliar);

    // Transferir elementos a la pila auxiliar, reemplazando negativos por cero
    while (!pilaVacia(pila)) {
        int valor = pop(pila);
        if (valor < 0) {
            push(pilaAuxiliar, 0);
        } else {
            push(pilaAuxiliar, valor);
        }
    }

    // Transferir de vuelta a la pila original para mantener el orden
    while (!pilaVacia(pilaAuxiliar)) {
        int valor = pop(pilaAuxiliar);
        push(pila, valor);
    }
}

void mostrarPila(Pila& pila) {
    Pila pilaAuxiliar;
    inicializarPila(pilaAuxiliar);

    // Transferir elementos a la pila auxiliar para mostrarlos
    while (!pilaVacia(pila)) {
        int valor = pop(pila);
        cout << valor << " -> ";
        push(pilaAuxiliar, valor);
    }
    cout << "NULL" << endl;

    // Transferir de vuelta a la pila original para mantener el orden
    while (!pilaVacia(pilaAuxiliar)) {
        int valor = pop(pilaAuxiliar);
        push(pila, valor);
    }
}

int main() {
    Pila pila;
    inicializarPila(pila);

    // Llenar la pila con algunos valores de ejemplo
    push(pila, -2);
    push(pila, 5);
    push(pila, -3);
    push(pila, 0);
    push(pila, 7);
    push(pila, -1);

    cout << "Pila original:" << endl;
    mostrarPila(pila);

    reemplazarNegativosPorCero(pila);

    cout << "Pila despues de reemplazar negativos por cero:" << endl;
    mostrarPila(pila);

    return 0;
}