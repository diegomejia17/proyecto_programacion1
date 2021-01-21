#include "editar.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "../funciones_francisco/validar_letras.h"
#include "./validarN.cpp"
#include "../funciones_francisco/validar_dui.h"
#include "./imprimir.h"
#include "clearP.h"
#include "../funciones_diego/validar_correlativo.h"
#include "../funciones_francisco/numero_correlativo.h"
using namespace std;

void editar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int& i)
{
    int posicion = 0;
    char name_aux[100],dui_aux[11] = {"\0"},Pcorrelativo[10]  = {"\0"},anio_aux[11]  = {"\0"};
    //variables auxiliares 
    bool exito = false;
    char clear;
   
    do
    //se verifica que el numero correlativo que se esta ingresando coincida con uno existente
    {
         interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
        gotoxy(27,2);cout<<"\x1b[1;34mMODIFICAR REGISTRO DE USUARIO\033[0m"<<endl;
        gotoxy(5,6);imprimir("ingrese el correlativo: ");
        gotoxy(20, 14);
        cout << "presione cero si desea salir " << endl;
        gotoxy(5,8);cin >> Pcorrelativo;
        clear = cin.get();
        fflush (stdin);
        if (verificar_registo_resibos(Numero_cuenta,Pcorrelativo,posicion) == false && Pcorrelativo[0] != 48)
        {
            gotoxy(13,16);cout<<"\033[1m                                                        \033[0m";
            gotoxy(31,25);imprimir( "\x1b[41;37m* DATO INGRESADO INCORRECTO * \033[0m");
            limpiar();

        }
        else
        {
            exito = true;
            limpiar();
        }
        

    } while (exito == false);
    if (Pcorrelativo[0]== 48) return;
    exito =  false;
    int op;
    char menu[1];
    

    do
    {
        interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
        gotoxy(27,2);cout<<"\x1b[1;34mMODIFICAR REGISTRO DE USUARIO\033[0m"<<posicion<<endl;
        gotoxy(5,6);imprimir("Seleccione una opcion: ");
        gotoxy(5,8);imprimir("1.  cambiar nombres.");
        gotoxy(5,10);imprimir("2.  cambiar apellidos.");
        gotoxy(5,12);imprimir("3.  cambiar numero de dui.");
        gotoxy(5,14);imprimir("0.  Salir.");

        gotoxy(5,16);cin >> menu;
        fflush(stdin);
        op = atoi(menu);
        
        switch (op)
        {
        case 0:
        limpiar();
            return;
            break;
        case 1:
            do
            //ciclo que evalua el cambio del nombre.
            {
                limpiar();
                interfaz(1, 27, 1, 80);
                interfaz(2, 26, 2, 79);
                gotoxy(27,2);cout<<"\x1b[1;34mMODIFICANDO NOMBRE DEL USUARIO\033[0m"<<endl;
                gotoxy(5,6);cout << "el nombre anterior es: \x1b[1;34m" << Nombres[posicion] << endl;
                gotoxy(5,8);cout << "\033[0mdigite el nuevo nombre:  \x1b[1;34m";
                gotoxy(30,8);cin.getline(name_aux, 100, '\n');
                
                fflush(stdin);
            } while (!ValidarLetras2(name_aux));
            interfaz(14, 17, 49, 62);
            strcpy( Nombres[posicion],name_aux); //copia a la matriz principal la modificacion del nombre..
            Ortografia(Nombres, posicion);
            gotoxy(20,16);imprimir("\033[32mnombre sustituido con exito\033[0m");
            limpiar();
            break;

        case 2:
            do
            //ciclo que evalua el cambio del apellido.
            {
                limpiar();
                interfaz(1, 27, 1, 80);
                interfaz(2, 26, 2, 79);
                gotoxy(27,2);cout<<"\x1b[1;34mMODIFICANDO APELLIDO DEL USUARIO \033[0m"<<posicion<<endl;
                 gotoxy(5,6);cout << "los apellidos anteriores son: \x1b[1;34m" << Apellidos[posicion] << endl;
                 gotoxy(5,8);cout << "\033[0mdigite el nuevo apellido:  \x1b[1;34m";
                gotoxy(31,8);cin.getline(name_aux, 100, '\n');
                fflush(stdin);

            } while (!ValidarLetras2(name_aux));
            interfaz(14, 17, 49, 62);
            strcpy( Apellidos[posicion], name_aux); //copia a la matriz principal la modificacion del apellido..
            Ortografia(Apellidos, posicion);
            gotoxy(20,16);imprimir("\033[32mapellido sustituido con exito\033[0m");
            limpiar();
            break;

        case 3:

            do
            //ciclo que evalua el cambio del dui
            {
                limpiar();
                interfaz(1, 27, 1, 80);
                interfaz(2, 26, 2, 79);
                gotoxy(27,2);cout<<"\x1b[1;34mMODIFICANDO DUI DEL USUARIO\033[0m"<<endl;
                 gotoxy(5,6);cout << "el numero de dui anterior es: \x1b[1;34m" << Dui[posicion] << endl;
                gotoxy(5,8);imprimirS("\033[0mingrese el nuevo numero: \x1b[1;34m");
                gotoxy(30,8);cin>> dui_aux;
                clear = cin.get();
                if(strlen(dui_aux) <9 || strlen(dui_aux) >9)
                    {
                        gotoxy(20,25);cout<<"\x1b[41;37m* Debe de ingresar 9 digitos * \033[0m"<<endl; 
                        system("pause>null");
                        gotoxy(20,25);cout<<"\033[1m                                       \033[0m";
                    }
                fflush(stdin);
            } while (validarNumeros2(dui_aux) == 0 || validar_dui2(Dui, i, dui_aux) == false  || strlen(dui_aux) < 9 || strlen(dui_aux) > 9);
            interfaz(14, 17, 49, 62); 
            fflush(stdin);   
            /*
            strcpy(Dui[posicion],"\0");
            strncat(Dui[posicion],dui_aux,8);
            strcat(Dui[posicion],"-");
            strrev(dui_aux);
            strncat(Dui[posicion],dui_aux,1);*/
            strcpy(Dui[posicion],dui_aux);
            fflush(stdin);

            //strcpy( Dui[posicion],dui_aux); //copia a la matriz principal la modificacion del dui..
            gotoxy(20,16);imprimir("\033[32mDui sustituido con exito\033[0m");
            limpiar();
            break;

        default:
            limpiar();
            break;
        }

    } while (isdigit(menu[0]) == 0 || op != 0); 


}