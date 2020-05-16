/*
  Archivo: TorresDeHanoi.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-24
  Fecha última modificación: 2018-05-24
  Versión: 0.1
  Licencia: GPL
*/

// Clase: TorresDeHanoi
// Responsabilidad: implementa el juego de las torres de Hanoi. No juega ningún humano. Esta clase resuelve el juego de forma recursiva e imprime cada paso.
// Colaboración: ninguna


#ifndef HH_TorresDeHanoi
#define HH_TorresDeHanoi
#include"ListaEnlazada.h"
#include"ElementoListaEnlazada.h"
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;


class TorresDeHanoi : public QThread
{
  private:
    int numeroDeAnillas;
    Stack torres[3];  // Cada torre es un Stack
    enum {IZQUIERDA=0, CENTRAL=1, DERECHA=2};  // Constantes para hacer el programa más fácil de entender. Las enumeraciones generan números enteros constantes
    QMutex mutex;
    QWaitCondition esperar;
    //bool repetir;

  public:
    /** Construye una Calculadora.
     *  - Entrada: el número de anillas en la primera torre (las otras dos están vacías)
    */
    TorresDeHanoi(int numeroDeAnillas);
    /** Destruye la Calculadora.
    */
    ~TorresDeHanoi();
    /** Resuelve el problema, imprimiendo en pantalla cada movimiento.
        - Entrada: ninguna
        - Salida: ninguna

    */

    void despertar();
    void resolver();
    void run();
    Stack * dimeLoQueHayQueImprimir();
    void terminar();

  protected:
    void mover(int cuantasAnillas, int origen, int destino, int auxiliar);
    void imprimir();
    string repetir(int veces, string letra);

};
  
#endif
