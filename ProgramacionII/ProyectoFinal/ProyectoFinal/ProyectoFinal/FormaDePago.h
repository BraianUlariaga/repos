#pragma once
#include <string>

class FormaDePago
{
public:

	/*Setters*/
	void setIdPago(int id);
	void setDescripcion(std::string descripcion);
	void setTasaInteres(float tasaInteres);
	void setVigente(bool vigente);

	/*Getters*/
	int getIdPago();
	std::string getDescripcion();
	float getTasaInteres();
	bool getVigente();

	/*Metodos*/
	void CargarMedioPago();
	void MostrarMedioPago();

private:

	int _IdPago;
	std::string _Descripcion;
	float _TasaInteres;
	bool _Vigente;

};
