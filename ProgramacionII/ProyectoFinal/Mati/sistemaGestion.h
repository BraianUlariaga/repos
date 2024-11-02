#pragma once
#include "archivoAutos.h"
#include "clienteArchivo.h"
#include "facturaArchivo.h"
#include "vendedoresArchivo.h"


class sistemaGestion{
private:
    void mostrarMenu();
    void ejecutarOpcion(int opcion);

public:
    void gestionarOpciones();
    void AutosenStock();
    void AgregarAutomovil();
    void realizarVenta();
    void historial_clientes();
    void vendedores_activos();
    void historial_vendedores();
    bool generarFactura(cliente &registroCliente, vendedor &registroVendedor, automovil &registroAuto, int posCliente, int posVendedor, int posAuto);

};
