#include "validar_letras.h"
#include "gotoxy.h"
#include <string.h>

using namespace std;

/*---------------------------------------FUNCION PARA VALIDAR LETRA---------------------------------------------*/
int ValidarLetras(char Ca[N][N], int i)      
        {
                int j = 0;
                char c;
                for (j = 0; j < strlen(Ca[i]); j++)//Numero de caracteres
                        {
                                c=Ca[i][j];
                                if(isalpha (c) == 0)//Falso si el caracter no es letra
                                        {
                                                if (isspace(c) == 0)//verdadero si tiene espacio
                                                        {
                                                                return 0;
                                                        }
                                        }
                        }
        }
