#include "Grafo.h"
#include "Nodo.h"
#include <iostream>


using namespace std;

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

void Grafo::EliminarSucursal(string nombre) {
    if (inicioNodo == nullptr) return;

    // Primero eliminar todas las conexiones hacia este nodo
    Nodo *aux = inicioNodo;
    while (aux != nullptr) {
        aux->eliminarArista(nombre); // limpia aristas que apuntan a él
        aux = aux->getSig();
    }

    // Luego eliminar el nodo de la lista
    if (inicioNodo->getSucursal().getNombre() == nombre) {
        Nodo *tmp = inicioNodo;
        inicioNodo = inicioNodo->getSig();
        delete tmp;
        return;
    }

    Nodo *prev = inicioNodo;
    while (prev->getSig() != nullptr) {
        if (prev->getSig()->getSucursal().getNombre() == nombre) {
            Nodo *tmp = prev->getSig();
            prev->setSig(tmp->getSig());
            delete tmp;
            return;
        }
        prev = prev->getSig();
    }
    cout << "Sucursal no encontrada." << endl;
}

void Grafo::conexion(string origen, string destino, int peso){

    Nodo *nodoOrigen = BuscarSucursal(origen);
    Nodo *nodoDestino = BuscarSucursal(destino);

    if(nodoOrigen == nullptr  ||  nodoDestino == nullptr){

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

Grafo::~Grafo() {
    Nodo *aux = inicioNodo;
    while (aux != nullptr) {
        Nodo *tmpNodo = aux;
        aux = aux->getSig();

        // Liberar lista de aristas del nodo
        Arista *a = tmpNodo->getListaAristas();
        while (a != nullptr) {
            Arista *tmpArista = a;
            a = a->getSig();
            delete tmpArista;
        }
        delete tmpNodo;
    }
}