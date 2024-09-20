#pragma once
#include "Herramienta.h"

class Destornillador : public Herramienta
{
private:
	string _tipoPunta;
public:

	Destornillador(string tipo, float peso, float longitud, float precio);

	void setTipo(float tipo);
	string getTipo();

	void mostrarInformacion();

};