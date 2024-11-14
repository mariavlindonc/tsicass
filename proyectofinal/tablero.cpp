#include "tablero.h"
#include <random>
#include <iostream> 
using namespace std;

Tablero::Tablero() {}

void Tablero::setTam(int t) {
    tamano = t;
}

int Tablero::getTam() {
    return tamano;
}

void Tablero::setTab(int i, int j, int b) {
    tablero[i][j] = b;
}

char Tablero::getTab(int i, int j) {
    return tablero[i][j];
}

void Tablero::elegirTam(int e) {
    switch (e) {
    case 1: 
        tamano = 10;
        break;
    case 2: 
        tamano = 12;
        break;
    case 3: 
    default: 
        tamano = 15;
        break;
    }
}

void Tablero::iniciarTab() {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            setTab(i, j, ' ');
        }
    }
}

void Tablero::mostrarTab() {
    for (int i = 0; i < tamano; i++) {
        cout << "|-----";
    }
    cout << "|" << endl;
    
    for (int j = 0; j < tamano; j++)
    {
        cout << "|  ";
        for (int i = 0; i < tamano; i++) {
            cout << tablero [j][i]<< "  |  ";
        }
        cout << endl;
        for (int i = 0; i < tamano; i++) {
            cout << "|-----";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

Tablero::~Tablero() {}

Barcos::Barcos() {}

void Barcos::setLar(int l){
    largo = l;
}

int Barcos::getLar() {
    return largo;
}

void Barcos::setCoo(int x, int y) {
    coorx = x;
    coory = y;
}

int Barcos::getCoo(char o) {
    if (o == 'x')
    {
        return coorx;
    }
    else if (o == 'y')
    {
        return coory;
    }
    else
    {
        cout << "ERROR 02.";
        cout << "Eje de coordenadas inválido.";
        return -1;
    }
}

void Barcos:: setPos(int p) {
    posicion = p;
}

int Barcos::getPos() {
    return posicion;
}

void Barcos::setId(char i) {
    id = i;
}

char Barcos::getId() {
    return id;
}

bool Barcos::checkHundido(){
    if (largo == impactos)
        return true;
    else
        return false;
}

bool Barcos::ubicarBarco(Tablero T){
    if(posicion==1){
        for (int i = coory; i < largo; i++){
            if (T.tablero[i][coorx] != ' ') {
                return false;
            }
            if (i >= T.getTam()) {
                return false;
            }
        }
        for (int i=coory; i<largo; i++) {
            T.tablero[i][coorx] = id;
        }
        return true;
    } else {
        for(int i = coorx; i < largo; i++){
            if (T.tablero[i][coorx] != ' ') {
                return false;
            }
            if (i >= T. getTam()) {
                return false;
            }
            T.tablero[coory][i];
        }
        for (int i=coorx; i<largo; i++) {
            T.tablero[coory][i] = id;
        }
        return true;
    }
}

Barcos::~Barcos() {}

Jugador::Jugador() {
    B[0].setId('A');
    B[1].setId('B');
    B[2].setId('C');
    B[3].setId('D');
    B[4].setId('E');
    B[5].setId('F');
    B[6].setId('G');
    B[7].setId('H');
    B[8].setId('I');
    B[9].setId('J');

    B[0].setLar(4);
    B[1].setLar(3);
    B[2].setLar(3);
    B[3].setLar(2);
    B[4].setLar(2);
    B[5].setLar(2);
    for (int i = 6; i < 10; i++) {
        B[i].setLar(1);
    }

    tPropio.iniciarTab();
    tRival.iniciarTab();
}

Tablero Jugador::getTP() {
    return tPropio;
}

Tablero Jugador::getTR() {
    return tRival;
}

Jugador::~Jugador() {}

Maquina::Maquina() {}

int Maquina::tiro(Usuario U) {
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(0, tPropio.getTam() - 1);
    int y = distr(eng), x = distr(eng);
    
    if (U.getTP().tablero[y][x] != ' ') {
        if (U.getTP().tablero[y][x] == 'O' || U.getTP().tablero[y][x] == 'X') {
            //YA ESTABA TOCADO O HUNDIDO DE ANTES
            return -2;
        } else {
            
        }
    } else {
        //AGUA
        tRival.tablero[y][x] = '-';
        return -1;
    }
}

void Maquina::iniciarBarcos(Barcos B) {
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(0, tPropio.getTam() - 1);
    do {
        B.setCoo(distr(eng), distr(eng));
        B.ubicarBarco(tPropio);
    } while (!B.ubicarBarco(tPropio));
}

Maquina::~Maquina() {}

Usuario::Usuario() {}

void Usuario::setNom(string n) {
    nombre = n;
}

string Usuario::getNom() {
    return nombre;
}

void Usuario::setPun(int p) {
    puntaje = p;
}

int Usuario::getPun() {
    return puntaje;
}

void Usuario::aumentarPuntaje(int a) {
    puntaje += a;
}

int Usuario::tiro(int y, int x, Maquina M)
{

}

Usuario::~Usuario() {}

Partida::Partida() {}

void Partida::setTur(int r) {
    turno = r;
}

void Partida::siguienteTur() {
    if (turno == 1)
    {
        turno = 2;
    }
    else
    {
        turno == 1;
    }
}

bool Partida::checkGanador() {

}

Partida::~Partida() {}