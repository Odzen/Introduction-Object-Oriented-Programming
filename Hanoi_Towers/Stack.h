/*
  Archivo: Stack.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-05-17
  Fecha última modificación: 2018-05-24
  Versión: 0.2
  Licencia: GPL
*/

// Clase: Stack
// Responsabilidad: es un stack (pila LIFO) de strings. Se puede añadir un elemento en el top, se puede sacar el top,
//    se puede imprimir todo el stack y se puede preguntar el número de elementos que tiene
// Colaboración: Es parecido a una ListaEnlazada


#include "ListaEnlazada.h"


#ifndef HH_Stack
#define HH_Stack

class Stack : protected ListaEnlazada
{
  private:

  public:
    /** Construye un Stack vacío.
     *  - Entrada: ninguna
    */
    Stack();
    /** Destruye el Stack. Para ello, destruye la ListaEnlazada.
    */
    ~Stack();
    /** Añade un nuevo elemento al principio del Stack.
        - Entrada: un valor a añadir
        - Salida: ninguna
    */
    void push(int nuevoValor);
    /** Saca el último dato introducido.
        - Entrada: 
          - Ninguna.
        - Salida:
          - el último dato introducido. Si no hay ninguno, lanza una excepción.
    */
    int pop();
    /** Averigua el número de elementos en el Stack
        - Entrada: 
          - Ninguna.
        - Salida:
          - El número de elementos.
    */
    int size();
    /** Imprime en pantalla (cout) el Stack
     *  - Entrada: ninguna
     *  - Salida: ninguna
    */
    void imprimir();
    /** Averigua el elemento que hay en cierta posición de la ListaEnlazada
        - Entrada: 
          - La posición.
        - Salida:
          - El elemento que hay en esa posición. Si la posición no existe (menor que cero o mayor o igual al tamaño), lanza una excepción.
    */
    int operator[](int posicion);
};
  
#endif
