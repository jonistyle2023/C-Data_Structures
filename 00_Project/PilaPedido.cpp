// Bloque de declaraciones
#include <iostream>
#include <string>
// espacio entre nombres
using namespace std;

// Estructura para los datos de un producto
struct Producto {
    int id;
    string nombre;
    double precio;
};

// Estructura para un item del pedido (producto y cantidad)
struct ItemPedido {
    Producto producto;
    int cantidad;
    ItemPedido *link;
};

// Estructura para un pedido del cliente
struct Pedido {
    int id;
    string cliente;
    ItemPedido *items;
};

// Estructura para un nodo de la cola de pedidos
struct NodoPedido {
    Pedido pedido;
    NodoPedido *link;
};

struct NodoHistorial {
    Pedido pedido;
    NodoHistorial *link;
};

struct NodoProducto {
    Producto producto;
    NodoProducto* link;
};

NodoHistorial* topeHistorial = NULL;

bool listaVaciaProductos(NodoProducto* cabecera) {
    return cabecera == NULL;
}

void insertarProducto(NodoProducto*& cabecera, Producto prod) {
    NodoProducto* nuevo = new NodoProducto;
    nuevo->producto = prod;
    nuevo->link = NULL;

    if (listaVaciaProductos(cabecera)) {
        cabecera = nuevo;
        return;
    }

    NodoProducto* actual = cabecera;
    while (actual->link != NULL) {
        actual = actual->link;
    }
    actual->link = nuevo;
}

void mostrarProductos(NodoProducto* cabecera) {
    if (listaVaciaProductos(cabecera)) {
        cout << "La lista de productos esta vacia." << endl;
        return;
    }

    cout << "\n--- LISTA DE PRODUCTOS ---" << endl;
    NodoProducto* actual = cabecera;
    while (actual != NULL) {
        cout << "ID: " << actual->producto.id << ", Nombre: " << actual->producto.nombre << ", Precio: $" << actual->producto.precio << endl;
        actual = actual->link;
    }
    cout << "--------------------------" << endl;
}

Producto* buscarProducto(NodoProducto* cabecera, int id) {
    NodoProducto* actual = cabecera;
    while (actual != NULL) {
        if (actual->producto.id == id) {
            return &actual->producto;
        }
        actual = actual->link;
    }
    return NULL;
}

bool colaVaciaPedidos(NodoPedido *frente) {
    return frente == NULL;
}

// insertar un pedido al final de la cola
void enter(NodoPedido *&frente, NodoPedido *&final, Pedido p) {
    NodoPedido *nuevo = new NodoPedido;
    nuevo->pedido = p;
    nuevo->link = NULL;

    if (colaVaciaPedidos(frente)) {
        frente = nuevo;
    } else {
        final->link = nuevo;
    }
    final = nuevo;
    cout << "Se ingreso el pedido de '" << p.cliente << "' a la cola.\n";
}

void apilarHistorial(Pedido p) {
    NodoHistorial* nuevo = new NodoHistorial;
    nuevo->pedido = p;
    nuevo->link = topeHistorial;
    topeHistorial = nuevo;
}

void mostrarHistorial() {
    if (topeHistorial == NULL) {
        cout << "\nEl historial de pedidos esta vacio." << endl;
        return;
    }

    cout << "\n=== HISTORIAL DE PEDIDOS ATENDIDOS ===" << endl;
    NodoHistorial* actual = topeHistorial;
    int contador = 0;
    double totalRecaudado = 0.0;

    while (actual != NULL) {
        contador++;

        cout << "\n--- Pedido #" << contador << " ---" << endl;
        cout << "ID Pedido: " << actual->pedido.id << endl;
        cout << "Cliente: " << actual->pedido.cliente << endl;
        cout << "Productos:" << endl;

        double totalPedido = 0.0;
        ItemPedido* itemActual = actual->pedido.items;
        while (itemActual != NULL) {
            double subtotal = itemActual->cantidad * itemActual->producto.precio;
            totalPedido += subtotal;
            cout << "  - " << itemActual->cantidad << "x " << itemActual->producto.nombre
                 << " ($" << itemActual->producto.precio << " c/u) = $" << subtotal << endl;
            itemActual = itemActual->link;
        }

        totalRecaudado += totalPedido;
        cout << "Total: $" << totalPedido << endl;
        cout << "---------------------" << endl;

        actual = actual->link;
    }

    cout << "\n=== METRICAS ===" << endl;
    cout << "Total de pedidos atendidos: " << contador << endl;
    cout << "Total recaudado: $" << totalRecaudado << endl;

    if (topeHistorial != NULL) {
        cout << "Ultimo pedido atendido: #" << topeHistorial->pedido.id
             << " - " << topeHistorial->pedido.cliente << endl;
    }
    cout << "========================" << endl;
}

