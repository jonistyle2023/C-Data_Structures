//
// Created by Jonathan Panchana Rodríguez on 21/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Simular un sistema de turnos en un hospital con tres colas de prioridad:
 * - Prioridad Alta (pacientes críticos)
 * - Prioridad Media (pacientes urgentes)
 * - Prioridad Baja (pacientes estables)
 * Se debe atender en el siguiente orden: 2 altos -> 1 medio -> 1 bajo. Si alguna cola se vacía, se continúa
 * con el patrón con las colas restantes.
 * Ejemplo:
 * - Alta: [P1, P2, P3]
 * - Media: [P4, P5]
 * - Baja: [P6, P7, P8]
 * - Orden de atención: P1 -> P2 -> P4 -> P6 -> P3 -> P5 -> P7 -> P8
 */

#include <iostream>
using namespace std;

const int MAX = 100;
struct Paciente {
    string nombre;
    int prioridad; // 1: Alta, 2: Media, 3: Baja
};

struct Cola {
    Paciente pacientes[MAX];
    int frente, final;
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

bool encolar(Cola &c, Paciente p) {
    if (colaLlena(c)) return false;
    c.pacientes[++c.final] = p;
    return true;
}

bool desencolar(Cola &c, Paciente &p) {
    if (colaVacia(c)) return false;
    p = c.pacientes[c.frente++];
    return true;
}

void atenderPacientes(Cola &alta, Cola &media, Cola &baja) {
    Paciente p;
    int contadorAlta = 0;

    while (!colaVacia(alta) || !colaVacia(media) || !colaVacia(baja)) {
        // Atender dos pacientes de alta prioridad
        for (int i = 0; i < 2; i++) {
            if (desencolar(alta, p)) {
                cout << "Atendiendo paciente de alta prioridad: " << p.nombre << endl;
                contadorAlta++;
            }
        }
        // Atender un paciente de media prioridad
        if (desencolar(media, p)) {
            cout << "Atendiendo paciente de media prioridad: " << p.nombre << endl;
        }
        // Atender un paciente de baja prioridad
        if (desencolar(baja, p)) {
            cout << "Atendiendo paciente de baja prioridad: " << p.nombre << endl;
        }
    }
}

int main() {
    Cola alta, media, baja;
    inicializarCola(alta);
    inicializarCola(media);
    inicializarCola(baja);

    // Agregar pacientes a las colas
    encolar(alta, {"P1", 1});
    encolar(alta, {"P2", 1});
    encolar(alta, {"P3", 1});
    encolar(media, {"P4", 2});
    encolar(media, {"P5", 2});
    encolar(baja, {"P6", 3});
    encolar(baja, {"P7", 3});
    encolar(baja, {"P8", 3});

    // Atender pacientes según la prioridad
    atenderPacientes(alta, media, baja);

    return 0;
}