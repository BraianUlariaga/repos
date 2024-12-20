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
    void AgregarVendedor();
    bool generarFactura(cliente &registroCliente, vendedor &registroVendedor, automovil &registroAuto, DetalleFactura &registroFactura);
    void historialFacturas();
    void bajaVendedor();

};
