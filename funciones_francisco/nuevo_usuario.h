#include<iostream>
 const  int B = 100;
#include "validar_letras.h"
#include "validar_numeros.h"
using namespace std;

/*---------------------------------------FUNCION PARA CREAR UN NUEVO USUARIO---------------------------------------------*/
void Guardar(char Nombres[B][100], char Apellidos[B][100], char Dui[B][11], char Numero_cuenta[B][10], char anio[B][11], int i)
        {
                        //agregar usuarios maximo 100
                        fflush(stdin);

                        do{
                                cout<<"Ingresa los nombre"<<endl;
                                gets(Nombres[i]);
                        }while(ValidarLetras(Nombres, i) == false);

                        do{
                                cout<<"Ingresa Tus apellidos"<<endl;
                                gets(Apellidos[i]);
                        }while(ValidarLetras(Apellidos, i) == false);

                        do{
                                cout<<"Ingrese el anio de asociado"<<endl;
                                gets(anio[i]);
                        }while(ValidarNumeros(anio,i) == false);

                         do{
                                cout<<"Ingresa el numero de DUI"<<endl;
                                gets(Dui[i]);
                        }while(ValidarNumeros(Dui,i) == false);
                        system("Cls");
                        //numero correlativo
                                                                 
        }
