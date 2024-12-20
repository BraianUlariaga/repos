#include <iostream>
#include "cliente.h"
#include "clienteArchivo.h"

//constructor
cliente::cliente(){
    _idCliente = 0;
}
//setters
void cliente::setidCliente(int idCliente){
    if(idCliente > 0){
        _idCliente = idCliente;
    }
}
//getters
int cliente::getidCliente(){
    return _idCliente;
}
//metodos
/*void cliente::cargar(){
    int idcliente;
    persona::Cargar();
    std::cout<< "ID cliente: ";
    std::cin>> idcliente;
    setidCliente(idcliente);
}*/

void cliente::cargar(){
    int idcliente;
    clienteArchivo archi;
    persona::Cargar();
    /*std::cout<< "ID cliente: ";
    std::cin>> idcliente;*/
    idcliente = archi.cantidadRegistros() + 1;
    setidCliente(idcliente);
}

void cliente::mostrar(){
    persona::Mostrar();
    std::cout<< "ID Cliente: " <<getidCliente() <<std::endl;
    std::cout<< "-------------------------------" << std::endl << std::endl;
}
