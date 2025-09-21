//
// Created by Jonathan Panchana Rodríguez on 20/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Implementar una función que reciba una pila de números enteros y elimine todos los elementos duplicados consecutivos.
 * La pila debe quedar con elementos únicos consecutivos:
 * Ejemplo:
 * - Pila original (tope a la izquierda): 3-> 3 -> 2 -> 4 -> 4 -> 4 -> 1 -> NULL
 * - Pila resultante: 3 -> 2 -> 4 -> 1 -> NULL
 */

#include <iostream>
using namespace std;

struct Node {
    int dato;
    Node* siguiente;
};

bool esDuplicado(Node* tope) {
    if (tope == nullptr || tope->siguiente == nullptr) {
        return false; // No hay duplicados en una pila vacía o con un solo elemento
    }

    Node* actual = tope;
    while (actual->siguiente != nullptr) {
        if (actual->dato == actual->siguiente->dato) {
            return true; // Se encontró un duplicado consecutivo
        }
        actual = actual->siguiente;
    }
    return false; // No se encontraron duplicados consecutivos
}

// Función para eliminar duplicados consecutivos
void eliminarDuplicadosConsecutivos(Node*& tope) {
    if (tope == nullptr) return; // Pila vacía
    Node* actual = tope;
    while (actual != nullptr && actual->siguiente != nullptr) {
        if (actual->dato == actual->siguiente->dato) {
            Node* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp; // Eliminar el nodo duplicado
        } else {
            actual = actual->siguiente; // Avanzar al siguiente nodo
        }
    }
}

// Función para mostrar la pila
void mostrarPila(Node* tope) {
    Node* actual = tope;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

// Función principal
int main() {
    Node* tope = new Node{3, nullptr};
    tope->siguiente = new Node{3, nullptr};
    tope->siguiente->siguiente = new Node{2, nullptr};
    tope->siguiente->siguiente->siguiente = new Node{4, nullptr};
    tope->siguiente->siguiente->siguiente->siguiente = new Node{4, nullptr};
    tope->siguiente->siguiente->siguiente->siguiente->siguiente = new Node{4, nullptr};
    tope->siguiente->siguiente->siguiente->siguiente->siguiente = new Node{1, nullptr};
    tope->siguiente->siguiente->siguiente->siguiente->siguiente->siguiente = nullptr;
    cout << "Pila original: ";
    mostrarPila(tope);
    eliminarDuplicadosConsecutivos(tope);
    cout << "Pila después de eliminar duplicados consecutivos: ";
    mostrarPila(tope);
    // Liberar memoria
    while (tope != nullptr) {
        Node* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
    return 0;
}

