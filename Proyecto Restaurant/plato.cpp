#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "plato.h"
#include "menu.h"


const char *FILE_PLATO = "./plato.dat";

Plato::Plato(){
    idPlato = 0;
    tipoPlato = 0;
    stock = 0;
    strcpy(nombrePlato, " ");
    precio = 0;
    estado = false;
}

int Plato::getIdPlato(){
    return idPlato;
}
int Plato::getTipoPlato(){
    return tipoPlato;
}
int Plato::getStock(){
    return stock;
}
char* Plato::getNombrePlato(){
    return nombrePlato;
}
float Plato::getPrecio(){
    return precio;
}
bool Plato::getEstado(){
    return estado;
}

void Plato::setIdPlato(int p){
    idPlato = p;
}
void Plato::setNombrePlato(char *np){
    strcpy(nombrePlato, np);
}
void Plato::setTipoPlato(int t){
    tipoPlato = t;
}
void Plato::setStock(int s){
        stock = s;
}
void Plato::setPrecio(float p){
    precio = p;
}
void Plato::setEstado(bool e){
    estado = e;
}


void Plato::mostrar(){
    cout << "Datos del plato: " << endl;
    cout << "Id: " << idPlato << endl;
    cout << "Tipo: " << tipoPlato << endl;
    cout << "Stock: " << stock << endl;
    cout << "Precio: " << precio << endl;
    cout << "Nombre: " << nombrePlato << endl;
    cout << "Estado: " << estado << endl;

}

void Plato::escribirArchivo(){
    FILE* p;
    p = fopen(FILE_PLATO, "ab");
    if (p == NULL)
    {
        colorError();
        coloresPrograma();
        return;
    }
    fwrite(this, sizeof (Plato), 1, p);
    colorCorrecto();
    coloresPrograma();
    fclose(p);
    return;
}

void Plato::leerArchivo(){
    FILE* p;
    Plato plato;
    int id;
    cout << "Ingrese el ID del plato que quisiera visualizar: " << endl;
    cin >> id;
    p = fopen(FILE_PLATO, "rb");
    if (p == NULL)
    {
        colorError();
        coloresPrograma();
        return;
    }
    while(fread(&plato, sizeof (Plato), 1, p)){
        if(id == plato.idPlato){

            plato.mostrar();
        }

    }
}

void Plato::mostrarCarta(){
    FILE* p;
    Plato plato;
    p = fopen(FILE_PLATO, "rb");
    if (p == NULL)
    {
        colorError();
        coloresPrograma();
        return;
    }
    while(fread(&plato, sizeof (Plato), 1, p)){
    if(plato.estado == 1 ){
    plato.mostrar();
    }
    }
    fclose(p);
}

void Plato::bajarPlato(){
    FILE* p;
    Plato plato;
    bool es = false;
    int id;
    p = fopen(FILE_PLATO, "rb+");
    if (p == NULL)
    {
        colorError();
        coloresPrograma();
        return;
    }
    cout << "Ingrese el id del plato que desea dar de baja: ";
    cin >> id;

    while (fread(&plato, sizeof (Plato), 1, p)){
        if (id == plato.idPlato){
            plato.setEstado(es);
            fseek(p, ftell(p) - sizeof (Plato), 0);
            fwrite(&plato, sizeof(Plato), 1, p);
            Pausa();
            fclose(p);
            return;

        }

    }


    fclose(p);

}

bool existeIdPlato(int id){
    FILE* p;
    Plato plato;
    int idArchivo;
    p = fopen(FILE_PLATO, "rb");
    if (p == NULL)
    {
        return 0;
    }

    while (fread(&plato, sizeof (Plato), 1, p) == 1)
    {
        idArchivo = plato.getIdPlato();
        if (id == idArchivo)
        {
            fclose(p);
            return 1;
        }
    }

    fclose(p);
    return 0;
}

