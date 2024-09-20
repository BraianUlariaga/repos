#pragma once
#include <string>
using namespace std;

void MostrarMenu();
void elegirOpc(int& opc, float hrMateria[20], int marzo[20][31]);
void IngresoDeDatos(float hrMateria[20], int marzo[20][31]);
void puntoA(float hrMateria[]);
void puntoB(float hrMateria[]);
void puntoC(int marzo[20][31], int dia, int numMateria);
int mostrarPuntoC(int marzo[20][31]);
