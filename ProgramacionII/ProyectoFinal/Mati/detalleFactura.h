#pragma once
#include <iostream>
#include "clsfecha.h"
#include <string>

class DetalleFactura{
    private:
        int _IDVenta;
        int _IDCliente;
        int _IDVendedor;
        fecha _fecha;
        int _Subtotal;
        int _IDPago;
        int _Total;
        char _Patente[8];

    public:
        DetalleFactura();

    //setter
    void setIDVenta(int IDVenta);
    void setIDCliente(int IDCliente);
    void setIDVendedor(int IDVendedor);
    void setFecha(fecha fecha);
    void setSubtotal(int Subtotal);
    void setIDPago(int IDPago);
    //void setTotal(int Total);
    void setPatente(std::string Patente);

    //getter
    int getIDVenta();
    int getIDCliente();
    int getIDVendedor();
    fecha getFecha();
    int getSubtotal();
    int getIDPago();
    int getTotal();
    const char* getPatente();


    //Metodos
    void cargar();
    void mostrar();
    void calcularTotal();

};
