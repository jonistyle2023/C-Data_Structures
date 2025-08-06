//
// Created by Jonathan Panchana Rodríguez on 28/7/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

// Bloque de declaraciones
// Declaramos las librerías que vamos a utilizar
#include <iostream>
// Bloque de uso de espacio de nombres
using namespace std;

int main() {
    int n;
    cout << "Cuantas notas desea ingresar ?: ";
    cin >> n;

    float* notas = new float[n];
    float suma = 0;

    for (int i = 0; i < n; ++i) {
        float nota;
        do {
            cout << "Nota # " << (i + 1) << ": ";
            cin >> nota;
            if (nota < 0 || nota > 10) {
                cout << "La nota debe estar entre 0 y 10. Intente de nuevo.\n";
            }
        } while (nota < 0 || nota > 10);
        notas[i] = nota;
        suma += nota;
    }

    cout << "\nContenido del arreglo:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante # " << (i + 1) << ": " << notas[i] << endl;
    }

    cout << "\nEl promedio del curso es: " << (suma / n) << endl;

    delete[] notas;
    return 0;
}