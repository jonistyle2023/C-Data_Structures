//
// Created by Jonathan Panchana Rodríguez on 21/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Implementar una función que reciba una pila de números enteros y separe los números pares
 * e impares en dos pilas diferentes, manteniendo el orden relativo original dentro de cada pila.
 * Ejemplo:
 * - Pila original (tope a la izquierda): 3 -> 8 -> 5 -> 2 -> 7 -> 4 -> NULL
 * - Pilas resultantes:
 *  - Pares: 8 -> 2 -> 4 -> NULL
 *  - Impares: 3 -> 5 -> 7 -> NULL
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
        cout << "Error: Pila vacía" << endl;
        return -1; // Valor de error
    }
    Nodo* nodoTemp = pila.tope;
    int valor = nodoTemp->dato;
    pila.tope = pila.tope->siguiente;
    delete nodoTemp;
    return valor;
}

void separarParesImpares(Pila& pilaOriginal, Pila& pilaPares, Pila& pilaImpares) {
    Pila pilaAuxiliar;
    inicializarPila(pilaAuxiliar);

    // Paso 1: Invertir la pila original para mantener el orden relativo
    while (!pilaVacia(pilaOriginal)) {
        int valor = pop(pilaOriginal);
        push(pilaAuxiliar, valor);
    }

    // Paso 2: Separar los números pares e impares
    while (!pilaVacia(pilaAuxiliar)) {
        int valor = pop(pilaAuxiliar);
        if (valor % 2 == 0) {
            push(pilaPares, valor);
        } else {
            push(pilaImpares, valor);
        }
    }
}

void imprimirPila(Pila& pila) {
    Pila pilaAuxiliar;
    inicializarPila(pilaAuxiliar);

    // Invertir la pila para imprimir en orden correcto
    while (!pilaVacia(pila)) {
        int valor = pop(pila);
        push(pilaAuxiliar, valor);
    }

    // Imprimir y restaurar la pila original
    while (!pilaVacia(pilaAuxiliar)) {
        int valor = pop(pilaAuxiliar);
        cout << valor << " -> ";
        push(pila, valor); // Restaurar la pila original
    }
    cout << "NULL" << endl;
}

int main() {
    Pila pilaOriginal, pilaPares, pilaImpares;
    inicializarPila(pilaOriginal);
    inicializarPila(pilaPares);
    inicializarPila(pilaImpares);

    // Llenar la pila original con algunos números
    push(pilaOriginal, 3);
    push(pilaOriginal, 8);
    push(pilaOriginal, 5);
    push(pilaOriginal, 2);
    push(pilaOriginal, 7);
    push(pilaOriginal, 4);

    cout << "Pila original: ";
    imprimirPila(pilaOriginal);

    separarParesImpares(pilaOriginal, pilaPares, pilaImpares);

    cout << "Pila de pares: ";
    imprimirPila(pilaPares);

    cout << "Pila de impares: ";
    imprimirPila(pilaImpares);

    return 0;
}