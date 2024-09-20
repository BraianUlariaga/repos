// EjercicioKloster.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
# include<cstring>
using namespace std;
class Alumno {
private:///significa que todo lo que se ubique en esta parte será accesible dentro de la clase
    int legajo;
    char nombre[30], apellido[30];
    bool regular;
public: ///todo lo que pongamos acá será accesible tanto dentro como fuera de la clase.
    void Cargar();
    void Mostrar();
    ///ASIGNAR VALOR A CADA UNA DE LAS PROPIEDADES-> SET
    void setLegajo(int l) {
        if (l >= 1000)legajo = l;
        else    l = -1;
    }

    void setNombre(const char* n) {
        strcpy_s(nombre, n);
    }

    void setApellido(const char* n) {
        strcpy_s(apellido, n);
    }
    ///comunicar al mundo externo el valor de las propiedades->GET
    int getLegajo() { return legajo; }

    const char* getNombre() { return nombre; }

    const char* getApellido() { return apellido; }

    bool getRegular() { return regular; }

};

void Alumno::Cargar() {
    cout << "LEGAJO ";
    cin >> legajo;
    cout << "NOMBRE ";
    cin >> nombre;
    cout << "APELLIDO ";
    cin >> apellido;

    regular = true;
}

void Alumno::Mostrar() {
    cout << "LEGAJO ";
    cout << legajo << endl;
    cout << "NOMBRE ";
    cout << nombre << endl;
    cout << "APELLIDO ";
    cout << apellido << endl;

}

void cargarAlumnos(Alumno* v, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        v[i].Cargar();
        cout << endl;
    }
}

void mostrarAlumnos(Alumno* v, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        v[i].Mostrar();
        cout << endl << endl;
    }
}



void mostrarPosicion(Alumno *v, int tam) {

    int buscarLegajo;
    int i;

    cout << "Ingrese un numero de legajo a buscar " << endl;

    cin >> buscarLegajo;

    for (i = 0; i < tam; i++) {

        if (v[i].getLegajo() == buscarLegajo)
        {

            cout << "La posicion del legajo es: " << i + 1 << endl;
            v[i].Mostrar();
            return;
        }
        else
        {
            cout << "-1" << endl;
            return;
        }
    }

}


void buscarRepetido(Alumno* v, int tam) {

    char buscarNombre[30];
    int i, contador = 0;


    cout << "Ingrese el nombre a buscar " << endl;

    cin >> buscarNombre;

    for (i = 0; i < tam; i++) {

        if (strcmp(v[i].getNombre(), buscarNombre) == 0)
        {
            contador++;
            
        }

    }
    if (contador != 0)
    {

        cout << "El nombre se repitio " << contador << " veces" << endl;
    }
    else
    {
        cout << "No se encontraron alumnos con ese nombre" << endl;
    }
}

int main() {
    Alumno vAlumnos[5];

    cargarAlumnos(vAlumnos, 5);
    system("cls");
    mostrarAlumnos(vAlumnos, 5);

    cout << endl;
    mostrarPosicion(vAlumnos, 5);
    cout << endl;
    buscarRepetido(vAlumnos, 5);

    system("pause");
    return 0;
}


/*
Cargar un vector de alumnos de 5, y luego :
a) Dado un legajo hacer una función que devuelva la posición del alumno con ese legajo en el vector.Si no existe devolver - 1
b) Dado un nombre que se ingresa por teclado, informar la cantidad de veces que ese nombre aparece en el vector de alumnos */

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
