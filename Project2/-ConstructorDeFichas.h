/*
  Archivo: -ConstructorDeFicha.h
  Autor: Juan Sebastian Velasquez Acevedo(1744936) - Cesar Alberto Becerra Ramirez(1744338) - Jose David Ortiz (1740634)
  Email: juan.velasquez.acevedo@correounivalle.edu.co - cesar.becerra@correounivalle.edu.co - jose.david.ortiz@correounivalle.edu.co
  Fecha creación: 2018-03-28
  Fecha última modificación: 2018-05-18
  Versión: 0.1
  Licencia: GPL
*/

/*
  Clase:  ConstructorDeFicha
  Responsabilidad: Escoge una ficha aleatoriamente y la crea.
  Esa ficha al azar puede poseer seis formas distintas, representadas en una matriz que se escoge aleatoriamente
  Entre las posibilidades están:
    Primera: Letra I
    {
      {0,1,0,0},
      {0,1,0,0},
      {0,1,0,0},
      {0,1,0,0}
    };

   Segunda: Letra O
   {
     {0,0,0,0},
     {0,2,2,0},
     {0,2,2,0},
     {0,0,0,0}
    };

   Tercera: Letra T
   {
     {0,0,0,0},
     {0,3,0,0},
     {3,3,3,0},
     {0,0,0,0}
    };

   Cuarta: Letra S
   {
     {0,0,0,0},
     {0,4,4,0},
     {4,4,0,0},
     {0,0,0,0}
    };

   Quinta: Letra L
   {
     {0,5,0,0},
     {0,5,0,0},
     {0,5,5,0},
     {0,0,0,0}
    };
    
    Sexta: Letra J
   {
     {0,6,0,0},
     {0,6,0,0},
     {6,6,0,0},
     {0,0,0,0}
    };
    
    Séptima: Letra Z
   {
     {0,0,0,0},
     {7,7,0,0},
     {0,7,7,0},
     {0,0,0,0}
    };
    
    Colaboración: Contiene una Ficha
 
*/

#ifndef ConstructorDeFichas_HH
#define ConstructorDeFichas_HH

#include <iostream>
#include "-Ficha.h"

using namespace std;

class ConstructorDeFichas
{
  private:
    int fichas [7][4][4]= {
                           {
                            //Primera: Letra I
                             {0,1,0,0},
                             {0,1,0,0},
                             {0,1,0,0},
                             {0,1,0,0}
                            },
                           
                           //Segunda: Letra O
                            {
                             {0,0,0,0},
                             {0,2,2,0},
                             {0,2,2,0},
                             {0,0,0,0}
                             },

                          //Tercera: Letra T
                            {
                              {0,0,0,0},
                              {0,3,0,0},
                              {3,3,3,0},
                              {0,0,0,0}
                            },

                          //Cuarta: Letra S
                            {
                              {0,0,0,0},
                              {0,4,4,0},
                              {4,4,0,0},
                              {0,0,0,0}
                            },

                          //Quinta: Letra L
                            {
                              {0,5,0,0},
                              {0,5,0,0},
                              {0,5,5,0},
                              {0,0,0,0}
                            },
    
                          //Sexta: Letra J
                            {
                              {0,6,0,0},
                              {0,6,0,0},
                              {6,6,0,0},
                              {0,0,0,0}
                            },
    
                          //Séptima: Letra Z
                            {
                              {0,0,0,0},
                              {7,7,0,0},
                              {0,7,7,0},
                              {0,0,0,0}
                            }
    };
  public:
    ConstructorDeFichas();
    Ficha *dameUnaFicha(int cual=-1); //en el cpp, si el cual es menor a 0 o mayor a 6, se le da la ficha al azar, sino se escoge la ficha dependiendo del cual, en el array
  
};

#endif