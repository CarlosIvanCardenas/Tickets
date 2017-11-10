#ifndef TICKETS_EVENTO_H
#define TICKETS_EVENTO_H

#include <iostream>
#include <cmath>

using namespace std;

class Evento{
public:
    Evento();
    Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos, string mapa);
    string getNombre();
    string getCategoria();
    string getFecha();
    string getUbicacion();
    void comprarBoletos();
private:
    string nombre;
    string categoria;
    string fecha;
    string ubicacion;
    int asientos;
    string mapa;
    int disponibles;
    void uiMapa();
    bool validar(string seleccion);
};

Evento::Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos, string mapa) {
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

bool Evento::validar(string seleccion){
    int grid = sqrt(asientos);
    int row = seleccion[0] - 64;
    int col = seleccion[1] - 48;
    int index = (row * col) - 1;
    if(row <= grid && col <= grid && mapa[index] != 'x'){
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
            cout << "CUANTOS BOLETOS DESEA COMPRAR?\n";
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
        cout << "GRACIAS POR SU COMPRA :)\n";
    }
    else{
        cout << "SE AGOTARON LOS BOLETOS PARA ESTE EVENTO" << endl;
    }
}

Evento::Evento() {

}
#endif //TICKETS_EVENTO_H
