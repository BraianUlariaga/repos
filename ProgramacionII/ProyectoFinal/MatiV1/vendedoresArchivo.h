#pragma once
#include "clsvendedor.h"

//void Mayuscula(char* cadena);


class vendedoresArchivo{
private:
    std::string _nombre;

public:
    vendedoresArchivo();
    bool agregarRegistro(vendedor &registro);
    vendedor listar(int pos);
    int cantidadRegistros();
    bool leerRegistros(vendedor registros[], int cantidad);
    int buscarRegistro(int legajo);
    bool modificar(vendedor &registro, int pos);

};
