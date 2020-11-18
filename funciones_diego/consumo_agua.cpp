#include "consumo_agua.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void consumo_agua(int posicion, char c_usuario[10],register_anual * registro_user,char nombres[N][100],char mes [1])
/*en esta funcion se pide los datos para establecer el consumo al cliente que se ingreso*/
{
	int mes_n= atoi(mes);
	bool exito = false;
	char  registro[20];
	float Fregistro;
	do
	{
		if (registro_user[posicion].registro_anual[2][mes_n]==0)
		//si aun no se a ingresado nada en la matriz de la estructura, entonces se pediran los datos
		{
		
			cout <<"ingrese el consumo de metros cubicos de agua que tendra el usuario: "<< c_usuario<<endl;
			cout <<" llamado: "<< nombres[posicion]<<endl;
			cout << "en el mes:  "<<mes<<endl;
			
			registro_user[posicion].registro_anual[0][mes_n]=mes_n;//en la estructura 
																   //el mes sera el que ingreso el cliente
			cin>>registro;
			int i = 0;
			float  anterior;
			do
			{
				if (isdigit(registro[i])== 0)
			{
				Fregistro = 0;
			}
			else
			{
				Fregistro = atof(registro);
			}
			i ++;
			} while (i< strlen(registro));
			
			if(mes_n>0 && Fregistro > 0)
			//si el mes que el cliente ingreso es mayor a cero y el consumo de agua es mayor a cero se cumplira
			//lo que esta dentro de este condicional
			{
    		
			if (mes_n==1)
				{
					registro_user[posicion].registro_anual[2][mes_n]=Fregistro;
					registro_user[posicion].registro_anual[1][mes_n]=Fregistro;
					exito = true;
					cout <<"registro exitoso"<<endl;
					system("pause>0");
					system("cls");
					return;	
				}
				else
				{
					
					anterior = registro_user[posicion].registro_anual[1][mes_n-1];
					if (anterior < Fregistro)
						{
							registro_user[posicion].registro_anual[1][mes_n]=Fregistro;

							registro_user[posicion].registro_anual[2][mes_n]=(Fregistro - anterior);
							exito = true;
							cout <<"registro exitoso"<<endl;
							system("pause>0");
							system("cls");
							return;	
						}
						else
							{
								exito = false;
								cout <<"vuelve a intentarlo"<<endl;
								system("pause>0");
								system("cls");
							}
							
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
				cout <<"ya existen registros"<<endl;
				system("pause>0");
				system("cls");
		}
		
    }while (exito == false);//mientras no se cumpla ningun condicional el ciclo se repetira 
}
