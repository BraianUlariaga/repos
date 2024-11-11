#include "Validaciones.h"
#include <cmath>

/*Metodos*/
bool Validaciones::ValidarStringVacio(const std::string& dato) {

	if (dato.empty())
	{
		return (true);
	}
	else
	{
		return (false);
	}

}

bool Validaciones::ValidaPositivo(const int& num) {
	// Validar que no sea negativo
	if (num < 0) {
		return true;
	}
	return false;
}

bool Validaciones::ValidaLongitudNumMayorA6(const int& num) {

	// Validar que tenga al menos 6 dígitos
	//Operador ternario (condición) ? expresión1 : expresión2;
	int cantidadDigitos = (num == 0) ? 1 : (int)log10(num) + 1;
	if (cantidadDigitos < 6) {
		return true;
	}

	return false;
}

bool Validaciones::ValidarMail(const std::string& mail) {

	if (mail.find('@') != std::string::npos && mail.find('.') != std::string::npos) { //la funcion find() lo que hace es buscar el caracter que se le indica buscar
		return true;                                                        //y siempre se compara con "npos" que es un valor especial que indica "que no se encontro el caracter buscado".
	}

	return false;
}
//
//void Validaciones::Mayuscula( char* cadena) {
//	int longitud = strlen(cadena);
//
//	for (int X = 0; X < longitud; X++) {
//		cadena[X] = toupper(cadena[X]);
//	}
//
//}

bool Validaciones::Bisiesto(int anio) {
	if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
		return 1;
	}
	else { return 0; }
}
