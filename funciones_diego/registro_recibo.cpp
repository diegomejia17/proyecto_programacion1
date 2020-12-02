#include "registro_recibo.h"
#include <iostream>
#include "validar_correlativo.cpp"
#include "menu_registro_recibo.cpp"
#include "../funciones_francisco/Interfaz.h"
#include "colores.h"


int registro_resibos(char numero_cuenta[N][10],register_anual * registro_user,char nombres[N][100])
{	/*esta funcion lo que hace es pedir los datos principales
 	y ademas de ejercer como puente en funciones*/

	char c_usuario[10] = { '\0' };	//arreglo que contiene el numero correlativo que sera evaluado
	int posicion = 0;	//almacena la pocicion del numero correlativo
	char mes [1];	//almacena el mes que se desea pagar
	int mes_n;
	char clear;
	bool exito = false;
	
    do
    {
        interfaz(1, 27, 1, 80);
        interfaz(2, 26, 2, 79);
		color(1);
        gotoxy(27,2);cout <<"REGISTRO DEL CONSUMO DE AGUA "<<endl;
		color(0);
		gotoxy(20,6);cout << " Ingrese el numero correlativo" << endl;
		color (0);
		gotoxy(20,14);cout << "presione cero si desea salir " << endl;
		gotoxy(20,8);cin >> c_usuario;
		
		
		if (verificar_registo_resibos(numero_cuenta,c_usuario,posicion)==false && c_usuario[0]!= 48)
		{
			color(2);
			gotoxy(20,18);cout <<"DATO INGRESADO INVALIDO"<<endl;
			color (0);
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
    }while( exito == false );
	
if (c_usuario[0] != 48)
	{
		do
		{
			interfaz(1, 27, 1, 80);
       		interfaz(2, 26, 2, 79);
			color(1);
			gotoxy(28,2);cout << "SELECCIONE EL MES" << endl;
			color (0);
			gotoxy(10,6);cout << " 01 -> Enero \t 02 -> Febrero \n ";
			gotoxy(10,8);cout <<" 03 -> Marzo \t 04 -> Abril\n";
			gotoxy(10,10);cout << " 05 -> Mayo \t 06 -> Junio \n ";
			gotoxy(10,12);cout <<" 07 -> Julio \t 08 -> Agosto\n";
			gotoxy(10,14);cout <<" 09 -> Septiembre \t 10 -> Octubre \n";
			gotoxy(10,16);cout <<" 11 -> Noviembre \t 12 -> Diciembre \n";
			gotoxy(28,18);cin >> mes;
			mes_n= atoi(mes);
			
			if ((isdigit(mes[0]))==0 || mes_n<=0 || mes_n >12)
			{
				exito = false;
				color(2);
				gotoxy(20,20);cout <<"DATO INGRESADO INVALIDO"<<endl;
				color (0);
				system("pause>null");
				system("cls");
			}
			else
			{
				if ((mes_n > 1 && (registro_user[posicion].registro_anual[1][mes_n-1]>0)) || mes_n == 1 )
				{
					exito = true;
					system("cls");	
				}
				else
				{
					exito = false;
					color(2);
					gotoxy(19,20);cout <<"DEBE INGRESAR REGISTROS EN EL MES ANTERIOR"<<endl;
					color(0);
					system("pause>null");
					system("cls");
				}
				
					
			}
			
			fflush(stdin);
		} while(exito == false);

		//return posicion;
		menu_registro_recibo(numero_cuenta,posicion, c_usuario, registro_user , nombres , mes); 
		/* 
		esta funcion sirve para mostrar las opciones para poder registrar un consumo de agua o modificar, 
		ademas en ella estan contenidas las otras funciones correspondientes a las opciones del men*/
		clear = cin.get();
		fflush(stdin);
		system("pause>null");
}

	}
	
	