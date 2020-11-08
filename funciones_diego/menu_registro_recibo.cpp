#include "menu_registro_recibo.h"//archivo que contiene la definicion de la funcion
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "consumo_agua.cpp"
#include "modificar_c_agua.cpp"

using namespace std;
void menu_registro_recibo(int posicion, char c_usuario[10],register_anual * registro_user,char nombres[N][100],char mes [1])
{
	int opcionnumber;
	char opcionletra[1];//variables que se en la funcion
	
	do
	{
	
		cout << "seleccione lo que desea hacer " << endl; //menu de opciones
		cout << "1- agregar consumo de metros cubicos de agua  " << endl;
		cout << "2- modificar el consumo del cliente " << endl;
		cout << "3- regresar al menu principal "<<endl;
		cin >> opcionletra;
		opcionnumber=atoi(opcionletra);//variable que sirven para hacer la convercion de char a numero 
		
	
		switch (opcionnumber)
		{
		case 1:
			system ("cls");
			consumo_agua( posicion,  c_usuario, registro_user, nombres,mes );
			break;
		case 2:
			system ("cls");
			modificar_c_agua(posicion,  c_usuario, registro_user, nombres,mes);
			
		case 3 : 
		break;
		default:
		system("cls");
			break;
		}
	}while (  opcionnumber< 0 || opcionnumber != 3);
}
