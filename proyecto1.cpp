#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include "funciones_francisco/gotoxy.h"
#include "funciones_francisco/menu_registro_usuario.h"





using namespace std;

int main()
    {
        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        char  Numero_cuenta[N][10] = {"\0"}, anio[N][11] = {"\0"}, Dui[N][11] = {"\0"};
        int  i= 0;
        int opccion;

        do{
        cout<<"CONTROL DE RECIBO DE AGUA"<<endl;
        cout<<"1: Registro de usuario"<<endl;
        cout<<"2: Registro de consumo de agua mensual"<<endl;
        cout<<"3: Registro de pago de recibo de agua"<<endl;
        cout<<"4: Informe de pago de usuarios"<<endl;
        cout<<"5: salir"<<endl;
        cin>>opccion;
        system("Cls");

        
            switch(opccion)
                {

                        case 1: 
                                {
                                        Menu_Registros_usuarios(Nombres, Apellidos, Dui, Numero_cuenta, anio, i);//agregar modificar y eliminar los usuarios
                                        system("Cls");
                                } break;
                        case 2: 
                                {

                                }break;
                        case 3:
                                {
									
                                }break;
                        case 4:
                                {

                                }break;
                        default:
                                {

                                }break;

                }        
            }while(opccion > 0);
            


        getchar();
        cin.get();
    }
//Funciones de Diego Mejia


//funciones de Javier Ayala




