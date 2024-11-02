#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "archivoAutos.h"

void Mayuscula(char* cadena){
    int longitud = strlen(cadena);

    for(int X=0; X<longitud; X++){
        cadena[X] = toupper(cadena[X]);
    }

}


ArchivoAutos::ArchivoAutos(){
    _nombre = "autos.dat";
}

bool ArchivoAutos::agregarRegistro(automovil &vehiculo){
    FILE *pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if(pFILE == nullptr){
        return false;
    }

    vehiculo.cargar();

    resultado = fwrite(&vehiculo, sizeof(automovil), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}
automovil ArchivoAutos::listar(int pos){
    FILE *pFILE;
    automovil vehiculo;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return vehiculo;
    }
    fseek(pFILE, sizeof(automovil)*pos, 0);
    fread(&vehiculo, sizeof(automovil), 1, pFILE);

    return vehiculo;

}

int ArchivoAutos::cantidadRegistros(){
    FILE *pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(automovil);

}

bool ArchivoAutos::leerRegistros(automovil registros[], int cantidad){
    FILE *pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return false;

    }

    result = fread(registros, sizeof(automovil), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;


}

int ArchivoAutos::buscarRegistro(char* patente){
    FILE *pFILE;
    automovil registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return -1;
    }

    Mayuscula(patente);

    while(fread(&registro, sizeof(automovil), 1, pFILE) == 1){
        if(strcmp(registro.getpatente(), patente) == 0){
            break;
        }
        pos++;
    }
    fclose(pFILE);

    if(strcmp(registro.getpatente(), patente) == 0){
        return pos;
    }
    else{return -2;}


}

bool ArchivoAutos::modificar(automovil &vehiculo, int pos){
    FILE *pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if(pFILE == nullptr || pos < 0){
        return false;
    }
    else{
        fseek(pFILE, sizeof(automovil)*pos, 0);
        result = fwrite(&vehiculo, sizeof(automovil), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}
