//
// Created by Group #5 on 20/8/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

// Bloque de declaraciones
#include <iostream>
#include <string>
// Espacio de nombres
using namespace std;

// Estructura de Producto
struct Producto {
    int id;
    string nombre;
    float precio;
    Producto *siguiente;
};

// Puntero al inicio de la lista *lista
Producto *lista = nullptr;

// Función para registrar producto
void registrarProducto() {
    Producto *nuevo = new Producto();

    cout << "\n--- Registro de Producto ---\n";
    cout << "Ingrese ID del producto: ";
    cin >> nuevo->id;

    // Validación de ID
    if (nuevo->id <= 0) {
        cout << "Error: El ID debe ser un número positivo.\n";
        delete nuevo;
        return;
    }

    cin.ignore(); // limpiar buffer
    cout << "Ingrese nombre del producto: ";
    getline(cin, nuevo->nombre);

    // Validación de nombre
    if (nuevo->nombre.empty()) {
        cout << "Error: El nombre no puede estar vacío.\n";
        delete nuevo;
        return;
    }

    cout << "Ingrese precio del producto: ";
    cin >> nuevo->precio;

    // Validación de precio
    if (nuevo->precio <= 0) {
        cout << "Error: El precio debe ser mayor que 0.\n";
        delete nuevo;
        return;
    }

    // Insertar al inicio de la lista
    nuevo->siguiente = lista;
    lista = nuevo;

    cout << "Producto registrado exitosamente.\n";
}

// Función para mostrar productos
void mostrarProductos() {
    if (lista == nullptr) {
        cout << "\nNo hay productos registrados.\n";
        return;
    }

    cout << "\n--- Lista de Productos ---\n";
    Producto *actual = lista;
    while (actual != nullptr) {
        cout << "ID: " << actual->id
                << " | Nombre: " << actual->nombre
                << " | Precio: $" << actual->precio << "\n";
        actual = actual->siguiente;
    }
}

// Función principal con menú
int main() {
    int opcion;

    do {
        cout << "\n===== MENU SUPERMERCADO =====\n";
        cout << "1) Registrar producto\n";
        cout << "2) Mostrar productos\n";
        cout << "3) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}
