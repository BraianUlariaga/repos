#pragma once
#include <iostream>
#include <string>

class DetalleFactura{
    private:
        int _IDVenta;
        int _Subtotal;
        int _IDPago;
        int _Total;
        std::string _Patente;
    
    public:
        DetalleFactura();
        DetalleFactura(int IDVenta, int Subtotal,int IDPago,int Total, std::string Patente);
    
    //getter
    
    int getIDVenta();
    int getSubtotal();
    int getIDPago();
    int getTotal();
    std::string getPatente();
    
    //setter
    void setIDVenta (int IDVenta);
    void setSubtotal (int IDCliente);
    void setIDVendedor (int IDVendedor);
    void setIDPago(int IDPago);
    void setTotal (int Total);
    void setPatente (std::string Patente);
    
    //Metodos
    void cargar ();
    void mostrar ();
    
};