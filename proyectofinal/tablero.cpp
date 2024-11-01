#include "tablero.h"
#include <random>
using namespace std;

tablero::tablero(){

}

void tablero::settam(int t){
    switch (t)
    {
    case 1: tam=10;
        break;
    case 2: tam=12;
        break;
    case 3: tam=15;
        break;
    default: tam=15;
        break;
    }
}

int tablero::gettam(){
    
}


barcos::barcos(){

}

void barcos::setlargo(int l){
    largo=l;
}

void barcos::setcoor(int x, int y){
    coorx=x;
    coory=y;
}

void barcos:: setpos(int p){
    pos=p;
}

int barcos::getpos() {
    return pos;
}

bool barcos::ubicarBarco(int t){
    if(pos==1){
        for (int i=coory; i<largo; i++){
            if (ta[i][coorx] != ' ')
            {
                return false;
            }
            if (i > t)
            {
                return false;
            }
        }
        for (int i=coory; i<largo; i++)
        {
            ta[i][coorx] != '#';
        }
        return true;
    } else {
        for(int i=coorx; i<largo; i++){
            if (ta[i][coorx] != ' ')
            {
                return false;
            }
            if (i > t)
            {
                return false;
            }
            ta[coory][i];
        }
        for (int i=coorx; i<largo; i++)
        {
            ta[coory][i] != '#';
        }
        return true;
    }
}

bool barcos::hundido(){

}

void maquina::iniciarBarcos(barcos B, int t)
{
    //REVISAR SI USAR SRAND ES MAS SIMPLE 
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(0, t);
    do {
        B.setcoor(distr(eng), distr(eng));
        B.ubicarBarco(t);
    } while (!B.ubicarBarco(t));
}