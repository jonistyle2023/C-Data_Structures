cmake_minimum_required(VERSION 3.31)
project(_c__DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(_c__DataStructures main.cpp)
# EJECUTABLES DE LA UNIDAD 1
## PRÁCTICAS
add_executable(notasPromedio 01_Estructuras_Arreglos/practicas/01_arregloDinamico_notasPromedio.cpp)
add_executable(nombresEdades 01_Estructuras_Arreglos/practicas/02_arregoPunteros_nombresEdades.cpp)
## TAREAS
add_executable(inventarioProductos 01_Estructuras_Arreglos/tareas/A1-E1_inventarioProductos.cpp)
add_executable(registroPacientes 01_Estructuras_Arreglos/tareas/A1-E2_registroDePacientes.cpp)
