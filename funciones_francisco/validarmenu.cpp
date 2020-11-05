#include "../constante.h"
#include <string.h>
#include <iostream>

using namespace std;

/*---------------------------------------FUNCION PARA VALIDAR NUMERO---------------------------------------------*/
  bool Validarmenu (char Nu[N]  , int tamanio)//a la funcion se le debe pasar el array que contiene el numero, y el numero de posiciones que se debe evaluar
        {
                char c ;
                for (int  i = 0; i < tamanio; i++)
                {
                        c=Nu[i];
                        if(isdigit (c) == 0)//Falso si el caracter no es letra
                                {
                                        return false;
                                }    
                }
        }
