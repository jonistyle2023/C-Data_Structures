//
// Created by Jonathan Panchana Rodríguez on 1/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//
#include <iostream>
#include <stack>

int main() {
    std::stack<int> pila;
    // Ejemplo: llenando la pila con algunos valores
    pila.push(5);
    pila.push(8);
    pila.push(3);
    pila.push(12);
    pila.push(7);
    pila.push(4);

    int contadorPares = 0;

    std::cout << "Numeros pares en la pila:\n";
    while (!pila.empty()) {
        int elemento = pila.top();
        if (elemento % 2 == 0) {
            std::cout << elemento << "\n";
            contadorPares++;
        }
        pila.pop();
    }

    std::cout << "Total de numeros pares encontrados: " << contadorPares << std::endl;
    return 0;
}