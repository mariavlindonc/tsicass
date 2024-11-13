#include "tablero.h"
#include <random>
#include <iostream> 
using namespace std;

Tablero::Tablero(){

}

void Tablero::setTam(int t){
    tamano = t;
}

void Tablero::elegirTam(int e) {
    switch (e){
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

int Tablero::getTam(){
    return tamano;
}

void Tablero::setTab(int i, int j, char b){
    tablero[i][j] = b;
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

Barcos::Barcos(){

}

void Barcos::setLar(int l){
    largo=l;
}

void Barcos::setCoo(int x, int y){
    coorx=x;
    coory=y;
}

void Barcos:: setPos(int p){
    posicion=p;
}

int Barcos::getPos() {
    return posicion;
}

bool Barcos::ubicarBarco(Tablero T){
    if(posicion==1){
        for (int i=coory; i<largo; i++){
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

bool Barcos::checkHundido(){
    if (largo == impactos)
        return true;
    else
        return false;
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
}

Tablero Jugador::getTP() {
    return tPropio;
}

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
        U.getTP().tablero[y][x] = '-';
        return -1;
    }
}

int Usuario::tiro(int y, int x, Maquina M) {

}