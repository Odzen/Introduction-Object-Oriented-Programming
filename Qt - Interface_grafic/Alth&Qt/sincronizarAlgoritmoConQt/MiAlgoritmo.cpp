/*
  Archivo: MiAlgoritmo.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-25
  Fecha última modificación: 2018-06-02
  Versión: 0.2
  Licencia: GPL
*/


#include "MiAlgoritmo.h"


MiAlgoritmo::MiAlgoritmo() : QThread()
{
  contador = 0;
}


void MiAlgoritmo::run()
{
  repetir = true;
  while(repetir)
  {
    mutex.lock();
    contador++;  // Este es mi algoritmo. En este caso, es muy sencillo. En el tetris es más complicado
    condicionDeEspera.wait(&mutex);  // Y aquí espero hasta que me despierten con wakeAll. En tetris espero a que el usuario haga clic en algún botón {izquierda, derecha, abajo, girar}
    mutex.unlock();
  }
}


MiAlgoritmo::~MiAlgoritmo()
{
  mutex.unlock();
}


void MiAlgoritmo::continuar()
{
  condicionDeEspera.wakeAll();   // Esta orden despierta la función anterior por donde iba
}


int MiAlgoritmo::dimeLoQueHayQueImprimir()
{
  return contador;
}


void MiAlgoritmo::terminar()
{
  repetir = false;
  continuar();
}
