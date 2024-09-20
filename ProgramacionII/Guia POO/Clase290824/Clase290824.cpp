// Clase290824.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Logical OR ( || )  Logical AND (&&)
//https://docs.google.com/document/d/1pzs4h83N6c3P5P2CBUnEg-2WBdPFGJnIo7sUFChkmNo/edit

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Fecha
{
	private:
		int _dia;
		int _mes;
		int _anio;

		void AgregarDia();

		void RestarDia();

	public:

		Fecha() {
		
			_dia = 01;
			_mes = 01;
			_anio = 2023;
		
		};

		Fecha(int dia, int mes, int anio) {
			
			if (dia >0 && dia <= 31 && mes > 0 && mes <= 12 && anio > 0)
			{
				_dia = dia;
				_mes = mes;
				_anio = anio;
			}
			else
			{
				_dia = 01;
				_mes = 01;
				_anio = 2023;
			}
	
		};


	
	int get_dia() {
		return _dia;
	}
	int get_mes() {
		return _mes;
	}
	int get_anio() {
		return _anio;
	}

	void incrementarDia() {
		AgregarDia();  // Llama al método privado
	}

	void decrementarDia() {
		RestarDia();  // Llama al método privado
	}
	string toString();

	void AgregarDias(int dias);

};

 void Fecha::AgregarDia()
{
	
	if (_dia == 31 && _mes < 12)
	{
		_dia = 1;
		_mes++;
	}
	else if (_mes == 12 && _dia == 31)
	{		_dia = 1;
			_mes = 1;
			_anio++;
	}
	else
	{
		_dia++;

	}

}

void Fecha::RestarDia()
{
	if (_dia == 1 && _mes > 1)
	{
	 _dia = 31;
	 _mes--;
	}
	else if (_dia == 1 && _mes == 1)
	{	
		_dia = 31;
		_mes = 12;
		_anio--;
	}
	else
	{
		_dia--;
	}
}

string Fecha::toString() {

	// se debe agregar al .cpp #include <string> 
	if (_dia < 10 && _mes < 10)
	{	
		return  "0" + to_string(+_dia) + "/" + "0" + to_string(_mes) + "/" + to_string(_anio);
	}
	else if(_dia >10 && _mes <10)
	{
		return  to_string(+_dia) + "/" + "0" + to_string(_mes) + "/" + to_string(_anio);
	}
	else if (_dia < 10 && _mes < 10)
	{
		return  "0" + to_string(+_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
	}
	else
	{
		return  to_string(+_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
	}
	//TODO falta validad los dias en los meses y los años bisiestos
}

void Fecha::AgregarDias(int dias) {

	int i;

	if (dias > 0)
	{
		for ( i = 0; i < dias; i++)
		{
			Fecha::AgregarDia();

		}
	}
	else
	{
		for (i = dias ; i < 0; i++)
		{
			Fecha::RestarDia();

		}
	}
}

int main()
{
	Fecha Objeto1(1,1,2024);

	string mostrar;
	mostrar = Objeto1.toString();
	cout << mostrar << endl;
	cout << endl << "******* Objeto1 *******" << endl;
	Objeto1.AgregarDias(-10);
	mostrar = Objeto1.toString();
	cout << mostrar << endl;
	/*Fecha Objeto2(1,1,2024);
	string mostrar, mostrar1;
	mostrar1 = Objeto2.toString();
	mostrar = Objeto1.toString();
	cout << endl << "******* Objeto1 *******" << endl;
	 cout << Objeto1.get_dia();
	 cout << Objeto1.get_mes();
	 cout << Objeto1.get_anio();
	cout << endl << "*******Objeto1 *******" << endl;
	cout << mostrar;
	cout << endl << "*******Objeto2 *******" << endl;
	cout << mostrar1;
	 cout << endl << "*******Objeto2 -1 *******" << endl;
	 Objeto2.decrementarDia();
	 mostrar1 = Objeto2.toString();
	 cout << Objeto2.get_dia();
	 cout << Objeto2.get_mes();
	 cout << Objeto2.get_anio() << endl;
	 cout << mostrar1;
	 cout << endl << "******* Objeto2 + 1*******" << endl;
	 Objeto2.incrementarDia();
	 mostrar1 = Objeto2.toString();
	 cout << mostrar1;
	 cout << endl << "****** Objeto2 + 2********" << endl;
	 Objeto2.incrementarDia();
	 cout << Objeto2.get_dia();
	 cout << Objeto2.get_mes();
	 cout << Objeto2.get_anio();
	 cout << endl << "**************" << endl;
	 mostrar1 = Objeto2.toString();
	 cout << mostrar1;*/

	 system("pause");
	 return 0;
}


