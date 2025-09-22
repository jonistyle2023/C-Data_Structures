//
// Created by Jonathan Panchana Rodríguez on 21/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Dada una lista enlazada de números enteros, eliminar todos los nodos que tengan valores
 * dentro de un rango [a, b] (inclusive) especificado por el usuario. Retornar la cantidad de nodos
 * eliminados; Ejemplo:
 * - Lista original 5 -> 10 -> 15 -> 20 -> 25 -> NULL
 * - Rango [12, 22]
 * - Lista resultante 5 -> 10 -> 25 -> NULL
 * - Nodos eliminados: 2 (15 y 20)
 */

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

//Función de eliminación de nodos en un rango [a, b]
int eliminarNodosEnRango(Nodo*& cabeza, int a, int b) {
    int contadorEliminados = 0;
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->dato >= a && actual->dato <= b) {
            Nodo* nodoAEliminar = actual;
            if (anterior == nullptr) {
                cabeza = actual->siguiente; // Eliminar el nodo cabeza
            } else {
                anterior->siguiente = actual->siguiente; // Saltar el nodo a eliminar
            }
            actual = actual->siguiente; // Mover al siguiente nodo
            delete nodoAEliminar; // Liberar memoria
            contadorEliminados++;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
    return contadorEliminados;
}

// Función para insertar un nuevo nodo al final de la lista
void insertarNodo(Nodo*& cabeza, int dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL" << endl;
}

int main() {
    Nodo* cabeza = nullptr;

    // Crear una lista de ejemplos
    insertarNodo(cabeza, 5);
    insertarNodo(cabeza, 10);
    insertarNodo(cabeza, 15);
    insertarNodo(cabeza, 20);
    insertarNodo(cabeza, 25);

    cout << "Lista original: ";
    imprimirLista(cabeza);

    int a, b;
    cout << "Ingrese el rango [a, b] para eliminar nodos: ";
    cin >> a >> b;

    int nodosEliminados = eliminarNodosEnRango(cabeza, a, b);

    cout << "Lista resultante: ";
    imprimirLista(cabeza);
    cout << "Nodos eliminados: " << nodosEliminados << endl;

    // Liberar memoria restante
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}