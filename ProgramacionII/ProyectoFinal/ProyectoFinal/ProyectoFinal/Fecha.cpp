#include "Fecha.h"
#include <iostream>


///setter
void Fecha::setDia(int dia) {
    if (dia >= 1 && dia <= 31) {
        _dia = dia;
    }
    else
    {
        _dia = 1;
    }
}
void Fecha::setMes(int mes) { 
    
    if (mes >=1 && mes <=12)
    {
        _mes = mes;
    }
    else
    {
        _mes = 1; 

    }


}
void Fecha::setAnio(int anio) { 
    if (anio > 1920)
    {
        _anio = anio;
    }
    else
    {
        _anio = 1800;
    }
}
///getter
int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }

///fin de la definición de la clase
///desarrollo de los métodos
void Fecha::Cargar() {
    int d,m,a;
    std::cout << "DIA ";
    std::cin >> d;
    setDia(d);
    std::cout << "MES ";
    std::cin >> m;
    setMes(m);
    std::cout << "ANIO ";
    std::cin >> a;
    setAnio(a);
}

void Fecha::Mostrar() {
    std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}

Fecha::Fecha(const int d, const int m, const int a) {
    _dia = d;
    _mes = m;
    _anio = a;
}


std::string Fecha::toString() {
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}