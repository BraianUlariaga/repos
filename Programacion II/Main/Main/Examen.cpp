#define _CRT_SECURE_NO_WARNINGS
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

    /*¿Cuál es la cantidad de mozos distintos que no recibieron propina?*/
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;

    int  i, cantidadRegistros = archivo.CantidadRegistros();
    int sinPropina[20] = {};
    int  cantMozos = 0;
    for (i = 0; i < cantidadRegistros; i++) {
        registro = archivo.Leer(i);
        if (registro.getPropina() == 0)
        {
            int mozo = registro.getIDMozo()-1;
            sinPropina[mozo]++;
        }
    }

    for ( i = 0; i < 20; i++)
    {
        if (sinPropina[i] != 0)
        {
            cantMozos++;
        }
    }

     cout << "Cantidad de mozos que no recibieron propina en al menos un servicio " << cantMozos << endl;

}

void Examen::Punto2() {
    /*¿Qué número de mozo de los que se muestran a continuación no obtuvo nunca un puntaje de 10 pero tampoco de 1?*/
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;

    int  i, j, cantidadRegistros = archivo.CantidadRegistros();
    int mozos[5] = {2,7,10,14,19};
    for (i = 0; i < cantidadRegistros; i++) {
        registro = archivo.Leer(i);

        if (registro.getPuntajeObtenido() == 1 || registro.getPuntajeObtenido() == 10)
        {
            for ( j = 0; j < 5; j++)
            {
                    if (registro.getIDMozo() == mozos[j])
                    {
                      // cout << "Id mozo : " << registro.getIDMozo() << " Puntaje " << registro.getPuntajeObtenido() << endl;

                       mozos[j] = 0;
                    }

            }

        }
       
    }


    for ( i = 0; i < 5; i++)
    {   
        if (mozos[i]!=0)
        {
            cout << mozos[i] << endl;
        }
    }

}

void Examen::Punto3() {
 /*¿Qué plato se vendió más veces en el 2024 que en el 2023? */
 
     ArchivoServicioMesa archivo("restaurant.dat");
     ServicioMesa registro;
 
     int  i, j, cantidadRegistros = archivo.CantidadRegistros();
     int platos[5] = {23,35,43,53,55};
     int idPlato2023[5] = {};
     int idPlato2024[5] = {};
    
     for (i = 0; i < cantidadRegistros; i++) {
         registro = archivo.Leer(i);
         for ( j = 0; j < 5 ; j++)
         {
             if (registro.getIDPlato() == platos[j])
             {

                 if (registro.getFecha().getAnio() == 2023)
                 {

                     idPlato2023[j]++;
            
                 }
                 else if (registro.getFecha().getAnio() == 2024)
                 {
                     idPlato2024[j]++;
                 }
 
             }
         }
     }
    
     int maxPlato = 0;

     for ( i = 0; i < 5; i++)
     { 
      if (idPlato2024[i] > idPlato2023[i] && idPlato2024[i] > maxPlato)
      {
          maxPlato = i;
      }
     }

     cout << platos[maxPlato] << endl;

}