// eliminar y atender el pedido del frente de la cola
void leave(NodoPedido *&frente, NodoPedido *&final) {
    if (colaVaciaPedidos(frente)) {
        cout << "La cola de pedidos esta vacia." << endl;
        return;
    }

    NodoPedido *tmp = frente;
    frente = frente->link;

    if (frente == NULL) final = NULL;

    cout << "\n--- PEDIDO ATENDIDO ---" << endl;
    cout << "ID Pedido: " << tmp->pedido.id << endl;
    cout << "Cliente: " << tmp->pedido.cliente << endl;
    double total = 0.0;

    ItemPedido* itemActual = tmp->pedido.items;
    while (itemActual != NULL) {
        cout << "  - " << itemActual->cantidad << "x " << itemActual->producto.nombre << " ($" << itemActual->producto.precio << ")" << endl;
        total += itemActual->cantidad * itemActual->producto.precio;
        itemActual = itemActual->link;
    }

    cout << "Total a pagar: $" << total << endl;
    cout << "------------------------" << endl;

    Pedido copiaPedido;
    copiaPedido.id = tmp->pedido.id;
    copiaPedido.cliente = tmp->pedido.cliente;
    copiaPedido.items = NULL;

    // Copiar los items del pedido
    ItemPedido* itemOriginal = tmp->pedido.items;
    ItemPedido* ultimoItemCopia = NULL;
    while (itemOriginal != NULL) {
        ItemPedido* nuevoItem = new ItemPedido;
        nuevoItem->producto = itemOriginal->producto;
        nuevoItem->cantidad = itemOriginal->cantidad;
        nuevoItem->link = NULL;

        if (copiaPedido.items == NULL) {
            copiaPedido.items = nuevoItem;
        } else {
            ultimoItemCopia->link = nuevoItem;
        }
        ultimoItemCopia = nuevoItem;
        itemOriginal = itemOriginal->link;
    }

    // Apilar en el historial
    apilarHistorial(copiaPedido);

    // Liberar la lista de ítems del pedido original
    ItemPedido* itemTemp = tmp->pedido.items;
    while (itemTemp != NULL) {
        ItemPedido* aBorrar = itemTemp;
        itemTemp = itemTemp->link;
        delete aBorrar;
    }

    delete tmp;
}

void liberarListaProductos(NodoProducto*& cabecera) {
    while (cabecera != NULL) {
        NodoProducto* tmp = cabecera;
        cabecera = cabecera->link;
        delete tmp;
    }
}

void liberarColaPedidos(NodoPedido*& frente, NodoPedido*& final) {
    while (frente != NULL) {
        NodoPedido* tmp = frente;
        frente = frente->link;
        delete tmp;
    }
    final = NULL;
    cout << "Cola de pedidos liberada." << endl;
}

void liberarHistorial() {
    while (topeHistorial != NULL) {
        NodoHistorial* tmp = topeHistorial;
        topeHistorial = topeHistorial->link;

        // Liberar items del pedido
        ItemPedido* itemTemp = tmp->pedido.items;
        while (itemTemp != NULL) {
            ItemPedido* aBorrar = itemTemp;
            itemTemp = itemTemp->link;
            delete aBorrar;
        }

        delete tmp;
    }
}

void mostrarMenu() {
    cout << "\n===== MENU SUPERMERCADO =====" << endl;
    cout << "1) Registrar producto" << endl;
    cout << "2) Mostrar productos" << endl;
    cout << "3) Agregar pedido" << endl;
    cout << "4) Atender pedido" << endl;
    cout << "5) Ver historial" << endl;
    cout << "6) Salir" << endl;
    cout << "=============================" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    NodoProducto* listaProductos = NULL;
    NodoPedido* colaPedidosFrente = NULL;
    NodoPedido* colaPedidosFinal = NULL;
    int opcion;
    int contadorProductoID = 1;
    int contadorPedidoID = 1;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                Producto nuevoProducto;
                nuevoProducto.id = contadorProductoID++;
                cout << "Ingrese el nombre del producto: ";
                getline(cin, nuevoProducto.nombre);
                cout << "Ingrese el precio del producto: ";
                cin >> nuevoProducto.precio;
                insertarProducto(listaProductos, nuevoProducto);
                cout << "Producto registrado con exito!" << endl;
                break;
            }
            case 2:
                mostrarProductos(listaProductos);
                break;
            case 3: {
                if (listaVaciaProductos(listaProductos)) {
                    cout << "Debe registrar productos primero." << endl;
                    break;
                }

                Pedido nuevoPedido;
                nuevoPedido.id = contadorPedidoID++;
                nuevoPedido.items = NULL;
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, nuevoPedido.cliente);

                int prodId, cantidad;
                char agregarMas;

                do {
                    mostrarProductos(listaProductos);
                    cout << "Ingrese el ID del producto que desea agregar: ";
                    cin >> prodId;
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidad;

                    Producto* prodEncontrado = buscarProducto(listaProductos, prodId);
                    if (prodEncontrado != NULL) {
                        ItemPedido* nuevoItem = new ItemPedido;
                        nuevoItem->producto = *prodEncontrado;
                        nuevoItem->cantidad = cantidad;
                        nuevoItem->link = NULL;

                        if (nuevoPedido.items == NULL) {
                            nuevoPedido.items = nuevoItem;
                        } else {
                            ItemPedido* ultimoItem = nuevoPedido.items;
                            while (ultimoItem->link != NULL) {
                                ultimoItem = ultimoItem->link;
                            }
                            ultimoItem->link = nuevoItem;
                        }
                        cout << "Producto agregado al pedido." << endl;
                    } else {
                        cout << "ID de producto no valido." << endl;
                    }

                    cout << "Desea agregar otro producto? (s/n): ";
                    cin >> agregarMas;
                } while (agregarMas == 's' || agregarMas == 'S');

                enter(colaPedidosFrente, colaPedidosFinal, nuevoPedido);
                cin.ignore();
                break;
            }
            case 4:
                leave(colaPedidosFrente, colaPedidosFinal);
                break;
            case 5:
                mostrarHistorial();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    liberarListaProductos(listaProductos);
    liberarColaPedidos(colaPedidosFrente, colaPedidosFinal);
    liberarHistorial();
    return 0;
}