#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "funciones_francisco/menu_registro_usuario.cpp"
#include "funciones_diego/registro_recibo.cpp"
#include "constante.h"
#include "funciones_diego/estructura_r_r.h"
#include "funciones_diego/llenado.cpp"
#include "funciones_francisco/Interfaz.h"



using namespace std;


int main()
    {
            
            //interfaz(1, 20, 1, 61);
           // system("mode con: cols = 500 lines = 100");//dar tamaño a la pantalla
        SetConsoleTitle("CONTROL DE RECIBO DE AGUA");
        register_anual * registro_user = new register_anual[N];
        llenando(registro_user);   //esta funcion llena la matriz de la estructura con ceros

        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        char  Numero_cuenta[N][10] = {"\0"}, anio[N][11] = {"\0"}, Dui[N][11] = {"\0"};
        int  i= 0;
        int opccion;
        char opccion1[1];
        char c;

        do{
                do{
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(25,2);cout<<"CONTROL DE RECIBO DE AGUA"<<endl;
                        gotoxy(5,4);cout<<"1: Registro de usuario"<<endl;
                        gotoxy(5,6);cout<<"2: Registro de consumo de agua mensual"<<endl;
                        gotoxy(5,8);cout<<"3: Registro de pago de recibo de agua"<<endl;
                        gotoxy(5,10);cout<<"4: Informe de pago de usuarios"<<endl;
                        gotoxy(5,12);cout<<"5: salir"<<endl;
                        gotoxy(17,16);cout<<"Seleccione una opcion: ";
                        gets(opccion1);
                        
                        system("Cls");
                        c=opccion1[0];
                }while((isdigit (c)) == 0);//reciba solo numeros
                opccion = atoi(opccion1);//pasar de char a int
            switch(opccion)
                {

                        case 1: 
                                {
                                        Menu_Registros_usuarios(Nombres, Apellidos, Dui, Numero_cuenta, anio, i);//agregar modificar y eliminar los usuarios
                                        system("Cls");
                                } break;
                        case 2: 
                                {
                                        registro_resibos(Numero_cuenta,registro_user,Nombres);
                                }break;
                        case 3:
                                {
									
                                }break;
                        case 4:
                                {

                                }break;
                        default:
                                {
                                    cout<<"Vuelva pronto!!"<<endl;    
                                }break;

                }        
            }while(opccion != 5);
            


        getchar();
        cin.get();
    }







