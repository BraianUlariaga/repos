#pragma once


class Fecha {
private:
    int _dia, _mes, _anio;
public:
    Fecha(int d = 0, int m = 0, int a = 0);

    void Cargar();
    void Mostrar(void);
    ///setter
    void setDia(int dia);
    void setMes(const int m);
    void setAnio(int a);
    ///getter
    int getDia();
    int getMes();
    int getAnio();
};