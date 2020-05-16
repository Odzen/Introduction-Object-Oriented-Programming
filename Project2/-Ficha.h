/*
  Archivo: -Ficha.h
  Autor: Juan Sebastian Velasquez Acevedo(1744936) - Cesar Alberto Becerra Ramirez(1744338) - Jose David Ortiz (1740634)
  Email: juan.velasquez.acevedo@correounivalle.edu.co - cesar.becerra@correounivalle.edu.co - jose.david.ortiz@correounivalle.edu.co
  Fecha creación: 2018-03-28
  Fecha última modificación: 2018-05-16
  Versión: 0.1
  Licencia: GPL
*/
/*
  Clase:  Ficha
  Responsabilidad: Es una de las fichas del juego Tetris. Se le puede pedir que rote en el sentido de las agujas del reloj.
  Además se le puede preguntar que elemento hay en cada casilla.
  Colaboración: Ninguna
*/

#ifndef Ficha_HH
#define Ficha_HH

using namespace std;


class Ficha
{
  private:
    int casillas[4][4];

  public:
    /**
        Construye una ficha a partir de una matriz de cuatro filas y cuatro columnas
    */
    Ficha(int casillas[4][4]);
    /**
        Retorna una ficha identica a la original pero rotada 90 grados en el sentido de las agujas del reloj.
    */
    Ficha *rotarComoReloj();
    /**
      Retorna una casilla de la matriz
    */
    int casilla(int fila, int columna);
};

#endif