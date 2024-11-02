#define _CRT_SECURE_NO_WARNINGS
#include "ArchivoCliente.h"
#include "Cliente.h"
#include <iostream>

ArchivoCliente::ArchivoCliente() {
    _NombreArchivo = "Cliente.dat";
}

bool ArchivoCliente::GuardarCliente(Cliente cliente) {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return true;
}

Cliente ArchivoCliente::LeerCliente(int posicion) {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return Cliente();
    }
    Cliente cliente;
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return cliente;
}

int ArchivoCliente::CantidadRegistros() {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
    fclose(pArchivo);
    return cantidadRegistros;
}

int ArchivoCliente::ObtenerUltimoId() {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 1; // devuelve 1 si no existe el archivo
    }

    fseek(pArchivo, 0, SEEK_END);
    long tamanoArchivo = ftell(pArchivo);

    if (tamanoArchivo == 0) {
        fclose(pArchivo);
        return 1; // devuelve 1 si el archivo esta vacio
    }

    // Nos movemos al último registro
    Cliente ultimoCliente;
    fseek(pArchivo, -static_cast<long>(sizeof(Cliente)), SEEK_END);
    fread(&ultimoCliente, sizeof(Cliente), 1, pArchivo);

    fclose(pArchivo);

    return ultimoCliente.getIDCliente() + 1; //Ultimo id + 1
}

int ArchivoCliente::Buscar(int id) {
    FILE* pFile;
    Cliente cliente;
    int pos = 0;

    pFile = fopen(_NombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    while (fread(&cliente, sizeof(Cliente), 1, pFile) == 1) {
        if (cliente.getIDCliente() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

bool ArchivoCliente::Guardar(Cliente cliente, int posicion) {
    FILE* pArchivo;
    fopen_s(&pArchivo, _NombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return true;
}

void ArchivoCliente::ModificarCliente(int id) {
    Cliente cliente;
    ArchivoCliente arch;

    int pos = arch.Buscar(id); // If the function returns -1, the record is not found

    if (pos != -1) {
            cliente = arch.LeerCliente(pos);

            std::cout << "Datos a modificar: " << std::endl;
            cliente.Mostrar();

            system("pause");
            std::cout << "      Presione una tecla para continuar..." << std::endl;
            system("cls"); // Clear screen

            std::cout << "MODIFICAR: " << std::endl;

            cliente.Cargar();

            if (arch.Guardar(cliente, pos)) {
                std::cout << "Modificacion exitosa." << std::endl;
            }
            else {
                std::cout << "ERROR al guardar la modificacion." << std::endl;
            }


    }
    else {
        std::cout << "El cliente no se encuentra en el sistema." << std::endl;
    }
}