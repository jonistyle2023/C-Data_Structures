//
// Created by Jonathan Panchana Rodríguez on 21/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Simular el sistema de atención en un call center con tres niveles de soporte:
 * - Nivel 1 (soporte básico)
 * - Nivel 2 (soporte técnico)
 * - Nivel 3 (soporte especializado)
 * Las llamadas deben ser transferidas entre colas según estas reglas:
 * - Una llamada en Nivel 2 que no se resuelve en 2 intentos pasa a Nivel 2
 * - Una llamada en Nivel 2 que no se resuelve en 3 intentos pasa a Nivel 3
 * - Una llamada en Nivel 3 se considera resuelta siempre
 * Simular el flujo de 10 llamadas iniciales en Nivel 1 y mostrar cómo se distribuyen finalmente en las colas.
 */

#include <iostream>
using namespace std;

const int MAX = 100;
struct Llamada {
    string id;
    int intentos; // Número de intentos de resolución
};

struct Cola {
    Llamada llamadas[MAX];
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

bool encolar(Cola &c, Llamada l) {
    if (colaLlena(c)) {
        return false;
    }
    c.llamadas[++c.final] = l;
    return true;
}

bool desencolar(Cola &c, Llamada &l) {
    if (colaVacia(c)) {
        return false;
    }
    l = c.llamadas[c.frente++];
    return true;
}

void mostrarColaFinal(const Cola &c, const string &nombreNivel) {
    cout << nombreNivel << ": ";
    if (colaVacia(c)) {
        cout << "Sin llamadas" << endl;
        return;
    }
    for (int i = c.frente; i <= c.final; i++) {
        cout << c.llamadas[i].id << " (intentos: " << c.llamadas[i].intentos << ") ";
    }
    cout << endl;
}

void procesarLlamadas(Cola &nivel1, Cola &nivel2, Cola &nivel3) {
    Llamada l;
    while (!colaVacia(nivel1) || !colaVacia(nivel2) || !colaVacia(nivel3)) {
        // Procesar llamadas de Nivel 1
        if (!colaVacia(nivel1)) {
            desencolar(nivel1, l);
            cout << "Procesando llamada " << l.id << " en Nivel 1" << endl;
            l.intentos++;
            if (l.intentos == 2) {
                cout << "Llamada " << l.id << " no resuelta en Nivel 1, pasando a Nivel 2" << endl;
                encolar(nivel2, l);
            } else if (l.intentos < 2) {
                cout << "Llamada " << l.id << " resuelta en Nivel 1" << endl;
            }
        }

        // Procesar llamadas de Nivel 2
        if (!colaVacia(nivel2)) {
            desencolar(nivel2, l);
            cout << "Procesando llamada " << l.id << " en Nivel 2" << endl;
            l.intentos++;
            if (l.intentos == 3) {
                cout << "Llamada " << l.id << " no resuelta en Nivel 2, pasando a Nivel 3" << endl;
                encolar(nivel3, l);
            } else if (l.intentos < 3) {
                cout << "Llamada " << l.id << " resuelta en Nivel 2" << endl;
            }
        }

        // Procesar llamadas de Nivel 3
        if (!colaVacia(nivel3)) {
            desencolar(nivel3, l);
            cout << "Procesando llamada " << l.id << " en Nivel 3" << endl;
            cout << "Llamada " << l.id << " resuelta en Nivel 3" << endl;
        }
    }
}

int main() {
    Cola nivel1, nivel2, nivel3;
    inicializarCola(nivel1);
    inicializarCola(nivel2);
    inicializarCola(nivel3);

    // Simular 10 llamadas iniciales en Nivel 1
    for (int i = 1; i <= 10; i++) {
        Llamada l = {"Llamada_" + to_string(i), 0};
        encolar(nivel1, l);
    }

    procesarLlamadas(nivel1, nivel2, nivel3);

    cout << "\nDistribución final de llamadas en las colas:" << endl;
    mostrarColaFinal(nivel1, "Nivel 1");
    mostrarColaFinal(nivel2, "Nivel 2");
    mostrarColaFinal(nivel3, "Nivel 3");

    return 0;
}