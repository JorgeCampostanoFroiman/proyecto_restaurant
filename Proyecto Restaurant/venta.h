#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "fecha.h"

class Venta {

    protected:
    int idVenta;
    Fecha fechaVenta;
    int idCliente;
    int idTrabajador;
    bool envio;
    char formaPago;

    public:
    Venta();
    int getIdVenta();
    int getIdCliente();
    int getIdTrabajador();
    char getFormaPago();
    bool getEnvio();
    Fecha getFechaVenta();

    void setIdVenta(int);
    void setFormaPago(char);
    void setIdCliente(int);
    void setIdTrabajador(int);
    void setFechaVenta(Fecha);
    void setEnvio(bool);

    void cargar();
    void mostrar();
    void escribirArchivo();
    void leerArchivo();
};


#endif // VENTA_H_INCLUDED
