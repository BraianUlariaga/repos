#pragma once
#include "PuntoDeRetiro.h"

class PuntoDeRetiroArchivo
{
public:
	PuntoDeRetiroArchivo();
	bool AgregarPuntoDeRetiro(PuntoDeRetiro puntoDeRetiro);
	PuntoDeRetiro ListarPuntoDeRetiro(int posicion);
	bool ListarPuntosDeRetiros(PuntoDeRetiro registros[], int cantidad);
	int CantidadRegistros();
	int BuscarPuntoDeRetiro(int codigo);
	void ModificarPuntoDeRetiro(int id);
	bool GuardarModificacion(PuntoDeRetiro puntoDeRetiro, int posicion);
	int ObtenerUltimoId();
private:
	std::string _NombreArchivo;

};
