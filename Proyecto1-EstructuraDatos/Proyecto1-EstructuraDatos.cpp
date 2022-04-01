#include <iostream>
#include <string>
#include <stdlib.h>
#include "Matriz.h"
#include "Juego.h"

using namespace std;
/*
    Este metodo se utiliza para comprobar que un numero este repetido.
*/
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
/*
    Metodo en donde se ingresn los datos de las matrices manualmente.
*/
int* ingresarDatos(int filas, int columnas, int niveles) {
    int dimension = filas * columnas * niveles;
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
/*
    Ingresa los datos de la matriz de forma aleatoria.
*/
int* ingresarDatosAleatorios(int filas, int columnas, int niveles) {
    int dimension = filas * columnas * niveles;
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


/*
    Metodo main de la aplicacion. Pide ingresar los datos iniciales del juego.
*/
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
    Matriz* matrices = new Matriz[niveles];
    int inicio = 1;
    for (int i = 0; i < niveles; i++)
    {
        matrices[i] = Matriz(filas, columnas);
        matrices[i].generarMatriz();
    }
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
        datosMatriz = ingresarDatos(filas, columnas, niveles);
    }
    else if (desicion == 2) {
        datosMatriz = ingresarDatosAleatorios(filas, columnas, niveles);
    }
    Juego* juego = new Juego(matrices, datosMatriz, niveles, columnas, filas);
    juego->iniciarJuego();
    
    system("pause");
    return 0;
}
