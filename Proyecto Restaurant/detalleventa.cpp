#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "detalleVenta.h"

detalleVenta::detalleVenta(){
    idPlato =  0;
    cantPorPlato = 0;
    cantPlatosVendidos = 0;
    importe = 0;
}

int detalleVenta::getIdPlato(){
    return idPlato;
}
int detalleVenta::getCantPorPlato(){
    return cantPorPlato;
}
int detalleVenta::getCantPlatosVendidos(){
    return cantPlatosVendidos;
}
float detalleVenta::getImporte(){
    return importe;
}

void detalleVenta::setIdPlato(int p){
    idPlato = p;
}
void detalleVenta::setCantPorPlato(int cp){
    cantPorPlato = cp;
}
void detalleVenta::setCantPlatosVendidos(int pv){
    cantPlatosVendidos = pv;
}
void detalleVenta::setImporte(float im){
    importe =im;
}

void detalleVenta::cargar(){
    Venta::cargar();
    cout << "Id Plato : ";
    cin >> idTrabajador;
    cout << "Cantidad de unidades (por cada plato) : ";
    cin >> cantPorPlato;
    cout << "Cantidad de platos en total : ";
    cin >> cantPlatosVendidos;
    cout << "Importe : ";
    cin >> importe;
}
void detalleVenta::mostrar(){
    Venta::mostrar();
    cout << "Id Plato : " << idPlato << endl;
    cout << "Cantidad de unidades (por cada plato) : " << cantPorPlato << endl;
    cout << "Cantidad de platos en total : " << cantPlatosVendidos << endl;
    cout << "Importe : " << importe << endl;
}
