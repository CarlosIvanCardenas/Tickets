//
// Created by cicc98 on 11/2/2017.
//

#ifndef TICKETS_BOLETO_H
#define TICKETS_BOLETO_H

#include "Evento.h"

class Boleto : public Evento{
private:
    int id;
    int precio;
    int asiento;
};

#endif //TICKETS_BOLETO_H
