/*
  Archivo: ElementoListaEnlazada.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2017-08-25
  Fecha última modificación: 2018-05-24
  Versión: 0.2
  Licencia: GPL
*/

// Clase: ElementoListaEnlazada
// Responsabilidad: es un elemento de la lista simplemente enlazada,
//   que contiene un entero y un puntero al siguiente elemento.
// Colaboración: conoce un ElementoListaEnlazada (el siguiente)

#include<iostream>
using namespace std;


#ifndef HH_ElementoListaEnlazada
#define HH_ElementoListaEnlazada

class ElementoListaEnlazada
{
  private:
    int valor;
    ElementoListaEnlazada *siguiente;

  public:
//    ElementoListaEnlazada * operator [] (int indice);  // Sobrecarga de operadores (y no la vamos a ver)
    /** Constructor, que crea un ElementoListaEnlazada con un valor concreto
        - Entrada: el valor
    */
    ElementoListaEnlazada(int valor);
    /** Destructor. No hace nada
    */
    ~ElementoListaEnlazada();
    /** Hace una copia profunda, cediendo propiedad
    */
    ElementoListaEnlazada *deepCopy();
    /** Averigua cual es el siguiente ElementoListaEnlazada
        - Entrada: ninguna
        - Salida: retorna el siguiente ElementoListaEnlazada
    */
    ElementoListaEnlazada *cualEsElSiguiente();
    /** Modificar el siguiente ElementoListaEnlazada, para que apunte a otro
        - Entrada: el nuevo ElementoListaEnlazada
        - Salida: ninguna
    */
    void cambiarSiguiente(ElementoListaEnlazada *siguiente);
    /** Me dice cuanto vale un ElementoListaEnlazada
        - Entrada: ninguna
        - Salida: el valor de ese elemento
    */
    int dimeSuValor();
};
  
#endif



