#include <iostream>
#include "clsvendedor.h"
#include "vendedoresArchivo.h" //esto lo puse para el cargar();

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
/*void vendedor::cargar(){
    int legajo;
    persona::Cargar();
    std::cout<< "LEGAJO: ";
    std::cin>> legajo;
    setlegajo(legajo);

    setestado(true);


}*/

void vendedor::cargar(){
    vendedoresArchivo archi;
    int legajo;
    persona::Cargar();
    /*std::cout<< "LEGAJO: ";
    std::cin>> legajo;*/
    legajo = archi.cantidadRegistros() +1;
    setlegajo(legajo);

    setestado(true);

//cambio el cargar desde aca porque si lo hacia desde la clase la clase en si me pedia que borre los #include y encima creo que iba a ser un poco engorroso
}
void vendedor::mostrar(){
    persona::Mostrar();
    std::cout<< "LEGAJO: " << getlegajo() <<std::endl;
    std::cout<< "-------------------------" <<std::endl;
}

