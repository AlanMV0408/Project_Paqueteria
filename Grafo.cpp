#include "Grafo.h"
#include "Nodo.h"
#include <iostream>


Grafo::Grafo(){

    inicioNodo = nullptr;
}

void Grafo::agregarSucursal(Sucursal sucursal)
{
    Nodo *nuevo = new Nodo(sucursal); //crea una sucursal nueva en un vertice 

    if(inicioNodo == nullptr)
    {
        inicioNodo = nuevo;
    }
    else
    {
        Nodo *aux = inicioNodo;

        while(aux->getSig() != nullptr)
        {
            aux = aux->getSig();
        }

        aux->setSig(nuevo);
    }

    
}


Nodo *Grafo::BuscarSucursal(string nombre) //busca la sucursal por su nombre 
{
    Nodo *aux = inicioNodo; // 

    while(aux != nullptr)
    {
        if(aux->getSucursal().getNombre() == nombre)
        {
            return aux;
        }

        aux = aux->getSig();
    }

    return nullptr;
}


void Grafo::conexion(string origen, string destino, int peso){

    Nodo *nodoOrigen = BuscarSucursal(origen);
    Nodo *nodoDestino = BuscarSucursal(destino);

    if(nodoOrigen == nullptr  &&  nodoDestino == nullptr){

        cout<<"Sucursal no existe en este momento."<<endl; 
        return; 
    }


    nodoOrigen->agregarArista(nodoDestino, peso);  //conecta el origen con el destino

    nodoDestino->agregarArista(nodoOrigen, peso);  //e lo contrario, conecta el destino con el origen


}



void Grafo::eliminarConexion(string origen, string destino){
    Nodo *nodoOrigen = BuscarSucursal(origen);
    Nodo *nodoDestino = BuscarSucursal(destino);

    if(nodoOrigen == nullptr ||
       nodoDestino == nullptr)
    {
        cout << "Sucursal no encontrada." << endl;
        return;
    }

    nodoOrigen->eliminarArista(destino);
    nodoDestino->eliminarArista(origen);

}

void Grafo::mostrarGrafo()
{
    Nodo *aux = inicioNodo;

    while(aux != nullptr)
    {
        cout << "\nSucursal: "
             << aux->getSucursal().getNombre()
             << endl;

        Arista *auxArista =
            aux->getListaAristas();

        while(auxArista != nullptr)
        {
            cout << " -> "
                 << auxArista->getDestino()
                    ->getSucursal()
                    .getNombre()

                 << " Peso: "
                 << auxArista->getPeso()
                 << endl;

            auxArista = auxArista->getSig();
        }

        aux = aux->getSig();
    }
}