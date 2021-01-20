#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "numero_correlativo.h"
using namespace std;

/*---------------------------------------FUNCION PARA CREAR EL NUMERO CORRELATIVO---------------------------------------------*/
void Numero_correlativo( char Numero_cuenta[N][10], char anio[N][11], int& i)
        {    
           char corre[1] ;
           char conts[10], numero[5], conteo[5];
           int conteo1;
     
               strncpy(Numero_cuenta[i],anio[i],4);//COPIAR AÑO EN NUMERO DE CUENTA
               strcat(Numero_cuenta[i],"-");//CONCATENAR UN - EN NUMERO DE CUENTA
                //Cuantos años iguales hay
                        
                         int anio1 = atoi(anio[i]);//de caracter a entero
                        int cont = 0, cont1 = 0;
                         for(int j = 0; j < i; j++)
                              {
                                   int cuenta = atoi(Numero_cuenta[j]);//de caracter a entero
                                   if(cuenta == anio1)
                                        {
                                             strcpy(conts,Numero_cuenta[j]);
                                             strrev(conts);
                                             strrev(numero);
                                             do{
                                                  int a = 4;
                                                  strncpy(numero,conts,a);//COPIAR conts EN NUMERO
                                                  strncpy(conteo,conts,1);
                                                  conteo1 = atoi(conteo);
                                                  a--;
                                             }while(conteo1 != 0);
                                             cont = atoi(numero);
                                                       cont1 = cont+1;
                                                  
                                        }
                              }
                                   
                              itoa(cont1,corre,10);//CONVERTIR DE ENTERO A CARECTER
                                        cont1 = 0;
                                        do{  
                                             if((strlen(Numero_cuenta[i])+(strlen(corre)))<=8)//IF PARA CONTAR LOS CARACTERES
                                                  {
                                                       strcat(Numero_cuenta[i],"0");//CONCATENAR UN CERO
                                                  }else 
                                                  {
                                                       strcat(Numero_cuenta[i],corre);//CONCATENAR CORRELATIVO
                                                  }                                 
                                        }while(strlen(Numero_cuenta[i])<=8);//FIN DEL BUCLE
                   
        }
