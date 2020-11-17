#include "nuevo_usuario.h"
#include<iostream>
#include "validar_letras.cpp"
#include "validar_numeros.cpp"
#include "ortografia.cpp"
#include "interfaz.cpp"
using namespace std;
/*---------------------------------------FUNCION PARA CREAR UN NUEVO USUARIO---------------------------------------------*/
void Guardar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int i)
        {
                        //agregar usuarios maximo 100
                        interfaz(1, 27, 1, 80);
                        interfaz(2, 26, 2, 79);
                        gotoxy(28,2);cout<<"D A T O S  P E R S O N A L E S"<<endl;
                        do{
                                fflush(stdin);
                               gotoxy(5,4); cout<<"Nombre: ";
                                gets(Nombres[i]);
                                Ortografia(Nombres, i);
                                if(ValidarLetras(Nombres, i) == false)
                                        {
                                                 gotoxy(31,25);cout<<"\x1b[41;37m* Caracter invalido * \033[0m ";
                                        }
                                        
                        }while(ValidarLetras(Nombres, i) == false);

                        do{
                                gotoxy(5,5);cout<<"Apellido: ";
                                gets(Apellidos[i]);
                                Ortografia(Apellidos, i);
                                if(ValidarLetras(Apellidos, i) == false)
                                        {
                                                gotoxy(31,25);cout<<"\x1b[41;37m* Caracter invalido *\033[0m ";
                                        }
                        }while(ValidarLetras(Apellidos, i) == false);
                        do{
                                gotoxy(5,6);cout<<"Anio de asociado: ";
                                gets(anio[i]);
                                
                                if(strlen(anio[i]) <4 || strlen(anio[i]) >4)
                                        {
                                           gotoxy(31,25);cout<<"\x1b[41;37m* Datos ingresados son mayor o menor a 4 digitos *\033[0m"<<endl; 
                                        }
                        }while(ValidarNumeros(anio,i) == false || (strlen(anio[i]) <4 || strlen(anio[i]) >4));

                         do{
                                gotoxy(5,7);cout<<"Numero de DUI: ";
                                gets(Dui[i]);
                        }while(ValidarNumeros(Dui,i) == false);
                        system("Cls");
                        //numero correlativo
                                                                 
        }