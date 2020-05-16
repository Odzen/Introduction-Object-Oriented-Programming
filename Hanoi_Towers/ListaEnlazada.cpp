/*
  Archivo: ListaEnlazada.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2017-08-25
  Fecha última modificación: 2018-05-24
  Versión: 0.4
  Licencia: GPL
*/


#include "ListaEnlazada.h"



ListaEnlazada::ListaEnlazada()
{
  primerElemento = 0;
  soyPropietarioDelPrimerElemento = true;
}


ListaEnlazada::~ListaEnlazada()
{
  if(not soyPropietarioDelPrimerElemento)
    return;
    
  ElementoListaEnlazada *adelantado;
  for(ElementoListaEnlazada *cualElemento = primerElemento; cualElemento != 0; 
                                                           cualElemento = adelantado)
  {
    adelantado = cualElemento->cualEsElSiguiente();
    delete cualElemento;
    cualElemento = 0;
  }
  primerElemento = 0;
}


void ListaEnlazada::anadirAlFinal(int nuevo)
{
  ElementoListaEnlazada *nuevoElemento = new ElementoListaEnlazada(nuevo);

  if(primerElemento == 0)
  {
    primerElemento = nuevoElemento;
  }
  else
  {
    ElementoListaEnlazada *cualElemento;
    for(cualElemento = primerElemento; cualElemento->cualEsElSiguiente() != 0; 
                                         cualElemento = cualElemento->cualEsElSiguiente())
    {
    }
    cualElemento->cambiarSiguiente(nuevoElemento);
  }
}


bool ListaEnlazada::anadirDespuesDe(int despuesDe, int nuevoValor)
{
  ElementoListaEnlazada *insertarDespuesDeEste = buscar(despuesDe);
  if(insertarDespuesDeEste == 0)
    return false;
    
  ElementoListaEnlazada *nuevoElemento = new ElementoListaEnlazada(nuevoValor);

  ElementoListaEnlazada *aux = insertarDespuesDeEste->cualEsElSiguiente();
  nuevoElemento->cambiarSiguiente(aux);
  insertarDespuesDeEste->cambiarSiguiente(nuevoElemento);
  return true;
}


bool ListaEnlazada::borrarElemento(int valor)
{
  if(primerElemento == 0)
    return false;
  
  if(primerElemento->dimeSuValor() == valor)
  {
    ElementoListaEnlazada *tmp = primerElemento;
    primerElemento = primerElemento->cualEsElSiguiente();
    delete tmp;
    return true;
  }

  for(ElementoListaEnlazada *cualElemento = primerElemento; cualElemento->cualEsElSiguiente() != 0; cualElemento = cualElemento->cualEsElSiguiente())
  {
    if(cualElemento->cualEsElSiguiente()->dimeSuValor() == valor) 
    {
      ElementoListaEnlazada *tmp = cualElemento->cualEsElSiguiente();
      ElementoListaEnlazada *aux = cualElemento->cualEsElSiguiente()->cualEsElSiguiente();
      cualElemento->cambiarSiguiente(aux);
      delete tmp;
      return true;
    }
  }
  return false;
}


bool ListaEnlazada::existe(int valor)
{
  for(ElementoListaEnlazada *cualElemento = primerElemento; cualElemento != 0; cualElemento = cualElemento->cualEsElSiguiente())
  {
    if(cualElemento->dimeSuValor() == valor)
      return true;
  }
  return false;
}


ElementoListaEnlazada *ListaEnlazada::buscar(int valor)
{
  for(ElementoListaEnlazada *cualElemento = primerElemento; cualElemento != 0; cualElemento = cualElemento->cualEsElSiguiente())
  {
    if(cualElemento->dimeSuValor() == valor)
      return cualElemento;
  }
  return 0;
}


int ListaEnlazada::cuantoVale(ElementoListaEnlazada *elemento)
{
  return elemento->dimeSuValor();
}


void ListaEnlazada::imprimir()
{
  if(primerElemento == 0)
  {
    cout << "La lista está vacía" << endl;
  }
  else
  {
    cout << "La lista es: ";
    for(ElementoListaEnlazada *cualElemento = primerElemento; cualElemento != 0; cualElemento = cualElemento->cualEsElSiguiente())
    {
      cout << cualElemento->dimeSuValor() << ", ";  
    }
    cout << endl;
  }
}




ListaEnlazada *ListaEnlazada::shallowCopy()
{
  ListaEnlazada *nueva = new ListaEnlazada;
  nueva->primerElemento = this->primerElemento;
  nueva->soyPropietarioDelPrimerElemento = true;
  soyPropietarioDelPrimerElemento = false;
  return nueva; // Cedo propiedad de este nuevo objeto
/* Otra alternativa:
  nueva->soyPropietarioDelPrimerElemento = false;
  soyPropietarioDelPrimerElemento = true;
  return nueva; // NO cedo propiedad de este nuevo objeto
*/
}



ListaEnlazada*ListaEnlazada::deepCopy()
{
  ListaEnlazada *nueva = new ListaEnlazada;
  nueva->primerElemento = this->primerElemento->deepCopy();
  return nueva; // Cede propiedad
}


// NUEVAS FUNCIONES


int ListaEnlazada::size()
{
  int contador = 0;
  for(ElementoListaEnlazada *cualElemento = primerElemento; cualElemento != 0; cualElemento = cualElemento->cualEsElSiguiente())
    contador++;
  return contador;
}


int ListaEnlazada::operator[](int posicion)
{
  if(posicion < 0 or posicion >= size())
    throw "Posición inexistente";
  
  ElementoListaEnlazada *cualElemento = primerElemento;
  for(int contador = 0; contador < posicion; contador++)
    cualElemento = cualElemento->cualEsElSiguiente();
  
  return cualElemento->dimeSuValor();
}


bool ListaEnlazada::borrar(int posicion)
{
  if(posicion < 0 or posicion >= size())
    throw "Posición inexistente";
  
  ElementoListaEnlazada *cualElemento = primerElemento;
  for(int contador = 0; contador < posicion-1; contador++)
    cualElemento = cualElemento->cualEsElSiguiente();
  
  if(posicion == 0)
  {
    ElementoListaEnlazada *tmp = primerElemento;
    primerElemento = primerElemento->cualEsElSiguiente();
    delete tmp;
    return true;
  }

  ElementoListaEnlazada *tmp = cualElemento->cualEsElSiguiente();
  ElementoListaEnlazada *aux = cualElemento->cualEsElSiguiente()->cualEsElSiguiente();
  cualElemento->cambiarSiguiente(aux);
  delete tmp;
  return true;
}







