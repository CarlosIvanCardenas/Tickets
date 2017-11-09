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
    vector<Evento> buscarCategoria(string search);
    vector<Evento> buscarFecha(string search);
    vector<Evento> buscarUbicacion(string search);
    void addEvento(string nombre, string categoria, string fecha, string ubicacion, int asientos);
private:
    vector<Evento> eventos;
};

void Cartelera::addEvento(string nombre, string categoria, string fecha, string ubicacion, int asientos) {
    eventos.emplace_back(Evento(nombre, categoria, fecha, ubicacion, asientos));
}

vector<Evento> Cartelera::buscarCategoria(string search) {
    vector<Evento> result;
    for (auto &evento : eventos) {
        if(evento.getCategoria() == search)
            result.push_back(evento);
    }
    return result;
}

vector<Evento> Cartelera::buscarFecha(string search) {
    vector<Evento> result;
    string hoy = "2017-11-08 00:00";
    for (auto &evento : eventos) {
        if(evento.getFecha() < search && evento.getFecha() >= hoy)
            result.push_back(evento);
    }
    return result;
}

vector<Evento> Cartelera::buscarUbicacion(string search) {
    vector<Evento> result;
    for (auto &evento : eventos) {
        if(evento.getUbicacion() == search)
            result.push_back(evento);
    }
    return result;
}


#endif //TICKETS_CARTELERA_H
