#pragma once
#include <string>

using namespace std;

class Herramienta
{
protected:

	string _nombre;
	float _peso;
	float _longitud;
	float _precioDeCompra;

	public:

	Herramienta(float peso, float longitud, float precio);

	float  getPeso();
	float  getLongitud();
	float  getPrecio();

	void setPeso(float peso);
	void setLongitud(float longitud);
	void setPrecio(float precio);

	void mostrarInformacion();

};