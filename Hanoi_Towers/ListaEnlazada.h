/*
  Archivo: ListaEnlazada.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2017-08-25
  Fecha última modificación: 2018-05-24
  Versión: 0.4
  Licencia: GPL
*/

// Clase: ListaEnlazada
// Responsabilidad: es una lista de int simplemente enlazada, a la que se pueden
//    añadir elementos, buscarlos y borrarlos.
// Colaboración: posee todos los ElementoListaEnlazada (toma propiedad de todos ellos)


#include<iostream>
#include "ElementoListaEnlazada.h"


#ifndef HH_ListaEnlazada
#define HH_ListaEnlazada

class ListaEnlazada
{
  private:
    ElementoListaEnlazada *primerElemento;
    bool soyPropietarioDelPrimerElemento;

  public:
    /** Construye una ListaEnlazada vacía.
     *  - Entrada: ninguna
    */
    ListaEnlazada();
    /** Destruye la ListaEnlazada. Borrra todos los ElementoListaEnlazada, ya que es propietario de todos.
    */
    ~ListaEnlazada();
    /** Añade un nuevo elemento al final de la lista enlazada.
        - Entrada: un valor a añadir
        - Salida: ninguna
    */
    void anadirAlFinal(int nuevoValor);
    /** Hace una copia superficial, cediendo propiedad. En SHALLOW COPY hay que decidir si se cede o no la propiedad de los objetos internos.
    */
    ListaEnlazada *shallowCopy();
    /** Hace una copia profunda, cediendo propiedad. En DEEP COPY siempre se cede la propiedad de los objetos internos.
    */
    ListaEnlazada *deepCopy();
    /** Añade un nuevo nùmero a la lista enlazada, después del nùmero indicado.
        - Entrada: 
          - el valor que hay que buscar para insertar detrás de él.
          - el nuevo valor a insertar.
        - Salida: true si se logró hacer; false si no se logró, típicamente porque no existe el elemento donde insertar después.
    */
    bool anadirDespuesDe(int insertarDespuesDeEste, int nuevoValor);
    /** Borra un valor de la ListaEnlazada
        - Entrada: el valor a borrar. Si hay más de uno, solo borra el primero.
        - Salida: retorna false si no lo encontró.
    */
    bool borrarElemento(int valor);
    /** Verifica si existe un cierto valor en la ListaEnlazda.
     *  - Entrada: el valor a buscar.
     *  - Salida: retorna true si lo encontró y false en caso contrario.
    */
    bool existe(int valor);
    /** Averigua cuanto vale un ElementoListaEnlazada
     *  - Entrada: un puntero a ese elemento.
     *  - Salida: el valor de ese elemento.
    */
    int cuantoVale(ElementoListaEnlazada *elemento);
    /** Imprime en pantalla (cout) la ListaEnlazada
     *  - Entrada: ninguna
     *  - Salida: ninguna
    */
    void imprimir();      

    // NUEVAS FUNCIONES:

    /** Averigua el número de elementos en la ListaEnlazada
        - Entrada: 
          - Ninguna.
        - Salida:
          - El número de elementos.
    */
    int size();
    /** Averigua el elemento que hay en cierta posición de la ListaEnlazada
        - Entrada: 
          - La posición.
        - Salida:
          - El elemento que hay en esa posición. Si la posición no existe (menor que cero o mayor o igual al tamaño), lanza una excepción.
    */
    int operator[](int posicion);

    /** Borra un valor de la ListaEnlazada
        - Entrada: la posición del valor a borrar.
        - Salida: retorna false si no lo encontró.
    */
    bool borrar(int posicion);

  protected:  
    /** Busca un valor en la lista enlazada.
     *  - Entrada: el valor a buscar
     *  - Salida: retorna un puntero al ElementoListaEnlazada. Retorna 0 (un puntero nulo) si no se encontró.
    */
    ElementoListaEnlazada *buscar(int valor); 
};
  
#endif
