#pragma once
#include "detalleFactura.h"

class facturaArchivo{
private:
    std::string _nombre;
public:
    facturaArchivo();
    bool agregarRegistro(DetalleFactura &registro);
    DetalleFactura listar(int pos);
    int cantidadRegistros();
    bool leerRegistros(DetalleFactura registros[], int cantidad);
    int buscarRegistro(int IDVenta);
    bool modificar(DetalleFactura &registro, int pos);

};
