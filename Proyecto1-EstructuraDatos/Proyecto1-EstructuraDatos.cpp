#include <iostream>
#include <string>
#include <stdlib.h>
#include "Matriz.h"
#include "Juego.h"


using namespace std;



bool comprobarNumero(int inicio, int numero, int *arreglo) {
    bool comprobacion = false;
    for (int i = 0; i < inicio; i++)
    {
        if (arreglo[i] == numero) {
            comprobacion = true;
        }
    }

    return comprobacion;
}

int* ingresarDatos(int filas, int columnas) {
    int dimension = filas * columnas;
    int* datosMatriz = new int[dimension];
    cout << "Ingresa los datos de la matriz. Debe ser mayor a 0 y menor a " << (dimension -1) << " El valor 0 sera tu posicion inicial. " << endl;
    for (int i = 0; i < dimension; i++)
    {
        int valor = -1;
        cout << "Ingresa la posicion " << (i +1) << ": ";        
        while (valor < 0 || valor >= dimension) {
            cin >> valor;
            if (valor < 0 || valor >= dimension) {
                cout << "DatoInvalido" << endl ;
                cout << "Ingresa la posicion " << (i + 1) << ": ";
            }
        }
        bool comprobacion = comprobarNumero(i, valor, datosMatriz);
        if (comprobacion == true) {
            cout << "Valor repetido" << endl;
            i--;
        }
        else {
            datosMatriz[i] = valor;
        }
    }
    return datosMatriz;
}

int* ingresarDatosAleatorios(int filas, int columnas) {
    int dimension = filas * columnas;
    int* datosMatriz = new int[dimension];
    for (int i = 0; i < dimension; i++)
    {
        int valor = rand() % dimension;
        bool comprobacion = comprobarNumero(i, valor, datosMatriz);
        if (comprobacion == true) {
            i--;
        }
        else {
            datosMatriz[i] = valor;
        }
    }
    return datosMatriz;
}



int main()
{
    cout << "Bienvenido al juego" << endl;
    int filas, columnas, niveles;    
    cout << "Ingresa el numero de filas: " << endl;
    cin >> filas;
    cout << "Ingresa el numero de columnas: " << endl;
    cin >> columnas;
    cout << "Ingresa la cantidad de niveles: " << endl;
    cin >> niveles;

    Matriz* matriz = new Matriz(filas, columnas, niveles);
    matriz->generarMatriz();
    int* datosMatriz = NULL;
    int desicion;
    do {
        cout << "¿Como deseas ingresar los datos de la matriz?" << endl;
        cout << "1. Manualmente" << endl;
        cout << "2. Datos Aleatorios" << endl;
        cin >> desicion;
        if (desicion < 1 || desicion > 2) {
            cout << "No ingresaste un numero valido" << endl;
        }
    } while (desicion < 1 || desicion > 2);
    if (desicion == 1) {
        datosMatriz = ingresarDatos(filas, columnas);
    }
    else if (desicion == 2) {
        datosMatriz = ingresarDatosAleatorios(filas, columnas);
    }
    Juego* juego = new Juego(matriz, datosMatriz);
    juego->iniciarJuego();
}
