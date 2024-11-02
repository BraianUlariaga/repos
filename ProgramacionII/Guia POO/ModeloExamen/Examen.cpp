#include <iostream>
#include <algorithm>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"

void Examen::EjemploDeListado() {
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;

    int i, cantidadRegistros = archivo.CantidadRegistros();
    for (i = 0; i < cantidadRegistros; i++) {
        registro = archivo.Leer(i);
        cout << registro.toCSV() << endl;
    }
}



void Examen::Punto1() {

    /*�Cu�l es la cantidad de mozos distintos que no recibieron propina?*/
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;

    int  i, cantidadRegistros = archivo.CantidadRegistros();
    int sinPropina[20] = {};
    for (i = 0; i < cantidadRegistros; i++) {
        registro = archivo.Leer(i);
        cout << "propina " << registro.getPropina() << " id mozo" << registro.getIDMozo() << endl;
        if (registro.getPropina() == 0)
        {
            int mozo = registro.getIDMozo();
            sinPropina[mozo]++;
        }
    }

    for (i = 0; i < 20; i++)
    {
        cout << sinPropina[i] << "Mozo sin propinas" << i + 1 << endl;
    }

   // cout << "Cantidad de servicios de mesa valorados con un puntaje mayor al puntaje promedio " << p << endl;
}

void Examen::Punto2() {
    /*�Qu� n�mero de plato recaud� mayor cantidad de dinero?*/

    //ArchivoServicioMesa archivo("restaurant.dat");
    //ServicioMesa *registro;
    //int idPlato[70];
    //
    //int i , cantidadRegistros = archivo.CantidadRegistros();

    //registro = new ServicioMesa[cantidadRegistros];



    //for (i = 0; i < cantidadRegistros; i++) {

    // /*   int plato = registro[i].getIDPlato();
    //    if (plato )
    //    {

    //        idPlato[];

    //    }*/
    //}



}

void Examen::Punto3() {
//    /*�Qu� plato se vendi� m�s veces en el 2024 que en el 2023? */
//
//    ArchivoServicioMesa archivo("restaurant.dat");
//    ServicioMesa registro;
//
//    int  i, cantidadRegistros = archivo.CantidadRegistros();
//    float propinaXmozo[20] = {};
//
//
//    for (i = 0; i < cantidadRegistros; i++) {
//        registro = archivo.Leer(i);
//        if (registro.getFecha().getAnio() == 2024 && registro.getPropina() >0)
//        {
//            int mozo = registro.getIDMozo() - 1;
//            float propina = registro.getPropina();
//            propinaXmozo[mozo] ++;
//        }
//    }
//
//    int mozoMayorPropina = 0;
//
//    for ( i = 0; i < 20; i++)
//    {
//
//        if (propinaXmozo[i] > propinaXmozo[mozoMayorPropina])
//        {
//            
//            mozoMayorPropina = i;
//        }
//    }
//
//    cout << "El mozo con mayor propina en el 2024 fue : " << mozoMayorPropina + 1;
}
