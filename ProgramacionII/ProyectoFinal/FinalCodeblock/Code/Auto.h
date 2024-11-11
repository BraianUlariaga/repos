#pragma once
#include <string>


class automovil {
private:
    char _Patente[100];
    char _Color[100];
    char _Marca[100];
    char _Tipo[100];
    int _Anio;
    int _Km;
    float _Precio;
    bool _Estado;

public:
    //constructor
    automovil();
    //setters
    void setPatente(std::string patente);
    void setColor(std::string color);
    void setMarca(std::string marca);
    void setTipo(std::string tipo);
    void setAnio(int anio);
    void setKm(int km);
    void setPrecio(float precio);
    void setEstado(bool estado);
    //getters
    const char* getPatente()const;
    const char* getColor()const;
    const char* getMarca()const;
    const char* getTipo()const;
    int getAnio()const;
    int getKm()const;
    float getPrecio()const;
    bool getEstado() const;
    //metodos
    void CargarAuto();
    void MostrarAuto()const;

};
