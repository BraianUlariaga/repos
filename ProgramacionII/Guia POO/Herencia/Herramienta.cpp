#include "Herramienta.h"
#include <iostream>


Herramienta::Herramienta(float peso, float longitud, float precio = 0.0) {
	_peso = peso;
	_longitud = longitud;
	_nombre = "";
	_precioDeCompra = precio;
};

/*	string getNombre() {

	return _nombre;
};*/
float  Herramienta::getPeso()
{
	return _peso;
};
float  Herramienta::getPrecio()
{
	return _precioDeCompra;
};
float  Herramienta::getLongitud()
{
	return _longitud;
};


//void setNombre(string nombre) 
//{
//	_nombre = nombre;
//};
void Herramienta::setPeso(float peso)
{
	_peso = peso;
};
void Herramienta::setPrecio(float precio)
{
	_precioDeCompra = precio;
};

void Herramienta::setLongitud(float longitud)
{
	_longitud = longitud;
};

void Herramienta::mostrarInformacion()
{
	cout << "Herramienta: " << _nombre << " Peso: " << _peso << " Longitud: " << _longitud << " ." << endl;

}