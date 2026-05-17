#include "Grafo.h"
#include "Nodo.h"
#include "Sucursal.h"
#include <iostream>

using namespace std;

void cargarDatosGrafo(Grafo &grafo){
    grafo.insertarVertice(Sucursal("Centro", "Av. Principal 123", "555-1234", "8:00-18:00"));
    grafo.insertarVertice(Sucursal("Norte", "Calle Norte 456", "555-5678", "9:00-17:00"));
    grafo.insertarVertice(Sucursal("Sur", "Calle Sur 789", "555-9012", "10:00-16:00"));
    grafo.insertarVertice(Sucursal("Este", "Calle Este 321", "555-3456", "8:30-18:30"));
    grafo.insertarVertice(Sucursal("Oeste", "Calle Oeste 654", "555-7890", "9:30-17:30"));
    grafo.insertarVertice(Sucursal("Aeropuerto", "Calle A 111", "555-1111", "8:00-18:00"));
    grafo,insertarVertice(Sucursal("Puerto", "Calle P 222", "555-2222", "9:00-17:00"));
    grafo.insertarVertice(Sucursal("Zona Industrial", "Calle Z 333", "555-3333", "10:00-16:00"));

    //falta insertar aristas entre las sucursales 
}

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

