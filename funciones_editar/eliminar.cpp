#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include "eliminar.h"
#include "./imprimir.h"
#include "clearP.h"
#include "../funciones_diego/validar_correlativo.h"
#include "../funciones_diego/estructura_r_r.h"
#include "../funciones_francisco/Interfaz.h"


void eliminar (char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int& i,register_anual * registro_user, char Mes[N][11])
{
    

    int posicion = 0;
    char Pcorrelativo[10] = {"\0"};
    bool exito = false;
    char clear;
    do
    //se verifica que el numero correlativo que se esta ingresando coincida con uno existente
    {
        interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
        gotoxy(27,2);cout<<"\x1b[1;34mELIMINAR REGISTRO DE USUARIO\033[0m"<<endl;
        gotoxy(5,6);cout<<"Ingresa el correlativo: "<<endl;
        gotoxy(20, 14);
		cout << "presione cero si desea salir " << endl;
        gotoxy(5,8);cin >> Pcorrelativo;
        clear = cin.get();
        fflush (stdin);
        
        if (verificar_registo_resibos(Numero_cuenta,Pcorrelativo,posicion) == false && Pcorrelativo[0] != 48)
        {
            gotoxy(31,25);imprimir("\x1b[41;37m* DATO INGRESADO INCORRECTO *\033[0m");
            system("pause>null"); 
            limpiar();
        }
        else
        {
            exito = true;
        }
        

    } while (exito == false);
    if (Pcorrelativo[0]== 48) return;

    //validacion para eliminar 
    char confirmar[1];
    
    do
    {
        interfaz(14, 17, 49, 62);
        gotoxy(13,16);
        imprimir("\x1b[1;34m desea eliminar su cuenta? 's' = si y 'n' = no: \033[0m");
        gotoxy(61,16);cin >> confirmar;

        if (confirmar[0] == 115)
        {
            exito = true;
            gotoxy(13,16);cout<<"\033[1m                                                               \033[0m";
            gotoxy(20,16);imprimir("\033[32m El Usuario se a eliminado exitosamente: \033[0m");
        }

        else if (confirmar[0] == 110)
        {
            exito = false;
            limpiar();
            return;
        }
        if (confirmar[0] != 115 && confirmar[0]!= 110 )
        {
            gotoxy(13,16);cout<<"\033[1m                                                        \033[0m";
            gotoxy(31,25);imprimir("\x1b[41;37m* DATO INGRESADO INCORRECTO *\033[0m"); 
        }

    } while (confirmar[0] != 115 && confirmar[0]!= 110 );
    limpiar();

  for (int a = posicion; a < i; a++)
    {
       strcpy(Nombres[a],Nombres[a+1]);
       strcpy(Apellidos[a],Apellidos[a+1]);
       strcpy(Dui[a],Dui[a+1]);
       strcpy(anio[a],anio[a+1]);
       strcpy(Numero_cuenta[a],Numero_cuenta[a+1]);
       strcpy(Mes[a],Mes[a+1]);
      registro_user[a].registro_anual[1][0] = 2;
      registro_user[a].registro_anual[2][0] = 2;
      registro_user[a].registro_anual[3][0] = 2;
      registro_user[a].registro_anual[4][0] = 2;
    }
       
}
