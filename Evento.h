//
// Created by cicc98 on 11/2/2017.
//

#ifndef TICKETS_EVENTO_H
#define TICKETS_EVENTO_H

#include <iostream>
using namespace std;

class Evento{
public:
    Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos);
    string getNombre();
    string getCategoria();
    string getFecha();
    string getUbicacion();
    void comprarBoletos(Usuario user);
private:
    string nombre;
    string categoria;
    string fecha;
    string ubicacion;
    int disponibles;
    int ocupados;
};

Evento::Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos) {
    this->nombre = nombre;
    this->categoria = categoria;
    this->fecha = fecha;
    this->ubicacion = ubicacion;
    disponibles = asientos;
    ocupados = 0;
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

void Evento::comprarBoletos(Usuario user) {
    if (disponibles > 0){

    }
}

#endif //TICKETS_EVENTO_H
