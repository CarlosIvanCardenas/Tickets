#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

#include "Usuario.h"
#include "Cartelera.h"

int iniciarSesion(vector<Usuario> usuarios, string nombre, string pass, bool registro = false){
    for (int i = 0; i < usuarios.size(); ++i) {
        if(usuarios[i].getNombre() == nombre && usuarios[i].getPass() == pass){
            if(!registro)
                cout << "SESION INICIADA" << endl;
            return i;
        }
    }
    if(!registro)
        cout << "NOMBRE O CONTRASEÑA INCORRECTA" << endl;
    return -1;
}

int registrar(vector<Usuario> &usuarios, string nombre, string pass){
    if(iniciarSesion(usuarios, nombre, pass, true) == -1){
        usuarios.emplace_back(Usuario(nombre, pass));
        cout << "USUARIO CREADO CON EXITO" << endl;
        return usuarios.size()-1;
    }
    cout << "EL USUARIO YA EXISTE" << endl;
    return -1;
}

void uiInicio(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                              COMPRA TUS BOLETOS                               *\n"
         << "*                               1) INICIA SESION                                *\n"
         << "*                               2) REGISTRATE                                   *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

void uiSesion(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                             INICIA SESION                                     *\n"
         << "*                                USUARIO:                                       *\n"
         << "*                               CONTRASENA:                                     *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

void uiRegistro(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                               REGISTRATE                                      *\n"
         << "*                                USUARIO:                                       *\n"
         << "*                               CONTRASENA:                                     *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

void uiInvalido(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                                                                               *\n"
         << "*                          INGRESA UN VALOR VALIDO                              *\n"
         << "*                        PRESIONE ENTER PARA CONTINUAR                          *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

void uiCartelera(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                             PROXIMOS EVENTOS POR:                             *\n"
         << "*                               1) CATEGORIA                                    *\n"
         << "*                               2) RANGO DE FECHAS                              *\n"
         << "*                               3) UBICACION                                    *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

void uiCategoria(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                         PROXIMOS EVENTOS POR CATEGORIA:                       *\n"
         << "*                               1) CONCIERTO                                    *\n"
         << "*                               2) CONFERENCIA                                  *\n"
         << "*                               3) ESPECTACULO                                  *\n"
         << "*                               4) OBRA DE TEATRO                               *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

void uiUbicacion(){
    cout << "*********************************************************************************\n"
         << "*                                                                               *\n"
         << "*                         PROXIMOS EVENTOS POR CATEGORIA:                       *\n"
         << "*                               1) CONCIERTO                                    *\n"
         << "*                               2) CONFERENCIA                                  *\n"
         << "*                               3) ESPECTACULO                                  *\n"
         << "*                               4) OBRA DE TEATRO                               *\n"
         << "*                                                                               *\n"
         << "*********************************************************************************\n";
}

int main() {
    int sesion = -1, seleccion;
    string nombre, pass;
    vector<Usuario> usuarios;
    usuarios.emplace_back(Usuario("carlos", "0123"));
    usuarios.emplace_back(Usuario("diego", "0123"));
    Cartelera cartelera;
    cartelera.addEvento("Ed Sheran", "Concierto", "2018-01-13 20:00", "Arena Mexico", 10000);
    cartelera.addEvento("Mario Molina", "Conferencia", "2017-11-15 10:00", "Luis Elizondo", 500);
    cartelera.addEvento("Circo Du Solei", "Espectaculo", "2018-10-05 18:30", "Arena Monterrey", 5000);
    cartelera.addEvento("Entremeses Cervantinos", "Teatro", "2017-12-18 10:00", "Luis Elizondo", 1000);
    uiInicio();
    cin >> seleccion;
    //system("cls");
    switch (seleccion) {
        case 1:
            uiSesion();
            cin >> nombre >> pass;
            sesion = iniciarSesion(usuarios, nombre, pass);
            break;
        case 2:
            uiRegistro();
            cin >> nombre >> pass;
            sesion = registrar(usuarios, nombre, pass);
            break;
        default:
            uiInvalido();
    }
    sesion == -1 ? uiInicio() : uiCartelera();
    cin >> seleccion;
    switch (seleccion){
        case 1:
            uiCategoria();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            uiInvalido();
    }
    return 0;
}