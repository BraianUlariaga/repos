// Ejercicio 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
/*
Crea una clase llamada Dado que simule el comportamiento de un dado de seis caras. La clase debe contener los siguientes atributos:
valor (int): Almacena el valor actual del dado (un número entre 1 y 6).
Implementa los siguientes métodos públicos:
Dado(): Constructor que inicializa el dado con un valor aleatorio entre 1 y 6.
lanzar(): Simula el lanzamiento del dado, asignando un nuevo valor aleatorio entre 1 y 6 al atributo valor.
getValor(): Devuelve el valor actual del dado.
esMaximo(): Devuelve true si el valor del dado es 6, y false en caso contrario.
esMinimo(): Devuelve true si el valor del dado es 1, y false en caso contrario
*/

#include <cstring>
#include <iostream>

using namespace std;

class Dado
{

private:
	int valor;

public:

	Dado() {
		valor = rand() % 6 + 1;
	};

	int getValor() {
		return valor;
	};

	void lanzar();

	bool esMaximo();

	bool esMinimo();

};

void Dado::lanzar()
{
	valor = rand() % 6 + 1;

}

bool Dado::esMaximo()
{

	if (getValor() == 6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dado::esMinimo()
{

	if (getValor() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	srand(time(0)); // inicializa siempre en cero el random

	Dado instanciaDado;
	char rta;

		cout << "***** BIENVENIDO *****" << endl;

	do
	{
		cout << "Valor acual del dado: " << instanciaDado.getValor() <<endl;
		cout << "Desea lanzar ? S/N" <<endl;
		cin >> rta;
		rta = toupper(rta);
		instanciaDado.lanzar();
	} while (rta != 'N');

	if (instanciaDado.esMaximo()) {
		cout << "El dado tiene el valor maximo." << endl;
	}
	else if (instanciaDado.esMinimo()) {
		cout << "El dado tiene el valor minimo." << endl;
	}
	

	cout << "Muxhas Gracias !"<<endl;

	system("pause");
	return 0;
}


