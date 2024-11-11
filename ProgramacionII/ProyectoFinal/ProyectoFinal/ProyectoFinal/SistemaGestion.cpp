#include <iostream>
#include "sistemaGestion.h"

void sistemaGestion::mostrarMenu() {
    std::cout << "--------MENU PRINCIPAL--------" << std::endl << std::endl;
    std::cout << "1- AUTOMOVILES EN STOCK" << std::endl;
    std::cout << "2- AGREGAR AUTOMOVIL" << std::endl;
    std::cout << "3- REALIZAR UNA VENTA" << std::endl;
    std::cout << "4- VENDEDORES ACTIVOS" << std::endl;
    std::cout << "5- VENDEDORES HISTORICOS" << std::endl;
    std::cout << "6- CLIENTES" << std::endl;
    std::cout << "7- AGREGAR VENDEDOR" << std::endl;
    std::cout << "8- HISTORIAL DE VENTAS" << std::endl;
    std::cout << "9- DAR DE BAJA UN VENDEDOR" << std::endl;

    std::cout << "0- SALIR" << std::endl;
    std::cout << "ELEGIR OPCION: ";
}

void sistemaGestion::gestionarOpciones() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();
        system("cls");

        ejecutarOpcion(opcion);
        system("pause");
        system("cls");

    } while (opcion != 0);

}

void sistemaGestion::ejecutarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        std::cout << "Listado de Autos en Venta:" << std::endl << std::endl;
        // Lógica para mostrar o gestionar autos en venta
        AutosenStock();
        break;
    case 2:
        std::cout << "Agregar automovil: " << std::endl << std::endl;
        // Lógica para agregar un registro de automovil.
        AgregarAutomovil();
        break;
    case 3:
        std::cout << "Realizar una venta:" << std::endl;
        // Lógica para realizar una venta.
        realizarVenta();
        break;
    case 4:
        //vendedores que tienen estado en true.
        vendedores_activos();
        break;
    case 5:
        //vendedores en true y false
        historial_vendedores();
        break;
    case 6:
        //historial de clientes.
        historial_clientes();
        break;
    case 7:
        std::cout << "Agregar vendedor: " << std::endl << std::endl;
        AgregarVendedor();
        break;
    case 8:
        std::cout << "Ventas realizadas: " << std::endl << std::endl;
        historialFacturas();
        break;
    case 9:
        vendedores_activos();
        bajaVendedor();
        break;

    case 0:
        std::cout << "Saliendo del programa.";
        break;
    default:
        std::cout << "Opción no válida. Intente de nuevo.";
        break;
    }
}


