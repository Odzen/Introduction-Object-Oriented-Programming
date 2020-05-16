/*
  Archivo: MainWindow.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-25
  Fecha última modificación: 2018-06-02
  Versión: 0.2
  Licencia: GPL
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  escena = new QGraphicsScene(this);
  ui->graphicsViewVista->setScene(escena);

  miAlgoritmo = new MiAlgoritmo;
}


MainWindow::~MainWindow()
{
  miAlgoritmo->terminar();
  miAlgoritmo->wait(1);
  delete miAlgoritmo;
  delete ui;
}


void MainWindow::slotComenzar()
{
  int numero = miAlgoritmo->dimeLoQueHayQueImprimir();
  imprimir(numero);  // Imprime el estado inicial
  miAlgoritmo->start();
}


void MainWindow::slotAvanzar()
{
  miAlgoritmo->continuar();
  int numero = miAlgoritmo->dimeLoQueHayQueImprimir();
  imprimir(numero); // Imprime el estado después de cada jugada
}


// Es ilegal en Qt actualizar QWidgewts desde otro hilo que no sea el principal
// Por tanto, esta función no puede llamarse desde otro hilo. Hay que llamarla desde aquí. Por eso la llamamos desde slotAvanzar()
void MainWindow::imprimir(int numero)
{
  escena->clear();
  ui->labelResultado->setText(QString::number(numero));
  escena->addText(QString::number(numero));
  escena->addRect(20,20,20+numero,30+numero);
}
