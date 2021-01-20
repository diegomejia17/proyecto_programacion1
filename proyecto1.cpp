#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "./funciones_francisco/menu_registro_usuario.cpp"
#include "funciones_diego/registro_recibo.cpp"
#include "constante.h"
#include "funciones_diego/estructura_r_r.h"
#include "funciones_diego/llenado.cpp"
#include "funciones_francisco/Interfaz.h"
#include "funciones_Christian/pago.cpp"

using namespace std;

int i = 0;

int main()
{

        //interfaz(1, 20, 1, 61);
        system("mode con: cols=82 lines=30"); //dar tamaño a la pantalla//dar tamaño a la pantalla
        SetConsoleTitle("CONTROL DE RECIBO DE AGUA");
        register_anual *registro_user = new register_anual[N];
        llenando(registro_user); //esta funcion llena la matriz de la estructura con ceros
        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        char Mes[N][11];
        char Numero_cuenta[N][10] = {"\0"}, anio[N][11] = {"\0"}, Dui[N][11] = {"\0"};
        int opccion;
        char opccion1[1];
        char c;
        string meses[12] = {{"Enero"}, {"Febrero"}, {"Marzo"}, {"Abril"}, {"Mayo"}, {"Junio"}, {"Julio"}, {"Agosto"}, {"Septiembre"}, {"Octubre"}, {"Noviembre"}, {"Diciembre"}};
        int anio_system = 2021;

        do
        {

                do
                {
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(27, 2);
                        cout << "\x1b[1;34mCONTROL DE RECIBO DE AGUA\033[0m" << endl;
                        gotoxy(5, 6);
                        cout << "1: Registro de usuario" << endl;
                        gotoxy(5, 8);
                        cout << "2: Registro de consumo de agua mensual" << endl;
                        gotoxy(5, 10);
                        cout << "3: Registro de pago de recibo de agua" << endl;
                        gotoxy(5, 12);
                        cout << "4: Informe de pago de usuarios" << endl;
                        gotoxy(5, 14);
                        cout << "5: salir" << endl;
                        gotoxy(23, 20);
                        cout << "\x1b[36m* Seleccione una opcion:\033[0m ";
                        gets(opccion1);
                        c = opccion1[0];
                        opccion = atoi(opccion1); //pasar de char a int
                        if (((isdigit(c)) == 0) || (opccion >= 6) || (opccion <= 0))
                        {
                                gotoxy(31, 25);
                                cout << "\x1b[41;37m* Opccion incorrecta *\033[0m";
                                system("pause>null");
                        }
                        system("Cls");
                } while ((isdigit(c)) == 0); //reciba solo numeros
                switch (opccion)
                {

                case 1:
                {
                        Menu_Registros_usuarios(Nombres, Apellidos, Dui, Numero_cuenta, anio, i, Mes, registro_user); //agregar modificar y eliminar los usuarios
                        system("Cls");
                }
                break;
                case 2:
                {
                        registro_resibos(Numero_cuenta, registro_user, Nombres, Mes);
                        system("Cls");
                }
                break;
                case 3:
                {
                        pago(Numero_cuenta, registro_user, i);
                        system("Cls");
                }
                break;
                case 4:
                {

                        char opc4c[2];
                        int opc4;
                        system("cls");
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(30, 2);
                        cout << "\x1b[1;34mINFORME DE PAGOS\033[0m" << endl;
                        interfaz(14, 17, 49, 62);

                        if (anio[0][0] == 0)
                        {
                                gotoxy(30, 4);
                                cout << "No hay datos almacenados" << endl;
                        }
                        else
                        {

                                gotoxy(39, 4);
                                cout << anio_system << endl;
                                gotoxy(5, 5);
                                cout << "Seleccione el mes para ver historial de pagos/deudas" << endl;

                                for (int b = 0; b < 12; b++)
                                {
                                        gotoxy(5, 6 + b);
                                        cout << b + 1 << "-" << meses[b] << endl;
                                }

                                gotoxy(5, 25);
                                cout << "Mes: ";
                                do
                                {
                                        gotoxy(10, 25);
                                        gets(opc4c);
                                        opc4 = atoi(opc4c);
                                } while ((opc4 >= 13) || (opc4 <= 0));

                                system("cls");
                                interfaz(1, 27, 1, 80);
                                interfaz(2, 26, 2, 79);
                                gotoxy(30, 2);
                                cout << "\x1b[1;34mINFORME DE PAGOS\033[0m" << endl;
                                interfaz(14, 17, 49, 62);
                                gotoxy(33, 3);
                                cout << meses[opc4 - 1] << endl;
                                gotoxy(45, 3);
                                cout << anio_system << endl;

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

                                        if (opc4 - 1 >= 1)
                                        { //si g>=1

                                                if (registro_user[g].registro_anual[4][opc4 - 1] == 0 && registro_user[g].registro_anual[4][opc4 - 2] == 0)
                                                {
                                                        gotoxy(63, g + 5);
                                                        cout << "2 meses sin pagar" << endl; //en rojo
                                                }
                                                else if ((registro_user[g].registro_anual[4][opc4 - 2] == 0 && registro_user[g].registro_anual[4][opc4 - 1] == 1) || (registro_user[g].registro_anual[4][opc4 - 2] == 0))
                                                {
                                                        gotoxy(63, g + 5);
                                                        cout << "1 mes sin pagar" << endl; //en amarillo
                                                }
                                                else if (registro_user[g].registro_anual[4][opc4 - 2] == 1 && registro_user[g].registro_anual[4][opc4 - 1] == 0)
                                                {
                                                        gotoxy(63, g + 5);
                                                        cout << "Pendienteeeee" << endl; //verde
                                                }
                                                else if (registro_user[g].registro_anual[4][opc4 - 1] == 1 && registro_user[g].registro_anual[4][opc4 - 2] == 1)
                                                { /////////////////////////////////////////////////////////////////7
                                                        gotoxy(63, g + 5);
                                                        cout << "Saldo canceladooooo " << registro_user[g].registro_anual[4][opc4 - 1] << endl; //verde////////////////////////////////////////////////////////////77/77
                                                }
                                        }
                                        else
                                        { //si g==0
                                                if (registro_user[g].registro_anual[4][opc4 - 1] == 0)
                                                {
                                                        gotoxy(63, g + 5);
                                                        cout << "Pendiente" << endl; //verde
                                                }
                                                if (registro_user[g].registro_anual[4][opc4 - 1] == 1)
                                                {
                                                        gotoxy(63, g + 5);
                                                        cout << "Saldo cancelado" << endl; //verde
                                                }
                                        } //fin de condicional dependiente del valor de g

                                } //Fin for (impresion)

                        } //fin else inicial

                        for (int h = 0; h < 20; h++)
                        {
                                for (int i = 0; i < 3; i++)
                                {
                                        for (int j = 0; j < 12; j++)
                                        {
                                                gotoxy(3, 25);
                                                cout << registro_user[h].registro_anual[i][j];
                                        }
                                        cout << "\n"
                                             << endl;
                                }
                        }

                        system("pause>=null");
                        system("cls");
                }
                break;                case 5:
                {
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(27, 2);
                        cout << "\x1b[1;34mCONTROL DE RECIBO DE AGUA\033[0m" << endl;
                        interfaz(14, 17, 49, 62);
                        gotoxy(31, 16);
                        cout << "Vuelva pronto!!";
                }
                break;
                }

                //
        } while (opccion != 5);

        getchar();
        cin.get();
}
