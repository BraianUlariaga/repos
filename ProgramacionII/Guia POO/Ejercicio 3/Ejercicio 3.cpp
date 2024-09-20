// Ejercicio 3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
class CuentaBancaria
{
	private:
		int _n_cuenta;
		float _saldo;

public:
	
	CuentaBancaria(int ncueta, float saldo)
	{
		_n_cuenta = ncueta;
		_saldo = saldo;
	
	};


	float getSaldo() {
		return _saldo;
	};
	void depositar();
	void retirar();
	string obtenerSaldo();
};

void CuentaBancaria::depositar()
{	
	float deposito;
	cout << "Ingrese el monto a depositar" << endl;
	cin >> deposito;

	if (deposito > 0)
	{
		_saldo += deposito;
	}
	
}

void CuentaBancaria::retirar()
{
	float retiro;
	cout << "Ingrese el monto a retirar" << endl;
	cin >> retiro;

	if (retiro < _saldo)
	{
		_saldo -= retiro;
	}

}
string CuentaBancaria::obtenerSaldo()
{
	return "Su saldo es: $" + to_string( _saldo );
}

int main()
{

	srand(time(0));

	int cuenta;
	string saldo;
	cout << "***** BIENVENIDO *****" << endl;

	cuenta = rand() % 1000;

	CuentaBancaria cliente1(cuenta, 0.0);
	saldo = cliente1.obtenerSaldo();

	cout << saldo << endl;

	cliente1.depositar();
	cout << endl;
	saldo = cliente1.obtenerSaldo();

	cout << saldo << endl;
	cliente1.retirar();
	cout << endl;
	saldo = cliente1.obtenerSaldo();
	cout << saldo << endl;
}
