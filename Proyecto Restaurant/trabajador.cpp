#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "trabajador.h"

Trabajador::Trabajador(){
    TipoTrabajador = false;
    estadoTrabajador = false;
    IdTrabajador = 0;
    IngresoTrabajador = 0;
}

bool Trabajador::getTipoTrabajador(){
    return TipoTrabajador;
}
bool Trabajador::getEstadoTrabajador(){
    return estadoTrabajador;
}
int Trabajador::getIdTrabajador(){
    return IdTrabajador;
}
Fecha Trabajador::getIngresoTrabajador(){
    return IngresoTrabajador;
}

void Trabajador::setTipoTrabajador(int t){
    TipoTrabajador = t;
}
void Trabajador::setEstadoTrabajador(bool e){
    estadoTrabajador = e;
}
void Trabajador::setIdTrabajador(int d){
    IdTrabajador = d;
}
void Trabajador::setIngresoTrabajador(Fecha fin){
    IngresoTrabajador = fin;
}

void Trabajador::cargar(){
    Persona::cargar();
    cout << "Id Trabajador : ";
    cin >> IdTrabajador;
    cout << "Estado del trabajador : (0 para inactivo, 1 para activo)";
    cin >> estadoTrabajador;
    ///cout << "Ingreso del trabajador : ";
   /// hacer el cin del ingreso (igualmente chequear bien los sets y gets)
    cout << "Tipo de trabajador: (0 para trabajador de local, 1 para delivery)";
    cin >> TipoTrabajador;
}
void Trabajador::mostrar(){
    Persona::mostrar();
    cout << "Id Trabajador: " << IdTrabajador << endl;
    cout << "Estado del trabajador: " << estadoTrabajador << endl;
    // cout << "Ingreso del trabajador: " << IngresoTrabajador << endl;
    cout << "Tipo de trabajador: (De local o delivery) " << TipoTrabajador << endl;
}
