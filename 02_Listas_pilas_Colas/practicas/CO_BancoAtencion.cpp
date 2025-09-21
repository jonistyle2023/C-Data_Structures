//
// Created by Jonathan Panchana Rodríguez on 20/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/*
 * Problema: Simular un proceso de atención en un banco donde hay 2 colas: una para clientes regulares y otra para clientes prioritarios
 * (mayores de 65 años). Atender siempre 1 prioritario por cada 2 regulares.
 */

#include<iostream>
using namespace std;

struct Cliente {
    string nombre;
    int edad;
};

struct Nodo {
    Cliente cliente;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* final;
};

bool estaVacia(Cola& cola) {
    return cola.frente == nullptr;
}

void encolar(Cola& cola, Cliente cliente) {
    Nodo* nuevo = new Nodo{cliente, nullptr};
    if (estaVacia((cola))) {
        cola.frente = cola.final = nuevo;
    } else {
        cola.final->siguiente = nuevo;
        cola.final = nuevo;
    }
}

Cliente desencolar (Cola& cola) {
    if (estaVacia(cola)) throw runtime_error("Cola vacía");
    Nodo* temp = cola.frente;
    Cliente cli = temp->cliente;
    cola.frente = temp->siguiente;
    if (cola.frente == nullptr) cola.final = nullptr;
    delete temp;
    return cli;
}

// Algoritmo de atención
void atenderClientes(Cola& regulares, Cola& prioritarios) {
    int contador = 0;

    while (!estaVacia(prioritarios) || !estaVacia(regulares)) {
        if (contador % 3 != 0 && !estaVacia(prioritarios)) {
            // Atender prioritario (cada 3 clientes)
            Cliente actual = desencolar(prioritarios);
            cout <<"Atendiendo prioritario: " << actual.nombre << endl;
        } else if (!estaVacia(regulares)) {
            // atender regulares
            Cliente actual = desencolar(regulares);
            cout << "Atendiendo regular: " << actual.nombre << endl;
        }
        contador++;
    }
}

int main() {
    Cola regulares{nullptr, nullptr}, prioritarios{nullptr, nullptr};

    encolar(prioritarios, {"Ana", 70});
    encolar(prioritarios, {"Carlos", 68});
    encolar(regulares, {"Luis", 30});
    encolar(regulares, {"Mar", 30});
    encolar(regulares, {"Jose", 40});

    atenderClientes(regulares, prioritarios);

    return 0;
}