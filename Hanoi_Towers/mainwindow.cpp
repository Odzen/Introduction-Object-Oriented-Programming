
/*
  Archivo: mainwindow.cpp
  Autor: Juan Sebastian Velazque Acevedo
  Email: juan.velasquez.acevedo@correounivalle.edu.co
  Fecha creación: 2018-06-7
  Fecha última modificación: 2018-06-15
  Versión: 0.7
  Licencia: GPL
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "QRect"
#include "QRectF"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    ui->graphicsViewVista->setScene(escena);
    torresDeHanoi = 0;
}

MainWindow::~MainWindow()
{
  if(torresDeHanoi != 0)
  {
    torresDeHanoi->terminar();
    torresDeHanoi->wait(1);
    delete torresDeHanoi;
  }
  delete ui;
}


void MainWindow::slotComenzar()
{
    if(torresDeHanoi != 0)
      delete torresDeHanoi;
    arandelas = ui->spinBoxAnillas->value();
    torresDeHanoi = new TorresDeHanoi(arandelas);
    Stack * torresStack = torresDeHanoi->dimeLoQueHayQueImprimir();
    imprimir(torresStack);
    torresDeHanoi->start();
}



void MainWindow::slotDespertar()
{
  if(torresDeHanoi != 0)
  {
    torresDeHanoi->despertar();
    Stack * torresStack = torresDeHanoi->dimeLoQueHayQueImprimir();
    imprimir(torresStack);
  }
}




void MainWindow::imprimir(Stack * torresStack)
{


   escena->clear();









  //--------------------------BLOQUE DE DEFINICIONES-------------------------------


   int alturaArandela = 20;
   int radioTorre = alturaArandela/5;
   int alturaPalos = arandelas * alturaArandela;
   int distanciaColumna = 20;
   int basePalos = 50*arandelas;
   QBrush colorArandelas(QColor(245, 68, 235));
   QBrush colorMarco(QColor(80, 80, 80));
   QPen lapiz(QColor(0,0,0));





  //-----------------------------------------------------------------------------------


   for(int distanciaColumna=0;distanciaColumna<basePalos; distanciaColumna+=(24*arandelas))
   {
     escena->addRect( QRect(0,alturaPalos,basePalos+radioTorre-basePalos/24,radioTorre),lapiz,colorMarco);
     escena->addRect( QRect(distanciaColumna,0,radioTorre,alturaPalos),lapiz,colorMarco);

   }


  for (int torre=0;torre<3;torre++)
  {
    for(int altura=0;altura<arandelas;altura++)
    {
      if(altura < torresStack[torre].size())
      {
        int radio = torresStack[torre][altura];

        int posYDiscos =  altura*-alturaArandela+alturaPalos-alturaArandela;
        int posXDiscos =  torre*24*arandelas-radio*9;

        escena->addRect(QRect(posXDiscos,posYDiscos,radio*20,alturaArandela-10),lapiz,colorArandelas);
      }
    }
  }
}


