#include <iostream>
using namespace std;

// Estructura del nodo de la lista doble
struct NodoD {
    int dato;
    NodoD *prev;
    NodoD *next;
};

bool listaVaciaD(NodoD *cabecera) { return cabecera == NULL; }

void insertarInicioD(NodoD *&cabecera, int valor) {
    NodoD *nuevo = new NodoD;
    nuevo->dato = valor;
    nuevo->prev = NULL;
    nuevo->next = cabecera;
    if (!listaVaciaD(cabecera)) cabecera->prev = nuevo;
    cabecera = nuevo;
}

void insertarFinalD(NodoD *&cabecera, int valor) {
    NodoD *nuevo = new NodoD;
    nuevo->dato = valor;
    nuevo->prev = NULL;
    nuevo->next = NULL;

    if (listaVaciaD(cabecera)) {
        cabecera = nuevo;
        return;
    }

    NodoD *actual = cabecera;
    while (actual->next != NULL) actual = actual->next;
    actual->next = nuevo;
    nuevo->prev = actual;
}

NodoD *buscarD(NodoD *cabecera, int valor) {
    NodoD *actual = cabecera;
    while (actual != NULL) {
        if (actual->dato == valor) return actual;
        actual = actual->next;
    }
    return NULL;
}

void eliminarPrimeroD(NodoD *&cabecera) {
    if (listaVaciaD(cabecera)) return;
    NodoD *tmp = cabecera;
    cabecera = cabecera->next;
    if (cabecera != NULL) cabecera->prev = NULL;
    delete tmp;
}

bool eliminarValorD(NodoD *&cabecera, int valor) {
    if (listaVaciaD(cabecera)) return false;


    if (cabecera->dato == valor) {
        eliminarPrimeroD(cabecera);
        return true;
    }

    NodoD *actual = cabecera->next;
    while (actual != NULL) {
        if (actual->dato == valor) {
            if (actual->prev != NULL) actual->prev->next = actual->next;
            if (actual->next != NULL) actual->next->prev = actual->prev;
            delete actual;
            return true;
        }
        actual = actual->next;
    }
    return false;
}

void mostrarAdelante(NodoD *cabecera) {
    if (listaVaciaD(cabecera)) {
        cout << "Lista vacia\n";
        return;
    }
    NodoD *actual = cabecera;
    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        actual = actual->next;
    }
    cout << "NULL\n";
}

void mostrarAtras(NodoD *cabecera) {
    if (listaVaciaD(cabecera)) {
        cout << "Lista vacia\n";
        return;
    }
    // Ir al último
    NodoD *actual = cabecera;
    while (actual->next != NULL) actual = actual->next;
    // Volver hacia atras
    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        actual = actual->prev;
    }
    cout << "NULL\n";
}

void liberarListaD(NodoD *&cabecera) {
    while (cabecera != NULL) {
        NodoD *tmp = cabecera;
        cabecera = cabecera->next;
        delete tmp;
    }
}

/* Esta es la función principal que recorre la lista
 * doblemente enlazada y verifica si en cada
 * tercer nodo el valor almacenado es 10
 */
bool verificarCadaTercerNodo(NodoD *cabecera) {
    if (listaVaciaD(cabecera)) {
        return true;
    }

    NodoD *actual = cabecera;
    int contador = 1;
    bool cumple = true;

    while (actual != NULL) {
        if (contador % 3 == 0) {
            if (actual->dato != 10) {
                cumple = false;
                break;
            }
        }
        actual = actual->next;
        contador++;
    }
    return cumple;
}

int main() {
    NodoD *cabecera = NULL;
    NodoD *cabecera2 = NULL;

    cout << "--- Ejemplo con cumplimiento ---" << "\n";
    insertarFinalD(cabecera, 5);
    insertarFinalD(cabecera, 15);
    insertarFinalD(cabecera, 10); // es 10
    insertarFinalD(cabecera, 25);
    insertarFinalD(cabecera, 35);
    insertarFinalD(cabecera, 10);
    insertarFinalD(cabecera, 45);
    insertarFinalD(cabecera, 55);
    insertarFinalD(cabecera, 10);

    cout << "Lista: ";
    mostrarAdelante(cabecera);

    if (verificarCadaTercerNodo(cabecera)) {
        cout << "?? El requerimiento se cumple: cada 3er nodo es 10." << "\n";
    } else {
        cout << "? El requerimiento NO se cumple." << "\n";
    }

    liberarListaD(cabecera);

    cout << "\n--- Ejemplo sin cumplimiento ---" << "\n";
    insertarFinalD(cabecera2, 5);
    insertarFinalD(cabecera2, 15);
    insertarFinalD(cabecera2, 20); // no es 10
    insertarFinalD(cabecera2, 25);
    insertarFinalD(cabecera2, 35);
    insertarFinalD(cabecera2, 10);

    cout << "Lista: ";
    mostrarAdelante(cabecera2);

    if (verificarCadaTercerNodo(cabecera2)) {
        cout << "El requerimiento se cumple: cada 3er nodo es 10." << "\n";
    } else {
        cout << "El requerimiento NO se cumple." << "\n";
    }

    liberarListaD(cabecera2);

    return 0;
}
