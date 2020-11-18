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
	float anterior;
	char Cmodificar[20];
	int i=0;
	do
	{
		if (registro_user[posicion].registro_anual[2][mes_n]>0 )
		//si en la estructura en la posicion del correlativo que se ingreso es mayor a cero 
		//entonces se modificara en el caso contrario no se podra 
		{
			if(mes_n>0)
			//validacion para verificar que el mes es correcto
			{	
				cout <<"el registro a modificar del usuario: "<< c_usuario<<"  es : "<<endl;
				cout <<registro_user[posicion].registro_anual[1][mes_n]<<"  metros cubicos "<<endl;
				cout <<"el consumo del mes es : "<<endl;
				cout <<registro_user[posicion].registro_anual[2][mes_n]<<"  metros cubicos "<<endl;
				cout <<"ingrese el nuevo consumo "<<endl;
				cin>> Cmodificar;

				do
				{
					if (isdigit(Cmodificar[i])== 0)
					{
						modificar = 0;
					}
					else
					{
						modificar = atof(Cmodificar);
					}
				i ++;
				} while (i< strlen(Cmodificar));
			
				if (modificar > 0 )
				//si la variable que se le pidio al cliente es mayor a cero
				// entoces se copiara ese valor en la estructura
					{
						

						if (mes_n==1)
							{
								registro_user[posicion].registro_anual[2][mes_n]=modificar;
								registro_user[posicion].registro_anual[1][mes_n]=modificar;
								exito = true;
								cout <<"registro exitoso"<<endl;
								system("pause>0");
								system("cls");
								return;	
							}
							else
							{
								anterior = registro_user[posicion].registro_anual[1][mes_n-1];

								if (anterior < modificar)
									{
										registro_user[posicion].registro_anual[1][mes_n]=modificar;
										registro_user[posicion].registro_anual[2][mes_n]=(modificar - anterior);
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