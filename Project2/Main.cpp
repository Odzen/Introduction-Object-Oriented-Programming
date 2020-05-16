/*
  Archivo: Main.cpp
  Autor: Juan Sebastian Velasquez Acevedo(1744936) - Cesar Alberto Becerra Ramirez(1744338) - Jose David Ortiz (1740634)
  Email: juan.velasquez.acevedo@correounivalle.edu.co - cesar.becerra@correounivalle.edu.co - jose.david.ortiz@correounivalle.edu.co
  Fecha creación: 2018-03-28
  Fecha última modificación: 2018-05-18
  Versión: 0.1
  Licencia: GPL
*/

#include <iostream>
#include <string>
#include "-DispositivoEntradaSalida.h"
#include "-DispositivoTerminal.h"
#include "-Temporizador.h"
#include "-Jugador.h"
#include "-Tablero.h"
#include "-ConstructorDeFichas.h"
#include "-Ficha.h"
#include "-HallDeLaFama.h"

int main()
{
  DispositivoEntradaSalida *dispositivo = new DispositivoTerminal;
  HallDeLaFama *records= new HallDeLaFama("LosGanadoresDelTetris.txt");
  Jugador *elJugador = new Jugador(dispositivo);
  ConstructorDeFichas *constructor = new ConstructorDeFichas;
  Tablero tablero(dispositivo, elJugador, constructor, records); 
  
  while(true)
  {
    if(tablero.jugar() == false)
    {
      if(dispositivo->leerSiVolverAJugar())
        continue;
      else
        break;
    }
  }
      
  delete dispositivo;
  dispositivo=0;
  delete records;
  records=0;
  delete elJugador;
  elJugador=0;
  delete constructor;
  constructor=0;
  return 0;
}