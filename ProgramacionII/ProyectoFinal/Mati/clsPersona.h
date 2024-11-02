#pragma once
#include "clsfecha.h"

class persona{
private:
    char _nombre[100];
    char _apellido[100];
    int _dni;
    fecha _nacimiento;
    char _telefono[13];
    char _email[100];
public:
    //constructor
    persona();
    //setters
    void setnombre(std::string nombre);
    void setapellido(std::string apellido);
    void setdni(int dni);
    void setnacimiento(fecha nacimiento);
    void settelefono(std::string telefono);
    void setemail(std::string email);
    //getters
    const char* getnombre()const;
    const char* getapellido()const;
    int getdni()const;
    fecha getnacimiento()const;
    const char* gettelefono()const;
    const char* getemail()const;
    //metodos
    void Cargar();
    void Mostrar()const;
};
