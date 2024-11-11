#define _CRT_SECURE_NO_WARNINGS
#include "FormaDePagoArchivo.h"
#include <iostream>
#include <cstring>

//fseek mueve el puntero (nombrearchivo, desplazamiento del puntero apartir de la ubicacion, ubicacion del puntero)
//SEEK_SET: Comienza desde el inicio del archivo.
//SEEK_CUR: Comienza desde la posición actual del puntero.
//SEEK_END : Comienza desde el final del archivo.
/*Manejo de archivos*/

FormaDePagoArchivo::FormaDePagoArchivo() {
    _NombreArchivo = "FormaDePago.dat";
}

bool FormaDePagoArchivo::AgregarFormaDePago(FormaDePago reg) {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(FormaDePago), 1, pArchivo);
    fclose(pArchivo);
    return true;
}


FormaDePago FormaDePagoArchivo::ListarFormaDePago(int posicion) {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return FormaDePago();
    }
    FormaDePago formaDePago;
    fseek(pArchivo, sizeof(FormaDePago) * posicion, SEEK_SET);
    fread(&formaDePago, sizeof(FormaDePago), 1, pArchivo);
    fclose(pArchivo);
    return formaDePago;
}

int FormaDePagoArchivo::CantidadRegistros() {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(FormaDePago);
    fclose(pArchivo);
    return cantidadRegistros;
}

    int FormaDePagoArchivo::ObtenerUltimoId() {
        FILE* pArchivo;

        pArchivo = fopen(_NombreArchivo.c_str(), "rb");
        if (pArchivo == NULL) {
            return 1; // Si el archivo no existe, retorna 1
        }

        fseek(pArchivo, 0, SEEK_END);
        long tamanoArchivo = ftell(pArchivo);

        if (tamanoArchivo == 0) {
            fclose(pArchivo);
            return 1; // Si el archivo está vacío, retornamos 1
        }

        // Nos movemos al último registro
        FormaDePago ultimoId;
        fseek(pArchivo, -static_cast<long>(sizeof(FormaDePago)), SEEK_END);
        fread(&ultimoId, sizeof(FormaDePago), 1, pArchivo);

        fclose(pArchivo);

        return ultimoId.getIdPago() + 1; // Ultimo id + 1
    }


int FormaDePagoArchivo::BuscarFormaDePago(int id) {
    FILE* pFile;
    FormaDePago formaDePago;
    int pos = 0;

    pFile = fopen(_NombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return false;
    }

    while (fread(&formaDePago, sizeof(FormaDePago), 1, pFile) == 1) {
        if (formaDePago.getIdPago() == id) {
            fclose(pFile);
            return pos;

        }
        pos++;
    }

    return -1;
}

/*Manejo de archivos para las modificaciones */


bool FormaDePagoArchivo::GuardarModificacion(FormaDePago formaDePago, int posicion) {
    FILE* pArchivo;
    fopen_s(&pArchivo, _NombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(FormaDePago) * posicion, SEEK_SET);
    bool ok = fwrite(&formaDePago, sizeof(FormaDePago), 1, pArchivo);
    fclose(pArchivo);
    return true;
}

void FormaDePagoArchivo::ModificarFormaDePago(int id) {
    FormaDePago formaDePago;
    FormaDePagoArchivo arch;

    int pos = arch.BuscarFormaDePago(id); //Si la funcion me devuelve -1 significa que no hay registros

    if (pos != -1) {

        std::cout << "Elija una opcion: " << std::endl;
        int opc;
        std::cout << "1 - Modificar registro." << std::endl;
        std::cout << "2 - Dar de baja." << std::endl;
        std::cin >> opc;
        if (opc == 1)
        {
            formaDePago = arch.ListarFormaDePago(pos);

            std::cout << "Datos a modificar: " << std::endl;
            formaDePago.MostrarFormaDePago();

            system("pause");
            std::cout << "      Presione una tecla para continuar..." << std::endl;
            system("cls"); // Limpia la pantalla antes de mostrar el menú nuevamente

            std::cout << "MODIFICAR: " << std::endl;

            formaDePago.ModificarFormaDePago();

            if (arch.GuardarModificacion(formaDePago, pos))
            {
                std::cout << "Modificacion exitosa " << std::endl;
            }
            else
            {
                std::cout << "ERROR al guardar la modificacion." << std::endl;
            }
        }
        else if (opc == 2)
        {
            formaDePago = arch.ListarFormaDePago(pos);
            formaDePago.BajaFormaDePago();
            arch.GuardarModificacion(formaDePago, pos);
            formaDePago.MostrarFormaDePago();
        }

    }
    else {
        std::cout << "El producto no se encuentra en el sistema." << std::endl;
    }
}
