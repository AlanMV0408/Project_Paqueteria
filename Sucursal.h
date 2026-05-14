#ifndef SUCURSAl_H
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
    
    Sucursal();
    Sucursal(const string& nombre,const string& direccion,const string& telefono,const string& horario);

    void imprimir() const;

};

#endif