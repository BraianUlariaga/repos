#include <iostream>
#include "DetalleFactura.h"
#include <cstring>

// Constructor por defecto
DetalleFactura::DetalleFactura() : _Subtotal(0), _IDPago(0), _Total(0), _Patente("S/P") {}

// Constructor con parametros
DetalleFactura::DetalleFactura(int Subtotal, int IDPago, int Total, const char* patente)
    : _Subtotal(Subtotal), _IDPago(IDPago), _Total(Total)/*, _Patente(patente)*/ {

    strcpy(_Patente, patente);
    }

// Setters

void DetalleFactura::setSubtotal(int Subtotal){
    if(Subtotal > 0){
        _Subtotal = Subtotal;
    }
}

void DetalleFactura::setIDPago(int IDPago){
    if(IDPago > 0){
        _IDPago = IDPago;
    }
}

void DetalleFactura::setTotal(int Total){
    if(Total > 0){
        _Total = Total;
    }
}

void DetalleFactura::setPatente(std::string patente){
    if(patente.size() == 6){
        if(isalpha(patente[0]) && isalpha(patente[1]) && isalpha(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isdigit(patente[5])){
            strcpy(_Patente,patente.c_str());
        }
    }
    else{
        if(patente.size() == 7){
            if(isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6])){
                strcpy(_Patente,patente.c_str());
            }
        }
    }
}

// Getters

int DetalleFactura::getSubtotal() {
    return _Subtotal;
}

int DetalleFactura::getIDPago() {
    return _IDPago;
}

int DetalleFactura::getTotal() {
    return _Total;
}

const char* DetalleFactura::getPatente(){
    return _Patente;
}


// Metodos

//Metodo para cargarFactura segun archivo
void DetalleFactura::cargar(){
    int Subtotal, IDpago, Total;
    std::string Patente;

    CabeceraFactura::cargar();
    std::cout<< "ID pago: ";
    std::cin>> IDpago;
    setIDPago(IDpago);
    std::cin.ignore();

    std::cout<< "PATENTE: ";
    getline(std::cin, Patente);
    setPatente(Patente);

    std::cout<< "Subtotal: ";
    std::cin>> Subtotal;
    setSubtotal(Subtotal);

    std::cout<< "Total: ";
    std::cin>> Total;
    setTotal(Total);
}

void DetalleFactura::mostrar() {
    CabeceraFactura::mostrar();
    std::cout << "Subtotal: " << getSubtotal() << std::endl;
    std::cout << "ID Pago: " << getIDPago() << std::endl;
    std::cout << "Total: " << getTotal() << std::endl;
    std::cout << "Patente: " << getPatente() << std::endl;
}
