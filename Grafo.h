#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"

using namespace std;

class Grafo{

private:

    Nodo* inicioNodo; //Es el h del nodo vertices

    public:

     Grafo();

     void agregarSucursal(Sucursal Sucursal); //Agregar vertice
     Nodo* BuscarSucursal(string nombre);

     void EliminarSucursal(string nombre);  //Eliminar vertice

     void conexion(string origen, string destino,int  peso); //Agregar arista con el peso de la conexion

     void eliminarConexion(string origen,string destino); //Eliminar arista

    // Mostrar
    void mostrarGrafo();
    void dijkstra(string origen, string destino); //Recorrido minimo entre 2 sucursales
     
    ~Grafo();

};  


#endif // GRAFO_H

