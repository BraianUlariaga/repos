#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"

int buscarPaisPorCodigo(char* codigoPais) {

    FILE* fPais;
    Pais newPais;
    int pos = 0;
    fPais = fopen("paises.dat", "rb");
    if ( fPais == nullptr) {
        std::cout << "NO SE PUDO ABRIR EL ARCHIVO " << std::endl;
        return -1;
    }
    while (fread(&newPais, sizeof(Pais), 1, fPais) == 1) {
        if (strcmp(newPais.getCodigo() , codigoPais)) {
            fclose(fPais);
            return pos+1;
        }
        pos++;
    }

    fclose(fPais);
    return -1;
};



int main()
{

    Pais primerPais;

    primerPais.listarRegistros();
    
    int busqueda = 0;
    char codigo[4];
    cout << "INGRESE UN CODIGO DE PAIS A BUSCAR" << endl;

    cin >> codigo;

    busqueda = buscarPaisPorCodigo(codigo);
    if (busqueda >0)
    {
        cout << "El registro que usted busca existe en el archivo" << endl;
    }
    else
    {
        cout << "El registro que usted busca NO existe en el archivo" << endl;
    }


    return 0;
}
