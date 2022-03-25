#include <iostream>
#include <string>
#include "Matriz.h"

using namespace std;

int* ingresarDatos(int filas, int columnas) {
    int dimension = filas * columnas;
    int* datosMatriz = new int[dimension];
    cout << "Ingresa los datos de la matriz. Debe ser mayor a 0 y menor a " << (dimension -1) << " El valor 0 sera tu posicion inicial. " << endl;
    for (size_t i = 0; i < dimension; i++)
    {
        int valor = -1;
        cout << "Ingresa la posicion " << i << ": ";        
        while (valor < 0 || valor >= dimension) {
            cin >> valor;
            if (valor < 0 || valor >= dimension) {
                cout << "DatoInvalido" << endl ;
                cout << "Ingresa la posicion " << i << ": ";
            }
        }
    }
    return datosMatriz;
}

int main()
{
    cout <<"Bienvenido al juego" << endl;
    int filas, columnas, niveles;
    string nombre;
    cout << "Ingresa tu nombre: " << endl;
    cin >> nombre;
    cout << "Ingresa el numero de filas: " << endl;
    cin >> filas;
    cout << "Ingresa el numero de columnas: " << endl;
    cin >> columnas;
    cout << "Ingresa la cantidad de niveles: " << endl;
    cin >> niveles;

    Matriz *matriz = new Matriz(filas, columnas, niveles);
    matriz->generarMatriz();
    int* datosMatriz = ingresarDatos(filas, columnas);
}
