#include "validar_letras.h"
#include "gotoxy.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;
/*---------------------------------------FUNCION PARA VALIDAR LETRA---------------------------------------------*/
int ValidarLetras(char Ca[N][N], int &i)
{
        int j = 0;
        char c;
        for (j = 0; j < strlen(Ca[i]); j++) //Numero de caracteres
        {
                c = Ca[i][j];
                if (isalpha(c) == 0) //Falso si el caracter no es letra
                {
                        if (isspace(c) == 0) //verdadero si tiene espacio
                        {
                                gotoxy(31, 25);
                                cout << "\x1b[41;37m* Caracter invalido * \033[0m\r";
                                system("pause>null");
                                gotoxy(31, 25);
                                cout << "\033[1m                        \033[0m";
                                return 0;
                        }
                }
        }
        return 1;
}

int ValidarLetras2(char Ca[N])
{
        int j = 0;
        char c;
        for (j = 0; j < strlen(Ca); j++) //Numero de caracteres
        {
                c = Ca[j];
                if (isalpha(c) == 0) //Falso si el caracter no es letra
                {
                        if (isspace(c) == 0) //verdadero si tiene espacio
                        {
                                gotoxy(31, 25);
                                cout << "\x1b[41;37m* Caracter invalido * \033[0m\r";
                                system("pause>null");
                                gotoxy(31, 25);
                                cout << "\033[1m                        \033[0m";
                                return 0;
                        }
                }
        }

        return 1;
} 
