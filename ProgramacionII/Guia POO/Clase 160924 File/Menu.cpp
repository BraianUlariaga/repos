#include "Menu.h"
#include "Alumno.h"
#include "ArchivoAlumno.h"
#include <iostream>


int Menu::verMenu() {
    int opcion;

    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "      Bienvenido, seleccione una opcion:      " << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "      1 _ Agregar registro" << std::endl;
    std::cout << "      2 _ Listar todos los registros" << std::endl;
    std::cout << "      3 _ Listar un registro" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "      0 _ SALIR" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cin >> opcion;

    return opcion;
}


void Menu::ElegirOpcion(int& opcion) {
    char confirmarSalida;
    int legajo;
    switch (opcion) {
    case 1: {
        std::cout << "      1 _ Agregar registro" << std::endl;
        Alumno reg;
        reg.Cargar();

        ArchivoAlumnos archivoAlumnos;
        archivoAlumnos.grabarRegistroAlumno(reg);

        break;
    }
    case 2: {
        std::cout << "      2 _ Listar todos los registros" << std::endl;
        ArchivoAlumnos archivosAlumnos;
        archivosAlumnos.listarRegistros();
        break;
    }
    case 3: {
        std::cout << "      3 _ Listar un registro" << std::endl;
        ArchivoAlumnos listarAlumno;
        std::cout << "INGRESE EL LEGAJO DEL ALUMNO QUE SE QUIERE BUSCAR ";
        std::cin >> legajo;
        int pos = listarAlumno.buscarRegistro(legajo);
        if (pos == -1) {
            std::cout << "NO EXISTE UN ALUMNO CON ESE LEGAJO";

        }
        else {
            Alumno reg = listarAlumno.leerRegistro(pos);
            if (reg.getLegajo() == -1) {
                std::cout << "ERROR DE LECTURA";
            }
            else {
                reg.Mostrar();
            }
        }
        break;
    }
    case 0: {
        std::cout << "      ¿ Quieres salir del juego ? (S/N): ";
        std::cin >> confirmarSalida;
        if (confirmarSalida == 'S' || confirmarSalida == 's') {
            std::cout << "      Saliendo del juego." << std::endl;
        }
        else {
            opcion = -1; // Asigna un valor diferente a 0 para que el bucle continúe
            std::cout << "      Cancelado. Regresando al menu..." << std::endl;
        }
        break;
    }
    default:
        std::cout << "      Opcion no valida." << std::endl;
        break;
    }
}
