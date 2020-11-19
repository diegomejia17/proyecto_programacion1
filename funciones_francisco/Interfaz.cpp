#include "gotoxy.h"
#include<iostream>
#include "Interfaz.h"
using namespace std;
void interfaz(int x1,int x2, int y1, int y2)
        {
                for(int j = x1; j < y2; j++)
                       {
                                gotoxy(j,x1);cout << "\033[32m_\033[0m";
                                gotoxy(j,x2);cout << "\033[32m_\033[0m";
                       }
                for(int k = y1+1; k < x2+1; k++)
                       {
                                gotoxy(y1,k);cout << "\033[32m|\033[0m";
                                gotoxy(y2,k);cout << "\033[32m|\033[0m";
                       }
        }