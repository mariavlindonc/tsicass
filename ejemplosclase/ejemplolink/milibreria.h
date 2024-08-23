struct Producto {
    string código;
    string descripcion;
    float precio;
    int stock;
};

void cargar(int n, Producto P[]) {
    for (int i = 0; i < n; i++)
    {
        cout << "Producto " << i + 1 << endl;
        cout << "Código: ";
        cin >> P[i].código;
        cout << "Descripción: ";
        cin >> P[i].descripcion;
        cout << "Precio: ";
        cin >> P[i].precio;
        cout << "Stock: ";
        cin >> P[i].stock;
        cout << endl;
    }
}

void mostrar(int n, Producto P[]) {
    for (int i = 0; i < n; i++)
    {
        cout << "Producto " << i + 1 << endl;
        cout << "Código: " << P[i].código << endl;
        cout << "Descripción: " << P[i].descripcion << endl;
        cout << "Precio: " << P[i].precio << endl;
        cout << "Stock: " << P[i].stock << endl;
        cout << endl;
    }  
}

void verBajoStock(int n, Producto P[]) {
    cout << "Productos con stock menor a 100..." << endl;
    for (int i = 0; i < n; i++)
    {
        if (P[i].stock < 100)
        {
            cout << "Producto " << i + 1 << endl;
            cout << "Código: " << P[i].código << endl;
            cout << "Descripción: " << P[i].descripcion << endl;
            cout << "Precio: " << P[i].precio << endl;
            cout << "Stock: " << P[i].stock << endl << endl;
        } 
    }
}

void verSobrantes(int n, Producto P[]) {
    cout << "Productos con stock mayor a 500 y precio mayor a 100..." << endl;
    for (int i = 0; i < n; i++)
    {
        if (P[i].stock > 500 && P[i].precio > 100)
        {
            cout << "Producto " << i + 1 << endl;
            cout << "Código: " << P[i].código << endl;
            cout << "Descripción: " << P[i].descripcion << endl;
            cout << "Precio: " << P[i].precio << endl;
            cout << "Stock: " << P[i].stock << endl << endl;
        }
    }
}
