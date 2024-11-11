#include "Cliente.h"
#include "ClienteArchivo.h"
#include "Persona.h"
#include "Validaciones.h"
#include <iostream>


Cliente::Cliente()  {}

/*Setters*/
void Cliente::setIDCliente(int id) { _IdCliente = id; }

/*Getters*/
int Cliente::getIDCliente() { return _IdCliente; }
/*Ver opciones para que el ID sea autoincremental*/

/*Metodos*/

void Cliente::CargarCliente() {

	ClienteArchivo archivo;
	setIDCliente(archivo.ObtenerUltimoId());
	Persona::CargarPersona();

}

void Cliente::MostrarCliente()	{

	std::cout << "Id: " << getIDCliente() << std::endl;
	Persona::MostrarPersona();
}

