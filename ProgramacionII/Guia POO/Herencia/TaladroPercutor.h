#pragma once
#include "Taladro.h"

class TaladroPercutor : public Taladro
{
	private:
		int _golpesPorMinuto;

	public:
	TaladroPercutor(float potencia, float peso, float longitud, float precio, int _golpesPorMinuto);

	void setGolpesPorMinuto(int golpesPorMinuto);
	int getGolpesPorMinuto();
	float getPotenciaTaladroPercutor();

	void mostrarInformacion();

};

