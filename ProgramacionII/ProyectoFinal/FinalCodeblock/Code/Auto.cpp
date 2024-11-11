#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Auto.h"

//constructor
automovil::automovil() {
    strcpy(_Patente, "S/P");
    strcpy(_Color, "S/C");
    strcpy(_Marca, "S/M");
    strcpy(_Tipo, "S/T");
    _Anio = 0;
    _Km = 0;
    _Precio = 0;
    _Estado = false;

}
//setters
void automovil::setPatente(std::string patente) {


    // Convertir cada carácter a mayúscula
    for (int i = 0; i < patente.size(); i++) {
        patente[i] = toupper(patente[i]);
    }

    if (patente.size() == 6) {
        if (isalpha(patente[0]) && isalpha(patente[1]) && isalpha(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isdigit(patente[5])) {
            strcpy(_Patente, patente.c_str());
        }
    }
    else {
        if (patente.size() == 7) {
            if (isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6])) {
                strcpy(_Patente, patente.c_str());
            }
        }
    }
}
void automovil::setColor(std::string color) {
    strcpy(_Color, color.c_str());
}
void automovil::setMarca(std::string marca) {
    strcpy(_Marca, marca.c_str());
}
void automovil::setTipo(std::string tipo) {
    strcpy(_Tipo, tipo.c_str());
}
void automovil::setAnio(int anio) {
    if (anio >= 1886) {
        _Anio = anio;
    }
}
void automovil::setKm(int km) {
    if (km >= 0) {
        _Km = km;
    }
}
void automovil::setPrecio(float precio) {
    if (precio >= 0) {
        _Precio = precio;
    }
}
void automovil::setEstado(bool estado) {
    _Estado = estado;
}
//getters
const char* automovil::getPatente()const {
    return _Patente;
}
const char* automovil::getColor()const {
    return _Color;
}
const char* automovil::getMarca()const {
    return _Marca;
}
const char* automovil::getTipo()const {
    return _Tipo;
}
int automovil::getAnio()const {
    return _Anio;
}
int automovil::getKm()const {
    return _Km;
}
float automovil::getPrecio()const {
    return _Precio;
}
bool automovil::getEstado() const {
    return _Estado;
}
//metodos
void automovil::CargarAuto() {
    std::string patente, color, marca, tipo;
    int anio, km, precio;

    std::cout << "PATENTE: ";
    getline(std::cin, patente);
    setPatente(patente);

    std::cout << "MARCA: ";
    getline(std::cin, marca);
    setMarca(marca);

    std::cout << "TIPO: ";
    getline(std::cin, tipo);
    setTipo(tipo);

    std::cout << "COLOR: ";
    getline(std::cin, color);
    setColor(color);

    std::cout << "ANIO: ";
    std::cin >> anio;
    setAnio(anio);

    std::cout << "KILOMETROS: ";
    std::cin >> km;
    setKm(km);

    std::cout << "PRECIO: ";
    std::cin >> precio;
    setPrecio(precio);

    setEstado(true);


}
void automovil::MostrarAuto()const {
    std::cout << "MARCA: " << getMarca() << std::endl;
    std::cout << "PATENTE: " << getPatente() << std::endl;
    std::cout << "TIPO: " << getTipo() << std::endl;
    std::cout << "COLOR: " << getColor() << std::endl;
    std::cout << "ANIO: " << getAnio() << std::endl;
    std::cout << "KILOMETROS: " << getKm() << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "PRECIO: " << getPrecio() << std::endl;
    std::cout << "ESTADO: " << getEstado() << std::endl;

    std::cout << "-------------------------------" << std::endl;
}

