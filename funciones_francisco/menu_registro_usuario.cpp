#include <windows.h>
#include<string.h>
#include "nuevo_usuario.cpp"
#include "menu_registro_usuario.h"
#include "numero_correlativo.cpp"
#include "editar_cuenta.cpp"
using namespace std;
/*---------------------------------------FUNCION MENU DE REGISTROS DE LOS USUARIOS---------------------------------------------*/
void Menu_Registros_usuarios(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int i)//funcion para agregar modificar y eliminar los usuarios

    { 
            int Opc_Registro;
            char Opc[1];
            char c;
            do{
                do{
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(30,2);cout<<"\x1b[1;34mR E G I S T R O S\033[0m"<<endl;
                        gotoxy(5,6);cout<<"1: Nueva cuenta"<<endl;
                        gotoxy(5,8);cout<<"2: Editar cuenta"<<endl;
                        gotoxy(5,10);cout<<"3: Eliminar cuenta"<<endl;
                        gotoxy(5,12);cout<<"4: Menu principal"<<endl;
                        gotoxy(23,16);cout<<"\x1b[36mSeleccione una opcion:\033[0m ";
                        gets(Opc);
                        c = Opc[0];
                        int opccion;
                        opccion = atoi(Opc);
                        if(((isdigit (c)) == 0) || (opccion >= 5) || (opccion <= 0))
                                {
                                        gotoxy(31,25);cout<<"\x1b[41;37m* Opccion incorrecta *\033[0m";
                                        system("pause>null");  
                                }
                        system("Cls");
                }while ( isdigit (c) == 0);//reciba solo numeros
                Opc_Registro = atoi(Opc);//pasar de char a int
                switch(Opc_Registro)
                        {
                                case 1: 
                                        {                                                    
                                                //agregar un nuevo usuarios
                                                Guardar(Nombres, Apellidos, Dui, Numero_cuenta, anio, i);
                                                Numero_correlativo(Numero_cuenta , anio, i);
                                                i++;
                                        }break;
                                case 2: 
                                        {
                                                //editar usuarios NOTA: lo que esta dentro de esta funcio lo hice para probar
                                                Editar(Nombres, Apellidos, Dui, Numero_cuenta, anio, i);
                                        }break;
                                case 3:
                                        {
                                        //eliminar cuenta
                                        }break;
                                default :
                                        {
                                                //salir
                                        }break;
                        }
                    }while((Opc_Registro != 4));
    }


