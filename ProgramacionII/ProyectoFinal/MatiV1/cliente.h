#pragma once
#include "clsPersona.h"

class cliente:public persona{
private:
    int _idCliente;
public:
    //constructor
    cliente();
    //setters
    void setidCliente(int idCliente);
    //getters
    int getidCliente();
    //metodos
    void cargar();
    void mostrar();

};
