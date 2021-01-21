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
#include "void_gerson/case_4.cpp"

using namespace std;

int i = 0;

int main()
{

        //interfaz(1, 20, 1, 61);
        system("mode con: cols=82 lines=30"); //dar tamaño a la pantalla
        SetConsoleTitle("CONTROL DE RECIBO DE AGUA");
        register_anual *registro_user = new register_anual[N];
        llenando(registro_user); //esta funcion llena la matriz de la estructura con ceros
        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        char Mes[N][11];
        char Numero_cuenta[N][10] = {"\0"}, anio[N][11] = {"\0"}, Dui[N][11] = {"\0"};
        int opccion;
        char opccion1[1];
        char c;
        //string meses[12] = {{"Enero"}, {"Febrero"}, {"Marzo"}, {"Abril"}, {"Mayo"}, {"Junio"}, {"Julio"}, {"Agosto"}, {"Septiembre"}, {"Octubre"}, {"Noviembre"}, {"Diciembre"}};
        char meses[12][20] = {{"Enero"}, {"Febrero"}, {"Marzo"}, {"Abril"}, {"Mayo"}, {"Junio"}, {"Julio"}, {"Agosto"}, {"Septiembre"}, {"Octubre"}, {"Noviembre"}, {"Diciembre"}};


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
                        case_4(registro_user, Nombres, Apellidos, anio, meses, Numero_cuenta, i);
                        system("cls");
                }
                break;
                case 5:
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
        } while (opccion != 5);

        getchar();
        cin.get();
}
