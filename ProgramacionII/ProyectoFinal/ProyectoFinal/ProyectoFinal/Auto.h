#pragma once
//#include <string>

class automovil{
private:
    std::string _patente;
    std::string _color;
    std::string _marca;
    std::string _tipo;
    int _anio;
    int _km;
    int _precio;
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
    void setprecio(int precio);
    void setestado(bool estado);
    //getters
    std::string getpatente()const;
    std::string getcolor()const;
    std::string getmarca()const;
    std::string gettipo()const;
    int getanio()const;
    int getkm()const;
    int getprecio() const;
    bool getestado() const;
    //metodos
    void cargar();
    void mostrar()const;

};
