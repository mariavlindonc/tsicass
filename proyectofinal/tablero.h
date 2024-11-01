class tablero{
    private: 
        int tam;
    protected:
        char ta[15][15];
    public: 
        tablero();
        void settam(int t);
        int gettam();

};

class barcos:public tablero{
    private: 
        int largo; 
        int coorx, coory;
        int pos;
        bool hundido;
    public: 
        barcos();
        void setlargo(int l);
        void setcoor(int x, int y);
        void setpos(int p);
        int getpos();
        bool hundido();
        bool ubicarBarco(int t);
};

class usuario{
    public: 

};

class maquina{
    public:
        void iniciarBarcos(barcos B, int t);


};

class partida{

};