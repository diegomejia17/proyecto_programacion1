#include "nuevo_usuario.h"
#include<iostream>
#include "validar_letras.cpp"
#include "validar_numeros.cpp"
#include "ortografia.cpp"
#include "interfaz.cpp"
#include "validar_dui.cpp"
using namespace std;
/*---------------------------------------FUNCION PARA CREAR UN NUEVO USUARIO---------------------------------------------*/
void Guardar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int i)
        {
                        //agregar usuarios maximo 100
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(28,2);cout<<"D A T O S  P E R S O N A L E S"<<endl;
                        do{
                               gotoxy(5,4); cout<<"Nombre: ";
                                gets(Nombres[i]);
                                fflush(stdin);
                                Ortografia(Nombres, i);
                                        
                        }while(ValidarLetras(Nombres, i) == false);

                        do{
                                gotoxy(5,6);cout<<"Apellido: ";
                                gets(Apellidos[i]);
                                Ortografia(Apellidos, i);
                        }while(ValidarLetras(Apellidos, i) == false);
                        do{
                                gotoxy(5,8);cout<<"Anio de asociado: ";
                                gets(anio[i]);
                                
                                if(strlen(anio[i]) <4 || strlen(anio[i]) >4)
                                        {
                                           gotoxy(20,25);cout<<"\x1b[41;37m* Debe de ingresar 4 digitos *\033[0m"<<endl; 
                                        }
                        }while(ValidarNumeros(anio,i) == false || (strlen(anio[i]) <4 || strlen(anio[i]) >4));

                         do{
                                gotoxy(5,10);cout<<"Numero de DUI: ";
                                gets(Dui[i]);                                
                                 if(strlen(Dui[i]) <9 || strlen(Dui[i]) >9)
                                        {
                                           gotoxy(20,25);cout<<"\x1b[41;37m* Debe de ingresar 9 digitos * \033[0m"<<endl; 
                                        }
                        }while((ValidarNumeros(Dui,i) == false) || (strlen(Dui[i]) <9 || strlen(Dui[i]) >9) || (validar_dui(Dui,i) == 0));
                        system("Cls");
                        //numero correlativo
                                                                 
        }