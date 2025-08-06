//
// Created by Jonathan Panchana Rodríguez on 6/8/2025.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string aMayusculas(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

struct Persona {
    string nombre;
    int edad;
};

int main() {
    int n;
    do {
        cout << "Cuantos elementos requiere ingresar? ";
        cin >> n;
    } while (n <= 0);

    Persona *lista = new Persona[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string nombre;
        int edad;

        cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
        getline(cin, nombre);
        lista[i].nombre = aMayusculas(nombre);

        cout << "Ingrese la edad de la persona " << i + 1 << ": ";
        cin >> edad;
        cin.ignore();
        lista[i].edad = edad;
    }

    string buscando;
    cout << "Ingrese el nombre de la persona que desea buscar: ";
    getline(cin, buscando);
    buscando = aMayusculas(buscando);

    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (lista[i].nombre == buscando) {
            encontrado = true;
            cout << "Persona encontrada: " << lista[i].nombre << ", Edad: " << lista[i].edad << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "No hay coincidencias de nombres" << endl;
    }

    delete[] lista;
    return 0;
}
