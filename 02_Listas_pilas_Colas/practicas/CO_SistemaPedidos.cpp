//
// Created by Jonathan Panchana Rodríguez on 21/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Implementar un sistema de procesamiento de pedidos de una tienda en línea con dos colas:
 * - Cola Express (pedidos con envío urgente)
 * - Cola Regular (pedidos con envío estándar)
 * Se deben procesar 3 pedidos Express por cada 5 pedidos Regulares. Si en algún momento no hay
 * pedidos de un tipo, se procesan solo del otro tipo. Mostrar el orden en que se procesan los pedidos.
 * Ejemplo:
 * - Express: [E1, E2, E3, E4, E5]
 * - Regular: [R1, R2, R3, R4, R5, R6, R7]
 * - Orden de procesamiento: E1 -> E2 -> E3 -> R1 -> R2 -> R3 -> R4 -> R5 -> E4 -> E5 -> R6 -> R7
 */

#include <iostream>
using namespace std;

const int MAX = 100;
struct Pedido {
    string id;
    string tipo; // "Express" o "Regular"
};

struct Cola {
    Pedido pedidos[MAX];
    int frente;
    int final;
};

void inicializarCola(Cola &c) {
    c.frente = 0;
    c.final = -1;
}

bool colaVacia(Cola c) {
    return c.frente > c.final;
}

bool colaLlena(Cola c) {
    return c.final == MAX - 1;
}

bool encolar(Cola &c, Pedido p) {
    if (colaLlena(c)) {
        return false;
    }
    c.pedidos[++c.final] = p;
    return true;
}

bool desencolar(Cola &c, Pedido &p) {
    if (colaVacia(c)) {
        return false;
    }
    p = c.pedidos[c.frente++];
    return true;
}

void procesarPedidos(Cola &express, Cola &regular) {
    int countExpress = 0, countRegular = 0;
    Pedido p;
    cout << "Orden de procesamiento de pedidos:\n";
    while (!colaVacia(express) || !colaVacia(regular)) {
        // Procesar hasta 3 pedidos Express
        while (countExpress < 3 && !colaVacia(express)) {
            desencolar(express, p);
            cout << p.id << " (" << p.tipo << ")\n";
            countExpress++;
        }
        countExpress = 0; // Reiniciar contador de Express
        // Procesar hasta 5 pedidos Regular
        while (countRegular < 5 && !colaVacia(regular)) {
            desencolar(regular, p);
            cout << p.id << " (" << p.tipo << ")\n";
            countRegular++;
        }
        countRegular = 0; // Reiniciar contador de Regular
    }
}

int main() {
    Cola express, regular;
    inicializarCola(express);
    inicializarCola(regular);
    // Agregar pedidos de ejemplo
    encolar(express, {"E1", "Express"});
    encolar(express, {"E2", "Express"});
    encolar(express, {"E3", "Express"});
    encolar(express, {"E4", "Express"});
    encolar(express, {"E5", "Express"});
    encolar(regular, {"R1", "Regular"});
    encolar(regular, {"R2", "Regular"});
    encolar(regular, {"R3", "Regular"});
    encolar(regular, {"R4", "Regular"});
    encolar(regular, {"R5", "Regular"});
    encolar(regular, {"R6", "Regular"});
    encolar(regular, {"R7", "Regular"});
    // Procesar los pedidos
    procesarPedidos(express, regular);
    return 0;
}