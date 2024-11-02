#pragma once
#include <iostream>
#include <string>
#include "cabeceraFactura.h"

class DetalleFactura:public CabeceraFactura{
    private:
        int _Subtotal;
        int _IDPago;
        int _Total;
        char _Patente[8];

    public:
        DetalleFactura();
        DetalleFactura(int Subtotal, int IDPago, int Total, const char* patente);

    //setter
    void setSubtotal(int Subtotal);
    void setIDPago(int IDPago);
    void setTotal(int Total);
    void setPatente(std::string Patente);

    //getter
    int getSubtotal();
    int getIDPago();
    int getTotal();
    const char* getPatente();


    //Metodos
    void cargar();
    void mostrar();

};
