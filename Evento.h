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
private:
    string nombre;
    string categoria;
    string fecha;
    string ubicacion;
    int asientos;
};

Evento::Evento(string nombre, string categoria, string fecha, string ubicacion, int asientos) {
    this->nombre = nombre;
    this->categoria = categoria;
    this->fecha = fecha;
    this->ubicacion = ubicacion;
    this->asientos = asientos;
}

#endif //TICKETS_EVENTO_H
