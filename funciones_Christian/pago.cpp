#include <iostream>
#include <stdlib.h>
#include <strings.h> 
#include "../funciones_francisco/Interfaz.h"
#include "../funciones_francisco/gotoxy.h"
#include "../funciones_diego/colores.h"
#include <windows.h>
#include "../funciones_diego/estructura_r_r.h"
#include "../funciones_diego/validar_correlativo.h"
#include <iomanip>
///verificar
using namespace std;

void pago(char Numero_cuenta[N][10], register_anual *registro_user, int &i)
{
    char c_usuario[1];
    int posicion = 1;
    float total = 0;
    float efectivo = 0;
    char clear;
    bool exito = false;
    int s = 0;
    int vuelto = 0;
    system("cls");

    do
    {
        interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
        color(1);
        gotoxy(27, 2);
        cout << "REGISTRO DE PAGO DE AGUA" << endl;
        color(0);
        gotoxy(20, 6);
        cout << " Ingrese el numero correlativo" << endl;
        color(0);
        gotoxy(20, 14);
        cout << "presione cero si desea salir " << endl;
        gotoxy(20, 8);
        gets(c_usuario);
        if (verificar_registo_resibos(Numero_cuenta, c_usuario, posicion) == false)
        {
            color(2);
            gotoxy(20, 18);
            cout << "DATO INGRESADO INVALIDO" << endl;
            color(0);
            system("pause>null");
            system("cls");
        }
        else
        {
            exito = true;
            system("cls");
        }
        fflush(stdin);
    } while ((exito == false) && c_usuario[0] != 48);

    do
    {
        if (exito == true)
        {
            for (int j = 0; j <= 11; j++)
            {
                interfaz(1, 27, 1, 80);
                interfaz(2, 26, 2, 79);
                color(1);
                gotoxy(27, 2);
                cout << "REGISTRO DE PAGO DE AGUA" << endl;
                color(1);
                // -1 = no a pagado y 1 = ya pago
                if ((registro_user[posicion].registro_anual[4][j] == -1) && (registro_user[posicion].registro_anual[3][j] > 0))
                {
                    gotoxy(21, 5 + s);
                    cout << "Consumo de m3: " << fixed << setprecision(2) << registro_user[posicion].registro_anual[2][j] << "   costo a pagar: $" << fixed << setprecision(2) << registro_user[posicion].registro_anual[3][j];
                    total = total + registro_user[posicion].registro_anual[3][j];
                    s++;
                }
            }
            gotoxy(20, 7 + s);
            cout << "Total a cancelar: $" << total;
            gotoxy(20, 9 + s);
            cout << "Efectivo: $";
            gotoxy(20, 10 + s);
            cin >> efectivo;
            system("pause>null");
        }
        vuelto = efectivo - total;
        if ((vuelto) < 0)
        {
            s = 0;
            total = 0;
            gotoxy(31, 25);
            cout << "\x1b[41;37m* Su pago es menor a la deuda *\033[0m";
            system("pause>null");
            system("Cls");
        }

    } while ((vuelto) < 0);
            gotoxy(20, 9 + s);
            cout << "Vuelto: $" << fixed << setprecision(2) << efectivo - total;
            system("pause>null");
            for (int j = 0; j < 13; j++)
            {
                if (registro_user[posicion].registro_anual[3][j] != 0)
                {
                    registro_user[posicion].registro_anual[4][j] = (1); // 1 = ya cancelo
                }
            }
    
    return;
    system("cls");
}