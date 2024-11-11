#pragma once
#include "Fecha.h"

class Persona{
private:
    char _Nombre[30];        //std::string _nombre;
    char _Apellido[30];      //std::string _apellido;
    int _DNI;
    Fecha _FechaNacimiento;
    char _Telefono[20]; //std::string _telefono;
    char _Email[50];    //std::string _email;
    
public:
    //constructor
    Persona();
    //setters
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setDNI(int dni);
    void setFechaNacimiento(Fecha nacimiento);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    //getters
    std::string getNombre()const;
    std::string getApellido()const;
    int getDNI()const;
    Fecha getFechaNacimiento()const;
    std::string getTelefono()const;
    std::string getEmail()const;
    //metodos
    void CargarPersona();
    void MostrarPersona()const;
};
