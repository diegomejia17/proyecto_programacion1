#include "registro_recibo.h"
#include <iostream>
#include "validar_correlativo.h"
#include "menu_registro_recibo.cpp"
#include "../funciones_francisco/Interfaz.h"
#include "colores.h"

void registro_resibos(char numero_cuenta[N][10], register_anual *registro_user, char nombres[N][100],char Mes[N][11])
{ /*esta funcion lo que hace es pedir los datos principales
 	y ademas de ejercer como puente en funciones*/

	char c_usuario[10] = {'\0'}; //arreglo que contiene el numero correlativo que sera evaluado
	int posicion = 0;			 //almacena la pocicion del numero correlativo
				
	int mes_n;
	char clear;
	bool exito = false;

	do
	{
		interfaz(1, 27, 1, 80);
		interfaz(2, 26, 2, 79);
		color(1);
		gotoxy(27, 2);
		cout << "REGISTRO DEL CONSUMO DE AGUA " << endl;
		color(0);
		gotoxy(20, 6);
		cout << " Ingrese el numero correlativo" << endl;
		color(0);
		gotoxy(20, 14);
		cout << "presione cero si desea salir " << endl;
		gotoxy(20, 8);
		cin >> c_usuario;

		if (verificar_registo_resibos(numero_cuenta, c_usuario, posicion) == false && c_usuario[0] != 48)
		{
			color(2);
			gotoxy(20, 18);
			cout << "DATO INGRESADO INVALIDO" << endl;
			color(0);
			system("pause>null");
			system("cls");
		}
		else
		{
			exito = true;
			system("cls");
		}
		clear = cin.get();
		fflush(stdin);
	} while (exito == false);

	if (c_usuario[0] != 48)
	{
		

		//return posicion;
		menu_registro_recibo(numero_cuenta, posicion, c_usuario, registro_user, nombres, Mes);
		/* 
		esta funcion sirve para mostrar las opciones para poder registrar un consumo de agua o modificar, 
		ademas en ella estan contenidas las otras funciones correspondientes a las opciones del men*/
		clear = cin.get();
		fflush(stdin);
		system("pause>null");
	}
}
