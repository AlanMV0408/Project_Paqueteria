#ifndef NODO_H
#define NODO_H

#include "SUCURSAL.h"

class Nodo; // declaración adelantada para hacer uso de ella

class Arista
{
private:
    Nodo *destino;
    int peso;
    Arista *sig;

public:
    Arista(Nodo *destino, int peso); //parametros principales
    Nodo *getDestino();     //devuelve nodo destino de la arista
    int getPeso();      //devuelve  peso de la arista
    Arista *getSig();   //devuelve la siguiente arista en la lista de adyacencia
    void setSig(Arista *sig); //marca la siguiente arista en la lista
};

class Nodo
{
private:
    Sucursal sucursal;
    Nodo *sig;
    Arista *listaAristas; // Lista de adyacencia para Rutas

public:
    //Constructor
    Nodo(Sucursal sucursal); 

    //Getters 
    Sucursal getSucursal();
    Nodo *getSig();
    Arista *getListaAristas();

    //Setters
    void setSig(Nodo *sig);
    
    //Funciones de Aristas
    void agregarArista(Nodo *destino, int peso);
    void eliminarArista(string nombreDestino);
};

#endif // NODO_H