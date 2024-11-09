#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "clsauto.h"

//constructor
automovil::automovil(){
    strcpy(_patente,"S/P");
    strcpy(_color,"S/C");
    strcpy(_marca,"S/M");
    strcpy(_tipo,"S/T");
    _anio = 0;
    _km = 0;
    _precio = 0;
    _estado = false;

}
//setters
void automovil::setpatente(std::string patente){


    // Convertir cada carácter a mayúscula
    for (int i = 0; i < patente.size(); i++) {
        patente[i] = toupper(patente[i]);
    }

    if(patente.size() == 6){
        if(isalpha(patente[0]) && isalpha(patente[1]) && isalpha(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isdigit(patente[5])){
            strcpy(_patente,patente.c_str());
        }
    }
    else{
        if(patente.size() == 7){
            if(isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6])){
                strcpy(_patente,patente.c_str());
            }
        }
    }
}
void automovil::setcolor(std::string color){
    strcpy(_color,color.c_str());
}
void automovil::setmarca(std::string marca){
    strcpy(_marca, marca.c_str());
}
void automovil::settipo(std::string tipo){
    strcpy(_tipo, tipo.c_str());
}
void automovil::setanio(int anio){
    if(anio >= 1886){
        _anio = anio;
    }
}
void automovil::setkm(int km){
    if(km >= 0){
        _km = km;
    }
}
void automovil::setprecio(float precio){
    if(precio >= 0){
        _precio = precio;
    }
}
void automovil::setestado(bool estado){
    _estado = estado;
}
//getters
const char* automovil::getpatente()const{
    return _patente;
}
const char* automovil::getcolor()const{
    return _color;
}
const char* automovil::getmarca()const{
    return _marca;
}
const char* automovil::gettipo()const{
    return _tipo;
}
int automovil::getanio()const{
    return _anio;
}
int automovil::getkm()const{
    return _km;
}
float automovil::getprecio()const{
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
    std::cout<<std::fixed;
    std::cout<<std::setprecision(2);
    std::cout<< "PRECIO: " << getprecio() <<std::endl;
    std::cout<< "ESTADO: " << getestado() <<std::endl;

    std::cout<< "-------------------------------" << std::endl;
}

