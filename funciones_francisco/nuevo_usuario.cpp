#include "nuevo_usuario.h"
#include<iostream>
#include "validar_letras.cpp"
#include "validar_numeros.cpp"
#include "ortografia.cpp"
using namespace std;

/*---------------------------------------FUNCION PARA CREAR UN NUEVO USUARIO---------------------------------------------*/
void Guardar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int i)
        {
                        //agregar usuarios maximo 100
                        fflush(stdin);

                        do{
                                cout<<"Ingresa los nombre"<<endl;
                                gets(Nombres[i]);
                                Ortografia(Nombres, i);
                        }while(ValidarLetras(Nombres, i) == false);

                        do{
                                cout<<"Ingresa Tus apellidos"<<endl;
                                gets(Apellidos[i]);
                                Ortografia(Apellidos, i);
                        }while(ValidarLetras(Apellidos, i) == false);
                        do{
                                cout<<"Ingrese el anio de asociado"<<endl;
                                gets(anio[i]);
                                
                                if(strlen(anio[i]) <4 || strlen(anio[i]) >4)
                                        {
                                           cout<<"Tiene que ingresar 4 digitos"<<endl;     
                                        }
                        }while(ValidarNumeros(anio,i) == false || (strlen(anio[i]) <4 || strlen(anio[i]) >4));

                         do{
                                cout<<"Ingresa el numero de DUI"<<endl;
                                gets(Dui[i]);
                        }while(ValidarNumeros(Dui,i) == false);
                        system("Cls");
                        //numero correlativo
                                                                 
        }
