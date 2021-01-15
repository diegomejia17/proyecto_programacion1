#include "validar_numeros.h"
#include "../constante.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
 

int ValidarNumeros(char Nu[N][11], int& i)
        {
                int j = 0;
                char c ;
                for (j = 0; j < strlen(Nu[i]); j++)//Numero de caracteres
                        {
                                c=Nu[i][j];
                                if(isdigit (c) == 0)//Falso si el caracter no es letra
                                        {
                                                gotoxy(22,25);cout<<"\x1b[41;37m* El caracter no es valido *\033[0m"<<endl;
                                                system("pause>null");
                                                gotoxy(22,25);cout<<"\033[1m                                              \033[0m";
                                                return 0;
                                        }
                        }
        }

