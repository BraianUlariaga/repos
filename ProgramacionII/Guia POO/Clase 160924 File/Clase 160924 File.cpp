#include <iostream>
#include "Alumno.h"
#include "ArchivoAlumno.h"
#include "Menu.h"
using namespace std;


///Hacer un proyecto con un menú
        ///para agregar registros,
        ///listar todos los registros y
        ///listar 1 registro (se pide el ingreso de un legajo y se los muestra)


int main()
{


    int opcion = -1;

    do {
    Menu menu;

    int opcion =  menu.verMenu();

    menu.ElegirOpcion(opcion);


        if (opcion != 0) {
            system("pause");
            cout << "      Presione una tecla para continuar..." << endl;
            system("cls"); // Limpia la pantalla antes de mostrar el menú nuevamente
        }
    } while (opcion != 0);

    return 0;

}
