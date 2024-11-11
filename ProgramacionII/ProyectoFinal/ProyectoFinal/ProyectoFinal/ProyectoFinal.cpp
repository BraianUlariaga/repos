
#include <iostream>
#include <iomanip>  // Para usar std::setprecision
#include "Cliente.h"
#include "PuntoDeRetiroArchivo.h"
#include "ClienteArchivo.h"
#include "FormaDePago.h"
#include "FormaDePagoArchivo.h"


int main()
{
    //float num;

    //std::cout << "ingrese num" << std::endl;
    //std::cin >> num;
    //std::cout << std::fixed;
    //std::cout << num << std::endl;

    //std::cout <<  std::setprecision(3);
    //std::cout << num;
    
        //***************************Cargamos cliente
        ////Cliente cliente1;
        ////ClienteArchivo archivoCliente;

        ////cliente1.Cargar();
        ////archivoCliente.GuardarCliente(cliente1);
       

        ////int registros = archivoCliente.CantidadRegistros(); // Traemos la cantiad de registros para el for

        ////for (int i = 0; i < registros; i++)
        ////{
        ////    cliente1 = archivoCliente.LeerCliente(i);
        ////    cliente1.Mostrar();
        ////}
        ////

        ////int id;
        ////std::cout << "Ingrese el ID del registro a modificar" << std::endl;
        ////std::cin >> id;
        ////archivoCliente.ModificarCliente(id);

        /////*Verificacion de que se dio de baja o se modifico */
        ////
        ////cliente1.Mostrar();

    /* PUNTO DE RETIRO */

    //
    //PuntoDeRetiro punto1;
    //ArchivoPuntoDeRetiro archivoPunto;

    ////Alta o carga de punto de retiro y guardado en el archivo
    //
    //
    //punto1.CargarPuntoDeRetiro();
    //archivoPunto.GuardarPuntoDeRetiro(punto1);

    //int registros = archivoPunto.CantidadRegistros(); // Traemos la cantiad de registros para el for

    //for (int i = 0; i < registros; i++)
    //{
    //    punto1 = archivoPunto.LeerPuntoDeRetiro(i);
    //    punto1.MostrarPuntoDeRetiro();
    //}

    ////Modificacion de los registros 

    //int id;
    //std::cout << "Ingrese el ID del registro a modificar" << std::endl;
    //std::cin >> id;
    //archivoPunto.ModificarPuntoDeRetiro(id);

    ///*Verificacion de que se dio de baja o se modifico */
    //for (int i = 0; i < registros; i++)
    //{
    //    punto1 = archivoPunto.LeerPuntoDeRetiro(i);
    //    if (punto1.getVigente())
    //    {
    //    punto1.MostrarPuntoDeRetiro();
    //      }
    //      else
    //      {
    //          std::cout << "No existen puntos de retiros Sin vigencia" << std::endl;
    //      }
    //}

    /********************** Medio de pago **********************/

    FormaDePago entidadPago;
    FormaDePagoArchivo archivoPago;

    //for (int i = 0; i < 3; i++)
    //{


    //entidadPago.CargarFormaDePago();

    //archivoPago.GuardarFormaDePago(entidadPago);

    //}
    int cantidad = archivoPago.CantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        entidadPago = archivoPago.ListarFormaDePago(i);
        entidadPago.MostrarFormaDePago();
    }

    ////Modificacion de los registros 

    int id;
    std::cout << "Ingrese el ID del registro a modificar" << std::endl;
    std::cin >> id;
    archivoPago.ModificarFormaDePago(id);
}
