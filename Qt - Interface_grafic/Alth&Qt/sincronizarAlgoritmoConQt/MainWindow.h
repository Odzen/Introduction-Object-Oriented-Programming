/*
  Archivo: MainWindow.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-25
  Fecha última modificación: 2018-06-02
  Versión: 0.2
  Licencia: GPL
*/

/*
  Clase: MainWindow (generada por qtcreator y modificada por mí)
  Responsabilidad: Recibe órdenes (slots) de la ventana gráfica principal, y puede escribir en ella. Las órdenes que puede recibir son:
    - slotComenzar() para comenzar el juego
    - slotAvanzar() para que el juego avance un paso. Después de darlo, pregunta a MiAlgoritmo qué es lo que hay que imprimir, y con ese dato llama a su propia función imprimir().
  Colaboración:
    - Es un QMainWindow.
    - Conoce la interfase gráfica ui.
    - Conoce una QGraphicsScene de la interfase gráfica, donde puede imprimir.
    - Contiene MiAlgoritmo.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include "MiAlgoritmo.h"


namespace Ui
{
  class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

  private:
    Ui::MainWindow *ui;
    MiAlgoritmo *miAlgoritmo;
    QGraphicsScene *escena;

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    void slotComenzar();
    void slotAvanzar();

  protected:
    void imprimir(int numero);
};

#endif
