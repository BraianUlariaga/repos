#include "Fecha.h"
#include <iostream>

///setter
void Fecha::setDia(int dia) {
    if (dia >= 1 && dia <= 31) {
        _dia = dia;
    }
    else
    {
        _dia = 0;
    } 
}
void Fecha::setMes(const int m) { _mes = m; }
void Fecha::setAnio(int a) { _anio = a; }
///getter
int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }

///fin de la definición de la clase
///desarrollo de los métodos
void Fecha::Cargar() {
    int d;
    std::cout << "DIA ";
    std::cin >> d;
    setDia(d);
    std::cout << "MES ";
    std::cin >> _mes;
    std::cout << "ANIO ";
    std::cin >> _anio;
}

void Fecha::Mostrar() {
    std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}

Fecha::Fecha(const int d, const int m, const int a) {
    _dia = d;
    _mes = m;
    _anio = a;
}