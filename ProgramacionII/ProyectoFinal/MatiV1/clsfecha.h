#pragma once
#include <string>

bool esBisiesto(int anio);

class fecha{
private:
    int _dia;
    int _mes;
    int _anio;
    bool validarFecha(int dia, int mes, int anio);
public:
    fecha();
    fecha(int dia, int mes, int anio);
    void setdia(int dia);
    void setmes(int mes);
    void setanio(int anio);
    int getdia();
    int getmes();
    int getanio();

    std::string toString();
    void Cargar();

};
