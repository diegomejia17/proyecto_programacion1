#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "validarN.h"
#include "../funciones_francisco/gotoxy.h"
using namespace std;


int validarNumeros2(char Nu[11])
{
    int j = 0;
    char c;
    for (j = 0; j < strlen(Nu); j++) //Numero de caracteres
    {
        c = Nu[j];
        if (isdigit(c) == 0) //Falso si el caracter no es letra
        {
            gotoxy(22, 25);
            cout << "\x1b[41;37m* El caracter no es valido *\033[0m" << endl;
            system("pause>null");
            gotoxy(22, 25);
            cout << "\033[1m                                              \033[0m";
            return 0;
        }
    }
}
