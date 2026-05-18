#include "Grafo.h"
#include "Nodo.h"
#include "Sucursal.h"
#include <iostream>
#include <string>

using namespace std;

void cargarDatosGrafo(Grafo &grafo){

    //Modelo de grafo ya planeado 

    //agregar sucursales
    grafo.agregarSucursal(Sucursal("1-Minerva", "Av. Lopez Mateos #203", "555-1234", "8:00-18:00"));
    grafo.agregarSucursal(Sucursal("2-Cloutier", "Av. Cloutier #904", "555-5678", "9:00-17:00"));
    grafo.agregarSucursal(Sucursal("3-PlazaBandera", "Av. Revolucion #346", "555-9012", "10:00-16:00"));
    grafo.agregarSucursal(Sucursal("4-Arcos", "Av. Lazaro Cardenas #567", "555-3456", "8:30-18:30"));
    grafo.agregarSucursal(Sucursal("5-Andares", "Av. Patria #654", "555-7890", "9:30-17:30"));
    grafo.agregarSucursal(Sucursal("6-Estadio", "Calzada Independecia  #111", "555-1111", "8:00-18:00"));
    grafo.agregarSucursal(Sucursal("7-Acuario", "Av. Alcalde #222", "555-2222", "9:00-17:00"));
    grafo.agregarSucursal(Sucursal("8-UAG", "Av. Plabo Neruda #333", "555-3333", "10:00-16:00"));

    //insertar conexiones

    //vertice(Nodo) 1 con sus 4 aritas
    grafo.conexion("1-Minerva", "8-UAG", 7);
    grafo.conexion("1-Minerva", "5-Andares", 5);
    grafo.conexion("1-Minerva", "4-Arcos", 6);
    grafo.conexion("1-Minerva", "2-Cloutier", 8);

    //vertice(Nodo) 2 con sus 3 aristas(1 ya se inserto con el vertice 1)
    grafo.conexion("2-Cloutier", "8-UAG", 4);
    grafo.conexion("2-Cloutier", "4-Arcos", 4);
    grafo.conexion("2-Cloutier", "3-PlazaBandera", 2);
    
    //vertice(Nodo) 3 con sus 3 aristas(1 ya se inserto con el vertice 2)
    grafo.conexion("3-PlazaBandera", "4-Arcos", 3);
    grafo.conexion("3-PlazaBandera", "7-Acuario", 4);
    grafo.conexion("3-PlazaBandera", "6-Estadio", 3);

    //vertice(Nodo) 4 con 1 arista(1,2,3 ya fueron insertadas)
    grafo.conexion("4-Arcos", "7-Acuario", 1);

    //vertice(Nodo) 5 con 3 aristas(1 ya fue insertada)
    grafo.conexion("5-Andares", "8-UAG", 5);
    grafo.conexion("5-Andares", "6-Estadio", 6);
    grafo.conexion("5-Andares", "7-Acuario", 4);

    //vertice(Nodo) 6 con 2 aristas(3 y 5 ya fueron insertadas)
    grafo.conexion("6-Estadio", "8-UAG", 3);
    grafo.conexion("6-Estadio", "7-Acuario", 1);

    //Los Nodos 7 y 8 ya tienen sus 4 aristas conectadas 
    //a través de las inserciones anteriores (7 conecta con 3, 4, 5, 6 y 8 conecta con 1, 2, 5, 6).
}

int main(){
    Grafo grafo;
    cargarDatosGrafo(grafo);

    int opcion;
    
    do{
        cout<<"\n\n\n------- Distribucion Paqueteria -------"<<endl;
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
            string n, d, t, h;
            cout<<"\n\n\n1) Insertar Sucursal(vertice/nodo)"<<endl;
            cout<<"Nombre de sucursal: ";
            cin>>n;
            cout<<"Direccion: ";
            cin>>ws; // Limpiar el buffer antes de usar getline
            getline(cin, d);
            cout<<"Telefono: ";
            getline(cin, t);
            cout<<"Horario: ";
            getline(cin, h);
            grafo.agregarSucursal(Sucursal(n, d, t, h));

        }
        else if(opcion == 2){
            string orig, dest; int peso;
            cout<<"\n\n\n2) Insertar Arista(conexion)"<<endl;
            cout<<"Sucursal de origen: ";
            cin>>orig;
            cout<<"Sucursal de destino: ";
            cin>>dest;
            cout<<"Distancia (Peso): ";
            cin>>peso;
            grafo.conexion(orig, dest, peso);

        }
        else if(opcion == 3){
            cout<<"\n\n\n3) Eliminar Vertice"<<endl;
            string name;
            cout<<"Nombre de la sucursal a eliminar: ";
            cin>>name;
            grafo.eliminarSucursal(name);

        }
        else if(opcion == 4){
            cout<<"\n\n\n4) Eliminar Arista"<<endl;
            string orig, dest;
            cout<<"Sucursal de origen: ";
            cin>>orig;
            cout<<"Sucursal de destino: ";
            cin>>dest;
            grafo.eliminarConexion(orig, dest);

        }
        else if(opcion == 5){
            cout<<"Listado de sucursales y conexiones:"<<endl;
            grafo.mostrarGrafo();
        }
        else if(opcion == 6){
            cout<<"\n\n\n6) Recorrido Minimo (Dijkstra) entre 2 sucursales"<<endl;
            string orig, dest;
            cout<<"Sucursal de origen: ";
            cin>>orig;
            cout<<"Sucursal de destino: ";
            cin>>dest;
            grafo.dijkstra(orig, dest);
        }
        else if(opcion == 7){
            cout<<"Hasta Pronto."<<endl;
            break;
        }
        else{
            cout<<"Opcion no valida. Intente de nuevo."<<endl;
        }   
    }while(opcion != 7);

    return 0;
}

