/*
  Archivo: MiAlgoritmo.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-25
  Fecha última modificación: 2018-06-02
  Versión: 0.2
  Licencia: GPL
*/

/*
  Clase: MiAlgoritmo
  Responsabilidad: Implementa el algoritmo que ya tenemos resuelto en modo 'terminal'. En este ejemplo, el algoritmo es muy simple: es un contador que cuenta 0,1,2,3...
  Colaboración:
    - Es un QThread. Se necesita que sea un hilo para poder ponerlo a dormir y despertarlo cada vez que haya un clic en un botón de la interfase gráfica.
    - Contiene un QWaitCondition y un QMutex que me sirven para dormir/despertar.
*/

#ifndef MiAlgoritmo_HH
#define MiAlgoritmo_HH

#include<QThread>
#include<QMutex>
#include<QWaitCondition>


class MiAlgoritmo : public QThread
{
  private:
    QWaitCondition condicionDeEspera;
    QMutex mutex;
    // Variables que conforman el estado de MiAlgoritmo:
    int contador;
    bool repetir;

  public:
    MiAlgoritmo();
    ~MiAlgoritmo();
    virtual void run();
    void continuar();
    void terminar();
    int dimeLoQueHayQueImprimir();
};

#endif
