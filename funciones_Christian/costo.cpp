#include <iostream>
using namespace std;

int costo(float consumo_mensual)
{

    float tax = consumo_mensual; //consumo de agua mensual
    float taxAl = 0;             //tarifa de acantarillado
    float taxAC = 0;             //tarifa de acuaducto
    float total = 0;             //total a pagar

    if (tax >= 0.00 && tax <= 10.00)
    {
        taxAl = 0.10;
        taxAC = 2.29;
    }
    else if (tax > 10.00 && tax <= 20.3)
    {
        taxAl = 5.0 + 0.10;
        taxAC = 0.21 + 2.29;
    }
    else if (tax > 20.30 && tax <= 30.00)
    {
        taxAl = 1.80 + 0.10;
        if (tax > 20 && tax < 22)
        {
            taxAC = 2.29 + 0.25;
        }
        else if (tax >= 22.00 && tax < 23)
        {
            taxAC = 2.29 + 0.28;
        }
        else if (tax >= 23.00 && tax > 24.00)
        {
            taxAC = 0.31 + 2.29;
        }
        else if (tax >= 24 && tax < 25)
        {
            taxAC = 2.29 + 0.34;
        }
        else
        {
            taxAC = 2.29 + 0.37;
        }
    }
    else if (tax > 30 && tax <= 40)
    {
        taxAl = 0.10 + 3.00;
        if (tax > 30 && tax <= 31)
        {
            taxAC = 2.29 + 0.42;
        }
        else if (tax > 31 && tax <= 32)
        {
            taxAC = 2.29 + 0.48;
        }
        else if (tax > 32 && tax <= 33)
        {
            taxAC = 2.29 + 0.54;
        }
        else if (tax > 33 && tax <= 34)
        {
            taxAC = 2.29 + 0.64;
        }
        else if (tax > 34 && tax <= 40)
        {
            taxAC = 2.29 + 0.76;
        }
    }
    else if (tax > 40 && tax <= 50)
    {
        taxAl = 0.10 + 4.00;
        if (tax < 40 && tax <= 41)
        {
            taxAC = 2.29 + 0.90;
        }
        else if (tax < 41 && tax <= 42)
        {
            taxAC = 2.29 + 1.05;
        }
        else if (tax > 42 && tax <= 43)
        {
            taxAC = 2.29 + 1.20;
        }
        else if (tax > 43 && tax <= 44)
        {
            taxAC = 2.29 + 1.40;
        }
        else if (tax > 44 && tax <= 50)
        {
            taxAC = 2.29 + 1.65;
        }
    }
    else if (tax > 50 && tax <= 100)
    {
        taxAl = 7.50 + 0.10;
        if (tax > 50 && tax >= 60)
        {
            taxAC = 2.29 + 1.90;
        }
        else if (tax > 60 && tax <= 70)
        {
            taxAC = 2.29 + 2.20;
        }
        else if (tax > 70 && tax <= 90)
        {
            taxAC = 2.29 + 2.50;
        }
        else if (tax > 90 && tax <= 100)
        {
            taxAC = 2.29 + 2.90;
        }
    }
    else if (tax > 100 && tax <= 500)
    {
        taxAl = 0.10 + 10.00;
        taxAC = 2.29 + 3.40;
    }
    else if (tax > 500)
    {
        taxAl = 0.10 + 20.00;
        taxAC = 2.29 + 3.90;
    }
    return total = (tax * taxAC) + taxAl;
    system("pause>null");
}