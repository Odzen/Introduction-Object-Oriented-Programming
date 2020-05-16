/*
  Archivo: Stack.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-18
  Fecha última modificación: 2018-05-24
  Versión: 0.2
  Licencia: GPL
*/

#include "Stack.h"


Stack::Stack() : ListaEnlazada()
{
  // No hay que hacer nada
}


Stack::~Stack()
{
  // No hay que hacer nada
}


void Stack::push(int nuevoValor)
{
  anadirAlFinal(nuevoValor);
}


int Stack::pop()
{
  int posicionABorrar = size() - 1;
  int resultado = (*this)[posicionABorrar];
  
  borrar(posicionABorrar);
  
  return resultado;
}


int Stack::size()
{
  return ListaEnlazada::size();
}


void Stack::imprimir()
{
  ListaEnlazada::imprimir();
}


int Stack::operator[](int posicion)
{
  return ListaEnlazada::operator[](posicion);  
}

