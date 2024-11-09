#include "clsfecha.h"
#include <iostream>

bool esBisiesto(int anio){
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
        return 1;
    }
    else{return 0;}
}

bool fecha::validarFecha(int dia, int mes, int anio){
    int vec[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(esBisiesto(anio)){
        vec[1] = 29;
    }
    if((anio > 0) && (mes > 0 && mes < 13) && (dia > 0 && dia<= vec[mes-1])){
        return 1;
    }
    else{return 0;}
}

fecha::fecha(){
    _dia = -1;
    _mes = -1;
    _anio = 2023;
}

fecha::fecha(int dia, int mes, int anio){
    int vec[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(esBisiesto(anio)){
        vec[1] = 29;
    }
    if((anio > 0) && (mes > 0 && mes < 13) && (dia > 0 && dia<= vec[mes-1])){
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    else{
        _dia = -1;
        _mes = -1;
        _anio = 2023;
    }
}

/*void fecha::setdia(int dia){
    if(validarFecha(dia, _mes, _anio)){
        _dia = dia;
    }
}*/

void fecha::setdia(int dia){
    if(dia > 0 && dia <= 31){
        _dia = dia;
    }
}

void fecha::setmes(int mes){
    if(mes > 0 && mes <=12){
        _mes = mes;
    }
}
void fecha::setanio(int anio){
    if(anio > 0){
        _anio = anio;
    }
}

int fecha::getdia(){return _dia;}
int fecha::getmes(){return _mes;}
int fecha::getanio(){return _anio;}


std::string fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

void fecha::Cargar(){
    int dia, mes, anio;
    std::cout<< "dia: ";
    std::cin>> dia;

    std::cout<< "mes: ";
    std::cin>> mes;

    std::cout<< "anio: ";
    std::cin>> anio;

    if(validarFecha(dia, mes, anio)){
        setdia(dia);
        setmes(mes);
        setanio(anio);
    }
}
