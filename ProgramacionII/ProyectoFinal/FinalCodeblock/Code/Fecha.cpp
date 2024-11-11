#define _CRT_SECURE_NO_WARNINGS
#include "Fecha.h"
#include <iostream>
#include <chrono>
#include <ctime>

bool Fecha::ValidarFecha(int dia, int mes, int anio){
    int vec[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(Validaciones::Bisiesto(anio)){
        vec[1] = 29;
    }
    if((anio > 0) && (mes > 0 && mes < 13) && (dia > 0 && dia<= vec[mes-1])){
        return 1;
    }
    else{return 0;}
}

Fecha::Fecha(){
    _dia = -1;
    _mes = -1;
    _anio = 2023;
}

Fecha::Fecha(int dia, int mes, int anio){
    int vec[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(Validaciones::Bisiesto(anio)){
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


void Fecha::setDia(int dia){
    if(dia > 0 && dia <= 31){
        _dia = dia;
    }
}

void Fecha::setMes(int mes){
    if(mes > 0 && mes <=12){
        _mes = mes;
    }
}
void Fecha::setAnio(int anio){
    if(anio > 0){
        _anio = anio;
    }
}

int Fecha::getDia(){return _dia;}
int Fecha::getMes(){return _mes;}
int Fecha::getAnio(){return _anio;}


std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

void Fecha::CargarFecha(){
    int dia, mes, anio;
    std::cout<< "dia: ";
    std::cin>> dia;

    std::cout<< "mes: ";
    std::cin>> mes;

    std::cout<< "anio: ";
    std::cin>> anio;

    if(ValidarFecha(dia, mes, anio)){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }
}

void Fecha::FechaSistema() {
    std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::tm* now = std::localtime(&t);

    _dia = now->tm_mday;
    _mes = now->tm_mon + 1;
    _anio = now->tm_year + 1900;
}
