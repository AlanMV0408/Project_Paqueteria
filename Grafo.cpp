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

void Grafo::eliminarSucursal(string nombre){
    if(inicioNodo == nullptr)
    {
        cout << "El grafo está vacío." << endl;
        return;
    }

    Nodo *aux = inicioNodo;
    while(aux != nullptr){
        aux->eliminarArista(nombre); // Eliminar todas las aristas que apuntan a la sucursal a eliminar
        aux = aux->getSig();
    }

    if(inicioNodo->getSucursal().getNombre() == nombre) // Si el nodo a eliminar es el nodo inicial
    {
        Nodo *tmp = inicioNodo;
        inicioNodo = inicioNodo->getSig(); // Actualizar el nodo inicial al siguiente nodo

        Arista *arista = tmp->getListaAristas();    // Eliminar todas las aristas del nodo a eliminar
        while(arista != nullptr)    // Mientras haya aristas en la lista de aristas del nodo a eliminar
        {
            Arista *tmpArista = arista;
            arista = arista->getSig();
            delete tmpArista;   // Eliminar la arista actual
            return;
        }
    }

    aux = inicioNodo;
    while(aux->getSig() != nullptr) // Buscar el nodo a eliminar en la lista de nodos
    {
        if(aux->getSig()->getSucursal().getNombre() == nombre){  // Si el siguiente nodo es el nodo a eliminar
            Nodo *tmp = aux->getSig();
            aux->setSig(tmp->getSig()); // Actualizar el enlace del nodo anterior al nodo siguiente del nodo a eliminar

            Arista *arista = tmp->getListaAristas();
            while(arista != nullptr){
                Arista *tmpArista = arista;
                arista = arista->getSig();
                delete tmpArista;
                return;
            }
        }
        aux = aux->getSig();    // Avanzar al siguiente nodo
    }
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
    int indiceOrigen = -1, indiceDestino = -1; // Índices de los nodos de origen y destino

    while(aux != nullptr){  //
        nodos[i] = aux;
        distancias[i] = MAX;
        previos[i] = nullptr;
        visitados[i] = false;
        
        if(aux->getSucursal().getNombre() == origen){   // Encontrar el índice del nodo de origen
            indiceOrigen = i;
        }
        if(aux->getSucursal().getNombre() == destino){  // Encontrar el índice del nodo de destino
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

    for(int count = 0; count < numNodos - 1; count++)   // Iterar para encontrar el camino más corto a cada nodo
    {
        int minDistancia = MAX;
        u = -1; // Índice del nodo con la distancia mínima

        for(int v = 0; v < numNodos; v++){  // Encontrar el nodo no visitado con la distancia mínima

            if(!visitados[v] && distancias[v] < minDistancia)   // Si el nodo no ha sido visitado y su distancia es menor que la distancia mínima actual
            {
                minDistancia = distancias[v];   // Actualizar la distancia mínima
                u = v;  // Actualizar el índice del nodo con la distancia mínima
            }
        }

        if(u == -1 || u == indiceDestino) // Si no se encuentra un nodo no visitado o se ha alcanzado el nodo destino, salir del bucle
        {
            break;
        }

        visitados[u] = true;

        Arista *arista = nodos[u]->getListaAristas();   // Obtener la lista de aristas del nodo actual
        while(arista != nullptr)
        {
            int vertice = -1;

            for(int k = 0; k < numNodos; k++){  // Encontrar el índice del nodo destino de la arista actual
                if(nodos[k] == arista->getDestino()){   // Si el nodo destino de la arista coincide con el nodo en la lista de nodos
                    vertice = k;    // Actualizar el índice del nodo destino
                    break;
                }
            }
            
            // Si el nodo destino de la arista no ha sido visitado y la distancia al nodo actual más el peso de la arista es menor que la distancia actual al nodo destino
            if(vertice != -1 && !visitados[vertice] && distancias[u] != MAX && distancias[u] + arista->getPeso() < distancias[vertice])
            {
                distancias[vertice] = distancias[u] + arista->getPeso();
                previos[vertice] = nodos[u];
            }

            arista = arista->getSig();
        }
    }

    // Si la distancia al nodo destino es MAX, significa que no hay un camino disponible entre el nodo de origen y el nodo de destino
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

    // Reconstruir el camino desde el nodo destino hasta el nodo origen utilizando el arreglo de nodos previos
    while(actual != nullptr){
        camino[indiceCamino++] = actual;
        int indiceActual = -1;

        for(int k = 0; k < numNodos; k++){  // Encontrar el índice del nodo actual en la lista de nodos
            if(nodos[k] == actual){
                indiceActual = k;
                break;
            }
        }
        actual = previos[indiceActual];
    }

    for(int k = indiceCamino - 1; k >= 0; k--){ // Imprimir el camino desde el nodo origen hasta el nodo destino
        cout<<"["<<camino[k]->getSucursal().getNombre()<<"]";
        if(k > 0){  // Si no es el último nodo en el camino, imprimir una flecha para indicar la conexión entre los nodos
            cout<<" -> ";
        }
        cout<<"\nDistancia total: "<<distancias[indiceDestino]<<endl;
    }

}