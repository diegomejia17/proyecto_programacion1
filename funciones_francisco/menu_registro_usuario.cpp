
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
                        cout<<"Registros"<<endl;
                        cout<<"1: Nueva cuenta"<<endl;
                        cout<<"2: Editar cuenta"<<endl;
                        cout<<"3: Eliminar cuenta"<<endl;
                        cout<<"4: Menu principal"<<endl;
                        gets(Opc);
                        c = Opc[0];
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
                    }while(Opc_Registro != 4);
    }

