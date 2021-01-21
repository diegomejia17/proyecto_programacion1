#include <windows.h>
#include <iostream>
#include "gotoxy.cpp"
#include "editar_cuenta.h"
#include <string.h>
#include <stdlib.h>
using namespace std;
/*---------------------------------------FUNCION PARA EDITAR CUENTA---------------------------------------------*/
void E_ditar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int& i)
        {
                                                strcpy(Nombres[i],Nombres[i+1]);
                                                strcpy(Apellidos[i],Apellidos[i+1]);
                                                strcpy(Dui[i],Dui[i+1]);
                                                strcpy(anio[i],anio[i+1]);
                                                strcpy(Numero_cuenta[i],Numero_cuenta[i+1]);

//mostrar
       
                interfaz(1, 27, 1, 80);
                interfaz(2, 26, 2, 79);
                gotoxy(27,2);cout<<"\x1b[1;34mTABLA DE USUARIOS\033[0m"<<endl;   
                gotoxy(24,4);cout << "|";            
                gotoxy(6,4);cout<<"\x1b[1;34mNumero de cuenta\033[0m";

                gotoxy(39,4);cout << "|";
                gotoxy(26,4);cout<<"\x1b[1;34mNombre\033[0m";

                gotoxy(59,4);cout << "|";
                gotoxy(41,4);cout<<"\x1b[1;34mApellido\033[0m";

                gotoxy(61,4);cout<<"\x1b[1;34mDui\033[0m"<<endl;               
                cout<<"\n";
                gotoxy(6,5);cout << "________________________________________________________________";                                        
                        
                for(int j = 0; j < i; j++)
                   {

                        int a = 6;
                        gotoxy(24,a+j);cout << "|";
                        gotoxy(24,a+j+1);cout << "|"; 
                        gotoxy(6,j+a);cout<<Numero_cuenta[j];
                        
                        gotoxy(39,a+j);cout << "|";
                        gotoxy(39,a+j+1);cout << "|";
                        gotoxy(26,j+a);cout<<Nombres[j];

                        gotoxy(59,a+j);cout << "|";
                        gotoxy(59,a+j+1);cout << "|"; 
                        gotoxy(41,j+a);cout<<Apellidos[j];

                        gotoxy(61,j+a);cout<<Dui[j]; 
                                                      
                   }
                   if(i == 0)   
                        {
                                 gotoxy(22,6);cout<<"No se encontraron registros";
                        }
                gotoxy(6,i+7);cout << "_________________________________________________________________";
                system("pause>null");
                system("Cls");
        }
