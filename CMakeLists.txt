cmake_minimum_required(VERSION 3.31)
project(_c__DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(_c__DataStructures main.cpp)

# PROJECT
add_executable(listaMenu 00_Project/listaMenu.cpp)
add_executable(ColaAtencion 00_Project/ColaAtencion.cpp)
add_executable(PilaPedido 00_Project/PilaPedido.cpp)

# EJECUTABLES DE LA UNIDAD 1
## PRÁCTICAS
add_executable(notasPromedio 01_Estructuras_Arreglos/practicas/01_arregloDinamico_notasPromedio.cpp)
add_executable(nombresEdades 01_Estructuras_Arreglos/practicas/02_arregoPunteros_nombresEdades.cpp)

## TAREAS
add_executable(inventarioProductos 01_Estructuras_Arreglos/tareas/A1-E1_inventarioProductos.cpp)
add_executable(registroPacientes 01_Estructuras_Arreglos/tareas/A1-E2_registroDePacientes.cpp)
add_executable(reporteCalificaciones 01_Estructuras_Arreglos/tareas/T2-reporteCalificaciones.cpp)

# EJECUTABLES DE LA UNIDAD 2
## PRÁCTICAS
add_executable(pilasPares 02_Listas_pilas_Colas/practicas/PI_PilaPares.cpp)
add_executable(LeEliminarPrimos 02_Listas_pilas_Colas/practicas/LE_EliminarPrimos.cpp)
add_executable(LeEliminarPares 02_Listas_pilas_Colas/practicas/LE_EliminarPares.cpp)
add_executable(LeEliminarDuplicados 02_Listas_pilas_Colas/practicas/LE_EliminarDuplicados.cpp)
add_executable(pilaCaracteres 02_Listas_pilas_Colas/practicas/PI_pilaCaracteres.cpp)
add_executable(BancoAtencion 02_Listas_pilas_Colas/practicas/CO_BancoAtencion.cpp)
add_executable(nvertirNodos 02_Listas_pilas_Colas/practicas/LE_InvertirNodos.cpp)
add_executable(PiEliminarDuplicados 02_Listas_pilas_Colas/practicas/PI_EliminarDuplicados.cpp)
add_executable(ColaImpresionDocumentos 02_Listas_pilas_Colas/practicas/CO_ImpresionDocumentos.cpp)
## TAREAS
add_executable(listasEnlazadasDobles 02_Listas_pilas_Colas/tareas/listas_dobles_enlazadas.cpp)