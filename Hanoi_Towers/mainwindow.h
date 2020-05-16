
/*
  Archivo: mainwindow.h
  Autor: Juan Sebastian Velazque Acevedo
  Email: juan.velasquez.acevedo@correounivalle.edu.co
  Fecha creación: 2018-06-7
  Fecha última modificación: 2018-06-15
  Versión: 0.7
  Licencia: GPL
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"TorresDeHanoi.h"
#include"Stack.h"
#include"ElementoListaEnlazada.h"
#include"ListaEnlazada.h"
#include<QGraphicsScene>


namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotComenzar();
    void slotDespertar();


private:
    Ui::MainWindow *ui;
    TorresDeHanoi *torresDeHanoi;
    QGraphicsScene *escena;
    int arandelas = 0;

protected:
  void imprimir(Stack * torresStack);

};

#endif // MAINWINDOW_H
