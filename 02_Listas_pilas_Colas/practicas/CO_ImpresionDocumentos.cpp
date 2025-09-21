//
// Created by Jonathan Panchana Rodríguez on 20/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Simular el proceso de impresión de documentos con dos colas: una para documentos de alta
 * prioridad (urgentes) y otra para prioridad normal. Se debe atender siempre 1 documento urgente por
 * cada 3 documentos normales. Si no hay documentos normales, se atienden urgentes y viceversa.
 * Ejemplo:
 * - Urgentes: [DocA, DocB, DocC]
 * - Normales: [Doc1, Doc2, Doc3, Doc4, Doc5]
 * - Orden de impresión: DocA -> Doc1 -> Doc2 -> Doc3 -> DocB -> Doc4 -> Doc5 -> DocC
 */


#include <iostream>
using namespace std;

struct Node {
    int dato;
    Node* siguiente;
};

// Algoritmo de impresión de documentos
void imprimirDocumentos(Node*& urgentes, Node*& normales) {
    int contadorNormales = 0;

    while (urgentes != nullptr || normales != nullptr) {
        // Imprimir un documento urgente si hay
        if (urgentes != nullptr) {
            cout << "Imprimiendo documento urgente: " << urgentes->dato << endl;
            Node* temp = urgentes;
            urgentes = urgentes->siguiente;
            delete temp;
        }

        // Imprimir hasta 3 documentos normales
        while (contadorNormales < 3 && normales != nullptr) {
            cout << "Imprimiendo documento normal: " << normales->dato << endl;
            Node* temp = normales;
            normales = normales->siguiente;
            delete temp;
            contadorNormales++;
        }
        contadorNormales = 0; // Reiniciar el contador después de imprimir normales
    }
}

// Función para agregar un documento a la cola
void encolar(Node*& tope, int dato) {
    Node* nuevoNodo = new Node{dato, nullptr};
    if (tope == nullptr) {
        tope = nuevoNodo;
    } else {
        Node* actual = tope;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función principal
int main() {
    Node* urgentes = nullptr;
    Node* normales = nullptr;
    encolar(urgentes, 101); // DocA
    encolar(urgentes, 102); // DocB
    encolar(urgentes, 103); // DocC
    encolar(normales, 201);  // Doc1
    encolar(normales, 202);  // Doc2
    encolar(normales, 203);  // Doc3
    encolar(normales, 204);  // Doc4
    encolar(normales, 205);  // Doc5

    imprimirDocumentos(urgentes, normales);
    return 0;
}