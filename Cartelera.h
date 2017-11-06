//
// Created by cicc98 on 11/2/2017.
//

#ifndef TICKETS_CARTELERA_H
#define TICKETS_CARTELERA_H

#include <vector>
#include <iostream>
using namespace std;

#include "Usuario.h"
#include "Evento.h"

class Cartelera{
public:
    void comprarBoletos(Usuario user, Evento event);
    string buscarEvento();
    void addEvento(string nombre, string categoria, string fecha, string ubicacion, int asientos);
private:
    vector<Evento> eventos;
};

void Cartelera::addEvento(string nombre, string categoria, string fecha, string ubicacion, int asientos) {
    eventos.emplace_back(Evento(nombre, categoria, fecha, ubicacion, asientos));
}


#endif //TICKETS_CARTELERA_H
