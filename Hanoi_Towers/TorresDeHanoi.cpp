/*
  Archivo: TorresDeHanoi.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-24
  Fecha última modificación: 2018-05-24
  Versión: 0.1
  Licencia: GPL
*/

#include"TorresDeHanoi.h"



TorresDeHanoi::TorresDeHanoi(int numeroDeAnillas) : QThread()
{
  this->numeroDeAnillas = numeroDeAnillas;
  for(int anilla = numeroDeAnillas; anilla > 0; anilla--)
    torres[IZQUIERDA].push(anilla);

  torres[0].imprimir();
  torres[1].imprimir();
  torres[2].imprimir();
}


TorresDeHanoi::~TorresDeHanoi()
{
  // No hay que hacer nada
}


void TorresDeHanoi::resolver()
{
  mover(numeroDeAnillas, IZQUIERDA, DERECHA, CENTRAL);
  imprimir();
}

void TorresDeHanoi::run()
{
  resolver();
}


void TorresDeHanoi::despertar()
{
  esperar.wakeAll();
}


void TorresDeHanoi::mover(int cuantasAnillas, int origen, int destino, int auxiliar)
{
  if(cuantasAnillas==1)
  {
    mutex.lock();
    imprimir();
    esperar.wait(&mutex);
    int anilla = torres[origen].pop();
    cout << "Hay que mover la anilla " << anilla << " de la torre " << origen << " a la torre " << destino << endl;
    torres[destino].push(anilla);
    mutex.unlock();
  }
  else
  {
    mover(cuantasAnillas-1, origen, auxiliar, destino);
    mover(1, origen, destino, auxiliar);
    mover(cuantasAnillas-1, auxiliar, destino, origen);
  }
}


void TorresDeHanoi::imprimir()
{
  for(int altura=numeroDeAnillas; altura>=0; altura--)
  {
    for(int torre=0; torre < 3; torre++)
    {
      int radio=0;
      if(altura < torres[torre].size())
        radio = torres[torre][altura];
    
      cout << repetir(numeroDeAnillas-radio, " ");
      cout << repetir(radio, "█");
      cout << repetir(1, "|");
      cout << repetir(radio, "█");
      cout << repetir(numeroDeAnillas-radio, " ");
      cout << repetir(4, " ");
    }
    cout << endl;
  }

}



string TorresDeHanoi::repetir(int veces, string letra)
{
  string resultado = "";
  for(int vez=0; vez<veces; vez++)
    resultado = resultado + letra;
  return resultado;
}

Stack * TorresDeHanoi::dimeLoQueHayQueImprimir()
{
  return torres;
}

void TorresDeHanoi::terminar()
{
  //repetir = false;
  despertar();
}


