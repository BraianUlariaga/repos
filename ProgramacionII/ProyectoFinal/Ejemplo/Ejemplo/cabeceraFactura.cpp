#include <iostream>
#include "CabeceraFactura.h"


// Constructor
CabeceraFactura::CabeceraFactura() : _IDVenta(0), _IDCliente(0), _IDVendedor(0), _fecha() {}


// Constructor con parametro
CabeceraFactura::CabeceraFactura(int IDVenta, int IDCliente, int IDVendedor, fecha fecha)
    : _IDVenta(IDVenta), _IDCliente(IDCliente), _IDVendedor(IDVendedor), _fecha(fecha) {}

// Setters
void CabeceraFactura::setIDVenta(int IDVenta){
    if(IDVenta > 0){
        _IDVenta = IDVenta;
    }
}

void CabeceraFactura::setIDCliente(int IDCliente){
    if(IDCliente > 0){
        _IDCliente = IDCliente;
    }
}

void CabeceraFactura::setIDVendedor(int IDVendedor){
    if(IDVendedor > 0){
        _IDVendedor = IDVendedor;
    }

}

void CabeceraFactura::setFecha(fecha fecha){
    _fecha = fecha;
}

// Getters
int CabeceraFactura::getIDVenta(){
    return _IDVenta;
}

int CabeceraFactura::getIDCliente(){
    return _IDCliente;
}

int CabeceraFactura::getIDVendedor(){
    return _IDVendedor;
}

fecha CabeceraFactura::getFecha(){
    return _fecha;
}

//Metodos

void CabeceraFactura::cargar(){
    int IDVenta, IDCliente, IDVendedor;
    fecha Fecha;

    std::cout << "Ingrese ID Venta: ";
    std::cin >> IDVenta;
    setIDVenta(IDVenta);
    std::cout << "Ingrese ID Cliente: ";
    std::cin >> IDCliente;
    setIDCliente(IDCliente);
    std::cout << "Ingrese ID Vendedor: ";
    std::cin >> IDVendedor;
    setIDVendedor(IDVendedor);
    std::cout << "Fecha de factura: ";
    Fecha.Cargar();
    setFecha(Fecha);

}

void CabeceraFactura::mostrar() {
    std::cout << "ID Venta: " << getIDVenta() << std::endl;
    std::cout << "ID Cliente: " << getIDCliente() << std::endl;
    std::cout << "ID Vendedor: " << getIDVendedor() << std::endl;
    std::cout << "Fecha: " << getFecha().toString() << std::endl;

}
