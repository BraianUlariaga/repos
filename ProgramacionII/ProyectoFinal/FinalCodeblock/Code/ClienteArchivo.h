#pragma once
#include "Cliente.h"

class ClienteArchivo
{
public:
    ClienteArchivo();
    bool AgregarCliente(Cliente cliente);
    Cliente ListarCliente(int posicion);
    bool ListarClientes(Cliente registros[], int cantidad);
    int CantidadRegistros();
    int BuscarCliente(int dni);
    void ModificarCliente(int id);
    bool GuardarModificacion(Cliente cliente, int posicion);
    int ObtenerUltimoId();
private:
    std::string _NombreArchivo;
};