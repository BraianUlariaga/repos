#include <iostream>
#include "DetalleFactura.h"
#include <string>



// Constructor por defecto
DetalleFactura::DetalleFactura() : _IDVenta(0), _Subtotal(0), _IDPago(0), _Total(0), _Patente("") {}

// Constructor con parametros
DetalleFactura::DetalleFactura(int IDVenta, int Subtotal, int IDPago, int Total, std::string Patente)
    : _IDVenta(IDVenta), _Subtotal(Subtotal), _IDPago(IDPago), _Total(Total), _Patente(Patente) {}

// Getters
int DetalleFactura::getIDVenta() {
    return _IDVenta;
}

int DetalleFactura::getSubtotal() {
    return _Subtotal;
}

int DetalleFactura::getIDPago() {
    return _IDPago;
}

int DetalleFactura::getTotal() {
    return _Total;
}

std::string DetalleFactura::getPatente() {
    return _Patente;
}

// Setters
void DetalleFactura::setIDVenta(int IDVenta) {
    _IDVenta = IDVenta;
}

void DetalleFactura::setSubtotal(int Subtotal) {
    _Subtotal = Subtotal;
}

void DetalleFactura::setIDPago(int IDPago) {
    _IDPago = IDPago;
}

void DetalleFactura::setTotal(int Total) {
    _Total = Total;
}

void DetalleFactura::setPatente(std::string Patente) {
    _Patente = Patente;
}

// Metodos

//Metodo para cargarFactura segun archivo
void DetalleFactura::cargar() {

}

void DetalleFactura::mostrar() {
    std::cout << "ID Venta: " << _IDVenta << std::endl;
    std::cout << "Subtotal: " << _Subtotal << std::endl;
    std::cout << "ID Pago: " << _IDPago << std::endl;
    std::cout << "Total: " << _Total << std::endl;
    std::cout << "Patente: " << _Patente << std::endl;
}