int validarIdPlato(){

    bool vali = false;
    Plato plato;
    int id;

    while (!vali)
    {
        cout << "Ingrese el ID del plato: \n";
        cin >> id;

        if (id <= 0)
        {
            cout << "El ID de usuario ingresado es invalido. El ID de usuario debe ser un valor entero positivo, por favor ingrese el ID de usuario nuevamente...\n";
        }
        else if (existeIdPlato(id))
        {
            cout << "El ID de usuario ingresado ya existe por favor ingrese el ID de usuario nuevamente...\n";
        }
        else
        {
            plato.setIdPlato(id);
            vali = true;
        }
    }
    return id;
}

int validarTipoPlato(){
    bool vali = false;
    int tipo;
    Plato plato;

    while (!vali){
        cout << "Ingrese el tipo de plato (1 para entrada, 2 para plato principal, 3 para guarnicion o 4 para postre" << endl;
        cin >> tipo;

        if (tipo >= 1 && tipo <= 4){
            vali = true;
            return tipo;
    }
    }
}

int validarStockPlato(){
    bool vali = false;
    int stock;
    Plato plato;

    while (!vali){
        cout << "Ingrese el stock del plato: " << endl;
        cin >> stock;

        if (stock > 0 ){
            plato.setStock(stock);
            vali = true;
        }
    }
    return stock;
}

float validarPrecioPlato(){
    bool vali = false;
    float precio;
    Plato plato;

    while (!vali){
        cout << "Ingrese el precio del plato: " << endl;
        cin >> precio;

        if (precio > 0 ){
            plato.setPrecio(precio);
            vali = true;
        }
    }
    return precio;


}

void validarNombrePlato(Plato *plato){

    bool CadenaValida = false;

    while (!CadenaValida){

        char str[50];
        cout << "Ingrese nombre del plato \n" << endl;
        cin.ignore();
        cin.getline(str, 50);

        if (str[0] == '\0')//La cadena está vacía
        {
            cout << "El valor ingresado es invalido, por favor ingreselo nuevamente...\n";
        }
        else
        {
            CadenaValida = true;
            plato->setNombrePlato(str);
        }
    }
}

void Plato::modificarPlatoPorId(){
    LimpiarPantalla();
    Plato plato;
    int id, st = -1;
    FILE* p;
    float pr;

    p = fopen(FILE_PLATO, "rb+");
    if (p == NULL)
    {
        cout << "Error de archivo. Nombre de archivo: " << "./platos.dat" << " -- Es posible que el archivo que intenta leer no exista aun, por favor cree un nuevo usuario para que el archivo de usuarios sea creado." << "\n";
        return;
    }
    cout << "Ingrese el id del plato que desea mostrar: ";
    cin >> id;

    while (fread(&plato, sizeof (Plato), 1, p))
    {
        if (id == plato.idPlato)
        {
            plato.mostrar();
            cout << "Ingrese un nuevo precio: " << endl;
            cin >> pr;
            plato.setPrecio(pr);

            while (st <= 0){
            cout << "Indique la cantidad a sumar/restar: " << endl;
            cout << "Favor de ingresar el numero con el signo correspondiente en caso de ser negativo (-)" << endl;
            cin >> st;
            st = plato.stock + st;
            }
            plato.setStock(st);
            fseek(p, ftell(p) - sizeof (Plato), 0);
            fwrite(&plato, sizeof(Plato), 1, p);
            Pausa();
            fclose(p);
            return;
        }
    }
    fclose(p);
    cout << "El id de usuario especificado no se encontro en la base de datos de usuarios...";
    Pausa();
    return;
}

void Plato::cargar(){
    Plato plato;
    plato.setIdPlato(validarIdPlato());
    plato.setTipoPlato(validarTipoPlato());
    plato.setStock(validarStockPlato());
    plato.setPrecio(validarPrecioPlato());
    plato.setEstado(1);
    validarNombrePlato(&plato);
    plato.mostrar();
    plato.escribirArchivo();
    Pausa();
}
