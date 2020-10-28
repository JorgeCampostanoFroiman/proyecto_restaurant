#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "persona.h"
#include "cliente.h"


Cliente::Cliente(){
    IdCliente = 0;
    Telefono = 0;
}
int Cliente::getIdCliente(){
    return IdCliente;
}
int Cliente::getTelefono(){
    return Telefono;
}
void Cliente::setIdCliente(int i){
    IdCliente = i;
}
void Cliente::setTelefono(int t){
    Telefono = t;
}
void Cliente::cargar(){
    Persona::cargar();
    cout << "Id Cliente : ";
    cin >> IdCliente;
    cout << "Telefono : ";
    cin >> Telefono;

}
void Cliente::mostrar(){
    Persona::mostrar();
    cout << "Id Cliente: " << IdCliente << endl;
    cout << "Telefono: " << Telefono << endl;
}

