#pragma once
#include <string>
#include "Validaciones.h"

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
    bool ValidarFecha(int dia, int mes, int anio);
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    int getDia();
    int getMes();
    int getAnio();

    std::string toString();
    void CargarFecha();
    void FechaSistema();

};