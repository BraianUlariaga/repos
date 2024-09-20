#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int opcion = -1;

    do {
        VerMenu();
        cout << endl;
        ElegirOpcion(opcion);
        if (opcion != 0) {
            system("pause");
            cout << "      Presione una tecla para continuar..." << endl;
            system("cls"); // Limpia la pantalla antes de mostrar el menú nuevamente
        }
    } while (opcion != 0);

    return 0;
}