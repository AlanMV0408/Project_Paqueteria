#include "SUCURSAL.h"
#include <iostream>
using namespace std;
Sucursal::Sucursal() : nombre(""), direccion(""), telefono(""), horario(""){} //Constructor por defecto que inicializa los atributos con valores vacíos

Sucursal::Sucursal(const string &Nombre, const string &Direccion, const string &Telefono, const string &Horario) //Constructor que recibe los valores de los atributos y los asigna a las variables miembro
{
    nombre = Nombre;
    direccion = Direccion;
    telefono = Telefono;
    horario = Horario;
}

void Sucursal::imprimir() const //imprime los detalles de la sucursal
{
    std::cout << "  Nombre    : " << nombre << "\n"
              << "  Dirección : " << direccion << "\n"
              << "  Teléfono  : " << telefono << "\n"
              << "  Horario   : " << horario << "\n";
}
