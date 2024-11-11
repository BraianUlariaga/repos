#pragma once
#include <string>

class PuntoDeRetiro
{
public:
	PuntoDeRetiro()
	{
	}

	/*Setters*/
	void setIdPuntoRetiro(int id);
	void setDomicilio(std::string domicilio);
	void setLocalidad(std::string localidad);
	void setVigente(bool vigencia);

	/*Getters*/
	int getIdPuntoRetiro();
	std::string getDomicilio();
	std::string getLocalidad();
	bool getVigente();

	/*Metodos*/

	void CargarPuntoDeRetiro();
	void MostrarPuntoDeRetiro();
	void BajaPuntoDeRetiro();
	void ModificarPuntoDeRetiro();


private:


	int _IdPuntoRetiro;
	char _Domicilio[100];	//std::string _Domicilio;
	char _Localidad[50];	//std::string _Localidad;
	bool _Estado;

};
