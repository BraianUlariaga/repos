#define _CRT_SECURE_NO_WARNINGS
#include "PuntoDeRetiroArchivo.h"
#include <iostream>

//fseek mueve el puntero (nombrearchivo, desplazamiento del puntero apartir de la ubicacion, ubicacion del puntero)
//SEEK_SET: Comienza desde el inicio del archivo.
//SEEK_CUR: Comienza desde la posición actual del puntero.
//SEEK_END : Comienza desde el final del archivo.
/*Manejo de archivos*/

PuntoDeRetiroArchivo::PuntoDeRetiroArchivo() {
	_NombreArchivo = "PuntoDeRetiro.dat";
}

bool PuntoDeRetiroArchivo::AgregarPuntoDeRetiro(PuntoDeRetiro reg) {
    FILE* pArchivo;
    pArchivo = fopen( _NombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&reg, sizeof(PuntoDeRetiro), 1, pArchivo);
    fclose(pArchivo);
    return true;
}


PuntoDeRetiro PuntoDeRetiroArchivo::ListarPuntoDeRetiro(int posicion) {
    FILE* pArchivo;
    pArchivo = fopen( _NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return PuntoDeRetiro();
    }
    PuntoDeRetiro puntoDeRetiro;
    fseek(pArchivo, sizeof(PuntoDeRetiro) * posicion, SEEK_SET);
    fread(&puntoDeRetiro, sizeof(PuntoDeRetiro), 1, pArchivo);
    fclose(pArchivo);
    return puntoDeRetiro;
}

bool PuntoDeRetiroArchivo::ListarPuntosDeRetiros(PuntoDeRetiro registros[], int cantidad) {
    FILE* pFILE;
    bool result;

    pFILE = fopen(_NombreArchivo.c_str(), "rb");
    if (pFILE == nullptr) {
        return false;
    }

    result = fread(registros, sizeof(PuntoDeRetiro), cantidad, pFILE) == cantidad;
    fclose(pFILE);

    return result;

}

int PuntoDeRetiroArchivo::CantidadRegistros() {
    FILE* pArchivo;
    pArchivo = fopen(_NombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(PuntoDeRetiro);
    fclose(pArchivo);
    return cantidadRegistros;
}

int PuntoDeRetiroArchivo::ObtenerUltimoId() {
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
    PuntoDeRetiro ultimoId;
    fseek(pArchivo, -static_cast<long>(sizeof(PuntoDeRetiro)), SEEK_END);
    fread(&ultimoId, sizeof(PuntoDeRetiro), 1, pArchivo);

    fclose(pArchivo);

    return ultimoId.getIdPuntoRetiro()+1; // Ultimo id + 1
}


int PuntoDeRetiroArchivo::BuscarPuntoDeRetiro(int id) {
    FILE* pFile;
    PuntoDeRetiro puntoDeRetiro;
    int pos = 0;

    pFile = fopen(_NombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return false;
    }

    while (fread(&puntoDeRetiro, sizeof(PuntoDeRetiro), 1, pFile) == 1) {
        if (puntoDeRetiro.getIdPuntoRetiro() == id) {
           fclose(pFile);
           return pos;
        
        }
        pos++;
    }

  return -1;
}

/*Manejo de archivos para las modificaciones */


bool PuntoDeRetiroArchivo::GuardarModificacion(PuntoDeRetiro puntoDeRetiro, int posicion) {
    FILE* pArchivo;
    fopen_s(&pArchivo, _NombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(PuntoDeRetiro) * posicion, SEEK_SET);
    bool ok = fwrite(&puntoDeRetiro, sizeof(PuntoDeRetiro), 1, pArchivo);
    fclose(pArchivo);
    return true;
}

void PuntoDeRetiroArchivo::ModificarPuntoDeRetiro(int id) {
    PuntoDeRetiro puntoDeRetiro;
    PuntoDeRetiroArchivo arch;

    int pos = arch.BuscarPuntoDeRetiro(id); //Si la funcion me devuelve -1 significa que no hay registros

    if (pos != -1) {

        std::cout << "Elija una opcion: " << std::endl;
        int opc;
        std::cout << "1 - Modificar registro." << std::endl;
        std::cout << "2 - Dar de baja." << std::endl;
        std::cin >> opc;
        if (opc == 1)
        {
            puntoDeRetiro = arch.ListarPuntoDeRetiro(pos);

            std::cout << "Datos a modificar: " << std::endl;
            puntoDeRetiro.MostrarPuntoDeRetiro();

            system("pause");
            std::cout << "      Presione una tecla para continuar..." << std::endl;
            system("cls"); // Limpia la pantalla antes de mostrar el menú nuevamente

            std::cout << "MODIFICAR: " << std::endl;

            puntoDeRetiro.ModificarPuntoDeRetiro();
        
            if ( arch.GuardarModificacion(puntoDeRetiro,pos) )
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
            puntoDeRetiro = arch.ListarPuntoDeRetiro(pos);
            puntoDeRetiro.BajaPuntoDeRetiro();
            arch.GuardarModificacion(puntoDeRetiro, pos);
            puntoDeRetiro.MostrarPuntoDeRetiro();
        }
        
    }
    else {
        std::cout << "El producto no se encuentra en el sistema." << std::endl;
    }
}
