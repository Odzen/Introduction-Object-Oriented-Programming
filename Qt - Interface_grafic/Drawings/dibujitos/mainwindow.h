#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <stdlib.h>



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
    void slotCirculo();

  private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;

  protected:
    double rnd(double max, double min=0);
};

#endif // MAINWINDOW_H
