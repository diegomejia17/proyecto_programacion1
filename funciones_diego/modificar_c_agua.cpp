#include "modificar_c_agua.h" //llamando a archivo de la definicion de la funcion
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "colores.h"
#include "../funciones_francisco/Interfaz.h"

void modificar_c_agua(int &posicion, char c_usuario[10], register_anual *registro_user, char nombres[N][100], char Mes[N][11])
/* 
esta funcion sirve para modificar el registro del consumo del agua por si se llega a ingresar un dato erroneo
*/
{
	int mes_n = atoi(Mes[posicion]);
	mes_n = mes_n - 2;

	cout <<Mes[posicion]<<"aqui...";
	bool exito = false; //variable para controar ciclos
	float modificar;
	float anterior;
	char Cmodificar[20];
	int i = 0;
	do
	{
		if (registro_user[posicion].registro_anual[2][mes_n] > 0)
		//si en la estructura en la posicion del correlativo que se ingreso es mayor a cero
		//entonces se modificara en el caso contrario no se podra
		{
			if (mes_n >= 0)
			//validacion para verificar que el mes es correcto
			{
				//mostrando datos
				interfaz(1, 27, 1, 80);
				interfaz(2, 26, 2, 79);
				color(1);
				gotoxy(27, 2);
				cout << "MODIFICAR  REGISTRO" << endl;
				color(0);
				gotoxy(8, 4);
				cout << "Usuario: " << c_usuario << endl;
				gotoxy(8, 6);
				cout << "Nombre: " << nombres[posicion] << endl;
				gotoxy(8, 8);
				cout << "Mes:  " << mes_n +1 << endl;
				gotoxy(8, 10);
				cout << "Registro anterior:  " << registro_user[posicion].registro_anual[1][mes_n] << endl;
				gotoxy(8, 12);
				cout << "Ingrese el cambio del registro:  ";

				cin.getline(Cmodificar, 20, '\n'); //variable a la que el usuario ingresa valores
				do
				{
					if (isdigit(Cmodificar[i]) == 0)
					{
						modificar = 0;
					}
					else
					{
						modificar = atof(Cmodificar); // pasar el valor de char Cmodificar a float modificar
					}
					i++;

				} while (i < strlen(Cmodificar)); //validacion para que solo se acepten numeros

				if (modificar > 0)
				//si la variable que se le pidio al cliente es mayor a cero
				// entoces se copiara ese valor en la estructura
				{

					if (mes_n == 0)

					{
						//si se esta llenando el primer mes, no de debe efectuar la resta
						//por lo que el proceso debe finalizar
						registro_user[posicion].registro_anual[2][mes_n] = modificar;
						registro_user[posicion].registro_anual[1][mes_n] = modificar;
						float consumo_mensual = modificar;
						float precio = costo(consumo_mensual);
						registro_user[posicion].registro_anual[3][mes_n] = (precio); //precio por mes
						registro_user[posicion].registro_anual[4][mes_n] = (-1);	 //no a pagado
						exito = true;
						color(1);
						gotoxy(8, 14);
						cout << "registro exitoso" << endl;
						gotoxy(8, 16);
						;
						cout << "El consumo del mes es de: " << registro_user[posicion].registro_anual[2][mes_n] << endl;
						color(0);
						system("pause>0");
						system("cls");
						return;
					}
					else
					{
						//si el mes es difenerente de 1 se almacenara el valor registrado anteriormente
						// en la variable anterior
						anterior = registro_user[posicion].registro_anual[1][mes_n - 1];

						if (anterior < modificar)
						{
							//si el valor de la variable anterior es menor que el valor de la variable
							//modificar entonses se ejecutara el cambio
							registro_user[posicion].registro_anual[1][mes_n] = modificar;
							registro_user[posicion].registro_anual[2][mes_n] = (modificar - anterior);
							float consumo_mensual =  (modificar - anterior);
							float precio = costo(consumo_mensual);
							registro_user[posicion].registro_anual[3][mes_n] = (precio); //precio por mes
							registro_user[posicion].registro_anual[4][mes_n] = (-1);	 //no a pagado
							//se efectua el proceso de resta para poder conocer los m3 de agua consumida
							//en el mes
							exito = true;
							color(1);
							gotoxy(8, 14);
							cout << "registro exitoso" << endl;
							gotoxy(8, 16);
							;
							cout << "El consumo del mes es de: " << registro_user[posicion].registro_anual[2][mes_n] << endl;
							color(0);
							system("pause>0");
							system("cls");
							return;
						}
						else
						{
							//si lo anterior no se cumple entonces se repetira todo el proceso
							exito = false;
							color(2);
							gotoxy(8, 14);
							cout << "vuelve a intentarlo" << endl;
							color(0);
							system("pause>0");
							system("cls");
						}
					}
				}
			}
			else
			{ //si el mes ingresado no es mayor a cero entonces se repetira el ciclo
				exito = false;
				color(2);
				gotoxy(8, 14);
				cout << "vuelve a intentarlo" << endl;
				color(0);
				system("pause>0");
				system("cls");
			}
		}
		else
		{
			//si aun no existen registro entonces no sera valido
			exito = true;
			color(1);
			gotoxy(27, 2);
			cout << "aun no existen registros." << endl;
			color(0);
			system("pause>0");
			system("cls");
		}

	} while (exito == false); //el ciclo se repetira mientras no se cumpla los condicionales anteriores
}