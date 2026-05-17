#include "Grafo.h"
#include "Nodo.h"
#include "Sucursal.h"
#include <iostream>

using namespace std;

int main(){
    

    int opcion;
    
    do{
        cout"------- Distribucion Paqueteria -------"<<endl;
        cout<<"1) Insertar Sucursal(vertice/nodo)"<<endl;
        cout<<"2) Insertar Arista(conexion)"<<endl;
        cout<<"3) Eliminar Vertice"<<endl;
        cout<<"4) Eliminar Arista"<<endl;
        cout<<"5) Mostrar listado de vertices/aristas"<<endl;
        cout<<"6) Recorrido Minimo (Dijkstra) entre 2 sucursales"<<endl;
        cout<<"7) Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion == 1){

        }
        else if(opcion == 2){

        }
        else if(opcion == 3){

        }
        else if(opcion == 4){

        }
        else if(opcion == 5){

        }
        else if(opcion == 6){

        }
        else if(opcion == 7){
            cout<<"Hasta Pronto."<<endl;
            break;
        }
        else{
            cout<<"Opcion no valida. Intente de nuevo."<<endl;
        }   
    }while(opcion != 8 && opcion != 0);

}

