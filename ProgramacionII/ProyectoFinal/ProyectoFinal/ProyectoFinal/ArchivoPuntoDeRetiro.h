#pragma once
#include "PuntoDeRetiro.h"

class ArchivoPuntoDeRetiro
{
public:
	ArchivoPuntoDeRetiro();
	bool GuardarPuntoDeRetiro(PuntoDeRetiro puntoDeRetiro);
	PuntoDeRetiro LeerPuntoDeRetiro(int posicion);
	int CantidadRegistros();
	int ObtenerUltimoId();
	int Buscar(int codigo);
	void ModificarPuntoDeRetiro(int id);
	bool Guardar(PuntoDeRetiro puntoDeRetiro, int posicion);
private:
	std::string _NombreArchivo;

};
