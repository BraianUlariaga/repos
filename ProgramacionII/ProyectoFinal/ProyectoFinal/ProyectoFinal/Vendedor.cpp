#include <iostream>
#include "vendedor.h"

//constructor
Vendedor::Vendedor(){
    _Legajo = 0;
    _Estado = false;
}
//setters
void Vendedor::setLegajo(int legajo){
    _Legajo = legajo;
}
void Vendedor::setEstado(bool estado){
    _Estado = estado;
}
//getters
int Vendedor::getLegajo()const{
    return _Legajo;
}
bool Vendedor::getEstado()const{
    return _Estado;
}
//metodos
void Vendedor::Cargar(){
    int legajo;
    Persona::Cargar();
    std::cout<< "LEGAJO: ";
    std::cin>> legajo;
    setLegajo(legajo);

    setEstado(true);


}
void Vendedor::Mostrar(){
    Persona::Mostrar();
    std::cout<< "LEGAJO: " << getLegajo() <<std::endl;
    std::cout<< "-------------------------" <<std::endl;
}
