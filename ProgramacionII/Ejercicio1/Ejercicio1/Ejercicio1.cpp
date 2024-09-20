// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <chrono>
#include "Header.h"
using namespace std;

int main()
{
    float hrMateria[20] = {};
    int marzo[20][31] = {};
//  int numMateria, cantAlm, cantProf, legajo, 
int opc;
//    string nombre;
    do
    {
    MostrarMenu();
    cout << endl;
    elegirOpc(opc, hrMateria, marzo);

    if (opc != 0) {
        system("pause");
        cout << "      Presione una tecla para continuar..." << endl;
        system("cls"); // Limpia la pantalla antes de mostrar el menú nuevamente
    }

    } while (opc != 0);

}

