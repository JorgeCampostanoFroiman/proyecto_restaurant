#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "fecha.h"
class Persona {

    protected:
    int Dni;
    char Nombre[50];
    char Apellido [50];
    Fecha Nacimiento;
    int genero;

    public:
    Persona();
    int getDni();
    int getGenero();
    char* getNombre();
    char* getApellido();
    Fecha getNacimiento();
    void setDni(int);
    void setGenero(int);
    void setNombre(char*);
    void setApellido(char*);
    void setNacimiento(Fecha);
    void cargar();
    void mostrar();
    void escribirArchivo();
    void leerArchivo();
};







#endif // PERSONA_H_INCLUDED
