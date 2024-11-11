#pragma once
#include "Persona.h"

class Vendedor:public Persona{
private:
    int _Legajo;
    bool _Estado;

public:
    //constructor
    Vendedor();
    //setters
    void setLegajo(int legajo);
    void setEstado(bool estado);
    //getters
    int getLegajo()const;
    bool getEstado()const;
    //metodos
    void CargarVendedor();
    void MostrarVendedor();


};
