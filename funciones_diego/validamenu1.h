#include <string.h>
#include <iostream>
using namespace std;
/*---------------------------------------FUNCION PARA VALIDAR NUMERO---------------------------------------------*/
int Validarmenu1(char Nu[2])//a la funcion se le debe pasar el array que contiene el numero, y el numero de posiciones que se debe evaluar
        {
                char c ;
                for (int  i = 0; i < 1; i++)
                {
                        c=Nu[i];
                        if(isdigit (c) == 0)//Falso si el caracter no es letra
                                {
                                        return 0;
                                }    
                }
        }
