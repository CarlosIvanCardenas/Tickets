#ifndef TICKETS_CARTELERA_H
#define TICKETS_CARTELERA_H

#include <vector>
#include <iostream>
using namespace std;

#include "Evento.h"

class Cartelera{
public:
    vector<Evento> buscarCategoria(string search);
    vector<Evento> buscarFecha(string search);
    vector<Evento> buscarUbicacion(string search);
    vector<Evento> getEventos();
    void addEvento(string nombre, string categoria, string fecha, string ubicacion, int asientos, string mapa, double precio);
    void comparar(Evento cambio);
private:
    vector<Evento> eventos;
};

void Cartelera::addEvento(string nombre, string categoria, string fecha, string ubicacion, int asientos, string mapa, double precio) {
    eventos.emplace_back(Evento(nombre, categoria, fecha, ubicacion, asientos, mapa, precio));
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

vector<Evento> Cartelera::getEventos() {
    return eventos;
}

//Busca un evento en la cartelara para actualizar el mapa de asientos
void Cartelera::comparar(Evento cambio) {
    for (int i = 0; i < eventos.size(); ++i) {
        if(eventos[i].getNombre() == cambio.getNombre()){
            eventos[i].setMapa(cambio.getMapa());
        }
    }
}


#endif //TICKETS_CARTELERA_H
