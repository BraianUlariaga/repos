#include "Destornillador.h"
#include <iostream>


Destornillador::Destornillador(string tipo, float peso, float longitud, float precio) : Herramienta(peso, longitud, precio) {

	_nombre = "Destornillador";
	_tipoPunta = tipo;
};

void Destornillador::setTipo(float tipo)
{
	_tipoPunta = tipo;
};

string  Destornillador::getTipo()
{
	return _tipoPunta;
};

void Destornillador::mostrarInformacion()
{
	cout << "Herramienta: " << _nombre << endl <<
		"Tipo de punta: " << _tipoPunta << endl <<
		"Peso: " << _peso << "kg" << endl <<
		"Longitud: " << _longitud << "cm." << endl;

}