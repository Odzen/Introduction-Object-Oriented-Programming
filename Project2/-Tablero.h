/*
  Archivo: -Tablero.h
  Autor: Juan Sebastian Velasquez Acevedo(1744936) - Cesar Alberto Becerra Ramirez(1744338) - Jose David Ortiz (1740634)
  Email: juan.velasquez.acevedo@correounivalle.edu.co - cesar.becerra@correounivalle.edu.co - jose.david.ortiz@correounivalle.edu.co
  Fecha creación: 2018-03-28
  Fecha última modificación: 2018-05-18
  Versión: 0.1
  Licencia: GPL
*/

/*
  Clase:  Tablero
  Responsabilidad: Es el plano de 20*10 casillas en donde el jugador ejecuta los movimientos de la ficha, incialmente cada casilla empieza en 0. 
  Se le puede pedir que verifique la posibilidad de colocar una ficha en una zona del plano y que elimine filas llenas de fichas, en este caso 
  retonando el numero de filas eliminadas.
  Además, se le puede ordenar que imprima sus elementos.
  Colaboración: Contiene una Ficha, Contiene un jugador, Contiene un ConstructorDeFichas, Contiene DispositivoEntradaSalida 
*/


#ifndef Tablero_HH
#define Tablero_HH

#include "-Jugador.h"
#include "-Ficha.h"
#include "-ConstructorDeFichas.h"
#include "-DispositivoEntradaSalida.h"
#include "-HallDeLaFama.h"
#include <iostream>
using namespace std;


class Tablero
{
  private:
    int casillas[20][10];
    DispositivoEntradaSalida *entradaSalida;
    Jugador *jugador;
    ConstructorDeFichas *constructor;
    HallDeLaFama *hallDeLafama;
  
    
  public:
    /**
        Construye un tablero a partir de parametros inicializados como: un dispositivo, un jugador, un constructor y un HallDeLaFama, 
    */
    Tablero(DispositivoEntradaSalida *entradaSalida, Jugador *jugador, ConstructorDeFichas *constructor,HallDeLaFama *hallDeLafama);
    /**
        Pone una ficha en las coordenadas (fila,columna).
        Retorna true si se pudo hacer y false si no se pudo hacer, porque tropieza con el borde o con otras fichas.
    */
    bool ponerFicha(Ficha *ficha, int fila, int columna);
    /**
        Retorna el número de filas eliminadas.
    */
    int eliminarFilasCompletas();
    /**
        Imprime el tablero en cout. Esta función nos sirve solo para hacer pruebas y depurar. 
        Para la versión definitiva habrá que cambiarla por otra que mantenga el tablero siempre
        en la misma posición de la pantalla, sin hacer scroll (yo se la daré a su debido momento).
    */
    void imprimir();
    /**
      Mueve la ficha hacia abajo 
    */
    
    void  moverFichaHaciaAbajo();
    
     /**
        Quita una ficha en las coordenadas (fila,columna).
    */
    void quitarFicha(Ficha ficha, int fila, int columna);
    
    /**
      Enviar puntaje al hall
    */
    
    void enviarPuntaje();
    /**
     Comienza el juego y realiza las operaciones necesarias con los parametros inicializados
     Retorna true si el jugador quiere volver a jugar o false si el jugador no puede continuar jugando porque perdió
     
     */
    
    bool jugar( );

};

#endif