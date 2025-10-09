/* Implemente un programa que mediante el uso de árboles me permita
 * verificar cuánto suman los elementos pares que almacena.
 * Como restricción me dan que debo utilizar el recorrido postorden.
 * El usuario debe decidir cuántos elementos desea ingresar al árbol.
 */

#include <iostream>
using namespace std;

// --- Nodo del Árbol ---
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    explicit Nodo(int x) :
        dato(x),
        izq(nullptr), der(nullptr) {}
};

// --- Insertar ---
bool insertar(Nodo*& r, int x) {
    if (!r) {  // árbol vacío
        r = new Nodo(x);
        return true;
    }
    if (x < r->dato) return insertar(r->izq, x);
    if (x > r->dato) return insertar(r->der, x);
    return false; // valor duplicado
}

// --- Recorridos ---
void preorden(Nodo* r) { // raíz - izq - der
    if (!r) return;
    cout << r->dato << " ";
    preorden(r->izq);
    preorden(r->der);
}

void inorden(Nodo* r) {    // izq - raíz - der
    if (!r) return;
    inorden(r->izq);
    cout << r->dato << " ";
    inorden(r->der);
}

void postorden(Nodo* r) {         // izq - der - raíz
    if (!r) return;
    postorden(r->izq);
    postorden(r->der);
    cout << r->dato << " ";
}

// postorden que suma pares (utiliza postorden como recorrido)
void postordenSumarPares(Nodo* r, int &suma) {
    if (!r) return;
    postordenSumarPares(r->izq, suma);
    postordenSumarPares(r->der, suma);
    if ((r->dato % 2) == 0) suma += r->dato;
}

//--- Liberar memoria ---
void liberar(Nodo* r) {
    if (!r) return;
    liberar(r->izq);
    liberar(r->der);
    delete r;
}

// --- Programa principal ---
int main() {
    Nodo* raiz = nullptr;
    int n;
    cout << "ARBOL BINARIO - SUMA DE PARES (recorrido POSTORDEN)\n";
    cout << "Cuantos elementos insertara?: ";
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        int valor;
        cout << "Valor #" << i << ": ";
        cin >> valor;
        if (!insertar(raiz, valor)) {
            cout << "  >> Valor duplicado, no se inserto. Reingrese otro valor.\n";
            --i; // volver a pedir
        }
    }

    // Solo por aplicar, también imprime los otros recorridos
    cout << "\nRECORRIDOS DEL ARBOL\n";
    cout << "Preorden  (raiz-izq-der): ";
    preorden(raiz);
    cout << "\nInorden   (izq-raiz-der): ";
    inorden(raiz);
    cout << "\nPostorden (izq-der-raiz): ";
    postorden(raiz);
    cout << "\n";

    // inicializamos la suma en 0 y llamamos a la función
    int sumaPares = 0;
    postordenSumarPares(raiz, sumaPares);
    // mostramos el resultado (solo en postorden)
    cout << "\nLa suma de los elementos pares (recorrido postorden) es: " << sumaPares << "\n";

    liberar(raiz);
    return 0;
}
