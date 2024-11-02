#pragma once
//#include <string>

class automovil{
private:
    char _patente[100];
    char _color[100];
    char _marca[100];
    char _tipo[100];
    int _anio;
    int _km;
    float _precio;
    bool _estado;

public:
    //constructor
    automovil();
    //setters
    void setpatente(std::string patente);
    void setcolor(std::string color);
    void setmarca(std::string marca);
    void settipo(std::string tipo);
    void setanio(int anio);
    void setkm(int km);
    void setprecio(float precio);
    void setestado(bool estado);
    //getters
    const char* getpatente()const;
    const char* getcolor()const;
    const char* getmarca()const;
    const char* gettipo()const;
    int getanio()const;
    int getkm()const;
    float getprecio()const;
    bool getestado() const;
    //metodos
    void cargar();
    void mostrar()const;

};
