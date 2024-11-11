#define _CRT_SECURE_NO_WARNINGS
#include "FormaDePago.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
#include "FormaDePagoArchivo.h"


/*Setters*/
void FormaDePago::setIdPago(int id) { _IdPago = id; }
void FormaDePago::setDescripcion(std::string descripcion) {
	if (descripcion.size()<100)
	{
	strcpy(_Descripcion, descripcion.c_str());

	}
}
void FormaDePago::setTasaInteres(float tasaInteres) { _TasaInteres = tasaInteres; }
void FormaDePago::setVigente(bool vigente) { _Vigente = vigente; }

/*Getters*/
int FormaDePago::getIdPago() { return _IdPago; }
std::string FormaDePago::getDescripcion() { return _Descripcion; }
float FormaDePago::getTasaInteres() { return _TasaInteres; }
bool FormaDePago::getVigente() { return _Vigente; }

/*Metodos*/

void FormaDePago::CargarFormaDePago() {

	// int id; //Ver como hacer para que sea autoincremental
	FormaDePagoArchivo archivo;
	setIdPago(archivo.ObtenerUltimoId());
	std::string descripcion;
	float interes;
	bool vigente;

	std::cout << "Ingrese la descripcion del medio de pago." << std::endl;
	std::cin.ignore();
	std::getline(std::cin, descripcion);

	if (Validaciones::ValidarStringVacio(descripcion))
	{
		std::cout << "La descripcion del medio de pago no puede estar vacio." << std::endl;
	}
	else
	{

		setDescripcion(descripcion);
	}

	std::cout << "Ingrese la tasa de interes del medio de pago." << std::endl;
	std::cin >> interes;
	if (Validaciones::ValidaPositivo(interes))
	{
		std::cout << "La tasa de interes no puede ser menor a 0." << std::endl;
	}
	else
	{
		setTasaInteres(interes);
	}

	setVigente(true);

}

void FormaDePago::MostrarFormaDePago() {

	std::cout << "Id de medio de pago: " << getIdPago() << std::endl;
	std::cout << "Descripcion: " << getDescripcion() << std::endl;
	std::cout << "Tasa de interes: " << getTasaInteres() << std::endl;
	std::cout << std::boolalpha; // Imprime verdadero o falso.
	std::cout << "Vigencia: " << getVigente() << std::endl;

}


void FormaDePago::BajaFormaDePago() {

	setVigente(false);
}


void FormaDePago::ModificarFormaDePago() {

	std::string descripcion;
	float interes;
	bool vigente;

	std::cout << "Ingrese la descripcion del medio de pago." << std::endl;
	std::cin.ignore();
	std::getline(std::cin, descripcion);

	if (Validaciones::ValidarStringVacio(descripcion))
	{
		std::cout << "La descripcion del medio de pago no puede estar vacio." << std::endl;
	}
	else
	{

		setDescripcion(descripcion);
	}

	std::cout << "Ingrese la tasa de interes del medio de pago." << std::endl;
	std::cin >> interes;
	if (Validaciones::ValidaPositivo(interes))
	{
		std::cout << "La tasa de interes no puede ser menor a 0." << std::endl;
	}
	else
	{
		setTasaInteres(interes);
	}

	setVigente(true);

}
