#include <iostream>
#include "sistemaGestion.h"

void sistemaGestion::mostrarMenu(){
    std::cout<< "--------MENU PRINCIPAL--------" <<std::endl <<std::endl;
    std::cout<< "1- AUTOMOVILES EN STOCK" <<std::endl;
    std::cout<< "2- AGREGAR AUTOMOVIL" <<std::endl;
    std::cout<< "3- REALIZAR UNA VENTA" <<std::endl;
    std::cout<< "4- VENDEDORES ACTIVOS" <<std::endl;
    std::cout<< "5- VENDEDORES HISTORICOS" <<std::endl;
    std::cout<< "6- CLIENTES" <<std::endl;
    std::cout<< "7- VENTAS REALIZADAS" <<std::endl;

    std::cout<< "0- SALIR" <<std::endl;
    std::cout<< "ELEGIR OPCION: ";
}

void sistemaGestion::gestionarOpciones(){
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        ejecutarOpcion(opcion);

    } while(opcion != 0);

}

void sistemaGestion::ejecutarOpcion(int opcion){
    switch(opcion){
        case 1:
            std::cout << "Listado de Autos en Venta:";
            // Lógica para mostrar o gestionar autos en venta
            AutosenStock();
            break;
        case 2:
            std::cout << "Agregar automovil." <<std::endl;
            // Lógica para agregar un registro de automovil.
            AgregarAutomovil();
            break;
        case 3:
            std::cout << "Realizar una venta:" <<std::endl;
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

        case 0:
            std::cout << "Saliendo del programa.";
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.";
            break;
    }
}


