#pragma once
#include "Auto.h"

class AutoArchivo {
private:
    std::string _nombre;

public:
    AutoArchivo();
    bool AgregarAuto(automovil& vehiculo);
    automovil ListarAuto(int pos);
    bool ListarAutos(automovil registros[], int cantidad);
    int CantidadRegistros();
    int BuscarAuto(char* patente);
    bool ModificarAuto(automovil& vehiculo, int pos);


};
