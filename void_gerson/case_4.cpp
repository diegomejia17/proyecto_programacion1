#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//#include "../funciones_francisco/menu_registro_usuario.cpp"
//#include "../funciones_diego/registro_recibo.cpp"
#include "../constante.h"
#include "../funciones_diego/estructura_r_r.h"
//#include "../funciones_diego/llenado.cpp"
#include "../funciones_francisco/Interfaz.h"
//#include "../funciones_Christian/pago.cpp"
#include "../funciones_francisco/gotoxy.h"

using namespace std;

void case_4(register_anual * registro_user, char Nombres[N][100], char Apellidos[N][100], char anio[N][11], char meses[12][20], char Numero_cuenta[N][10], int& i)
{
    char opc4c[2] = {"\0"};
    int opc4 = 0;
    system("cls");
    interfaz(1, 27, 1, 80);
    interfaz(2, 26, 2, 79);
    gotoxy(30, 2);
    cout << "\x1b[1;34mINFORME DE PAGOS\033[0m" << endl;

    if (anio[0][0] == 0)
    {
        gotoxy(30, 4);
        cout << "No hay datos almacenados" << endl;
    }
    else
    {
        gotoxy(5, 5);
        cout << "Seleccione el mes para ver historial de pagos/deudas" << endl;

        for (int b = 1; b < 13; b++)
        {
            gotoxy(5, 6 + b);
            cout << b << "-" << meses[b - 1] << endl;
        }

        gotoxy(5, 25);
        cout << "Mes: ";
        do
        {
            gotoxy(10, 25);
            fflush(stdin);
            gets(opc4c);
            fflush(stdin);
            opc4 = atoi(opc4c);
        } while ((opc4 >= 13) || (opc4 <= 0));

        system("cls");
        interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
        gotoxy(30, 2);
        cout << "\x1b[1;34mINFORME DE PAGOS\033[0m" << endl;
        gotoxy(36, 3);
        cout << meses[opc4 - 1] << endl;

        gotoxy(8, 4);
        cout << "Nombre(s)";
        gotoxy(25, 4);
        cout << "Apellido(s)";
        gotoxy(45, 4);
        cout << "No. Cuenta";
        gotoxy(61, 4);
        cout << "Estado Actual";

        for (int g = 0; g < i; g++)
        {
            gotoxy(8, g + 5);
            cout << Nombres[g] << endl;
            gotoxy(25, g + 5);
            cout << Apellidos[g] << endl;
            gotoxy(45, g + 5);
            cout << Numero_cuenta[g] << endl;

            if (opc4 - 1 >= 1) ///Mes de Febrero mínimo
            {
                if (registro_user[g].registro_anual[2][opc4 - 1] == 0)
                {
                    gotoxy(61, g + 5);
                    cout << "No hay consumo" << endl;
                }

                //added el else
                else if (registro_user[g].registro_anual[4][opc4 - 1] == 0 && registro_user[g].registro_anual[4][opc4 - 2] == 0)
                {
                    gotoxy(60, g + 5);
                    cout << "2 meses sin pagar" << endl;
                }
                else if (registro_user[g].registro_anual[4][opc4 - 2] == -1 && registro_user[g].registro_anual[4][opc4 - 1] == 0)
                {
                    gotoxy(63, g + 5);
                    cout << "Pendiente" << endl;
                }
                else if (registro_user[g].registro_anual[4][opc4 - 1] == 1 && registro_user[g].registro_anual[4][opc4 - 2] == 1)
                {
                    gotoxy(61, g + 5);
                    cout << "Saldo cancelado " << endl;
                }
            }
            else //en caso de ser Enero
            {

                if (registro_user[g].registro_anual[2][opc4 - 1] == 0)
                {
                    gotoxy(61, g + 5);
                    cout << "No hay consumo" << endl;
                } //added el else
                else if (registro_user[g].registro_anual[4][opc4 - 1] == 0)
                {
                    gotoxy(63, g + 5);
                    cout << "Pendiente" << endl;
                }
                else if (registro_user[g].registro_anual[4][opc4 - 1] == 1)
                {
                    gotoxy(61, g + 5);
                    cout << "Saldo cancelado" << endl;
                }
                else
                {
                    gotoxy(61, g + 5);
                    cout << "Pendiente" << endl;
                }
            } //fin de condicional dependiente del valor de g

        } //Fin for (impresion)

    } //fin else inicial

    system("pause>=null");
    system("cls");
}