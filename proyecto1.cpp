#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

using namespace std;

const int N = 100;

void Registros(char Nombres[N][100], char Apellidos[N][100],int Dui[N]);

int main()
    {
        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        int Dui[N];
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
                                   Registros(Nombres, Apellidos, Dui);
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
void gotoxy(int x, int y)
    {//esta funcion permite el posicionamiento del curso x, y
        HANDLE hcon;
        hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hcon,dwPos);
    }

void Registros(char Nombres[N][100], char Apellidos[N][100], int Dui[N])

    { 
            int i=0, Opc_Registro;
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
                                                fflush(stdin);
                                                cout<<"Ingresa los nombre"<<endl;
                                                gets(Nombres[i]);
                                                cout<<"Ingresa Tus apellidos"<<endl;
                                                gets(Apellidos[i]);
                                                cout<<"Ingresa el numero de DUI"<<endl;
                                                cin>>Dui[i];
                                                system("Cls");
                                                i++;
                                        }break;
                                case 2: 
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
                                                for(int j = 0; j <= i; j++)
                                                        {
                                                                gotoxy(0,j+1);
                                                                cout<<j;
                                                                gotoxy(25,j+1);
                                                                cout<<"Numero co";
                                                                gotoxy(50,j+1);
                                                                cout<<Nombres[j];
                                                                gotoxy(75,j+1);
                                                                cout<<Apellidos[j];
                                                                gotoxy(100,j+1);
                                                                cout<<Dui[j];
                                                                
                                                        }
                                                        system("pause>null");
                                                        system("Cls");
                                        }break;
                                case 3:
                                        {

                                        }break;
                                default :
                                        {

                                        }break;
                        }

                    }while(Opc_Registro != 4);
    }


void registro_pago()
        {
                cout << "REGISTRO DE PAGO" << endl;
        }

