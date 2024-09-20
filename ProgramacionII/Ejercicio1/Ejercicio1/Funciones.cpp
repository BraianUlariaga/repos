#include <iostream>
#include <vector>
#include <windows.h>
#include "Header.h"
using namespace std;


void MostrarMenu() {

    cout << "------------------------------------------------------------------------" << endl;
    cout << "      BIENVENIDOS      " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "      1 _ INGRESO" << endl;
    cout << "      2 _ MATERIAS QUE NO TUVIERON ACCESO " << endl;
    cout << "      3 _ MATERIAS CON MAS CANTIDAD DE HORAS " << endl;
    cout << "      4 _ CANTIDAD DE ACCESOS POR MATERIA EN MARZO " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "      0 _ SALIR" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}

void elegirOpc(int& opc, float hrMateria[20], int marzo[20][31]) {


    char confirmarSalida;
    cout << "      Seleccione una opcion. " << endl;
    cin >> opc;

    switch (opc) {
    case 1:
        cout << "      1 _ INGRESO" << endl;
        IngresoDeDatos(hrMateria, marzo);
        break;
    case 2:
        cout << "      2 _ MATERIAS QUE NO TUVIERON ACCESO" << endl;
        puntoA(hrMateria);
        break;
    case 3:
        cout << "      3 _  MATERIAS CON MAS CANTIDAD DE HORAS" << endl;
        puntoB(hrMateria);
        break;
    case 4:
        cout << "      4 _ CANTIDAD DE ACCESOS POR MATERIA EN MARZO" << endl;
        cout <<" Materia con mas acceso en marzo, " << mostrarPuntoC(marzo) << endl;
        break;
    case 0:
        cout << "      Confirmar salir  ? (S/N): ";
        cin >> confirmarSalida;
        if (confirmarSalida == 'S' || confirmarSalida == 's') {
            cout << "      Saliendo" << endl;
        }
        break;
    default:
        cout << "      Opcion no valida." << endl;
        break;
    }

}

void IngresoDeDatos(float hrMateria[20], int marzo[20][31]) {

    int legajo, mes, dia, numMateria, hora;
//    float hrMateria[20] = {};
    
    cout << "Ingrese su legajo" << endl;
    cin >> legajo;

    while (legajo !=0)
    {
        cout << "Ingrese el mes de acceso" << endl;
        cin >> mes;
        cout << "Ingrese el dia de acceso" << endl;
        cin >> dia;
        cout << "Numero de la materia (entre 1 y 20)" << endl;
        cin >> numMateria;
        cout << "Ingrese la cantidad de horas." << endl;
        cin >>  hora;
        hrMateria[numMateria - 1] += hora;

        if (mes == 3)
        {
            puntoC(marzo, dia, numMateria);
        }

        system("cls");
        cout << "Ingrese su legajo" << endl;
        cin >> legajo;
    }

}

void puntoA(float hrMateria[]) {

    cout << "Las materias sin acceso fueron las siguientes: " << endl;
    for (int i = 0;  i < 20; i++)
    {
        if (hrMateria[i] == 0) {
        
            cout << i+1 << "    ";

        }
    }
    cout << endl;
}

void puntoB(float hrMateria[]) {

    float maxMateria=0.0;

    for (int i = 0; i < 20; i++)
    {
        if (i==0)
        {
            maxMateria = i;
            maxMateria += 1;

        }

        if (hrMateria[i] > maxMateria) {

            maxMateria = i;
            maxMateria += 1;

        }
    }

    if (maxMateria ==0)
    {
        cout << "No hay datos cargados" << endl;
    }
    else
    {
     cout << "La materia con mas cantidad de horas fue: " << maxMateria << endl;
        
    }

}

void puntoC(int marzo[20][31], int dia, int numMateria) {

    numMateria -= 1;
    dia -= 1;

    for ( int i = 0; i <= numMateria; i++)
    {
        if (i==numMateria)
        {
            for (int j = 0; j <= dia; j++)
            {
                if (j==dia)
                {
                    marzo[i][j]++;
                }
            }
        }
    }
}

int mostrarPuntoC(int marzo[20][31]){

    int maxIngresos = 0;
    int maxAuxiliar = 0;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            maxAuxiliar += marzo[i][j];

        }

        if (maxAuxiliar > maxIngresos)
        {
            maxIngresos = i+1;
        }
        maxAuxiliar = 0;
    }

    return maxIngresos;
}