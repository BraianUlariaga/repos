#pragma once
#include <string>

class Fecha {
public:
    Fecha(int d = 0, int m = 0, int a = 0);

    void Cargar();
    void Mostrar();
    std::string toString();

    ///setter
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    ///getter
    int getDia();
    int getMes();
    int getAnio();

private:
    int _dia, _mes, _anio;
};