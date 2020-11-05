#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "numero_correlativo.h"
using namespace std;

/*---------------------------------------FUNCION PARA CREAR EL NUMERO CORRELATIVO---------------------------------------------*/
void Numero_correlativo( char Numero_cuenta[N][10], char anio[N][11], int i)
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
