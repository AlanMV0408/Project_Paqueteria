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

void Grafo::dijkstra(string origen, string destino){
    int MAX = 1000; // Valor máximo para representar la distancia infinita
    int numNodos = 0;
    Nodo *aux = inicioNodo;

    while(aux != nullptr){ // Contar el número de nodos en el grafo
        numNodos++;
        aux = aux->getSig(); //avanzar al siguiente nodo
    }

    if(numNodos == 0){
        cout << "El grafo está vacío." << endl;
        return;
    }

    Nodo *nodos[100]; // Suponiendo un máximo de 100 nodos
    int distancias[100]; // almacenar las distancias desde el nodo origen
    bool visitados[100];    // marcar los nodos visitados
    Nodo *previos[100]; // almacenar los nodos anteriores en el camino más corto

    aux = inicioNodo;
    int i = 0;
    int indiceOrigen = -1, indiceDestino = -1;

    while(aux != nullptr){
        nodos[i] = aux;
        distancias[i] = MAX;
        previos[i] = nullptr;
        visitados[i] = false;
        
        if(aux->getSucursal().getNombre() == origen){
            indiceOrigen = i;
        }
        if(aux->getSucursal().getNombre() == destino){
            indiceDestino = i;
        }

        i++;
        aux = aux->getSig();
    }

    if(indiceOrigen == -1 || indiceDestino == -1)
    {
        cout << "Sucursal de origen o destino no encontrada." << endl;
        return;
    }

    distancias[indiceOrigen] = 0; // La distancia al nodo origen es 0

    for(int count = 0; count < numNodos - 1; count++)
    {
        int minDistancia = MAX;
        u = -1; // Índice del nodo con la distancia mínima

        for(int v = 0; v < numNodos; v++){

            if(!visitados[v] && distancias[v] < minDistancia)
            {
                minDistancia = distancias[v];
                u = v;
            }
        }

        if(u == -1 || u == indiceDestino)
        {
            break;
        }

        visitados[u] = true;

        Arista *arista = nodos[u]->getListaAristas();
        while(arista != nullptr)
        {
            int vertice = -1;

            for(int k = 0; k < numNodos; k++){
                if(nodos[k] == arista->getDestino()){
                    vertice = k;
                    break;
                }
            }

            if(vertice != -1 && !visitados[vertice] && distancias[u] != MAX && distancias[u] + arista->getPeso() < distancias[vertice])
            {
                distancias[vertice] = distancias[u] + arista->getPeso();
                previos[vertice] = nodos[u];
            }

            arista = arista->getSig();
        }
    }

    if(distancias[indiceDestino] == MAX)
    {
        cout<<"No hay camino disponible entre "<<origen<<" y "<<destino<<"."<<endl;
        return;
    }

    cout<<"----- Recorrido minimo (Dijkstra) -----"<<endl;
    cout<<"Ruta mas corta de "<<origen<<" a "<<destino<<": \n";

    Nodo *camino[100];
    int indiceCamino = 0;
    Nodo *actual = nodos[indiceDestino];

    while(actual != nullptr){
        camino[indiceCamino++] = actual;
        int indiceActual = -1;

        for(int k = 0; k < numNodos; k++){
            if(nodos[k] == actual){
                indiceActual = k;
                break;
            }
        }
        actual = previos[indiceActual];
    }

    for(int k = indiceCamino - 1; k >= 0; k--){
        cout<<"["<<camino[k]->getSucursal().getNombre()<<"]";
        if(k > 0){
            cout<<" -> ";
        }
        cout<<"\nDistancia total: "<<distancias[indiceDestino]<<endl;
    }

}