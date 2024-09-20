#pragma once
#include "Herramienta.h"

using namespace std;

class Martillo : public Herramienta
{
private:
	string _tipoCabeza;
public:

	Martillo(string tipo, float peso, float longitud, float precio);

	void setPeso(float peso);
	void setLongitud(float longitud);

	float  getPeso();
	float  getLongitud();

	void mostrarInformacion();

};