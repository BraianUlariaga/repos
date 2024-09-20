// Herencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//https://docs.google.com/document/d/1I6bGOE3fIrPyT3yWR5gLvO8UT_wqCcLG4ykzsoF6D-4/edit


#include <iostream>
#include <string>
#include "Herramienta.h"
#include "Martillo.h"
#include "Destornillador.h"
#include "Taladro.h"
#include "TaladroPercutor.h"

using namespace std;

int main()
{

	Martillo martillo1("Plana", 2, 25);

	martillo1.mostrarInformacion();
	cout << "*******************" << endl;

	Destornillador destornillador1("Punta", 0.5, 15);
	destornillador1.mostrarInformacion();

	cout << "*******************" << endl;
	Taladro taladro1(150, 15, 35);

	taladro1.mostrarInformacion();

	cout << "*******************" << endl;

	TaladroPercutor	percutor1(3500,3.5,45,1200);

	percutor1.mostrarInformacion();
}

