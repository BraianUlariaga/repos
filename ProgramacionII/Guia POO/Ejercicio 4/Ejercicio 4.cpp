// Ejercicio 4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <iomanip>  // Necesario para std::boolalpha

using namespace std;

	class Triangulo{

	private:
		float lados[3];

	public:
		
		void setLado(int lado, float medida) {
			if (lado < 0 || lado >= 3)
			{
				cout << "0";
			}
			else
			{
				lados[lado] = medida;
			}
		}

		float getLado(int lado){
			if (lado < 0 || lado >= 3)
			{
				return 0;
			}
			else
			{
				return lados[lado];
			}
		}
		bool isEscaleno();
		bool isIsosceles();
		bool isEquilatero();
		void getTipo();
	};


	bool Triangulo::isEscaleno() {
		return lados[0] != lados[1] && lados[0] != lados[2] && lados[1] != lados[2];
	};

	bool Triangulo::isIsosceles() {

		return lados[0] == lados[1] && lados[1] != lados[2];
	};

	bool Triangulo::isEquilatero() {
		return lados[0] == lados[1] && lados[1]== lados[2];
	};




void Triangulo::getTipo() {

	int i;

	for ( i = 0; i < 3; i++)
	{
		isEquilatero();
		isEscaleno();
		isIsosceles();
	}
	cout << boolalpha;
	cout << "Equilatero (todos los lados iguales): " << isEquilatero() << endl;
	cout << "Isosceles (dos lados iguales): " << isIsosceles() << endl;
	cout << "Escaleno (todos los lados diferentes): " << isEscaleno() << endl; 

}
int main()
{
	int i;
	float medida;
	char rta;
	Triangulo figura1;
	do
	{

		for ( i = 0; i < 3; i++)
		{
			cout << "Ingrese la medida del "<< i+1 << " lado." << endl;
			cin >> medida;
			figura1.setLado(i, medida);
		}

		figura1.getTipo();
		cout << "*************************" << endl;
		cout << "Desea ingresar otros datos ? S/N" << endl;
		cin >> rta;
	
	} while (rta == 'S');
}

