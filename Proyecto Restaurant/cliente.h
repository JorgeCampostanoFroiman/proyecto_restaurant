#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "persona.h"

class Cliente : public  Persona{

    private:
    int IdCliente;
    int Telefono;

    public:
    Cliente();
    int getIdCliente();
    int getTelefono();
    void setIdCliente(int);
    void setTelefono(int);
    void cargar();
    void mostrar();
    escribirArchivo();
    leerArchivo();
};


#endif // CLIENTE_H_INCLUDED
