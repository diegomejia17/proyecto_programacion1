#include "nuevo_usuario.h"
#include <iostream>
#include "validar_letras.cpp"
#include "validar_numeros.cpp"
#include "ortografia.cpp"
#include "interfaz.cpp"
#include "validar_dui.cpp"
using namespace std;
/*---------------------------------------FUNCION PARA CREAR UN NUEVO USUARIO---------------------------------------------*/
void Guardar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int &i, char Mes[N][11])
{
        int mes;
        //agregar usuarios maximo 100
        interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
        gotoxy(28, 2);
        cout << "D A T O S  P E R S O N A L E S" << endl;
        do
        {
                gotoxy(5, 4);
                cout << "\033[1m                \033[0m";
                gotoxy(5, 4);
                cout << "Nombre: ";
                gets(Nombres[i]);
                fflush(stdin);
                Ortografia(Nombres, i);
        } while (ValidarLetras(Nombres, i) == false);

        do
        {
                gotoxy(5, 6);
                cout << "\033[1m                                    \033[0m";
                gotoxy(5, 6);
                cout << "Apellido: ";
                gets(Apellidos[i]);
                Ortografia(Apellidos, i);
        } while (ValidarLetras(Apellidos, i) == false);
        do
        {
                gotoxy(5, 8);
                cout << "\033[1m                                      \033[0m";
                gotoxy(5, 8);
                cout << "Anio de asociado: ";
                gets(anio[i]);
                fflush(stdin);

                if (strlen(anio[i]) < 4 || strlen(anio[i]) > 4)
                {
                        gotoxy(20, 25);
                        cout << "\x1b[41;37m* Debe de ingresar 4 digitos *\033[0m" << endl;
                        system("pause>null");
                        gotoxy(20, 25);
                        cout << "\033[1m                                        \033[0m";
                }
        } while (ValidarNumeros(anio, i) == false || (strlen(anio[i]) < 4 || strlen(anio[i]) > 4));

        do
        {
                gotoxy(5, 10);
                cout << "\033[1m                                      \033[0m";
                gotoxy(5, 10);
                cout << "\x1b[1;34m1. Enero: ";
                gotoxy(5, 11);
                cout << "2. Febrero: ";
                gotoxy(5, 12);
                cout << "3. Marzo: ";
                gotoxy(20, 10);
                cout << "4. Abril: ";
                gotoxy(20, 11);
                cout << "5. Mayo: ";
                gotoxy(20, 12);
                cout << "6. Junio: ";
                gotoxy(40, 10);
                cout << "7. Julio: ";
                gotoxy(40, 11);
                cout << "8. Agosto: ";
                gotoxy(40, 12);
                cout << "9. Septiembre: ";
                gotoxy(60, 10);
                cout << "10. Octubre: ";
                gotoxy(60, 11);
                cout << "11. Noviembre: ";
                gotoxy(60, 12);
                cout << "12. Diciembre: \033[0m";
                gotoxy(5, 14);
                cout << "\033[1m                                                                    \033[0m";
                gotoxy(5, 14);
                cout << "Elige el numero que corresponde a el mes: ";
                
                fflush(stdin);
                gets(Mes[i]);
                mes = atoi(Mes[i]); //de caracter a entero 
                fflush(stdin);
                if ((strlen(Mes[i]) < 0 || strlen(Mes[i]) > 3))
                {
                        gotoxy(20, 25);
                        cout << "\x1b[41;37m* Debe de ingresar 1 o 2 digitos *\033[0m" << endl;
                        system("pause>null");
                        gotoxy(20, 25);
                        cout << "\033[1m                                        \033[0m";
                }
                if (mes <= 0 || mes >= 13)
                {
                        gotoxy(20, 25);
                        cout << "\x1b[41;37m* Debe de ingresar numeros entre 1 y 12 *\033[0m" << endl;
                        system("pause>null");
                        gotoxy(20, 25);
                        cout << "\033[1m                                                     \033[0m";
                } else {
                 mes = mes;
                }
        } while ((ValidarNumeros(Mes, i) == false || (strlen(Mes[i]) < 0 || strlen(Mes[i]) > 3)) || (mes <= 0 || mes >= 13));

        do
        {
                gotoxy(5, 16);
                cout << "\033[1m                                                  \033[0m";
                gotoxy(5, 16);
                cout << "Numero de DUI: ";
                gets(Dui[i]);
                if (strlen(Dui[i]) < 9 || strlen(Dui[i]) > 9)
                {
                        gotoxy(20, 25);
                        cout << "\x1b[41;37m* Debe de ingresar 9 digitos * \033[0m" << endl;
                        system("pause>null");
                        gotoxy(20, 25);
                        cout << "\033[1m                                       \033[0m";
                }
        } while ((ValidarNumeros(Dui, i) == false) || (strlen(Dui[i]) < 9 || strlen(Dui[i]) > 9) || (validar_dui(Dui, i) == 0));
        
        /*
        char Dui1[1];
        strcpy(Dui1,Dui[i]);
        strcpy(Dui[i],"\0");
        strncat(Dui[i],Dui1,8);
        strcat(Dui[i],"-");
        strrev(Dui1);
        strncat(Dui[i],Dui1,1);*/
        system("Cls");
}
