//
// Created by Jonathan Panchana Rodríguez on 19/9/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

/* Problema: Implementar una función que reciba una pila de caracteres y determine si los paréntesis están
 * balanceados. Solo considerar '(' y ')'.
 */

#include <iostream>
#include <stack>
using namespace std;

bool parentesisBalanceados (string expresion) {
    stack<char> pila;

    for (char c : expresion) {
        if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            if (pila.empty() || pila.top() != '(') {
                return false; // Paréntesis de cierre sin apertura
            }
            pila.pop();
        }
    }
    return pila.empty();
}

int main() {
    cout << boolalpha;
    cout << parentesisBalanceados("(a + b)") << endl;         // true
    cout << parentesisBalanceados("((a + b) * c)") << endl;   // true
    cout << parentesisBalanceados("(a + b))") << endl;        // false
    cout << parentesisBalanceados("((a + b)") << endl;        // false
    return 0;
}