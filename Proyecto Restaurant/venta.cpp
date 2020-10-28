#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "venta.h"

Venta::Venta(){
    idVenta = 0;
    idCliente = 0;
    idTrabajador = 0;
    formaPago = 'z';
    envio = false;
    fechaVenta = 0;
}


int Venta::getIdVenta(){
    return idVenta;
}
int Venta::getIdCliente(){
    return idCliente;
}
int Venta::getIdTrabajador(){
    return idTrabajador;
}
char Venta::getFormaPago(){
    return formaPago;
}
bool Venta::getEnvio(){
    return envio;
}
Fecha Venta::getFechaVenta(){
    return fechaVenta;
}

void Venta::setIdVenta(int iv){
    idVenta = iv;
}
void Venta::setFormaPago(char fp){
    formaPago = fp;
}
void Venta::setIdCliente(int ic){
    idCliente = ic;
}
void Venta::setIdTrabajador(int it){
    idTrabajador = it;
}
void Venta::setFechaVenta(Fecha fv){
    fechaVenta = fv;
}
void Venta::setEnvio(bool e){
    envio = e;
}

void Venta::cargar(){
    cout << "Id Venta : ";
    cin >> idVenta;
    cout << "Forma de pago : ";
    cin >> formaPago;
    cout << "Id cliente : ";
    cin >> idCliente;
    cout << "Id trabajador : ";
    cin >> idTrabajador;
    //cout << "Fecha de venta: ";
    //cin >> fechaVenta;
    cout << "Envio: ";
    cin >> envio;
}
void Venta::mostrar(){
    cout << "Id Venta : " << idVenta << endl;
    cout << "Forma de pago : " << idVenta << endl;
    cout << "Id Cliente : " << idCliente << endl;
    cout << "Id Trabajador : " << idTrabajador << endl;
    //cout << "Fecha de venta : " << fechaVenta << endl;
    cout << "Envio : " << envio << endl;
}
