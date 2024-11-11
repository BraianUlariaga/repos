#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AutoArchivo.h"
#include "Validaciones.h"


AutoArchivo::AutoArchivo() {
    _nombre = "Autos.dat";
}

bool AutoArchivo::AgregarAuto(automovil& vehiculo) {
    FILE* pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if (pFILE == nullptr) {
        return false;
    }

    resultado = fwrite(&vehiculo, sizeof(automovil), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}

automovil AutoArchivo::ListarAuto(int pos) {
    FILE* pFILE;
    automovil vehiculo;

    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return vehiculo;
    }
    fseek(pFILE, sizeof(automovil) * pos, 0);
    fread(&vehiculo, sizeof(automovil), 1, pFILE);

    return vehiculo;

}

int AutoArchivo::CantidadRegistros() {
    FILE* pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(automovil);

}

bool AutoArchivo::ListarAutos(automovil registros[], int cantidad) {
    FILE* pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return false;

    }

    result = fread(registros, sizeof(automovil), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;

}

int AutoArchivo::BuscarAuto(char* patente) {
    FILE* pFILE;
    automovil registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return -1;
    }

    while (fread(&registro, sizeof(automovil), 1, pFILE) == 1) {

        //stricmp compara las palabras sin tener en cuenta mayusculas/minusculas

        if (_stricmp(registro.getPatente(), patente) == 0) {
            break;
        }
        pos++;
    }
    fclose(pFILE);

    if (_stricmp(registro.getPatente(), patente) == 0) {
        return pos;
    }
    else { return -2; }


}

bool AutoArchivo::ModificarAuto(automovil& vehiculo, int pos) {
    FILE* pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if (pFILE == nullptr || pos < 0) {
        return false;
    }
    else {
        fseek(pFILE, sizeof(automovil) * pos, 0);
        result = fwrite(&vehiculo, sizeof(automovil), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}
