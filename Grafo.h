#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"

using namespace std;

class Grafo{

private:

    Nodo* inicioNodo; //Es el h del nodo vertices

    public:

     Grafo();

     void agregarSucursal(Sucursal Sucursal);
     Nodo* BuscarSucursal(string nombre);

     void EliminarSucursal(string nombre);

     void conexion(string origen, string destino,int  peso);

     void eliminarConexion(string origen,string destino);

    // Mostrar
    void mostrarGrafo();
     
    ~Grafo();

};  


#endif // GRAFO_H