void sistemaGestion::AutosenStock(){
    int total;
    automovil *registros;
    ArchivoAutos archi;

    total = archi.cantidadRegistros();

    registros = new automovil[total];
    if(registros == nullptr){
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.leerRegistros(registros, total);

    if(result){
        for(int X = 0; X < total; X++){
            if(registros[X].getestado()){
                registros[X].mostrar();
            }
        }
    }
    else{
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::AgregarAutomovil(){
    bool result;
    automovil registro;
    ArchivoAutos archi;

    result = archi.agregarRegistro(registro);

    if(result){
        std::cout<< "SE AGREGO CON EXITO.";
    }
    else{
        std::cout<< "NO SE PUDO AGREGAR EL REGISTRO.";
    }
}

void sistemaGestion::historial_clientes(){
    int total;
    cliente *registros;
    clienteArchivo archi;

    total = archi.cantidadRegistros();

    registros = new cliente[total];
    if(registros == nullptr){
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.leerRegistros(registros, total);

    if(result){
        for(int X = 0; X < total; X++){
            registros[X].mostrar();
        }
    }
    else{
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::vendedores_activos(){
    int total;
    vendedor *registros;
    vendedoresArchivo archi;

    total = archi.cantidadRegistros();

    registros = new vendedor[total];
    if(registros == nullptr){
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.leerRegistros(registros, total);

    if(result){
        for(int X = 0; X < total; X++){
            if(registros[X].getestado()){
                registros[X].mostrar();
            }
        }
    }
    else{
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

void sistemaGestion::historial_vendedores(){
    int total;
    vendedor *registros;
    vendedoresArchivo archi;

    total = archi.cantidadRegistros();

    registros = new vendedor[total];
    if(registros == nullptr){
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.leerRegistros(registros, total);

    if(result){
        for(int X = 0; X < total; X++){
            registros[X].mostrar();
        }
    }
    else{
        std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
    }

    delete[] registros;
}

/*void sistemaGestion::realizarVenta(){
    bool nuevo, eleccion, eleccion2, eleccion3, eleccion4;
    cliente registro;
    clienteArchivo registroCliente;
    ArchivoAutos registroAuto;
    automovil vehiculo, *vAUTOS;
    int dni, pos, cantidad;
    char patente[10];
    DetalleFactura factura;
    facturaArchivo registroFactura;

    std::cout<< "ES CLIENTE 1-SI 0-NO: ";
    std::cin>> nuevo;
    std::cin.ignore();

    if(nuevo){
        std::cout<< "dni: ";
        std::cin>> dni;
        pos = registroCliente.buscarRegistro(dni);
        if(pos == -1){
            std::cout<< "NO SE PUDO LEER EL ARCHIVO.";
        }
        else{
            if(pos == -2){
                std::cout<< "NO EXISTE EL CLIENTE.";
            }
            else{
                registro = registroCliente.listar(pos);
                registro.Mostrar();
                std::cout<< "AUTOS EN STOCK: ";
                cantidad = registroAuto.cantidadRegistros();

                vAUTOS = new automovil[cantidad];

                if(vAUTOS == nullptr){
                    std::cout<< "NO SE PUDO LEER EL ARCHIVO.";
                }
                else{
                    registroAuto.leerRegistros(vAUTOS, cantidad);
                        for(int X=0; X<cantidad; X++){
                        vAUTOS[X].mostrar();
                        }
                    delete[] vAUTOS;
                }
                std::cout<< "DESEA REALIZAR UNA COMPRA 1-SI 0-NO: ";
                std::cin>> eleccion;
                std::cin.ignore();
                if(eleccion){
                    std::cout<< "ESCRIBIR PATENTE:";
                    std::cin.getline(patente, 10, '\n');
                    pos = registroAuto.buscarRegistro(patente);
                    vehiculo = registroAuto.listar(pos);
                    vehiculo.mostrar();
                    std::cout<< "ES ESTE AUTO 1-SI 0-NO";
                    std::cin>> eleccion2;
                    std::cin.ignore();
                    if(eleccion2){
                        vehiculo.setestado(false);
                        eleccion3 = registroAuto.modificar(vehiculo, pos);
                        if(eleccion3){
                            std::cout<< "MODIFICADO CON EXITO.";
                            eleccion4 = registroFactura.agregarRegistro(factura);
                            if(eleccion4){
                                std::cout<< "VENTA REALIZADA Y FACTURADA CON EXITO.";
                            }
                            else{
                                std::cout<< "NO SE PUDO FACTURAR LA VENTA.";
                            }


                        }
                        else{
                            std::cout<< "NO SE PUDO MODIFICAR.";
                        }
                    }
                }



            }
        }

    }
    else{
        bool realizado = registroCliente.agregarRegistro(registro);
        if(realizado){
            std::cout<< "SE AGREGO CON EXITO.";
        }
        else{std::cout<< "NO SE PUDO REGISTRAR EL CLIENTE.";}
    }

}*/

bool sistemaGestion::generarFactura(cliente &registroCliente, vendedor &registroVendedor, automovil &registroAuto, int posCliente, int posVendedor, int posAuto){
    ArchivoAutos archiAuto;
    clienteArchivo archiCliente;
    vendedoresArchivo archiVendedor;
    facturaArchivo archiFactura;
    DetalleFactura registroFactura;
    int idpago;
    std::string patente;
    std::cout<< "idpago: ";
    std::cin>> idpago;


    registroFactura.setIDPago(idpago);
    registroFactura.setIDPago(idpago);
    patente = registroAuto.getpatente();
    registroFactura.setPatente(patente);
    registroFactura.setSubtotal(registroAuto.getprecio());
    registroFactura.setTotal(300000.0);









}

void sistemaGestion::realizarVenta(){
    bool viejo, eleccion1, eleccion2;
    int dni, posicion = -1, posicion2 = -1;
    cliente registroCliente;
    clienteArchivo archiCliente;
    automovil registroAuto;
    ArchivoAutos archiAuto;
    char patente[8];


    std::cout<< "ES CLIENTE: 1-SI 0-NO: ";
    std::cin>> viejo;
    system("cls");
        if(viejo){
            std::cout<< "PEDIR DNI: ";
            std::cin>> dni;
            posicion = archiCliente.buscarRegistro(dni);
            system("cls");
            if(posicion >= 0){
                std::cout<< "QUE AUTO ESTAS BUSCANDO: "<<std::endl;
                AutosenStock();
                std::cout<< "TE INTERESA ALGUNO: 1-SI 0-NO: ";
                std::cin>> eleccion1;
                if(eleccion1){
                    std::cin.ignore();
                    std::cout<<"PATENTE: ";
                    std::cin.getline(patente, 8, '\n');
                    posicion2 = archiAuto.buscarRegistro(patente);

                    system("cls");
                        if(posicion2 >= 0){
                            registroAuto = archiAuto.listar(posicion2);
                            registroAuto.mostrar();
                            std::cout<< "Es EL AUTO QUE ESTAS BUSCANDO 1-SI 0-NO: ";
                            std::cin>> eleccion2;
                            system("cls");
                            if(eleccion2){
                                registroAuto.setestado(false);
                                archiAuto.modificar(registroAuto, posicion2);

                            }
                        }
                }
            }
            else{
                std::cout<< "NO SE ENCONTRO EL CLIENTE." <<std::endl;
                system("pause");
            }




        }
}









