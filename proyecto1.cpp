#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>



using namespace std;
const int N = 100;
//funciones de Francisco Ayala
void Menu_Registros_usuarios(char Nombres[N][100], char Apellidos[N][100],int Dui[N],char Numero_cuent[N][10], char anio[N][10], int i);//prototipo de agregar modificar y eliminar los usuarios
void Numero_correlativo( char Numero_cuenta[N][10], char anio[N][10], int i);//CREAR NUMERO DE CUENTA
void Guardar(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuenta[N][10], char anio[N][10], int i);//PROTOTIPO PARA LA FUNCION GUARDAR UN NUEVO USUARIO
void Editar(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuenta[N][10], char anio[N][10], int i);//EDITAR UN USUARIO

//funciones de Diego Mejia
void registro_resibos();//esta funcion es el prototipo de el registro de recibos
void menu_registo_recibos(); //muestra el sub menu de opciones del registro de recibos


int main()
    {
        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        char  Numero_cuenta[N][10] = {"\0"}, anio[N][10] = {"\0"};
        int Dui[N], i= 0;
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
									registro_resibos();
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
void menu_registo_recibos()
{
        cout <<"seleccione lo que desea hacer "<<endl;
        cout <<"1- agregar consumo de agua del cliente "<<
}
void registro_resibos()
{
        char c_usuario[10]={'\0'};
        cout << "ingrese el numero de cuenta del usuario al que desea agregar consumo de agua"<<endl;
        cin>>c_usuario;
        

}

//funciones de Javier Ayala
void gotoxy(int x, int y)//para posicionamiento de las impresiones
    {//esta funcion permite el posicionamiento del curso x, y
        HANDLE hcon;
        hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hcon,dwPos);
    }
/*---------------------------------------FUNCION PARA CREAR EL NUMERO CORRELATIVO---------------------------------------------*/
void Numero_correlativo( char Numero_cuenta[N][10], char anio[N][10], int i)
        {
                char corre[N][10] = {"\0"};
                strncpy(Numero_cuenta[i],anio[i],4);//COPIAR AÑO EN NUMERO DE CUENTA
                strcat(Numero_cuenta[i],"-");//CONCATENAR UN - EN NUMERO DE CUENTA
                itoa(i,corre[i],10);//CONVERTIR DE ENTERO A CARECTER
                     do{  
                          fflush(stdin);
                          if((strlen(Numero_cuenta[i])+(strlen(corre[i])))<=8)//IF PARA CONTAR LOS CARACTERES
                              {
                                   strcat(Numero_cuenta[i],"0");//CONCATENAR UN CERO
                              }else 
                                  {
                                       strcat(Numero_cuenta[i],corre[i]);//CONCATENAR CORRELATIVO
                                  }                                 
                    }while(strlen(Numero_cuenta[i])<=8);//FIN DEL BUCLE
        }
/*---------------------------------------FUNCION PARA CREAR UN NUEVO USUARIO---------------------------------------------*/
void Guardar(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuenta[N][10], char anio[N][10], int i)
        {
                        //agregar usuarios maximo 100
                        fflush(stdin);
                        cout<<"Ingresa los nombre"<<endl;
                        gets(Nombres[i]);
                        cout<<"Ingresa Tus apellidos"<<endl;
                        gets(Apellidos[i]);
                        cout<<"Ingrese el anio de asociado"<<endl;
                        gets(anio[i]);
                        cout<<"Ingresa el numero de DUI"<<endl;
                        cin>>Dui[i];
                        system("Cls");
                        //numero correlativo
                                                                 
        }
/*---------------------------------------FUNCION PARA EDITAR CUENTA---------------------------------------------*/
void Editar(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuenta[N][10], char anio[N][10], int i)
        {
                gotoxy(0,0);
                cout<<"N de usuario";
                gotoxy(25,0);
                cout<<"Numero de cuenta";
                gotoxy(50,0);
                cout<<"Nombre";
                gotoxy(75,0);
                cout<<"Apellido";
                gotoxy(100,0);
                cout<<"Dui"<<endl;
                cout<<"\n";
                for(int j = 0; j < i; j++)
                   {
                        gotoxy(0,j+1);
                        cout<<j;
                        gotoxy(25,j+1);
                        cout<<Numero_cuenta[j];
                        gotoxy(50,j+1);
                        cout<<Nombres[j];
                        gotoxy(75,j+1);
                        cout<<Apellidos[j];
                        gotoxy(100,j+1);
                        cout<<Dui[j];                                     
                   }
                system("pause>null");
                system("Cls");
        }
/*---------------------------------------FUNCION MENU DE REGISTROS DE LOS USUARIOS---------------------------------------------*/
void Menu_Registros_usuarios(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuenta[N][10], char anio[N][10], int i)//funcion para agregar modificar y eliminar los usuarios

    { 
            int Opc_Registro;
            do{
                cout<<"Registros"<<endl;
                cout<<"1: Nueva cuenta"<<endl;
                cout<<"2: Editar cuenta"<<endl;
                cout<<"3: Eliminar cuenta"<<endl;
                cout<<"4: Menu principal"<<endl;
                cin>>Opc_Registro;
                system("Cls");
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




