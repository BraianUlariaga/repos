#include <iostream>
#include <string>
#include "auto.h"

//constructor
automovil::automovil(){
    _patente = "S/P";
    _color = "S/C";
    _marca = "S/M";
    _tipo = "S/T";
    _anio = 0;
    _km = 0;
    _precio = 0;
    _estado = false;

}
//setters
void automovil::setpatente(std::string patente){
    if(patente.size() == 6 || patente.size() == 7){
        _patente = patente;
    }
}
void automovil::setcolor(std::string color){
    _color = color;
}
void automovil::setmarca(std::string marca){
    _marca = marca;
}
void automovil::settipo(std::string tipo){
    _tipo = tipo;
}
void automovil::setanio(int anio){
    _anio = anio;
}
void automovil::setkm(int km){
    _km = km;
}
void automovil::setprecio(int precio){
    _precio = precio;
}
void automovil::setestado(bool estado){
    _estado = estado;
}
//getters
std::string automovil::getpatente()const{
    return _patente;
}
std::string automovil::getcolor()const{
    return _color;
}
std::string automovil::getmarca()const{
    return _marca;
}
std::string automovil::gettipo()const{
    return _tipo;
}
int automovil::getanio()const{
    return _anio;
}
int automovil::getkm()const{
    return _km;
}
int automovil::getprecio() const{
    return _precio;
}
bool automovil::getestado() const{
    return _estado;
}
//metodos
void automovil::cargar(){
    std::string patente, color, marca, tipo;
    int anio, km, precio;

    std::cout<< "PATENTE: ";
    getline(std::cin, patente);
    setpatente(patente);

    std::cout<< "MARCA: ";
    getline(std::cin, marca);
    setmarca(marca);

    std::cout<< "TIPO: ";
    getline(std::cin, tipo);
    settipo(tipo);

    std::cout<< "COLOR: ";
    getline(std::cin, color);
    setcolor(color);

    std::cout<< "ANIO: ";
    std::cin>> anio;
    setanio(anio);

    std::cout<< "KILOMETROS: ";
    std::cin>> km;
    setkm(km);

    std::cout<< "PRECIO: ";
    std::cin>> precio;
    setprecio(precio);

    setestado(true);


}
void automovil::mostrar()const{
    std::cout<< "MARCA: " << getmarca() <<std::endl;
    std::cout<< "PATENTE: " << getpatente() <<std::endl;
    std::cout<< "TIPO: "<< gettipo() <<std::endl;
    std::cout<< "COLOR: " << getcolor() <<std::endl;
    std::cout<< "ANIO: " << getanio() <<std::endl;
    std::cout<< "KILOMETROS: " << getkm() <<std::endl;
    std::cout<< "PRECIO: " << getprecio() <<std::endl;
    std::cout<< "-------------------------------" << std::endl;
}

