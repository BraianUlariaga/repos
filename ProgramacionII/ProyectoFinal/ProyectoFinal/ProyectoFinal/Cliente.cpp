#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Persona.h"
#include "Validaciones.h"
#include <iostream>


Cliente::Cliente()
{
}

/*Setters*/
void Cliente::setIDCliente(int id) { _IdCliente = id; };
	 
/*Getters*/
int Cliente::getIDCliente() { return _IdCliente ; };
/*Ver opciones para que el ID sea autoincremental*/

/*Metodos*/

void Cliente::Cargar() {

	ArchivoCliente archivo;
	setIDCliente(archivo.ObtenerUltimoId());
	Persona::Cargar();

};

void Cliente::Mostrar()	{

	std::cout << "Id: " << getIDCliente() << std::endl;
	Persona::Mostrar();
};

