#pragma once
#include<iostream>
#include<cstring>
#include "Alumno.h"

class ArchivoAlumnos {
private:
    char _nombre[50];
public:
    ArchivoAlumnos(const char* n = "alumnos.dat");
    bool grabarRegistroAlumno(Alumno reg);
    bool leerRegistroAlumno(Alumno& reg);
    bool listarRegistros();
    int buscarRegistro(int leg);
    Alumno leerRegistro(int ubicacion);

};

