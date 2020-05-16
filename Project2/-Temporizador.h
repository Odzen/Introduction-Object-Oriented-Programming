/*
  Archivo: -Temporizador.h
  Autor: Juan Sebastian Velasquez Acevedo(1744936) - Cesar Alberto Becerra Ramirez(1744338) - Jose David Ortiz (1740634)
  Email: juan.velasquez.acevedo@correounivalle.edu.co - cesar.becerra@correounivalle.edu.co - jose.david.ortiz@correounivalle.edu.co
  Fecha creación: 2018-03-28
  Fecha última modificación: 2018-05-18
  Versión: 0.1
  Licencia: GPL
*/

/*
  Clase: Temporizador
  Responsabilidad: contiene un hilo que periódicamente (cada 1 seg. u otro tiempo programable) da la orden al Tablero para que baje la Ficha actual. Se puede cambiar ese tiempo.
  Colaboración: 
    - Contiene un hilo (es propietario de él)
    - Conoce el Tablero (no es propietario de él).
*/

#ifndef Temporizador_HH
#define Temporizador_HH

#include "-Tablero.h"
#include <thread>
#include <chrono>
using namespace std;


class Temporizador
{
  private:
    Tablero &tablero;
    int milisegundos;
    thread *hilo;
    bool repetir;

  public:
    Temporizador(Tablero &tablero, int milisegundos);
    ~Temporizador();
    void aumentarTiempo();
    void disminuirTiempo();
    void comenzar();
    void finalizar();
    
  protected:
    void funcionPeriodica();
};

#endif
