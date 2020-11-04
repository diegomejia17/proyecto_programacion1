#include "gotoxy.h"
void gotoxy(int x, int y)//para posicionamiento de las impresiones
    {//esta funcion permite el posicionamiento del curso x, y
        HANDLE hcon;
        hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hcon,dwPos);
    }
