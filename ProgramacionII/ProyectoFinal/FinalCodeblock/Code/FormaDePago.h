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
	void CargarFormaDePago();
	void MostrarFormaDePago();
	void BajaFormaDePago();
	void ModificarFormaDePago();

private:

	int _IdPago;
	char _Descripcion[100];		//std::string _Descripcion;
	float _TasaInteres;
	bool _Vigente;

};
