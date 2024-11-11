#pragma once
#include "FormaDePago.h"

class FormaDePagoArchivo
{
public:
	FormaDePagoArchivo();
	bool AgregarFormaDePago(FormaDePago formaDePago);
	FormaDePago ListarFormaDePago(int posicion);
	int CantidadRegistros();
	int BuscarFormaDePago(int codigo);
	void ModificarFormaDePago(int id);
	bool GuardarModificacion(FormaDePago formaDePago, int posicion);
	int ObtenerUltimoId();
private:
	std::string _NombreArchivo;

};
