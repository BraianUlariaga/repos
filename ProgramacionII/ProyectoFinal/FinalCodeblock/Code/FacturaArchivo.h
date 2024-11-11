#pragma once
#include "DetalleFactura.h"

class FacturaArchivo {
private:
    std::string _nombre;
public:
    FacturaArchivo();
    bool AgregarFactura(DetalleFactura& registro);
    DetalleFactura ListarFactura(int pos);
    bool ListarFacturas(DetalleFactura registros[], int cantidad);
    int CantidadRegistros();
    int BuscarFactura(int IDVenta);
    bool ModificarFactura(DetalleFactura& registro, int pos);

};
