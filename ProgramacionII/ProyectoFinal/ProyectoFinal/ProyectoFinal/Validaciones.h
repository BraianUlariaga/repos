#pragma once
#include <string>

class Validaciones
{
public:
	Validaciones()
	{
	}

	/*Funciones*/
	static bool ValidarStringVacio(const std::string& dato);
	static bool ValidaPositivo(const int& numero);
	static bool ValidaLongitudNumMayorA6(const int& numero);
	static bool ValidarMail(const std::string& mail);

private:
	//std::string _Dato;
	//int _Numero;

};
