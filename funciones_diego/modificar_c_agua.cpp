#include "modificar_c_agua.h"//llamando a archivo de la definicion de la funcion
#include <iostream>
#include <stdlib.h>
#include <string.h>

void modificar_c_agua (int posicion, char c_usuario[10],register_anual * registro_user,char nombres[N][100], char mes[1])
/* 
esta funcion sirve para modificar el registro del consumo del agua por si se llega a ingresar un dato erroneo
*/
{
    int mes_n= atoi(mes);
	bool exito = false;
	float modificar;
	do
	{
		if (registro_user[posicion].registro_anual[2][mes_n]>0 )
		//si en la estructura en la posicion del correlativo que se ingreso es mayor a cero 
		//entonces se modificara en el caso contrario no se podra 
		{
			if(mes_n>0)
			//validacion para verificar que el mes es correcto
			{
				
			cout <<"el consumo a modificar del usuario: "<< c_usuario<<"  es : "<<endl;
			cout <<registro_user[posicion].registro_anual[2][mes_n]<<"metros cubicos "<<endl;
			cout <<"ingrese el nuevo consumo "<<endl;
			cin>> modificar;
			
			if (modificar > 0 )
			//si la variable que se le pidio al cliente es mayor a cero
			// entoces se copiara ese valor en la estructura
        		{
					registro_user[posicion].registro_anual[2][mes_n]= modificar;//copiando en la estructura
					exito=true;
					cout <<"modificacion exitosa"<<endl;
					system("pause>0");
					system("cls");
					return;	
        		}
			}
			else 
				{
					exito=false;
					cout <<"vuelve a intentarlo"<<endl;
					system("pause>0");
					system("cls");
				}
		}
		else
		{
			exito=true;
			cout <<"aun no existen registros."<<endl;
			system("pause>0");
			system("cls");
		}
		
		
    }while (exito == false);//el ciclo se repetira mientras no se cumpla los condicionales anteriores
}