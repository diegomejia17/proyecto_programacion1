#include <windows.h>
#include <iostream>
#include "gotoxy.cpp"
#include "editar_cuenta.h"
using namespace std;
/*---------------------------------------FUNCION PARA EDITAR CUENTA---------------------------------------------*/
void Editar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int i)
        {
                
                gotoxy(0,0);
                cout<<"Numero de cuenta";
                gotoxy(20,0);
                cout<<"Nombre";
                gotoxy(35,0);
                cout<<"Apellido";
                gotoxy(55,0);
                cout<<"Dui"<<endl;
                cout<<"\n";
                for(int j = 0; j < i; j++)
                   {
                        gotoxy(0,j+1);
                        cout<<Numero_cuenta[j];
                        gotoxy(20,j+1);
                        cout<<Nombres[j];
                        gotoxy(35,j+1);
                        cout<<Apellidos[j];
                        gotoxy(55,j+1);
                        cout<<Dui[j];                                  
                   }
                system("pause>null");
                system("Cls");
        }
