#pragma once
#include "cliente.h"

class clienteArchivo{
private:
    std::string _nombre;

public:
    clienteArchivo();
    bool agregarRegistro(cliente &registro);
    cliente listar(int pos);
    int cantidadRegistros();
    bool leerRegistros(cliente registros[], int cantidad);
    int buscarRegistro(int dni);
    bool modificar(cliente &registro, int pos);

};


