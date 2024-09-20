#include "TaladroPercutor.h"
#include <iostream>


TaladroPercutor::TaladroPercutor(float potencia, float peso, float longitud, float precio, int golpesPorMinuto) : Taladro( potencia, peso, longitud, precio){

	_nombre = "Taladro percutor";
	_golpesPorMinuto = golpesPorMinuto;
};

void TaladroPercutor::setGolpesPorMinuto(int golpesPorMinuto)
{
	_golpesPorMinuto = golpesPorMinuto;
};

int  TaladroPercutor::getGolpesPorMinuto()
{
	return _golpesPorMinuto;
};

float TaladroPercutor::getPotenciaTaladroPercutor() {

	return Taladro::getPotencia();
};


void TaladroPercutor::mostrarInformacion()
{
	cout << "Herramienta: " << _nombre << endl <<
		"Potencia: " << _potencia << " Watts" << endl <<
		"Golpes por mint.: " << _golpesPorMinuto << endl <<
		"Peso: " << _peso << "kg" << endl <<
		"Longitud: " << _longitud << "cm." << endl;

}