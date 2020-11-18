#include "validar_numeros.h"
#include <string.h>
 const  int P = 100;
using namespace std;
/*---------------------------------------FUNCION PARA VALIDAR NUMERO---------------------------------------------*/
int ValidarNumeros(char Nu[P][11], int i)
        {
                int j = 0;
                char c ;
                for (j = 0; j < strlen(Nu[i]); j++)//Numero de caracteres
                        {
                                c=Nu[i][j];
                                if(isdigit (c) == 0)//Falso si el caracter no es letra
                                        {
                                                gotoxy(22,25);cout<<"\x1b[41;37m* El caracter no es valido *\033[0m"<<endl;
                                                return 0;
                                        }
                        }
        }