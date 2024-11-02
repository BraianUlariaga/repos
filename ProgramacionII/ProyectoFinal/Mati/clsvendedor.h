#pragma once
#include "clsPersona.h"

class vendedor:public persona{
private:
    int _legajo;
    bool _estado;

public:
    //constructor
    vendedor();
    //setters
    void setlegajo(int legajo);
    void setestado(bool estado);
    //getters
    int getlegajo()const;
    bool getestado()const;
    //metodos
    void cargar();
    void mostrar();


};
