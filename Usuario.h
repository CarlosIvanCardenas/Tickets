//
// Created by cicc98 on 11/2/2017.
//

#ifndef TICKETS_USUARIO_H
#define TICKETS_USUARIO_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Usuario{
public:
    Usuario(string nombre, string pass);
    string getNombre();
    string getPass();
    void addBoleto(int id);
private:
    string nombre;
    string pass;
    vector<int> comprados;
};

Usuario::Usuario(string nombre, string pass){
    this->nombre = nombre;
    this->pass = pass;
}

string Usuario::getNombre() {
    return nombre;
}

string Usuario::getPass() {
    return pass;
}

void Usuario::addBoleto(int id) {
    comprados.push_back(id);
};

#endif //TICKETS_USUARIO_H
