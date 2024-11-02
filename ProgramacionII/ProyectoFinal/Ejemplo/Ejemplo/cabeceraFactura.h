#pragma once
#include "clsFecha.h"

class CabeceraFactura{
    private:
        int _IDVenta;
        int _IDCliente;
        int _IDVendedor;
        fecha _fecha;

    public:
        CabeceraFactura();
        CabeceraFactura(int IDVenta, int IDCliente, int IDVendedor, fecha fecha);

        //setter
        void setIDVenta(int IDVenta);
        void setIDCliente(int IDCliente);
        void setIDVendedor(int IDVendedor);
        void setFecha(fecha fecha);

        //getter
        int getIDVenta();
        int getIDCliente();
        int getIDVendedor();
        fecha getFecha();

        //Metodos
        void cargar();
        void mostrar();

};
