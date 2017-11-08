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
        cout << "SESION INICIADA" << endl;
        return usuarios.size()-1;
    }
    cout << "EL USUARIO YA EXISTE" << endl;
    cout << "SESION INICIADA" << endl;
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
    int seleccion;
    bool invalido;
    do{
        cout << "*********************************************************************************\n"
             << "*                                                                               *\n"
             << "*                         PROXIMOS EVENTOS POR CATEGORIA:                       *\n"
             << "*                               1) CONCIERTO                                    *\n"
             << "*                               2) CONFERENCIA                                  *\n"
             << "*                               3) ESPECTACULO                                  *\n"
             << "*                               4) OBRA DE TEATRO                               *\n"
             << "*                                                                               *\n"
             << "*********************************************************************************\n";
        cin >> seleccion;
        switch (seleccion){
            case 1:
                invalido = false;
                break;
            case 2:
                invalido = false;
                break;
            case 3:
                invalido = false;
                break;
            case 4:
                invalido = false;
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    }while (invalido);
}

void uiFecha(){
    int seleccion;
    bool invalido;
    do{
        cout << "*********************************************************************************\n"
             << "*                                                                               *\n"
             << "*                       PROXIMOS EVENTOS POR RANGO DE FECHAS:                   *\n"
             << "*                               1) PROXIMOS 7 DIA                               *\n"
             << "*                               2) ESTE MES                                     *\n"
             << "*                               3) ESTE AÑO                                     *\n"
             << "*                               4) PROXIMO AÑO                                  *\n"
             << "*                                                                               *\n"
             << "*********************************************************************************\n";
        cin >> seleccion;
        switch (seleccion){
            case 1:
                invalido = false;
                break;
            case 2:
                invalido = false;
                break;
            case 3:
                invalido = false;
                break;
            case 4:
                invalido = false;
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    }while (invalido);
}

void uiUbicacion(){
    int seleccion;
    bool invalido;
    do{
        cout << "*********************************************************************************\n"
             << "*                                                                               *\n"
             << "*                         PROXIMOS EVENTOS POR UBICACION:                       *\n"
             << "*                               1) ARENA MEXICO                                 *\n"
             << "*                               2) AUDITORIO LUIS ELIZONDO                      *\n"
             << "*                               3) ARENA MONTERREY                              *\n"
             << "*                                                                               *\n"
             << "*********************************************************************************\n";
        cin >> seleccion;
        switch (seleccion){
            case 1:
                invalido = false;
                break;
            case 2:
                invalido = false;
                break;
            case 3:
                invalido = false;
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    }while (invalido);
}

int main() {
    int sesion = -1, seleccion, subseleccion;
    bool invalido, subinvalido;
    string nombre, pass;
    vector<Usuario> usuarios;
    usuarios.emplace_back(Usuario("carlos", "0123"));
    usuarios.emplace_back(Usuario("diego", "0123"));
    Cartelera cartelera;
    cartelera.addEvento("Ed Sheran", "Concierto", "2018-01-13 20:00", "Arena Mexico", 10000);
    cartelera.addEvento("Mario Molina", "Conferencia", "2017-11-15 10:00", "Luis Elizondo", 500);
    cartelera.addEvento("Circo Du Solei", "Espectaculo", "2018-10-05 18:30", "Arena Monterrey", 5000);
    cartelera.addEvento("Entremeses Cervantinos", "Teatro", "2017-12-18 10:00", "Luis Elizondo", 1000);
    do{
        uiInicio();
        cin >> seleccion;
        switch (seleccion) {
            case 1:
                invalido = false;
                uiSesion();
                cin >> nombre >> pass;
                sesion = iniciarSesion(usuarios, nombre, pass);
                break;
            case 2:
                invalido = false;
                uiRegistro();
                cin >> nombre >> pass;
                sesion = registrar(usuarios, nombre, pass);
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    } while(invalido || sesion == -1);
    do{
        uiCartelera();
        cin >> seleccion;
        switch (seleccion){
            case 1:
                invalido = false;
                uiCategoria();
                break;
            case 2:
                invalido = false;
                uiFecha();
                break;
            case 3:
                invalido = false;
                uiUbicacion();
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    } while(invalido);

    return 0;
}