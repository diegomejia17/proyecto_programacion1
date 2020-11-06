
#include <string.h>
#include <iostream>
using namespace std;
/*---------------------------------------FUNCION PARA VALIDAR NUMERO---------------------------------------------*/
int Validarmenu(char Nu[2])//a la funcion se le debe pasar el array que contiene el numero, y el numero de posiciones que se debe evaluar
        {
                char c1 ;
                for (int  i1 = 0; i1 < 1; i1++)
                {
                        c1=Nu[i1];
                        if(isdigit (c1) == 0)//Falso si el caracter no es letra
                                {
                                        return 0;
                                }    
                }
        }
