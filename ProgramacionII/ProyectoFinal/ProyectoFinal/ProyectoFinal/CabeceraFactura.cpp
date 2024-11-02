#include <iostream>
#include "CabeceraFactura.h"
#include "Fecha.h"


// Constructor
CabeceraFactura::CabeceraFactura() : _IDVenta(0), _IDCliente(0), _IDVendedor(0), _fecha() {}

// Constructor con parametro
CabeceraFactura::CabeceraFactura(int IDVenta, int IDCliente, int IDVendedor, Fecha fecha)
    : _IDVenta(IDVenta), _IDCliente(IDCliente), _IDVendedor(IDVendedor), _fecha(fecha) {}

// Getters
int CabeceraFactura::getIDVenta() {
    return _IDVenta;
}

int CabeceraFactura::getIDCliente() {
    return _IDCliente;
}

int CabeceraFactura::getIDVendedor() {
    return _IDVendedor;
}

Fecha CabeceraFactura::getFecha() {
    return _fecha;
}

// Setters
void CabeceraFactura::setIDVenta(int IDVenta) {
    _IDVenta = IDVenta;
}

void CabeceraFactura::setIDCliente(int IDCliente) {
    _IDCliente = IDCliente;
}

void CabeceraFactura::setIDVendedor(int IDVendedor) {
    _IDVendedor = IDVendedor;
}

void CabeceraFactura::setFecha(Fecha fecha) {
    _fecha = fecha;
}

// Métodos

void CabeceraFactura::cargar() {
    // lógica para Generar ID automáticamente
//    TODO:Falta traer los datos de las entidades;
    //_IDVenta = ;
    //_IDCliente = ;
    //_IDVendedor = ;
    //_fecha = Fecha();

    //std::cout << "Ingrese ID Venta: ";
    //std::cin >> _IDVenta;
    //std::cout << "Ingrese ID Cliente: ";
    //std::cin >> _IDCliente;
    //std::cout << "Ingrese ID Vendedor: ";
    //std::cin >> _IDVendedor;

    // _fecha.cargar();
}

void CabeceraFactura::mostrar() {
    std::cout << "ID Venta: " << _IDVenta << std::endl;
    std::cout << "ID Cliente: " << _IDCliente << std::endl;
    std::cout << "ID Vendedor: " << _IDVendedor << std::endl;

    _fecha.Mostrar();
}
