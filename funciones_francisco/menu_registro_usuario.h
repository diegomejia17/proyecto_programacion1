#include<string.h>
#include "nuevo_usuario.h"
#include "numero_correlativo.h"
#include "editar_cuenta.h"
#include "ordenamiento.h"
#include "validarmenu.h"
extern const  int N = 100;
using namespace std;
/*---------------------------------------FUNCION MENU DE REGISTROS DE LOS USUARIOS---------------------------------------------*/
void Menu_Registros_usuarios(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int i)//funcion para agregar modificar y eliminar los usuarios

    { 
            //AGREGAR ORDENAMIENTO Y VALIDAR EL Opc_Registro JAVIER
            int Opc_Registro;
            char Opc[11];
            do{
                do{
                        cout<<"Registros"<<endl;
                        cout<<"1: Nueva cuenta"<<endl;
                        cout<<"2: Editar cuenta"<<endl;
                        cout<<"3: Eliminar cuenta"<<endl;
                        cout<<"4: Menu principal"<<endl;
                        gets(Opc);
                        system("Cls");
                }while(Validarmenu(Opc) == false);//reciba solo numeros
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
