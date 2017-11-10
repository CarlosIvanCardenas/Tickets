#ifndef TICKETS_BOLETO_H
#define TICKETS_BOLETO_H

#include "Evento.h"

class Boleto : public Evento{
public:
    Boleto(int asiento, double precio);
private:
    int id;
    double precio;
    int asiento;
};

Boleto::Boleto(int asiento, double precio) {

}

#endif //TICKETS_BOLETO_H
