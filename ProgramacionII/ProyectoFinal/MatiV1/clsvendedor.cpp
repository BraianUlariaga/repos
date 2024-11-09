#include <iostream>
#include "clsvendedor.h"

//constructor
vendedor::vendedor(){
    _legajo = 0;
    _estado = false;
}
//setters
void vendedor::setlegajo(int legajo){
    _legajo = legajo;
}
void vendedor::setestado(bool estado){
    _estado = estado;
}
//getters
int vendedor::getlegajo()const{
    return _legajo;
}
bool vendedor::getestado()const{
    return _estado;
}
//metodos
void vendedor::cargar(){
    int legajo;
    persona::Cargar();
    std::cout<< "LEGAJO: ";
    std::cin>> legajo;
    setlegajo(legajo);

    setestado(true);


}
void vendedor::mostrar(){
    persona::Mostrar();
    std::cout<< "LEGAJO: " << getlegajo() <<std::endl;
    std::cout<< "-------------------------" <<std::endl;
}

