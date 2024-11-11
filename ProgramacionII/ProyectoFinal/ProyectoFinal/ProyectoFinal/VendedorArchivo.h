#pragma once
#include "Vendedor.h"

//void Mayuscula(char* cadena);


class VendedorArchivo {
private:
    std::string _nombre;

public:
    VendedorArchivo();
    bool AgregarVendedor(Vendedor& registro);
    Vendedor ListarVendedor(int pos);
    int CantidadRegistros();
    bool ListarVendedores(Vendedor registros[], int cantidad);
    int BuscarVendedor(int legajo);
    bool ModificarVendedor(Vendedor& registro, int pos);

};
