#define _CRT_SECURE_NO_WARNINGS
#include "clienteArchivo.h"

clienteArchivo::clienteArchivo(){
    _nombre = "clientes.dat";
}

bool clienteArchivo::agregarRegistro(cliente &registro){
    FILE *pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if(pFILE == nullptr){
        return false;
    }

    registro.cargar();

    resultado = fwrite(&registro, sizeof(cliente), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}

cliente clienteArchivo::listar(int pos){
    FILE *pFILE;
    cliente registro;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return registro;
    }
    fseek(pFILE, sizeof(cliente)*pos, 0);
    fread(&registro, sizeof(cliente), 1, pFILE);

    return registro;

}

int clienteArchivo::cantidadRegistros(){
    FILE *pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(cliente);

}

bool clienteArchivo::leerRegistros(cliente registros[], int cantidad){
    FILE *pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return false;

    }

    result = fread(registros, sizeof(cliente), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;


}

int clienteArchivo::buscarRegistro(int dni){
    FILE *pFILE;
    cliente registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return -1;
    }

    while(fread(&registro, sizeof(cliente), 1, pFILE) == 1){
        if(registro.getdni() == dni){
            break;
        }
        pos++;
    }
    fclose(pFILE);

    if(registro.getdni() == dni){
        return pos;
    }
    else{return -2;}


}

bool clienteArchivo::modificar(cliente &registro, int pos){
    FILE *pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if(pFILE == nullptr || pos < 0){
        return false;
    }
    else{
        fseek(pFILE, sizeof(cliente)*pos, 0);
        result = fwrite(&registro, sizeof(cliente), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}
