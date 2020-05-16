#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    ui->graphicsViewVista->setScene(escena);

    escena->addLine(10,30,400,500);
}



MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::slotCirculo()
{
  double diametro = rnd(300,20);
  QBrush relleno(QColor(rnd(255), rnd(255), rnd(255)));
  QPen lapiz(QColor(rnd(255), rnd(255), rnd(255)));
  escena->addEllipse(rnd(100),rnd(100),diametro,diametro,lapiz,relleno);
}


double MainWindow::rnd(double max, double min)
{
  return ((1.0 * rand())/RAND_MAX)*(max-min) + min;
}

