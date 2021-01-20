#include "validar_correlativo.h"	
#include "menu_registro_recibo.h"	//archivo que contiene la definicion de la funcion
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "consumo_agua.cpp"	// archivos que contienen las funciones que se llaman.
#include "modificar_c_agua.cpp"
#include"colores.h"
#include "../funciones_francisco/Interfaz.h"

using namespace std;
void menu_registro_recibo(char numero_cuenta[N][10], int& posicion, char c_usuario[10],register_anual * registro_user,char nombres[N][100],char Mes[N][11])
{
	int opcionnumber;
	char opcionletra[1];	
	bool exito= false;
	
	do
	{
		do
		{	verificar_registo_resibos(numero_cuenta,c_usuario,posicion);
			system("cls");
			interfaz(1, 27, 1, 80);
            interfaz(2, 26, 2, 79);
			color(1);
			gotoxy(27,2);cout << "seleccione lo que desea hacer " << endl; //menu de opciones
			color(0);

			gotoxy(5,6);cout << "1- agregar consumo de metros cubicos de agua  " << endl;
			gotoxy(5,8);cout << "2- modificar el consumo del cliente " << endl;
			gotoxy(5,10);cout <<"3- regresar al menu principal "<<endl;
			gotoxy(5,12);cin>>opcionletra;
			opcionnumber=atoi(opcionletra);//variable que sirven para hacer la convercion de char a numero 
			if ((isdigit(opcionletra[0]))==0)
			{
				exito = false;
				color(2);
				gotoxy(20,18);cout <<"DATO INGRESADO INVALIDO"<<endl;
				color (0);
				system("pause>null");
			}
			else
			{
				exito = true;
			}
			
	
		} while(exito = false);//mientras lo que se ingrese no sea un numero el ciclo

		switch (opcionnumber)
		{
		case 1:
			system ("cls");
			consumo_agua( posicion,  c_usuario, registro_user, nombres,Mes );
			//funcion contenida en uno de los archivos llamados 
			break;
		case 2:
			system ("cls");
			modificar_c_agua(posicion,  c_usuario, registro_user, nombres,Mes);
			//funcion contenida en uno de los archivos llamados
			
		case 3 : 
		break;
		default:
		system("cls");
			break;
		}
	}while (opcionnumber != 3);
}
