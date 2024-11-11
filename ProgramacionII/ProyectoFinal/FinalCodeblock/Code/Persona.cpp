#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persona.h"
#include "Validaciones.h"
#include <string>
#include <cstring>


//constructor
Persona::Persona() {
	strcpy(_Nombre, "S/N");
	strcpy(_Apellido, "S/A");
	_DNI = 0;
	_FechaNacimiento.toString();
	strcpy(_Telefono, "S/T");
	strcpy(_Email, "S/E");
}
//setters
void Persona::setNombre(std::string nombre) {
	if (nombre.length() < 30)
	{
		strcpy(_Nombre, nombre.c_str());
	}
}
void Persona::setApellido(std::string apellido) {
	if (apellido.length() < 30)
	{
		strcpy(_Apellido, apellido.c_str());
	}
}
void Persona::setDNI(int dni) {
	_DNI = dni;
}
void Persona::setFechaNacimiento(Fecha nacimiento) {
	_FechaNacimiento = nacimiento;
}
void Persona::setTelefono(std::string telefono) {
	if (telefono.length() < 20)
	{
		strcpy(_Telefono, telefono.c_str());
	}
}
void Persona::setEmail(std::string email) {
	if (email.length() < 50)
	{
		strcpy(_Email, email.c_str());
	}
}
//getters
std::string Persona::getNombre()const {
	return _Nombre;
}
std::string Persona::getApellido()const {
	return _Apellido;
}
int Persona::getDNI()const {
	return _DNI;
}
Fecha Persona::getFechaNacimiento()const {
	return _FechaNacimiento;
}
std::string Persona::getTelefono()const {
	return _Telefono;
}
std::string Persona::getEmail()const {
	return _Email;
}
//metodos
void Persona::CargarPersona() {
	std::string nombre, apellido, telefono, email;
	int dni;
	Fecha nacimiento;

	std::cout << "NOMBRE: ";
	getline(std::cin, nombre);
	if (Validaciones::ValidarStringVacio(nombre)) // valido que el nombre no este vacio
	{
		std::cout << "El nombre no puede estar vacio." << std::endl;
	}
	else
	{
		setNombre(nombre);
	}

	std::cout << "APELLIDO: ";
	getline(std::cin, apellido);
	if (Validaciones::ValidarStringVacio(apellido)) // valido que el nombre no este vacio
	{
		std::cout << "El apellido no puede estar vacio." << std::endl;
	}
	else
	{
		setApellido(apellido);

	}

	std::cout << "DNI: ";
	std::cin >> dni;
	if (Validaciones::ValidaPositivo(dni))// valido que el DNI no sea negativo
	{
		std::cout << "El numero no puede ser negativo." << std::endl;
	}
	else
	{
		if (Validaciones::ValidaLongitudNumMayorA6(dni)) // valido que el dni tenga mas de 6 digitos
		{
			std::cout << "El DNI debe tener 6 digitos." << std::endl;
		}
		else
		{
			setDNI(dni);
			std::cout << "DNI ingresado correctamente." << std::endl;
		}
	}


	std::cout << "FECHA DE NACIMIENTO: ";
	nacimiento.CargarFecha();
	setFechaNacimiento(nacimiento);
	std::cin.ignore();

	std::cout << "TELEFONO: ";
	getline(std::cin, telefono);
	if (Validaciones::ValidarStringVacio(telefono))
	{
		std::cout << "El telefono no puede estar vacio." << std::endl;
	}
	else if (telefono.size()>=8)
	{
		setTelefono(telefono);
	}
	else
	{
		std::cout << "El telefono tiene menos de 8 caracteres." << std::endl;
	}


	std::cout << "EMAIL: ";
	getline(std::cin, email);
	if (Validaciones::ValidarMail(email)) {

		setEmail(email);
	}
	else
	{
		std::cout << "Mail invalido" << std::endl;
	}
}
void Persona::MostrarPersona()const {
	std::cout << "NOMBRE: " << getNombre() << std::endl;
	std::cout << "APELLIDO: " << getApellido() << std::endl;
	std::cout << "DNI: " << getDNI() << std::endl;
	std::cout << "FECHA DE NACIMIENTO: " << getFechaNacimiento().toString() << std::endl;
	std::cout << "TELEFONO: " << getTelefono() << std::endl;
	std::cout << "EMAIL: " << getEmail() << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

