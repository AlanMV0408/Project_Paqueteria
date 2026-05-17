#include "Nodo.h"
using namespace std;
//Funciones y implementaciones de Arista
Arista::Arista(Nodo *destino, int peso){
    this->destino = destino;
    this->peso = peso;
    this->sig = nullptr;
}

Nodo *Arista::getDestino(){ 
    return destino;
}
int Arista::getPeso(){
    return peso;
}
Arista *Arista::getSig(){
    return sig;
}
void Arista::setSig(Arista *sig){ 
    this->sig = sig;
}

//Funciones y implementaciones de Nodo
Nodo::Nodo(Sucursal sucursal){
    this->sucursal = sucursal;
    this->sig = nullptr;
    this->listaAristas = nullptr;
}

Sucursal Nodo::getSucursal(){
    return sucursal;
}
Nodo *Nodo::getSig(){
    return sig;
}
void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}
Arista *Nodo::getListaAristas(){ //devuelve la lista de aristas del nodo
    return listaAristas;
}

//Agregar una arista
void Nodo::agregarArista(Nodo *destino, int peso){
    // Verificar si ya existe
    Arista *aux = listaAristas;
    while (aux != nullptr) {
        if (aux->getDestino() == destino) {
            cout << "Conexión ya existe." << endl;
            return;
        }
        aux = aux->getSig();
    }
    //inserta la nueva arista
    Arista *nuevaArista = new Arista(destino, peso);
    
    if(listaAristas == nullptr){
        listaAristas = nuevaArista;
    }else{
        Arista *aux = listaAristas;

        while(aux->getSig() != nullptr){
            aux = aux->getSig();
        }
        aux->setSig(nuevaArista);
    }

}

void Nodo::eliminarArista(string nombreDestino){
    if(listaAristas == nullptr)
    {
        cout << "No hay aristas para eliminar." << endl;
        return;
    }
    
    if(listaAristas->getDestino()->getSucursal().getNombre() == nombreDestino){
        Arista *tmp = listaAristas;
        listaAristas = listaAristas->getSig();
        delete tmp;
        return;
    }

    Arista *aux = listaAristas;
    while(aux->getSig() != nullptr){
        if(aux->getSig()->getDestino()->getSucursal().getNombre() == nombreDestino) {
            Arista *tmp = aux->getSig();
            aux->setSig(aux->getSig()->getSig());
            delete tmp;
            return;
            }

            aux = aux->getSig();
    }

}
