#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;
#include "fecha.h"

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}

void Fecha::setDia(int d){
    dia = d;
}
void Fecha::setMes(int m){
    mes = m;
}
void Fecha::setAnio(int a){
    anio = a;
}

void Fecha::mostrar(){
    cout << dia << "/" << mes << "/" << anio;
}
void Fecha::cargar(){
    cout << "Día: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
}

void MostrarFechaLocal(){
    char* dS[7] = {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
   time_t tSac = time(NULL);       // instante actual
   struct tm* tmP = localtime(&tSac);
   cout << "Dia: " << dS[tmP->tm_wday] << endl;
   cout << "Fecha: " << tmP->tm_mday << "-" << tmP->tm_mon+1 << "-" << tmP->tm_year+1900 << endl;
   cout << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":" <<tmP->tm_sec << endl;

}
int ObtenerAnio(){
    time_t currentTime = time(0);
    tm* ltm = localtime(&currentTime);
    return ltm->tm_year + 1900;
}
bool Fecha::validarFecha(Fecha* fecha){ /// Valida una fecha. No permite utilizar dias invalidos.
    bool validarFecha = false;

    if (fecha->anio >= 0)
    {
        switch (fecha->mes) {

        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (fecha->dia >= 1 && fecha->dia <= 31) {
                validarFecha = true;
            };
            break;

        case 4: case 6: case 9: case 11:
            if (fecha->dia >= 1 && fecha->dia <= 30) {
                validarFecha = true;
            };
            break;
        case 2:
            //Si el año es bisiesto se suma un día.
            if ((fecha->anio  % 4 == 0) && (fecha->anio % 100 != 0) || (fecha->anio % 400 == 0)) {
                if (fecha->dia >= 1 && fecha->dia <= 29) {
                    validarFecha = true;
                };
            }
            else {
                if (fecha->dia >= 1 && fecha->dia <= 28) {
                    validarFecha = true;
                };
            };
            break;
        default:
            break;
        };
    }

    return validarFecha;
}
