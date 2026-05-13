#include "Sucursal.h"
#include <iostream>



Sucursal::Sucursal(const string& Nombre,const string& Direccion,const string& Telefono,const string& Horario){

    nombre = Nombre;
    direccion = Direccion;
    telefono = Telefono;
    horario = Horario;
}

void Sucursal::imprimir() const {
    std::cout << "  Nombre    : " << nombre    << "\n"
              << "  Dirección : " << direccion << "\n"
              << "  Teléfono  : " << telefono  << "\n"
              << "  Horario   : " << horario   << "\n";
}
 