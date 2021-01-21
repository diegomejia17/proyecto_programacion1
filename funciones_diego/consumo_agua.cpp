
#include <stdlib.h>
#include <string.h>
#include "estructura_r_r.h"
#include "../constante.h"
#include <iostream>
#include "consumo_agua.h"
#include "colores.cpp"
#include "../funciones_francisco/Interfaz.h"
#include "../funciones_Christian/costo.cpp"

using namespace std;
void consumo_agua(int &posicion, char c_usuario[10], register_anual *registro_user, char nombres[N][100], char Mes[N][11])
/*en esta funcion se pide los datos para establecer el consumo al cliente que se ingreso*/
{
	char aux[20];

	int mes_n = atoi(Mes[posicion]);
	

	itoa(mes_n +1 ,aux,10); 

	strcpy(Mes[posicion],aux);

	

	mes_n = mes_n - 1;

	
	

	bool exito = false;
	char registro[20];
	float Fregistro;
	do
	{

		if (registro_user[posicion].registro_anual[4][11] > 0)
		{
			for (int s = 0; s <= 11; s++)
			{
				registro_user[posicion].registro_anual[0][s] = 0;
				registro_user[posicion].registro_anual[1][s] = 0;
				registro_user[posicion].registro_anual[2][s] = 0;
				registro_user[posicion].registro_anual[3][s] = 0;
				registro_user[posicion].registro_anual[4][s] = 0;
			}
		}
		/*if (registro_user[posicion].registro_anual[2][mes_n] == 0)
		//si aun no se a ingresado nada en la matriz de la estructura, entonces se pediran los datos
		{*/
			interfaz(1, 27, 1, 80);
			interfaz(2, 26, 2, 79);
			color(1);
			gotoxy(27, 2);
			cout << "INGRESO DE CONSUMO" << endl;
			
			color(0);
			gotoxy(8, 4);
			cout << "Usuario: " << c_usuario << endl;
			gotoxy(8, 6);
			cout << "Nombre: " << nombres[posicion] << endl;
			gotoxy(8, 8);
			cout << "Mes:  " << mes_n + 1 << endl;
			gotoxy(8, 10);
			cout << "Registre el consumo :  ";

			registro_user[posicion].registro_anual[0][mes_n] = mes_n; //en la estructura
																	  //el mes sera el que ingreso el cliente
			cin >> registro;										  //variable que llenara el usuario
			int i = 0;
			float anterior;
			do
			{
				if (isdigit(registro[i]) == 0)
				{
					Fregistro = 0;
				}
				else
				{
					Fregistro = atof(registro); //convercion de char a float
				}
				i++;
			} while (i < strlen(registro)); //validacion para que solo se acepten numeros

			if (mes_n >= 0 && Fregistro > 0)
			//si el mes que el cliente ingreso es mayor a cero y el consumo de agua es mayor a cero se cumplira
			//lo que esta dentro de este condicional
			{

				if (mes_n == 0)
				{
					//si se esta llenando el primer mes, no de debe efectuar la resta
					//por lo que el proceso debe finalizar
					registro_user[posicion].registro_anual[2][mes_n] = Fregistro;
					registro_user[posicion].registro_anual[1][mes_n] = Fregistro;
					float consumo_mensual = Fregistro;
					float precio = costo(consumo_mensual);
					registro_user[posicion].registro_anual[3][mes_n] = (precio); //precio por mes
					registro_user[posicion].registro_anual[4][mes_n] = (-1);	 //no a pagado
					exito = true;
					color(1);
					gotoxy(8, 12);
					cout << "Registro exitoso" << endl;
					gotoxy(8, 14);
					cout << "El consumo del mes es de: " << registro_user[posicion].registro_anual[2][mes_n] << endl;
					color(0);
					system("pause>0");
					system("cls");
					return;
				}
				else
				{

					anterior = registro_user[posicion].registro_anual[1][mes_n - 1];
					//si el mes es difenerente de 1 se almacenara el valor registrado anteriormente
					// en la variable anterior

					if (anterior < Fregistro)
					{
						//si el valor de la variable anterior es menor que el valor de la variable
						//modificar entonses se ejecutara el cambio
						registro_user[posicion].registro_anual[1][mes_n] = Fregistro;

						registro_user[posicion].registro_anual[2][mes_n] = (Fregistro - anterior);

						float consumo_mensual = Fregistro - anterior;
						float precio = costo(consumo_mensual);
						registro_user[posicion].registro_anual[3][mes_n] = (precio); //precio por mes
						registro_user[posicion].registro_anual[4][mes_n] = -1;		 //no a pagado
						
						exito = true;
						color(1);
						gotoxy(8, 12);
						cout << "registro exitoso" << endl;
						gotoxy(8, 14);

						cout << "El consumo del mes es de: " << registro_user[posicion].registro_anual[2][mes_n] <<endl;
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
						gotoxy(8, 12);
						cout << "vuelve a intentarlo" << endl;
						color(0);
						system("pause>0");
						system("cls");
					}
				}
			}
			else
			{
				exito = false;
				color(2);
				gotoxy(8, 12);
				cout << "vuelve a intentarlo" << endl;
				color(0);
				system("pause>0");
				system("cls");
			}
		/*}
		else
		{
			exito = true;
			color(1);
			gotoxy(27, 2);
			cout << "ya existen registros" << endl;
			color(0);
			system("pause>0");
			system("cls");
		}*/

	} while (exito == false); //mientras no se cumpla ningun condicional el ciclo se repetira

	

}
