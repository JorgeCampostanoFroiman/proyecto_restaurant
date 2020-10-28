#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "persona.h"

Persona::Persona(){
    Dni= 0;
    strcpy(Nombre, "Sin Nombre Registrado");
    strcpy(Apellido, "Sin Apellido Registrado");
    Nacimiento=0;
    genero=0;
}
int Persona::getDni(){
    return Dni;
    }
int Persona::getGenero(){
    return genero;
}
char* Persona::getNombre(){
    return Nombre;
    }
char* Persona::getApellido(){
    return Apellido;
    }
Fecha Persona::getNacimiento(){
    return Nacimiento;
    }

void Persona::setDni(int d){
    Dni=d;
}
void Persona::setGenero(int g){
    genero=g;
}
void Persona::setNombre(char *n){
    strcpy(Nombre, n);
}
void Persona::setApellido(char* a){
    strcpy(Apellido, a);
}
void Persona::setNacimiento(Fecha fn){
    Nacimiento = fn;
}

void Persona::cargar(){
    cout << "Dni : ";
    cin >> Dni;
    cout << "Nombre : ";
    cin >> Nombre;
    cout << "Apellido : ";
    cin >> Apellido;
    ///cout << "Nacimiento : ";
   /// hacer el cin del nacimiento (igualmente chequear bien los sets y gets)}
    cout << "Genero: ";
    cin >> genero;
}
void Persona::mostrar(){
    cout << "Dni: " << Dni << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Apellido: " << Apellido << endl;
    cout << "Genero: " << genero << endl;
    /// cout << "Nacimiento " << Nacimiento << endl;
}


