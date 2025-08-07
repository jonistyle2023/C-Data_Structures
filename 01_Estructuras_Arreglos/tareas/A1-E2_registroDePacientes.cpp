/*Una clínica desea llevar el registro de sus pacientes. Cada paciente debe tener:
Nombre completo
Edad
Motivo de consulta (cadena)
Prioridad (entero del 1 al 5, donde 1 es mayor urgencia)
El programa debe permitir lo siguiente mediante un men�:
1. Ingresar los datos de todos los pacientes (el usuario decide cuántos).
2. Mostrar la lista de todos los pacientes.
3. Mostrar solo los pacientes cuya prioridad sea igual o menor a 2 (m�s urgentes).
4. Mostrar el nombre del paciente más joven registrado.
5. Finalizar el programa.*/

#include <iostream>
#include <string>
using namespace std;

struct Paciente
{
    string nombre;
    int edad;
    string motivo;
    int prioridad;
};

int main()
{
    Paciente lista[100];
    int total = 0;
    int opcion;

    do
	{
        cout<<"\nMENU DE OPCIONES\n";
        cout<<"1. Ingresar pacientes\n";
        cout<<"2. Mostrar todos\n";
        cout<<"3. Mostrar urgentes (prioridad 1-2)\n";
        cout<<"4. Mostrar mas joven\n";
        cout<<"5. Salir\n";
        cout<<"Elige una opción: ";
        cin>>opcion;

        if(opcion == 1)
		{
            cout << "Cuantos pacientes quieres agregar? ";
            int n;
            cin >> n;
            cin.ignore();

            for(int i = 0; i < n; i++)
			{
                cout<<"\nPaciente "<< i+1 << ":\n";
                cout<<"Nombre: ";
                getline(cin, lista[total].nombre);

                cout<<"Edad: ";
                cin>>lista[total].edad;
                cin.ignore();

                cout<<"Motivo: ";
                getline(cin, lista[total].motivo);

                do
				{
                    cout<<"Prioridad (1-5): ";
                    cin>>lista[total].prioridad;
                    cin.ignore();
                } while(lista[total].prioridad < 1 || lista[total].prioridad > 5);

                total++;
            }
        }
        else if(opcion == 2)
		{
            cout<<"\nLISTA DE PACIENTES:\n";
            for(int i = 0; i < total; i++)
			{
                cout<<"Nombre: "<< lista[i].nombre << endl;
                cout<<"Edad: "<< lista[i].edad << endl;
                cout<<"Motivo: "<< lista[i].motivo << endl;
                cout<<"Prioridad: "<< lista[i].prioridad << "\n\n";
            }
        }
        else if(opcion == 3)
		{
            cout<<"\nPACIENTES URGENTES:\n";
            for(int i = 0; i < total; i++)
			{
                if(lista[i].prioridad <= 2)
				{
                    cout<<"Nombre: "<<lista[i].nombre << endl;
                    cout<<"Edad: "<<lista[i].edad << endl;
                    cout<<"Motivo: "<<lista[i].motivo << endl;
                    cout<<"Prioridad: "<<lista[i].prioridad << "\n\n";
                }
            }
        }
        else if(opcion == 4)
		{
            if(total == 0)
			{
                cout<<"No hay pacientes registrados.\n";
                continue;
            }

            int menorEdad = lista[0].edad;
            int posicion = 0;

            for(int i = 1; i < total; i++)
			{
                if(lista[i].edad < menorEdad)
				{
                    menorEdad=lista[i].edad;
                    posicion=i;
                }
            }

            cout<<"\nPACIENTE MAS JOVEN:\n";
            cout<<"Nombre: " << lista[posicion].nombre << endl;
            cout<<"Edad: " << lista[posicion].edad << endl;
            cout<<"Motivo: " << lista[posicion].motivo << endl;
            cout<<"Prioridad: " << lista[posicion].prioridad << "\n";
        }

    } while(opcion != 5);

    return 0;
}