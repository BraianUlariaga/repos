#include "facturaArchivo.h"

facturaArchivo::facturaArchivo(){
    _nombre = "facturas.dat";
}
bool facturaArchivo::agregarRegistro(DetalleFactura &registro){
    FILE *pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if(pFILE == nullptr){
        return false;
    }

    registro.cargar();

    resultado = fwrite(&registro, sizeof(DetalleFactura), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}

DetalleFactura facturaArchivo::listar(int pos){
    FILE *pFILE;
    DetalleFactura registro;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return registro;
    }
    fseek(pFILE, sizeof(DetalleFactura)*pos, 0);
    fread(&registro, sizeof(DetalleFactura), 1, pFILE);

    return registro;
}

int facturaArchivo::cantidadRegistros(){
    FILE *pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(DetalleFactura);
}

bool facturaArchivo::leerRegistros(DetalleFactura registros[], int cantidad){
    FILE *pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return false;

    }

    result = fread(registros, sizeof(DetalleFactura), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;
}

int facturaArchivo::buscarRegistro(int IDVenta){
    FILE *pFILE;
    DetalleFactura registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return -1;
    }

    while(fread(&registro, sizeof(DetalleFactura), 1, pFILE) == 1){
        if(registro.getIDVenta() == IDVenta){
            break;
        }
        pos++;
    }
    fclose(pFILE);

    if(registro.getIDVenta() == IDVenta){
        return pos;
    }
    else{return -2;}
}

bool facturaArchivo::modificar(DetalleFactura &registro, int pos){
    FILE *pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if(pFILE == nullptr || pos < 0){
        return false;
    }
    else{
        fseek(pFILE, sizeof(DetalleFactura)*pos, 0);
        result = fwrite(&registro, sizeof(DetalleFactura), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}
