#ifndef SUCURSAL_H
#define SUCURSAL_H
#include <iostream>
#include <string>
using namespace std;


class Sucursal{

    private: 

    string nombre; 
    string direccion;
    string telefono;
    string horario;

    public: 
    string getNombre(){
        return nombre;
    }
    
    Sucursal(); //Constructor por defecto
    Sucursal(const string& nombre,const string& direccion,const string& telefono,const string& horario); //Contructor con parámetros

    void imprimir() const; 

};

#endif