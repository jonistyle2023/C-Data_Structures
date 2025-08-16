//
// Created by Jonathan Panchana Rodríguez on 16/8/2025.
// You can review this code and more in: https://github.com/jonistyle2023/C-Data_Structures
//

// Bloque de Declaraciones
// Librerías necesarias
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Para std::fixed y std::setprecision

// Nota; En esta occasion no se usa el espacio entre nombres

// Estructuras de datos (obligatorias según el literal 3 de la tarea)
struct RegistroNota {
    int codigo;
    float nota;
};

struct RegistroAlumno {
    int codigo;
    std::string nombre;
};

// --- Prototipos de funciones auxiliares ---

// Función Booleana para verificar si un código de alumno ya existe
bool codigoAlumnoExiste(int codigo, const RegistroAlumno *alumnos, int tamano);

// Esta función es para buscar el nombre de un alumno por su código
std::string buscarNombrePorCodigo(int codigo, const RegistroAlumno *alumnos, int n_alumnos);


int main() {
    // --- 1. Ingreso dinámico ---
    int n_notas, n_alumnos;

    std::cout << "Ingrese la cantidad de registros de notas: ";
    std::cin >> n_notas;

    std::cout << "Ingrese la cantidad de registros de alumnos: ";
    std::cin >> n_alumnos;

    // Reserva de memoria para los arreglos dinámicos
    RegistroNota *notas = new RegistroNota[n_notas];
    RegistroAlumno *alumnos = new RegistroAlumno[n_alumnos];

    std::cout << "\n--- Captura de datos de Alumnos ---\n";
    // --- 2. Captura de datos ---
    for (int i = 0; i < n_alumnos; ++i) {
        std::cout << "Registro de Alumno #" << i + 1 << std::endl;
        int codigo_temp;

        // Validar que el código no se repita
        while (true) {
            std::cout << "Codigo: ";
            std::cin >> codigo_temp;
            if (!codigoAlumnoExiste(codigo_temp, alumnos, i)) {
                alumnos[i].codigo = codigo_temp;
                break;
            } else {
                std::cout << "Error: El codigo ya existe. Intente con otro.\n";
            }
        }

        std::cout << "Nombre completo: ";
        std::cin.ignore(); // Limpiar el buffer antes de getline
        std::getline(std::cin, alumnos[i].nombre);
    }

    std::cout << "\n--- Captura de datos de Notas ---\n";
    for (int i = 0; i < n_notas; ++i) {
        std::cout << "Registro de Nota #" << i + 1 << std::endl;
        std::cout << "Codigo: ";
        std::cin >> notas[i].codigo;

        float nota_temp;
        // Aquí se valida que la nota esté en el rango [0, 100]
        while (true) {
            std::cout << "Nota: ";
            std::cin >> nota_temp;
            if (nota_temp >= 0 && nota_temp <= 100) {
                notas[i].nota = nota_temp;
                break;
            } else {
                std::cout << "Error: La nota debe estar entre 0 y 100. Vuelva a intentarlo.\n";
            }
        }
    }

    // --- 5. Salida (reporte) ---
    std::cout << "\n\n==== REPORTE DE CALIFICACIONES =======================================\n";
    std::cout << std::left << std::setw(10) << "CODIGO" << "| "
            << std::setw(30) << "NOMBRE" << "| "
            << std::setw(10) << "NOTA" << "| "
            << "ESTADO\n";
    std::cout << "---------------------------------------------------------------------\n";

    int aprobados = 0;
    int reprobados = 0;

    // --- 3. Unión por código y el literal 4.Reglas de negocio ---
    for (int i = 0; i < n_notas; ++i) {
        std::string nombre_estudiante = buscarNombrePorCodigo(notas[i].codigo, alumnos, n_alumnos);
        std::string estado;

        if (notas[i].nota >= 70.0) {
            estado = "Aprobado";
            aprobados++;
        } else {
            estado = "Reprobado";
            reprobados++;
        }

        std::cout << std::left << std::setw(10) << notas[i].codigo << "| "
                << std::setw(30) << nombre_estudiante << "| "
                << std::fixed << std::setprecision(2) << std::setw(10) << notas[i].nota << "| "
                << estado << std::endl;
    }

    std::cout << "\n======== RESUMEN =====================================================\n";
    std::cout << "Total evaluados: " << n_notas << std::endl;

    // Calcular porcentajes
    float porc_aprobados = (n_notas > 0) ? (static_cast<float>(aprobados) / n_notas) * 100.0f : 0.0f;
    float porc_reprobados = (n_notas > 0) ? (static_cast<float>(reprobados) / n_notas) * 100.0f : 0.0f;

    std::cout << "Aprobados: " << aprobados << " (" << std::fixed << std::setprecision(2) << porc_aprobados << "%)" <<
            std::endl;
    std::cout << "Reprobados: " << reprobados << " (" << std::fixed << std::setprecision(2) << porc_reprobados << "%)"
            << std::endl;
    std::cout << "====================================================================\n";

    // --- 6. Limpieza ---
    delete[] notas;
    delete[] alumnos;

    return 0;
}


// --- Implementación de funciones auxiliares ---

bool codigoAlumnoExiste(int codigo, const RegistroAlumno *alumnos, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        if (alumnos[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}

std::string buscarNombrePorCodigo(int codigo, const RegistroAlumno *alumnos, int n_alumnos) {
    for (int i = 0; i < n_alumnos; ++i) {
        if (alumnos[i].codigo == codigo) {
            return alumnos[i].nombre;
        }
    }
    return "DESCONOCIDO"; // En caso de que no se encuentre el código
}
