
#include "gotoxy.h"
#include <string.h>
#include <iostream>

using namespace std;
int validar_dui(char Dui[100][11], int& i)
    {
        int dui;
        dui = atoi(Dui[i]);
        for(int j=0; j < i; j++)
            {
                int aux = atoi(Dui[j]);
                if(aux != dui)
                    {
                        aux = atoi(Dui[j+1]);
                    }else{
                                gotoxy(20,25);cout<<"\x1b[41;37m* El Dui ya existe *\033[0m";
                                system("pause>null");
                                return 0;
                        }
           }
        return -1;
    }