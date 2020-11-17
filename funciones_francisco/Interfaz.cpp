#include "gotoxy.h"
#include<iostream>
void interfaz(int x1,int x2, int y1, int y2)
        {
                for(int j = x1; j < y2; j++)
                       {
                                gotoxy(j,x1);cout << "_";
                                        for(int k = y1+1; k < x2+1; k++)
                                               {
                                                        gotoxy(y1,k);cout << "|";
                                                        gotoxy(y2,k);cout << "|";
                                               }
                                gotoxy(j,x2);cout << "_";
                       }
        }