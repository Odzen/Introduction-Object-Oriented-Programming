#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotSumar()
{
  QString operando1 = ui->lineEditOperando1->text();
  QString operando2 = ui->lineEditOperando2->text();
  int resultado = operando1.toInt() + operando2.toInt();
  ui->labelResultado->setText(QString::number(resultado));

}


void MainWindow::slotRestar()
{
    QString operando1 = ui->lineEditOperando1->text();
    QString operando2 = ui->lineEditOperando2->text();
    int resultado = operando1.toInt() - operando2.toInt();
    ui->labelResultado->setText(QString::number(resultado));
}


void MainWindow::slotMultiplicar()
{
    QString operando1 = ui->lineEditOperando1->text();
    QString operando2 = ui->lineEditOperando2->text();
    int resultado = operando1.toInt() * operando2.toInt();
    ui->labelResultado->setText(QString::number(resultado));
}



