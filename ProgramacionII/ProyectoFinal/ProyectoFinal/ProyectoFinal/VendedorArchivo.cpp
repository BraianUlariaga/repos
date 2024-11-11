#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "VendedorArchivo.h"


VendedorArchivo::VendedorArchivo() {
    _nombre = "Vendedores.dat";
}

bool VendedorArchivo::AgregarVendedor(Vendedor& registro) {
    FILE* pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if (pFILE == nullptr) {
        return false;
    }

    resultado = fwrite(&registro, sizeof(Vendedor), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}

Vendedor VendedorArchivo::ListarVendedor(int pos) {
    FILE* pFILE;
    Vendedor registro;

    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return registro;
    }
    fseek(pFILE, sizeof(registro) * pos, 0);
    fread(&registro, sizeof(Vendedor), 1, pFILE);

    return registro;

}

int VendedorArchivo::CantidadRegistros() {
    FILE* pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(Vendedor);

}

bool VendedorArchivo::ListarVendedores(Vendedor registros[], int cantidad) {
    FILE* pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return false;

    }

    result = fread(registros, sizeof(Vendedor), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;


}

int VendedorArchivo::BuscarVendedor(int legajo) {
    FILE* pFILE;
    Vendedor registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return -1;
    }

    while (fread(&registro, sizeof(Vendedor), 1, pFILE) == 1) {
        if (registro.getLegajo() == legajo) {
            break;
        }
        pos++;
    }
    fclose(pFILE);
    if (registro.getLegajo() == legajo) {
        return pos;
    }
    else { return -2; }

}

bool VendedorArchivo::ModificarVendedor(Vendedor& registro, int pos) {
    FILE* pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if (pFILE == nullptr || pos < 0) {
        return false;
    }
    else {
        fseek(pFILE, sizeof(Vendedor) * pos, 0);
        result = fwrite(&registro, sizeof(Vendedor), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}
