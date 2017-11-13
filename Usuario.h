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
private:
    string nombre;
    string pass;
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


#endif //TICKETS_USUARIO_H
