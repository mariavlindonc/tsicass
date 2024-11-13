class Tablero{
    private:  
        int tamano;
    public: 
        char tablero[14][14];
        Tablero();
        void setTam(int t) { tamano = t; };
        int getTam() const { return tamano; };
        void setTab(int i, int j, char b);
        void elegirTam(int e);
        void iniciarTab();
        void mostrarTab();
        ~Tablero();
};

class Barcos{
    private: 
        int largo; 
        int tamano;
        int coorx, coory;
        int posicion;
        int impactos;
        bool hundido;
        char id;
    public: 
        Barcos();
        int getTam() const { return tamano; };
        void setTam(int t) { tamano = t; };
        void setLar(int l);
        int getLar();
        void setCoo(int x, int y) { x = x; y = y; };
        void setPos(int p){ posicion = p; } ;
        int getPos();
        bool checkHundido();
        bool ubicarBarco(Tablero T);
        void setId(char i);
        char getId();
        void ubicarBarco(int tamano){
            cout<<"Barco de tamaño: "<< tamano << "ubicado. \n";
        };

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
        int tiro(int y, int x);
        ~Jugador();
};

class Usuario:public Jugador{
    private:
        string nombre;
        int puntaje;
    public:
        Usuario();
        int tiro(int y, int x, Maquina M);
        void setNom(string n);
        string getNom();
        void setPun(int p);
        int getPun();
        ~Usuario();
};

class Maquina:public Jugador{
    public:
        Maquina();
        int tiro(Usuario U);
        void iniciarBarcos(Barcos& barco, int tamano){
            barco.setTam(tamano);
        }
        void iniciarTiro();
        ~Maquina();
};

class Partida{
    private:
        int turno;
    public:
        Partida();
        void setTur(int r);
        int getTur();
        ~Partida();
};