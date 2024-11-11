#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DetalleFactura.h"
#include <cstring>

// Constructor por defecto
DetalleFactura::DetalleFactura() {
    _IDVenta = 0;
    _IDCliente = 0;
    _IDVendedor = 0;
    _fecha.toString();
    _Subtotal = 0;
    _Total = 0;
    _IDPago = 0;
    strcpy(_Patente, "S/P");
}


// Setters
void DetalleFactura::setIDVenta(int IDVenta) {
    if (IDVenta > 0) {
        _IDVenta = IDVenta;
    }
}

void DetalleFactura::setIDCliente(int IDCliente) {
    if (IDCliente > 0) {
        _IDCliente = IDCliente;
    }
}

void DetalleFactura::setIDVendedor(int IDVendedor) {
    if (IDVendedor > 0) {
        _IDVendedor = IDVendedor;
    }
}

void DetalleFactura::setFecha(Fecha fecha) {
    _fecha = fecha;
}

void DetalleFactura::setSubtotal(int Subtotal) {
    if (Subtotal > 0) {
        _Subtotal = Subtotal;
    }
}

void DetalleFactura::setIDPago(int IDPago) {
    if (IDPago > 0 && IDPago <= 3) {
        _IDPago = IDPago;
    }
}

/*void DetalleFactura::setTotal(int Total){
    if(Total > 0){
        _Total = Total;
    }
}*/

void DetalleFactura::setPatente(std::string patente) {
    if (patente.size() == 6) {
        if (isalpha(patente[0]) && isalpha(patente[1]) && isalpha(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isdigit(patente[5])) {
            strcpy(_Patente, patente.c_str());
        }
    }
    else {
        if (patente.size() == 7) {
            if (isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6])) {
                strcpy(_Patente, patente.c_str());
            }
        }
    }
}

// Getters
int DetalleFactura::getIDVenta() {
    return _IDVenta;
}

int DetalleFactura::getIDCliente() {
    return _IDCliente;
}

int DetalleFactura::getIDVendedor() {
    return _IDVendedor;
}

Fecha DetalleFactura::getFecha() {
    return _fecha;
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

const char* DetalleFactura::getPatente() {
    return _Patente;
}


// Metodos

//Metodo para cargarFactura segun archivo
void DetalleFactura::CargarFactura() {
    int Subtotal, IDpago, Total, idvendedor, idcliente, idventa;
    std::string Patente;
    Fecha fechaFactura;

    std::cout << "idVendedor: ";
    std::cin >> idvendedor;
    setIDVendedor(idvendedor);

    std::cout << "idCliente: ";
    std::cin >> idcliente;
    setIDCliente(idcliente);

    std::cout << "idVenta: ";
    std::cin >> idventa;
    setIDVenta(idventa);

    std::cout << "Fecha: ";
    fechaFactura.CargarFecha();
    setFecha(fechaFactura);

    std::cout << "ID pago: ";
    std::cin >> IDpago;
    setIDPago(IDpago);
    std::cin.ignore();

    std::cout << "PATENTE: ";
    getline(std::cin, Patente);
    setPatente(Patente);

    std::cout << "Subtotal: ";
    std::cin >> Subtotal;
    setSubtotal(Subtotal);

    CalcularTotal();



    /*std::cout<< "Total: ";
    std::cin>> Total;
    setTotal(Total);*/
}

void DetalleFactura::MostrarFactura() {
    std::cout << "id vendedor: " << getIDVendedor() << std::endl;
    std::cout << "id cliente: " << getIDCliente() << std::endl;
    std::cout << "id Venta: " << getIDVenta() << std::endl;
    std::cout << "fecha de facturacion: " << getFecha().toString() << std::endl;
    std::cout << "Subtotal: " << getSubtotal() << std::endl;
    std::cout << "ID Pago: " << getIDPago() << std::endl;
    std::cout << "Total: " << getTotal() << std::endl;
    std::cout << "Patente: " << getPatente() << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;
}

void DetalleFactura::CalcularTotal() {
    _Total = _Subtotal;
    if (_IDPago == 2) {
        _Total = _Subtotal * 1.25;
    }
    else {
        if (_IDPago == 3) {
            _Total = _Subtotal * 1.40;
        }
    }
}
