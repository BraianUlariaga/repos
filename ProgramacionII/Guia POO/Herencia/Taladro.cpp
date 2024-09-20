#include "Taladro.h"
#include <iostream>


Taladro::Taladro(float potencia, float peso, float longitud, float precio) : Herramienta(peso, longitud, precio) {

	_nombre = "Taladro";
	_potencia = potencia;
};

void Taladro::setPotencia(float potencia)
{
	_potencia = potencia;
};
float  Taladro::getPotencia()
{
	return _potencia;
};


void Taladro::mostrarInformacion()
{
	cout << "Herramienta: " << _nombre << endl <<
		"Potencia: " << _potencia << " Watts" << endl <<
		"Peso: " << _peso << "kg" << endl <<
		"Longitud: " << _longitud << "cm." << endl;

}