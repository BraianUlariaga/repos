#pragma once
#include "clsauto.h"

void Mayuscula(char* cadena);


class ArchivoAutos{
private:
    std::string _nombre;

public:
    ArchivoAutos();
    bool agregarRegistro(automovil &vehiculo);
    automovil listar(int pos);
    int cantidadRegistros();
    bool leerRegistros(automovil registros[], int cantidad);
    int buscarRegistro(char* patente);
    bool modificar(automovil &vehiculo, int pos);


};
