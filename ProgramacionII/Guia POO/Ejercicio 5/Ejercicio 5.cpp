// Ejercicio 5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Termometro
{
	private:
		float _temperatura;
		char _unidad;
	public:
	Termometro(float tempInicial, char unidadInicial)
	{
		_temperatura = tempInicial;
		_unidad = unidadInicial;
	}

	void setTemp(float temp) {
	
		_temperatura = temp;
	}
	float getTemp(){

		return _temperatura;
	}

	char getUnidad(){
		return _unidad;
	}

	void cambiarUnidad(char nuevaUnidad);

};

void Termometro::cambiarUnidad(char nuevaUnidad) {

	if (_unidad != nuevaUnidad)
	{
		if (nuevaUnidad == 'F') {
		
			_temperatura = (_temperatura * 9.0 / 5.0) + 32;
			_unidad = nuevaUnidad;
		}
		else
		{
			_temperatura = (_temperatura - 32) * 5.0 / 9.0;
			_unidad = nuevaUnidad;
		}
	}

}



int main()
{
	Termometro objeto1(1,'F');

	cout <<  objeto1.getTemp() << endl;
	cout << objeto1.getUnidad() << endl;

	cout << "**********" << endl;

	objeto1.cambiarUnidad('C');

	cout <<  objeto1.getTemp() << endl;
	cout << objeto1.getUnidad() << endl;

	system("pause");
	return 0;
}

