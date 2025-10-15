//
// Created by Jonathan Panchana Rodríguez on 14/10/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class Graph {
private:
    std::map<std::string, std::vector<std::string>> adj;

    static bool contains(const std::vector<std::string> &v, const std::string &x) {
        return std::find(v.begin(), v.end(), x) != v.end();
    }

public:
    // Añade un nuevo usuario (nodo). Si ya existe, no hace nada.
    void addUser(const std::string &user) {
        if (adj.find(user) == adj.end()) {
            adj[user] = {};
        }
    }

    // Establece amistad (arista) no dirigida entre a y b. Crea usuarios si no existen.
    void addFriendship(const std::string &a, const std::string &b) {
        if (a == b) return; // evitar auto-aristas
        addUser(a);
        addUser(b);
        if (!contains(adj[a], b)) adj[a].push_back(b);
        if (!contains(adj[b], a)) adj[b].push_back(a);
    }

    // Devuelve los amigos de un usuario. Si no existe, devuelve vector vacío.
    std::vector<std::string> getFriends(const std::string &user) const {
        auto it = adj.find(user);
        if (it == adj.end()) return {};
        return it->second;
    }

    // Imprime la lista de adyacencia completa.
    void printAll() const {
        for (const auto &p : adj) {
            std::cout << p.first << ": [";
            for (size_t i = 0; i < p.second.size(); ++i) {
                std::cout << p.second[i];
                if (i + 1 < p.second.size()) std::cout << ", ";
            }
            std::cout << "]\n";
        }
    }
};

int main() {
    Graph red;
    // Usuarios y amistades del ejemplo
    red.addUser("Juan");
    red.addUser("Maria");
    red.addUser("Pedro");
    red.addUser("Ana");

    red.addFriendship("Juan", "Maria");
    red.addFriendship("Juan", "Pedro");
    red.addFriendship("Maria", "Ana");

    // Mostrar lista de adyacencia
    red.printAll();

    // Ejemplo de obtener amigos de Maria
    auto amigos = red.getFriends("Maria");
    std::cout << "Amigos de Maria: [";
    for (size_t i = 0; i < amigos.size(); ++i) {
        std::cout << amigos[i];
        if (i + 1 < amigos.size()) std::cout << ", ";
    }
    std::cout << "]\n";

    return 0;
}