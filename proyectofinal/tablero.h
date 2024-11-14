class Tablero {
    private:  
        int tamano;
    public: 
        char tablero[14][14];
        Tablero();
        void setTam(int t);
        int getTam();
        void setTab(int i, int j, int b);
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
        bool hundido;
        char id;
    public: 
        Barcos();
        void setLar(int l);
        int getLar();
        void setCoo(int x, int y);
        int getCoo(char o);
        void setPos(int p);
        int getPos();
        void setId(char i);
        char getId();
        bool checkHundido();
        bool ubicarBarco(Tablero T);
        ~Barcos();
};

class Jugador {
    protected:
        Tablero tPropio;
        Tablero tRival;
        Barcos B[10];
    public:
        Jugador();
        Tablero getTP();
        Tablero getTR();
        int tiro(int y, int x);
        ~Jugador();
};

class Maquina:public Jugador{
    public:
        Maquina();
        int tiro(Usuario U);
        void iniciarBarcos(Barcos barco);
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
    private:
        int turno;
        Maquina M;
        Usuario U;
    public:
        Partida();
        void setTur(int r);
        int getTur();
        void siguienteTur();
        bool checkGanador();
        ~Partida();
};