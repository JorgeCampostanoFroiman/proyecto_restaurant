#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
    int dia, mes, anio;

    public:
    Fecha(int = 0, int = 0, int = 0);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    void mostrar();
    void cargar();
    bool validarFecha(Fecha*);
};

void MostrarFechaLocal();
int ObtenerAnio();  /// Obtiene el año actual
bool validarFecha(Fecha* ); /// Valida una fecha. No permite utilizar dias invalidos.

#endif // FECHA_H_INCLUDED
