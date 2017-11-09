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

void uiCategoria(Cartelera cartelera){
    vector<Evento> resultados;
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
                resultados = cartelera.buscarCategoria("Concierto");
                break;
            case 2:
                invalido = false;
                resultados = cartelera.buscarCategoria("Conferencia");
                break;
            case 3:
                invalido = false;
                resultados = cartelera.buscarCategoria("Espectaculo");
                break;
            case 4:
                invalido = false;
                resultados = cartelera.buscarCategoria("Teatro");
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    }while (invalido);
    for(auto &resultado : resultados){
        cout << resultado.getNombre() << endl;
    }
}

void uiFecha(Cartelera cartelera){
    string hoy = "2017-11-08 00:00";
    string semana = "2017-11-15 00:00";
    vector<Evento> resultados;
    int seleccion;
    bool invalido;
    do{
        cout << "*********************************************************************************\n"
             << "*                                                                               *\n"
             << "*                       PROXIMOS EVENTOS POR RANGO DE FECHAS:                   *\n"
             << "*                               1) PROXIMOS 7 DIA                               *\n"
             << "*                               2) ESTE MES                                     *\n"
             << "*                               3) ESTE AÑO                                     *\n"
             << "*                               4) TODOS                                        *\n"
             << "*                                                                               *\n"
             << "*********************************************************************************\n";
        cin >> seleccion;
        switch (seleccion){
            case 1:
                invalido = false;
                resultados = cartelera.buscarFecha("2017-11-16 00:00");
                break;
            case 2:
                invalido = false;
                resultados = cartelera.buscarFecha("2017-12-09 00:00");
                break;
            case 3:
                invalido = false;
                resultados = cartelera.buscarFecha("2018-01-01 00:00");
                break;
            case 4:
                invalido = false;
                resultados = cartelera.buscarFecha("2019-01-01 00:00");
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    }while (invalido);
    for(auto &resultado : resultados){
        cout << resultado.getNombre() << endl;
    }
}

void uiUbicacion(Cartelera cartelera){
    vector<Evento> resultados;
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
                resultados = cartelera.buscarUbicacion("Arena Mexico");
                break;
            case 2:
                invalido = false;
                resultados = cartelera.buscarUbicacion("Luis Elizondo");
                break;
            case 3:
                invalido = false;
                resultados = cartelera.buscarUbicacion("Arena Monterrey");
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    }while (invalido);
    for(auto &resultado : resultados){
        cout << resultado.getNombre() << endl;
    }
}

void uiComprar(vector<Evento> resultados){

}

int main() {
    int sesion = -1, seleccion, subseleccion;
    bool invalido, subinvalido;
    vector<Usuario> usuarios;
    string nombre, pass;
    ifstream db;
    db.open("dbUsuarios.txt");
    while(db >> nombre >> pass){
        usuarios.emplace_back(Usuario(nombre, pass));
    }
    db.close();
    Cartelera cartelera;
    string data, categoria, fecha, ubicacion, asientos;
    db.open("dbEventos.txt");
    while(!db.eof()){
        getline(db, data);
        nombre = data.substr(0, data.find(','));
        data.erase(0, data.find(',')+1);
        categoria = data.substr(0, data.find(','));
        data.erase(0, data.find(',')+1);
        fecha = data.substr(0, data.find(','));
        data.erase(0, data.find(',')+1);
        ubicacion = data.substr(0, data.find(','));
        data.erase(0, data.find(',')+1);
        asientos = data.substr(0, data.find(','));
        data.erase(0, data.find(',')+1);
        cartelera.addEvento(nombre, categoria, fecha, ubicacion, stoi(asientos));
    }
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
                uiCategoria(cartelera);
                break;
            case 2:
                invalido = false;
                uiFecha(cartelera);
                break;
            case 3:
                invalido = false;
                uiUbicacion(cartelera);
                break;
            default:
                invalido = true;
                cout << "INGRESA UN VALOR VALIDO" << endl;
        }
    } while(invalido);

    return 0;
}