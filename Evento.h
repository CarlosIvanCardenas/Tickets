#ifndef TICKETS_EVENTO_H
#define TICKETS_EVENTO_H

#include <iostream>
#include <cmath>

using namespace std;

class Evento{
public:
    Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos, string mapa, double precio);
    string getNombre();
    string getCategoria();
    string getFecha();
    string getUbicacion();
    int getAsientos();
    string getMapa();
    double getPrecio();
    void comprarBoletos();
    void setMapa(string mapa);
private:
    string nombre;
    string categoria;
    string fecha;
    string ubicacion;
    int asientos;
    string mapa;
    int disponibles;
    double precio;
    void uiMapa();
    bool validar(string seleccion);
};

Evento::Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos, string mapa, double precio) {
    this->nombre = nombre;
    this->categoria = categoria;
    this->fecha = fecha;
    this->ubicacion = ubicacion;
    this->asientos = asientos;
    this->mapa = mapa;
    disponibles = asientos;
    for (char i : mapa) {
        if(i == 'x')
            disponibles--;
    }
    this->precio = precio;
}

string Evento::getNombre() {
    return nombre;
}

string Evento::getCategoria() {
    return categoria;
}

string Evento::getFecha() {
    return fecha;
}

string Evento::getUbicacion() {
    return ubicacion;
}

int Evento::getAsientos() {
    return asientos;
}

string Evento::getMapa() {
    return mapa;
}

double Evento::getPrecio() {
    return precio;
}

//Dibide el mapa de asientos en una matriz para formar una interfaz
void Evento::uiMapa(){
    int grid = sqrt(asientos);
    cout << "*********************************************************************************\n";
    for (int j = 1; j <= grid; ++j) {
        cout << "\t" << j;
    }
    for (int i = 0; i < mapa.length(); ++i) {
        if(i % grid == 0)
            cout << endl << static_cast<char>(65+(i/grid)) << "\t";
        cout << mapa[i] << "\t";
    }
    cout << endl;
    cout << "*********************************************************************************\n";
}

//Valida que el asiento seleccionado este disponible y que este exista
bool Evento::validar(string seleccion){
    int grid = sqrt(asientos);
    int row = seleccion[0] - 65;
    int col = seleccion[1] - 49;
    int index = (row * grid + col);
    if(row <= grid && row >= 0 && col <= grid && col >= 0 && mapa[index] != 'x'){
        cout << "ASIENTO DISPONIBLE\n";
        mapa[index] = 'x';
        return false;
    }
    else{
        cout << "ESE ASIENTO ESTA OCUPADO O NO EXISTE\nINTENTE DE NUEVO\n";
        return true;
    }
}

void Evento::comprarBoletos() {
    if(disponibles != 0){
        int num = 0;
        do{
            cout << "CUANTOS BOLETOS DESEA COMPRAR? (PRECIO POR BOLETO: $" << precio << ")\n";
            cin >> num;
            if(num > disponibles)
                cout << "ESA CANTIDAD DE BOLETOS NO ESTA DISPONIBLE\nEXISTEN " << disponibles << " BOLETOS DISPONIBLES\n";
        }while(num > disponibles);
        string seleccion;
        for (int i = 1; i <= num; ++i) {
            cout << "BOLETO NUMERO " << i << endl;
            do{
                uiMapa();
                cout << "INGRESA EL ASIENTO QUE DESEA, EJEMPLO: A2\n";
                cin >> seleccion;
            }while(validar(seleccion));

        }
        cout << "*********************************************************************************\n"
             << "*                                                                               *\n"
             << "*                            GRACIAS POR SU COMPRA :)                           *\n"
             << "*                                                                               *\n"
             << "*                       DESEA CONTINUAR COMPRANDO: (si/no)                      *\n"
             << "*                                                                               *\n"
             << "*********************************************************************************\n";
    }
    else{
        cout << "*********************************************************************************\n"
             << "*                                                                               *\n"
             << "*                  SE AGOTARON LOS BOLETOS PARA ESTE EVENTO :(                  *\n"
             << "*                                                                               *\n"
             << "*                      DESEA CONTINUAR COMPRANDO: (si/no)                       *\n"
             << "*                                                                               *\n"
             << "*********************************************************************************\n";
    }
}

void Evento::setMapa(string mapa) {
    this->mapa = mapa;
}

#endif //TICKETS_EVENTO_H
