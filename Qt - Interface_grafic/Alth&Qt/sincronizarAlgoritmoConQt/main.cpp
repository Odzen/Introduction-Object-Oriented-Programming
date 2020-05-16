/*
  Archivo: main.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-25
  Fecha última modificación: 2018-06-02
  Versión: 0.2
  Licencia: GPL
*/

/*
   Este archivo fue generado automáticamente por qtcreator, y no hay que hacer nada especial con él, aparte de organizar el estilo.
   Aunque, si se desea, aqui también se pueden crear los objetos de mi programa y luego hay que pasarlos al constructor de MainWindow.
   La otra alternativa es crear esos objetos dentro del constructor de MainWindow, que es lo que he optado por hacer en este ejemplo.
*/


#include "MainWindow.h"
#include <QApplication>


int main(int numeroDeArgumentosEnLaLineaDeEjecucion, char *argumentosEnLaLineaDeEjecucion[])
{
  QApplication aplicacion(numeroDeArgumentosEnLaLineaDeEjecucion, argumentosEnLaLineaDeEjecucion);
  MainWindow window;
  window.show();

  return aplicacion.exec();
}
