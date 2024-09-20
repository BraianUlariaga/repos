#include "Martillo.h"
#include <iostream>


Martillo::Martillo(string tipo, float peso, float longitud, float precio) : Herramienta(peso, longitud, precio) {

	_nombre = "Martillo";
	_tipoCabeza = tipo;
};

void Martillo::setPeso(float peso)
{
	_peso = peso;
};
void Martillo::setLongitud(float longitud)
{
	_longitud = longitud;
};

float  Martillo::getPeso()
{
	return _peso;
};
float  Martillo::getLongitud()
{
	return _longitud;
};


void Martillo::mostrarInformacion()
{
	cout << "Herramienta: " << _nombre << endl <<
		"Tipo de Cabeza: " << _tipoCabeza << endl <<
		"Peso: " << _peso << "kg" << endl <<
		"Longitud: " << _longitud << "cm." << endl;

}