void sistemaGestion::AutosenStock() {
    int total;
    automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();

    registros = new automovil[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

    if (result) {
        for (int X = 0; X < total; X++) {
            if (registros[X].getEstado()) {
                registros[X].MostrarAuto();
            }
        }
    }
    else {
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::AgregarAutomovil() {
    bool result;
    automovil registro;
    AutoArchivo archi;

    registro.CargarAuto();
    result = archi.AgregarAuto(registro);

    if (result) {
        std::cout << "SE AGREGO CON EXITO." << std::endl;
    }
    else {
        std::cout << "NO SE PUDO AGREGAR EL REGISTRO." << std::endl;
    }
}

void sistemaGestion::historial_clientes() {
    int total;
    Cliente* registros;
    ClienteArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Cliente[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarClientes(registros, total);

    if (result) {
        for (int X = 0; X < total; X++) {
            registros[X].MostrarCliente();
        }
    }
    else {
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::vendedores_activos() {
    int total;
    Vendedor* registros;
    VendedorArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Vendedor[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarVendedores(registros, total);

    if (result) {
        for (int X = 0; X < total; X++) {
            if (registros[X].getEstado()) {
                registros[X].MostrarVendedor();
            }
        }
    }
    else {
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::historial_vendedores() {
    int total;
    Vendedor* registros;
    VendedorArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Vendedor[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarVendedores(registros, total);

    if (result) {
        for (int X = 0; X < total; X++) {
            registros[X].MostrarVendedor();
        }
    }
    else {
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::AgregarVendedor() {
    Vendedor registroVendedor;
    VendedorArchivo archiVendedor;

    registroVendedor.CargarVendedor();
    bool result = archiVendedor.AgregarVendedor(registroVendedor);

    if (result) {
        std::cout << "VENDEDOR AGREGADO CON EXITO." << std::endl;
    }
    else { std::cout << "NO SE PUDO GUARDAR EL VENDEDOR." << std::endl; }
}


bool sistemaGestion::generarFactura(Cliente& registroCliente, Vendedor& registroVendedor, automovil& registroAuto, DetalleFactura& registroFactura) {
    FacturaArchivo archiFactura;
    Fecha sistema;
    std::string patente;
    int total;
    total = archiFactura.CantidadRegistros() + 1;


    registroFactura.setIDVenta(total);
    registroFactura.setIDVendedor(registroVendedor.getLegajo());
    registroFactura.setIDCliente(registroCliente.getIDCliente());
    patente = registroAuto.getPatente();
    registroFactura.setPatente(patente);
    registroFactura.setSubtotal(registroAuto.getPrecio());
    registroFactura.CalcularTotal();
    sistema.FechaSistema();
    registroFactura.setFecha(sistema);

    bool result = archiFactura.AgregarFactura(registroFactura);
    return result;

}

void sistemaGestion::realizarVenta() {
    bool viejo, eleccion1, eleccion2, result, exitoso;
    int dni, posicionCliente = -1, posicionPatente = -1, posVendedor, legajoVendedor, idpago;
    Cliente registroCliente;
    ClienteArchivo archiCliente;
    automovil registroAuto;
    DetalleFactura registroFactura;
    AutoArchivo archiAuto;
    Vendedor registroVendedor;
    VendedorArchivo archiVendedor;
    char patente[8];


    std::cout << "ES CLIENTE: 1-SI 0-NO: ";
    std::cin >> viejo;
    std::cin.ignore();
    system("cls");
    if (viejo) {
        std::cout << "PEDIR DNI: ";
        std::cin >> dni;
        posicionCliente = archiCliente.BuscarCliente(dni);
        registroCliente = archiCliente.ListarCliente(posicionCliente);
        system("cls");
    }
    else {
        registroCliente.CargarCliente();
        //exitoso = archiCliente.agregarRegistro(registroCliente);
        //posicionCliente = archiCliente.buscarRegistro(registroCliente.getdni());
        posicionCliente = archiCliente.CantidadRegistros() + 1;
        system("cls");
    }
    if (posicionCliente >= 0) {
        //std::cout<< posicionCliente;
        std::cout << "QUE AUTO ESTAS BUSCANDO: " << std::endl;
        AutosenStock();
        std::cout << "TE INTERESA ALGUNO: 1-SI 0-NO: ";
        std::cin >> eleccion1;
        if (eleccion1) {
            std::cin.ignore();
            std::cout << "PATENTE: ";
            std::cin.getline(patente, 8, '\n');
            posicionPatente = archiAuto.BuscarAuto(patente);
            //aca yo yo tengo las pantentes en consola de AutosenStock() pero si yo pongo una patente que antes estuvo tambien me la toma
            //se entiende que no va a haber un auto que no figura en autos en stock, le cambio la logica ?
            system("cls");
            if (posicionPatente >= 0) {
                registroAuto = archiAuto.ListarAuto(posicionPatente);
                registroAuto.MostrarAuto();
                std::cout << "Es EL AUTO QUE ESTAS BUSCANDO 1-SI 0-NO: ";
                std::cin >> eleccion2;
                system("cls");
                if (eleccion2) {
                    std::cout << "MEDIO DE PAGO: 1-EFECTIVO. 2-FINANCIACION TARJETA. 3-CREDITO PERSONAL: ";
                    std::cin >> idpago;
                    if (idpago > 0 && idpago <= 3) {
                        registroFactura.setIDPago(idpago);
                        std::cout << "LEGAJO DEL VENDEDOR: ";
                        std::cin >> legajoVendedor;
                        posVendedor = archiVendedor.BuscarVendedor(legajoVendedor);
                        if (posVendedor >= 0) {
                            registroVendedor = archiVendedor.ListarVendedor(posVendedor);
                            if (archiCliente.BuscarCliente(dni) < 0) {
                                exitoso = archiCliente.AgregarCliente(registroCliente);
                            }
                            registroAuto.setEstado(false);
                            archiAuto.ModificarAuto(registroAuto, posicionPatente);
                            result = generarFactura(registroCliente, registroVendedor, registroAuto, registroFactura);
                            if (result) {
                                //exitoso = archiCliente.agregarRegistro(registroCliente); hacer logica para ver si existe, sino no lo puedo agregar.
                                std::cout << "Venta realizada con exito.";
                            }
                            else {
                                std::cout << "no se pudo realizar la venta";
                            }
                        }
                        else {
                            std::cout << "NO SE ENCONTRO EL VENDEDOR.";
                            system("pause");
                        }
                    }
                    else {
                        std::cout << "FORMA DE PAGO INCORRECTO";
                        system("pause");
                    }

                }
            }
            else {
                std::cout << "NO SE ENCONTRO LA PATENTE.";
                system("pause");
            }
        }
    }
    else {
        std::cout << "NO SE ENCONTRO EL CLIENTE." << std::endl;
        system("pause");
    }

}

void sistemaGestion::historialFacturas() {
    int total;
    DetalleFactura* registros;
    FacturaArchivo archi;

    total = archi.CantidadRegistros();

    registros = new DetalleFactura[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarFacturas(registros, total);

    if (result) {
        for (int X = 0; X < total; X++) {
            registros[X].MostrarFactura();
        }
    }
    else {
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::bajaVendedor() {
    Vendedor registroVendedor;
    VendedorArchivo archi;
    int legajo, pos = -1;
    bool opcion;

    std::cout << "LEGAJO A DAR DE BAJA: ";
    std::cin >> legajo;
    system("cls");

    pos = archi.BuscarVendedor(legajo);

    if (pos >= 0) {
        registroVendedor = archi.ListarVendedor(pos);
        registroVendedor.MostrarVendedor();
        std::cout << "ES EL VENDEDOR QUE DESEAS DAR DE BAJA: 1-SI 0-NO: ";
        std::cin >> opcion;

        if (opcion) {
            registroVendedor.setEstado(false);
            archi.ModificarVendedor(registroVendedor, pos);
            std::cout << "REGISTRO DADO DE BAJA CON EXITO." << std::endl;
        }
    }
    else {
        std::cout << "NO SE ENCONTRO EL REGISTRO." << std::endl;
    }



}





