#pragma once
#include <string>
#include "Fecha.h"
#include "Persona.h"

class Cliente : public Persona
{
public:

	Cliente();
	/*Setters*/
	void setIDCliente(int id);

	/*Getters*/
	int getIDCliente();

	/*Funciones*/
	void CargarCliente();
	void MostrarCliente();

private:
	int _IdCliente;

};
