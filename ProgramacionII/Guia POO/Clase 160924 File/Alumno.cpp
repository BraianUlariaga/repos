#include "Alumno.h"
#include <iostream>


    int Alumno::getLegajo() { return _legajo; }
    void Alumno::setLegajo(int l) { _legajo = l; }
    
    ///Métodos de alumno
    void Alumno::Cargar() {
        std::cout << "LEGAJO ";
        std::cin >> _legajo;
        std::cout << "NOMBRE ";
        std::cin >> _nombre;
        std::cout << "APELLIDO ";
        std::cin >> _apellido;
        std::cout << "FECHA DE NACIMIENTO ";
        _fechaNacimiento.Cargar();
        std::cout << "EMAIL ";
        std::cin >> _email;
        std::cout << "CARRERA ";
        std::cin >> _codigoCarrera;
    }

    void Alumno::Mostrar() {
        std::cout << "LEGAJO ";
        std::cout << _legajo << std::endl;
        std::cout << "NOMBRE ";
        std::cout << _nombre << std::endl;
        std::cout << "APELLIDO ";
        std::cout << _apellido << std::endl;
        std::cout << "FECHA DE NACIMIENTO " << std::endl;
        _fechaNacimiento.Mostrar();
        std::cout << "EMAIL ";
        std::cout << _email << std::endl;
        std::cout << "CARRERA ";
        std::cout << _codigoCarrera << std::endl;

    }

