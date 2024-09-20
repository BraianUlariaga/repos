#pragma once
#include "Fecha.h"

class Alumno : public Fecha{
private:
    int _legajo;
    char _nombre[30];
    char _apellido[30];
    Fecha _fechaNacimiento;
    char _email[50];
    int _codigoCarrera;
public:
    int getLegajo();
    void setLegajo(int l);
    void Cargar();
    void Mostrar();
};