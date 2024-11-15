#include <iostream>
#include <string>
using namespace std;

class Usuario;
class Maquina;

class Tablero {
    private:  
        int tamano;
    public: 
        char tablero[14][14];
        Tablero();
        void setTam(int t);
        int getTam();
        void setTab(int i, int j, char b);
        char getTab(int i, int j);
        void elegirTam(int e);
        void iniciarTab();
        void mostrarTab();
        ~Tablero();
};

class Barcos{
    private: 
        int largo;
        int coorx, coory;
        int posicion; //orientación del barco
        int impactos;
        char id;
    public: 
        Barcos();
        void setLar(int l);
        int getLar();
        void setCoo(int y, int x);
        int getCoo(char o);
        void setPos(int p);
        int getPos();
        void setId(char i);
        char getId();
        void setImpactos(int s);
        int getImpactos();
        bool checkHundido();
        bool ubicarBarco(Tablero T);
        ~Barcos();
};

class Jugador {
    protected:
        Tablero tPropio;
        Tablero tRival;
        Barcos B[9];
    public:
        Jugador();
        Tablero getTP();
        Tablero getTR();
        Barcos getBar(int i);
        int identificarBarco(char i);
        ~Jugador();
};

class Maquina:public Jugador{
    public:
        Maquina();
        int tiro(Usuario U);
        void iniciarBarcos();
        ~Maquina();
};

class Usuario:public Jugador{ 
    private:
        string nombre;
        int puntaje;
    public:
        Usuario();
        void setNom(string n);
        string getNom();
        void setPun(int p);
        int getPun();
        void aumentarPuntaje(int a);
        int tiro(int y, int x, Maquina M);
        ~Usuario();
};

class Partida{
    public:
        int turno;
        Maquina M;
        Usuario U;
        char ganador;
        bool empate;
        Partida();
        void siguienteTur();
        bool checkGanador();
        ~Partida();
};