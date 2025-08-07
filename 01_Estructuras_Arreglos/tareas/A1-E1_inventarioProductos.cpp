// CONTROL DE INVENTARIO DE PRODUCTOS
// Una tienda desea gestionar su inventario de productos. Cada producto debe almacenar: Codigo , Nombre , Precio , Estado = Activo e Inactivo
// El programa debe tener un menu de opciones que permita:
// 1.Ingresar los datos de todos los productos( el usuario decide cuantos quiere registrar
// 2.Mostrar todos los productos registrados
// 3.Mostrar todos los productos activos o inactivos ( el usuario elige)
//4. Finalizar el programa

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

struct producto {
	int codigo;
	string nombre;
	float precio;
	char estado;
};

const int Max_productos = 100;

int main() {
	int op;
	int est;

	producto inventario[Max_productos];
	int productos_registrados = 0;

	do {
		cout << "-----------INVENTARIO-------------" << endl;
		cout << "1.INGRESAR PRODUCTO" << endl;
		cout << "2.MOSTRAR PRODUCTOS" << endl;
		cout << "3.MOSTRAR PRODUCTOS ACTIVOS O INACTIVOS" << endl;
		cout << "4.Cerrar inventario" << endl;
		cout << "Seleccione una opcion: ";
		cin >> op;

		switch (op) {
			case 1: {
				int cantidad_registrar = 0;
				cout << "Cuantos productos desea registrar?" << endl;
				cin >> cantidad_registrar;

				if (productos_registrados + cantidad_registrar > Max_productos) {
					cout << "El inventario esta lleno!" << endl;
					cout << "Solo puede registrar hasta " << Max_productos - productos_registrados << "productos." <<
							endl;
					break;
				}

				for (int i = 0; i < cantidad_registrar; ++i) {
					cout << "--- Ingrese datos para el producto " << i + 1 << " de " << cantidad_registrar << endl;
					cout << "Ingrese el codigo del producto: ";
					cin >> inventario[productos_registrados].codigo;
					cout << "Ingrese el nombre del producto: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, inventario[productos_registrados].nombre);
					cout << "Ingrese el precio del producto: ";
					cin >> inventario[productos_registrados].precio;
					cout << "Ingrese el estado del producto (A/I): ";
					cin >> inventario[productos_registrados].estado;
					inventario[productos_registrados].estado = toupper(inventario[productos_registrados].estado);
					productos_registrados++;
					cout << "Producto agregado con exito." << endl;
				}
			}
			break;
			case 2:
				cout << "-------PRODUCTOS REGISTRADOS---------" << endl;
				if (productos_registrados == 0) {
					cout << "No hay productos en el inventario." << endl;
				} else {
					for (int i = 0; i < productos_registrados; ++i) {
						cout << "---------------------------------" << endl;
						cout << "Codigo:" << inventario[i].codigo << endl;
						cout << "Nombre:" << inventario[i].nombre << endl;
						cout << "Precio:$" << inventario[i].precio << endl;
						cout << "Estado: ";
						if (inventario[i].estado == 'A') {
							cout << "Activo" << endl;
						} else {
							cout << "Inactivo" << endl;
						}
					}
				}
				break;

			case 3:
				cout << "Filtrar productos por estado:" << endl;
				cout << "1.Activos" << endl;
				cout << "2.Inactivos" << endl;
				cout << "Seleccione: ";
				cin >> est; {
					bool encontrado = false;
					char estado_buscado;

					if (est == 1) {
						estado_buscado = 'A';
						cout << "--- PRODUCTOS ACTIVOS ---" << endl;
					} else if (est == 2) {
						estado_buscado = 'I';
						cout << "--- PRODUCTOS INACTIVOS ---" << endl;
					} else {
						cout << "Opcion de estado no valida." << endl;
						break;
					}

					for (int i = 0; i < productos_registrados; ++i) {
						if (inventario[i].estado == estado_buscado) {
							cout << "---------------------------------" << endl;
							cout << "Codigo: " << inventario[i].codigo << endl;
							cout << "Nombre: " << inventario[i].nombre << endl;
							cout << "Precio: $" << inventario[i].precio << endl;
							encontrado = true;
						}
					}
					if (!encontrado) {
						cout << "No se encontraron productos con ese estado." << endl;
					}
				}
				break;
			case 4:
				cout << "Cerrando inventario" << endl;
				break;

			default:
				cout << "Opcion no valida. Intente de nuevo." << endl;
				break;
		}
	} while (op != 4);

	return 0;
}
