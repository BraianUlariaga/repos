#include <iostream>
#include "Vendedor.h"
#include "VendedorArchivo.h"

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
void Vendedor::CargarVendedor(){

    VendedorArchivo archi;
    int legajo;
    Persona::CargarPersona();
    std::cout<< "LEGAJO: ";
    std::cin>> legajo;
    setLegajo(legajo);

    setEstado(true);


}
void Vendedor::MostrarVendedor(){
    Persona::MostrarPersona();
    std::cout<< "LEGAJO: " << getLegajo() <<std::endl;
    std::cout<< "-------------------------" <<std::endl;
}
