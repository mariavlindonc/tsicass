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

void Barcos::setCoo(int y, int x) {
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
        cout << "ERROR 02." << endl;
        cout << "Eje de coordenadas inválido." << endl;
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

void Barcos::setImpactos(int s) {

}

bool Barcos::checkHundido(){
    if (largo == impactos)
        return true;
    else
        return false;
}

bool Barcos::ubicarBarco(Tablero T){
    if(posicion == 1){
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
    } else if (posicion == 2) {
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
    } else {
        cout << "ERROR 03." << endl;
        cout << "Orientación inválida!" << endl;
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

Barcos Jugador::getBar(int i) {
    return B[i];
}

int Jugador::identificarBarco(char i) {
    switch (i)
    {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'E':
            return 4;
        case 'F':
            return 5;
        case 'G':
            return 6;
        case 'H':
            return 7;
        case 'I':
            return 8;
        case 'J':
            return 9; 
    }
}

Jugador::~Jugador() {}

Maquina::Maquina() {}

int Maquina::tiro(Usuario U) {
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(0, tPropio.getTam() - 1);
    
    int y, x;
    do
    {
        y = distr(eng);
        x = distr(eng);
    } while (U.getTP().tablero[y][x] == 'O');

    if (U.getTP().tablero[y][x] != ' ') {
        char id = U.getTP().tablero[y][x];
        //IMPACTO
        U.getBar(identificarBarco(id)).setImpactos(U.getBar(identificarBarco(id)).getImpactos() + 1);
        U.getTP().tablero[y][x] = 'O';
        tRival.tablero[y][x] = 'O';
        if (U.getBar(identificarBarco(id)).checkHundido())
        {
            //HUNDIDO
            return -4;
        } else {
            //TOCADO
            return -3;
        }
    } else {
        //AGUA
        tRival.tablero[y][x] = '-';
        return -1;
    }
}

void Maquina::iniciarBarcos() {
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(0, tPropio.getTam() - 1);
    for (int i = 0; i < 9; i++)
    {
        do {
            B[i].setCoo(distr(eng), distr(eng));
            B[i].ubicarBarco(tPropio);
        } while (!B[i].ubicarBarco(tPropio));
    }
}

Maquina::~Maquina() {}

Usuario::Usuario() {
    nombre = "guest";
    puntaje = 0;
}

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
    if (M.getTP().tablero[y][x] != ' ') {
        if (M.getTP().tablero[y][x] == 'O') {
            //YA ESTABA TOCADO O HUNDIDO DE ANTES
            return -2;
        } else {
            char id = M.getTP().tablero[y][x];
            //IMPACTO
            M.getBar(identificarBarco(id)).setImpactos(M.getBar(identificarBarco(id)).getImpactos() + 1);
            M.getTP().tablero[y][x] = 'O';
            tRival.tablero[y][x] = 'O';
            if (M.getBar(identificarBarco(id)).checkHundido())
            {
                //HUNDIDO
                return -4;
            } else {
                //TOCADO
                return -3;
            }
        }
    } else {
        //AGUA
        tRival.tablero[y][x] = '-';
        return -1;
    }
}

Usuario::~Usuario() {}

Partida::Partida() {
    empate = false;
    turno = 1;
    ganador = 'o';
}

void Partida::siguienteTur() {
    if (turno == 1)
    {
        turno = 0;
    }
    else
    {
        turno = 1;
    }
}

bool Partida::checkGanador() {
    int u = 0, m = 0;
    for (int i = 0; i < 9; i++)
    {
        if (U.getBar(i).checkHundido()) {
            u++;
        }
        if (M.getBar(i).checkHundido()) {
            m++;
        }
    }

    if (u == 10 && m == 10) {
        empate = true;   
    }
    else if (u == 10) {
        ganador = u;
    }
    else if (m == 10) {
        ganador = m;
    }
    else {
        return false;
    }
    return true;
}

Partida::~Partida() {}