#include "tablero.h"
#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

Tablero::Tablero() {
    tamano = 15;
}

void Tablero::setTam(int t) {
    tamano = t;
}

int Tablero::getTam() {
    return tamano;
}

void Tablero::setTab(int i, int j, char b) {
    if (i >= 0 && i < MAX_TAB && j >= 0 && j < MAX_TAB) {
        tablero[i][j] = b;
    } else {
        cerr << "Error 06. Índices fuera de rango (" << i << ", " << j << ")" << endl;
    }
}

char Tablero::getTab(int i, int j) {
    if (i >= 0 && i < MAX_TAB && j >= 0 && j < MAX_TAB) {
        return tablero[i][j];
    } else {
        cerr << "Error 06. Índices fuera de rango (" << i << ", " << j << ")" << endl;
        return '0';
    }
}

void Tablero::elegirTam(int e) {
    switch (e) {
    case 1: 
        tamano = TAM_1;
        break;
    case 2: 
        tamano = TAM_2;
        break;
    case 3: 
    default: 
        tamano = TAM_3;
        break;
    }
}

void Tablero::iniciarTab() {
    for (int j = 0; j < tamano; j++) {
        for (int i = 0; i < tamano; i++) {
            tablero[j][i] = ' ';
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

Barcos::Barcos() {
    largo = 0;
    coorx = 0, coory = 0;
    posicion = 1;
    impactos = 0;
    id = ' ';
}

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
        cout << "ERROR 02. Eje de coordenadas inválido." << endl;
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
    impactos = s;
}

int Barcos::getImpactos() {
    return impactos;
}

bool Barcos::checkHundido(){
    if (largo == impactos)
        return true;
    else
        return false;
}

bool Barcos::ubicarBarco(Tablero& T){
    if (coory < 0 || coory >= MAX_TAB || coorx < 0 || coorx >= MAX_TAB) 
    {
        return false;
    }
    if(posicion == 1){
        if (coory + largo > T.getTam())
        {
            return false;
        }
        for (int i = coory; i < coory + largo; i++){
            if (T.getTab(i, coorx) != ' ') {
                return false;
            }
        }
        for (int i = coory; i < coory + largo; i++) {
            T.setTab(i, coorx, id);
        }
        return true;
    } else if (posicion == 2) {
        if (coorx + largo > T.getTam())
        {
            return false;
        }
        for(int i = coorx; i < coorx + largo; i++){
            if (T.getTab(coory, i) != ' ') {
                return false;
            }
        }
        for (int i=coorx; i < coorx + largo; i++) {
            T.setTab(coory, i, id);
        }
        return true;
    } else {
        cout << "ERROR 03. Orientación inválida!" << endl;
        return false;
    }
}

Barcos::~Barcos() {}

Jugador::Jugador() {}

Tablero& Jugador::getTP() {
    return tPropio;
}

Tablero& Jugador::getTR() {
    return tRival;
}

Barcos& Jugador::getBar(int i) {
    return B[i];
}

void Jugador::iniciar() {
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
    B[6].setLar(1);
    B[7].setLar(1);
    B[8].setLar(1);
    B[9].setLar(1);

    tPropio.iniciarTab();
    tRival.iniciarTab();
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
        default:
            cout << "ERROR 05. Id de barco inválido" << endl;
            return -1;
    }
}

Jugador::~Jugador() {}

Maquina::Maquina() {}

int Maquina::tiro(Usuario &U) {
    int y, x;
    do
    {
        y = rand() % tPropio.getTam();
        x = rand() % tPropio.getTam();
    } while (U.getTP().getTab(y,x) == 'O');

    if (U.getTP().getTab(y,x) != ' ') {
        char id = U.getTP().getTab(y,x);
        U.getBar(identificarBarco(id)).setImpactos(U.getBar(identificarBarco(id)).getImpactos() + 1);
        U.getTP().setTab(y,x,'O');
        tRival.setTab(y,x,'O');
        if (U.getBar(identificarBarco(id)).checkHundido())
        {
            //HUNDIDO
            return HUNDIDO;
        } else {
            //TOCADO
            return TOCADO;
        }
    } else {
        //AGUA
        tRival.setTab(y,x,'-');
        return AGUA;
    }
}

void Maquina::iniciarBarcos() {
    int y, x;
    bool e;
    for (int i = 0; i < 9; i++)
    {
        do {
            y = rand()%tPropio.getTam();
            x = rand()%tPropio.getTam();
            B[i].setCoo(y,x);
            if (i % 2 == 0)
            {
                B[i].setPos(1);
            } else
            {
                B[i].setPos(2);
            }
            if (!B[i].ubicarBarco(tPropio))
            {
                e = true;
                y = 0, x = 0;
                B[i].setPos(1);
            }
            else
            {
                e = false;
            }
        } while (e);
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

int Usuario::tiro(int y, int x, Maquina &M)
{
    if (M.getTP().getTab(y,x) != ' ') {
        if (M.getTP().getTab(y,x) == 'O') {
            return YA_TOCADO;
        } else {
            char id = M.getTP().getTab(y,x);
            //IMPACTO
            M.getBar(identificarBarco(id)).setImpactos(M.getBar(identificarBarco(id)).getImpactos() + 1);
            M.getTP().setTab(y,x,'O');
            tRival.setTab(y,x,'O');
            if (M.getBar(identificarBarco(id)).checkHundido())
            {
                return HUNDIDO;
            } else {
                return TOCADO;
            }
        }
    } else {
        tRival.setTab(y,x,'-');
        return AGUA;
    }
}

Usuario::~Usuario() {}

Partida::Partida() {
    turno = 0;
    ganador = -1;
    empate = false;
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
    for (int i = 0; i < 10; i++)
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
        return true;
    }
    else if (u == 10) {
        ganador = 0;
        return true;
    }
    else if (m == 10) {
        ganador = 1;
        return true;
    }
    else {
        return false;
    }
}

Partida::~Partida() {}