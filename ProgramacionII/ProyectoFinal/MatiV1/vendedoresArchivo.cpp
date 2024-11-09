#include <iostream>
#include <cstring>
#include "vendedoresArchivo.h"

/*void Mayuscula(char* cadena){
    int longitud = strlen(cadena);

    for(int X=0; X<longitud; X++){
        cadena[X] = toupper(cadena[X]);
    }

}*/


vendedoresArchivo::vendedoresArchivo(){
    _nombre = "vendedores.dat";
}

bool vendedoresArchivo::agregarRegistro(vendedor &registro){
    FILE *pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if(pFILE == nullptr){
        return false;
    }

    registro.cargar();

    resultado = fwrite(&registro, sizeof(vendedor), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}

vendedor vendedoresArchivo::listar(int pos){
    FILE *pFILE;
    vendedor registro;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return registro;
    }
    fseek(pFILE, sizeof(registro)*pos, 0);
    fread(&registro, sizeof(vendedor), 1, pFILE);

    return registro;

}

int vendedoresArchivo::cantidadRegistros(){
    FILE *pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(vendedor);

}

bool vendedoresArchivo::leerRegistros(vendedor registros[], int cantidad){
    FILE *pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return false;

    }

    result = fread(registros, sizeof(vendedor), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;


}

int vendedoresArchivo::buscarRegistro(int legajo){
    FILE *pFILE;
    vendedor registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if(pFILE == nullptr){
        return -1;
    }

    while(fread(&registro, sizeof(vendedor), 1, pFILE) == 1){
        if(registro.getlegajo() == legajo){
            break;
        }
        pos++;
    }
    fclose(pFILE);
    if(registro.getlegajo() == legajo){
        return pos;
    }
    else{return -2;}

}

bool vendedoresArchivo::modificar(vendedor &registro, int pos){
    FILE *pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if(pFILE == nullptr || pos < 0){
        return false;
    }
    else{
        fseek(pFILE, sizeof(vendedor)*pos, 0);
        result = fwrite(&registro, sizeof(vendedor), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}
