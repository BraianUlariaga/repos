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
    strcpy(_nombre, nombre.c_str());
}

void persona::setapellido(std::string apellido){
    strcpy(_apellido, apellido.c_str());
}

void persona::setdni(int dni){
    _dni = dni;
}

void persona::setnacimiento(fecha nacimiento){
    _nacimiento = nacimiento;
}

void persona::settelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}

void persona::setemail(std::string email){
        strcpy(_email, email.c_str());
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

void persona::Cargar() {
    std::string nombre, apellido, telefono, email;
    int dni;
    fecha nacimiento;

    do {
        std::cout << "NOMBRE: ";
        getline(std::cin, nombre);
        if (nombre.size() <= 99) {
            setnombre(nombre);
            break;
        } else {
            std::cout << "El nombre es demasiado largo. Intente nuevamente." <<std::endl;
        }
    } while (true);

    do {
        std::cout << "APELLIDO: ";
        getline(std::cin, apellido);
        if (apellido.size() <= 99) {
            setapellido(apellido);
            break;
        } else {
            std::cout << "El apellido es demasiado largo. Intente nuevamente. " <<std::endl;
        }
    } while (true);

    do {
        std::cout << "DNI: ";
        std::cin >> dni;
        if (dni > 0) {
            setdni(dni);
            break;
        } else {
            std::cout << "DNI invalido. Debe ser un numero positivo. Intente nuevamente." <<std::endl;
        }
    } while (true);

    std::cout << "FECHA DE NACIMIENTO: ";
    nacimiento.Cargar();
    setnacimiento(nacimiento);
    std::cin.ignore();

    do {
        std::cout << "TELEFONO: ";
        getline(std::cin, telefono);
        if (telefono.size() <= 12) {
            settelefono(telefono);
            break;
        } else {
            std::cout << "El telefono es demasiado largo. Intente nuevamente." <<std::endl;
        }
    } while (true);

    do {
        std::cout << "EMAIL: ";
        getline(std::cin, email);
        if (email.size() <= 99 && email.find('@') != std::string::npos && email.find('.') != std::string::npos) {
            setemail(email);
            break;
        } else {
            std::cout << "Email invalido. Debe contener '@' y '.'. Intente nuevamente. " <<std::endl;
        }
    } while (true);
    //la funcion find() lo que hace es buscar el caracter que se le indica buscar
    //y siempre se compara con "npos" que es un valor especial que indica "que no se encontro el caracter buscado".
}


void persona::Mostrar()const{
    std::cout<< "NOMBRE: " << getnombre() <<std::endl;
    std::cout<< "APELLIDO: " << getapellido() <<std::endl;
    std::cout<< "DNI: " << getdni() <<std::endl;
    std::cout<< "FECHA DE NACIMIENTO: " << getnacimiento().toString() <<std::endl;
    std::cout<< "TELEFONO: " << gettelefono() <<std::endl;
    std::cout<< "EMAIL: " << getemail() <<std::endl;
}

