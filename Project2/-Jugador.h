/*
  Archivo: -Jugador.h
  Autor: Juan Sebastian Velasquez Acevedo(1744936) - Cesar Alberto Becerra Ramirez(1744338) - Jose David Ortiz (1740634)
  Email: juan.velasquez.acevedo@correounivalle.edu.co - cesar.becerra@correounivalle.edu.co - jose.david.ortiz@correounivalle.edu.co
  Fecha creación: 2018-03-28
  Fecha última modificación: 2018-05-18
  Versión: 0.1
  Licencia: GPL
*/
/*
  Clase: Jugador
  Responsabilidad: Es un jugador en el juego Tetris el cual conoce un dispositivo de entrada-salida con el que
  le ordena al tablero para que este efectúe movimientos rectilíneos y rotación sobre la ficha.
  Colaboración: Contiene un DispositivoEntradaSalida 
  
*/

#ifndef Jugador_HH
#define Jugador_HH


#include <string>
#include <cstdlib>
#include "-DispositivoEntradaSalida.h"
using namespace std;

class Jugador
{
  private:
    string nombre;
    DispositivoEntradaSalida *entradaSalida;
  
  public:
  /**
    Construye un Jugador, inicializando su parametro que es un Dispositivo de Entrada y Salida 
  */
    Jugador(DispositivoEntradaSalida *entradaSalida);
  /**
    Retorna un nombre,leyéndolo por medio de una funcion del dispositivo 
  */ 
    string preguntarNombre();//
  /**
    Lee la jugada desde el Dispositvo 
  */
    int accionDejugada();
};

#endif