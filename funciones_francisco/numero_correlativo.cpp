#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "numero_correlativo.h"
using namespace std;

/*---------------------------------------FUNCION PARA CREAR EL NUMERO CORRELATIVO---------------------------------------------*/
void Numero_correlativo( char Numero_cuenta[N][10], char anio[N][11], int i)
        {
                char corre[1] ;
                strncpy(Numero_cuenta[i],anio[i],4);//COPIAR AÑO EN NUMERO DE CUENTA
                strcat(Numero_cuenta[i],"-");//CONCATENAR UN - EN NUMERO DE CUENTA

                //Cuantos años iguales hay

                       // char cuenta1[1];
                       // strncpy(cuenta1,Numero_cuenta[i],4);//COPIAR AÑO EN NUMERO DE CUENTA
                        int cuenta = atoi(Numero_cuenta[0]);//de caracter a entero
                        int ani1 = atoi(anio[i]);//de caracter a entero
                        int cont = 0;
                         for(int j = 0; j < i; j++)
                              {
                                   if(cuenta == ani1)
                                        {
                                             cont++;
                                        }
                                   cuenta = atoi(Numero_cuenta[j]);//de caracter a entero
                              }
                         itoa(cont,corre,10);//CONVERTIR DE ENTERO A CARECTER
                         cont = 0;
                     do{  
                          fflush(stdin);
                          if((strlen(Numero_cuenta[i])+(strlen(corre)))<=8)//IF PARA CONTAR LOS CARACTERES
                              {
                                   strcat(Numero_cuenta[i],"0");//CONCATENAR UN CERO
                              }else 
                                  {
                                       strcat(Numero_cuenta[i],corre);//CONCATENAR CORRELATIVO
                                  }                                 
                    }while(strlen(Numero_cuenta[i])<=8);//FIN DEL BUCLE
        }
