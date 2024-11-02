#include <iostream>
#include <cstring>
#include "clsPersona.h"


//constructor
persona::persona(){
    strcpy(_nombre, "S/N");
    strcpy(_apellido, "S/A");
    _dni = 0;
    _nacimiento.toString();
    strcpy(_telefono, "S/T");
    strcpy(_email, "S/E");
}
//setters
void persona::setnombre(std::string nombre){
    if(nombre.size() <= 10){
        strcpy(_nombre, nombre.c_str());
    }
}
void persona::setapellido(std::string apellido){
    if(apellido.size() <= 99){
        strcpy(_apellido, apellido.c_str());
    }
}
void persona::setdni(int dni){
    if(dni > 0){
        _dni = dni;
    }
}
void persona::setnacimiento(fecha nacimiento){
    _nacimiento = nacimiento;
}
void persona::settelefono(std::string telefono){
    if(telefono.size() <= 12){
        strcpy(_telefono, telefono.c_str());
    }
}
void persona::setemail(std::string email){
    if(email.size() <= 99){
        if(email.find('@') != std::string::npos && email.find('.') != std::string::npos){ //la funcion find() lo que hace es buscar el caracter que se le indica buscar
            strcpy(_email, email.c_str());                                                              //y siempre se compara con "npos" que es un valor especial que indica "que no se encontro el caracter buscado".
        }
    }
}
//getters
const char* persona::getnombre()const{
    return _nombre;
}
const char* persona::getapellido()const{
    return _apellido;
}
int persona::getdni()const{
    return _dni;
}
fecha persona::getnacimiento()const{
    return _nacimiento;
}
const char* persona::gettelefono()const{
    return _telefono;
}
const char* persona::getemail()const{
    return _email;
}
//metodos
void persona::Cargar(){
    std::string nombre, apellido, telefono, email;
    int dni;
    fecha nacimiento;

    std::cout<< "NOMBRE: ";
    getline(std::cin, nombre);
    setnombre(nombre);

    std::cout<< "APELLIDO: ";
    getline(std::cin, apellido);
    setapellido(apellido);

    std::cout<< "DNI: ";
    std::cin>> dni;
    setdni(dni);

    std::cout<< "FECHA DE NACIMIENTO: ";
    nacimiento.Cargar();
    setnacimiento(nacimiento);
    std::cin.ignore();

    std::cout<< "TELEFONO: ";
    getline(std::cin, telefono);
    settelefono(telefono);

    std::cout<< "EMAIL: ";
    getline(std::cin, email);
    setemail(email);
}
void persona::Mostrar()const{
    std::cout<< "NOMBRE: " << getnombre() <<std::endl;
    std::cout<< "APELLIDO: " << getapellido() <<std::endl;
    std::cout<< "DNI: " << getdni() <<std::endl;
    std::cout<< "FECHA DE NACIMIENTO: " << getnacimiento().toString() <<std::endl;
    std::cout<< "TELEFONO: " << gettelefono() <<std::endl;
    std::cout<< "EMAIL: " << getemail() <<std::endl;
    std::cout<< "-------------------------------" << std::endl;
}

