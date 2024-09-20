#include "Funciones.h"
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

/*Cargar las notas del primer parcial de los 78 estudiantes de un curso. Luego de cargar todas las notas:

- Pedir un número y mostrar por pantalla la nota registrada. Por ejemplo, se ingresa 10 para mostrar el décimo examen.

- Listar cuántos estudiantes obtuvieron una nota mayor al promedio.
*/

void Ejercicio1() {

	int notas[78] = {};
	int alumno;
	float promedio = 0.0;
	int mayorAlPromedio = 0;
	for (int i = 0; i < 78; i++)
	{
		notas[i] = rand() % 10;
		cout << notas[i] <<endl;
		promedio += notas[i];
	}

	promedio = promedio / 78;

	cout << "Ingrese un numero (entre 1 y 78) " << endl;
	cin >> alumno;

	cout << "La nota del alumno "<< alumno << " es de: "<< notas[alumno-1] << endl;

	for (int i = 0; i < 78; i++)
	{
		if (notas[i] >  promedio)
		{
			mayorAlPromedio++;
		}
	}

	cout << "La cantidad de alumnos con notas mas altas que el promedio fue de: " << mayorAlPromedio <<endl;
}

/*Hacer una función llamada quitarRepetidos que reciba dos vectores de enteros de 10 elementos llamados vectorSinProcesar y vectorSinRepetidos. 
La función debe procesar el vectorSinProcesar de manera que en el vectorSinRepetidos queden todos los elementos distintos del vectorSinProcesar. 
La función debe devolver la cantidad de elementos asignados a vectorSinRepetidos.

Ejemplo:
vectorUno[10] = { 1, 2, 1, 2, 5, 5, 4, 4, 3, 3 }
vectorDos[10];
int elementos = quitarRepetidos(vectorUno, vectorDos);

En elementos debe quedar el valor 5 ya que son 5 los elementos sin repetirse del vector. Además el vectorDos debe contener los valores 1, 2, 5, 4 y 3.
*/

vector<int> Ejercicio2( int vec1[10], int vec2[10]) {

	for (int i = 0; i < 10; i++)
	{


	}
}