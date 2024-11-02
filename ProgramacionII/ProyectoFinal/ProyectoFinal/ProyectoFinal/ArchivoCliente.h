#pragma once
#include "Cliente.h"

class ArchivoCliente
{
public:
    ArchivoCliente();
    bool GuardarCliente(Cliente cliente);
    Cliente LeerCliente(int posicion);
    int CantidadRegistros();
    int ObtenerUltimoId();
    int Buscar(int id);
    void ModificarCliente(int id);
    bool Guardar(Cliente cliente, int posicion);
private:
    std::string _NombreArchivo;
};