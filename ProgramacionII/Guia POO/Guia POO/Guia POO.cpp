// Guia POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

/* Crea una clase llamada Rectangulo que represente un rectángulo.La clase debe tener dos atributos correspondientes a la base y 
altura.Implementa las siguientes metodos :
Getters y Setter de cada atributo.
calcularArea() : Devuelve el área del rectángulo.
calcularPerimetro() : Devuelve el perímetro del rectángulo
*/

#include <cstring>
#include <iostream>

using namespace std;

class Rectangulo {

    private:
        float base;
        float altura;

    public :
		
        void setBase(float B){
        
            base = B;
        };

        void setAltura(float H) {

            altura = H;
        };

        float getBase() {

            return base;
        };

        float getAltura() {

            return altura;
        };

        float CalcularArea();

        float CalcularPerimetro();

};

float Rectangulo::CalcularArea() {

    float B, H, area;

    cout << "Calculamos el area: "<< endl;
    cout << "Ingrese la base: " << endl;
    cin >> B ;
    setBase(B);

    cout << "Ingrese la altura: " << endl;
    cin >> H;
    setAltura(H);

    area = getBase() * getAltura();

    return area;

}

float Rectangulo::CalcularPerimetro() {
    
    float B, H, perimetro;
    char rta;

     cout << "Calculamos el perimetro: "<< endl;
     cout << "Desea utilizar los valores ya ingresados ? S/N" << endl;
     cin >>  rta;
     rta = toupper(rta);
     if (rta == 'S')
     {
         perimetro = 2 * (getBase() * getAltura());

         return perimetro;
     }
     else
     {

        cout << "Ingrese la base: " << endl;
        cin >> B ;
        setBase(B);

        cout << "Ingrese la altura: " << endl;
        cin >> H;
        setAltura(H);

        perimetro = 2 *(getBase() * getAltura());

        return perimetro;
     }

}


int main()
{
    Rectangulo instancia1;

    float area = instancia1.CalcularArea();

    float perimetro = instancia1.CalcularPerimetro() ;

    cout << "El valor del area es: " <<  area  << endl;

    cout << "El valor del perimetro es: " << perimetro << endl;

    system("pause");
    return 0;
}


