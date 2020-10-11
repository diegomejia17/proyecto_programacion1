#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

#pragma warning(disable : 4996)
using namespace std;
const int N = 100;

void Registros(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuent[N][10]);
//prototipo de agregar modificar y eliminar los usuarios
void registro_resibos();
//esta funcion es el prototipo de el registro de recibos
int main()
{
	char Nombres[N][100] = { "\0" }, Apellidos[N][100] = { "\0" }, Numero_cuenta[N][10] = { "\0" };
	int Dui[N];
	int opccion;
	do {
		
		cout << "CONTROL DE RECIBO DE AGUA" << endl;
		cout << "1: Registro de usuario" << endl;
		cout << "2: Registro de consumo de agua mensual" << endl;
		cout << "3: Registro de pago de recibo de agua" << endl;
		cout << "4: Informe de pago de usuarios" << endl;
		cout << "5: salir" << endl;
		cin >> opccion;
		system("Cls");


		switch (opccion)
		{

		case 1:
		{
			Registros(Nombres, Apellidos, Dui, Numero_cuenta);
			//agregar modificar y eliminar los usuarios
			system("Cls");
		} break;
		case 2:
		{

		}break;
		case 3:
		{
			registro_resibos();

		}break;
		case 4:
		{

		}break;
		default:
		{

		}break;

		}
	} while (opccion > 0);



	getchar();
	cin.get();
}
void gotoxy(int x, int y)//para posicionamiento de las impresiones
{//esta funcion permite el posicionamiento del curso x, y
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Registros(char Nombres[N][100], char Apellidos[N][100], int Dui[N], char Numero_cuenta[N][10])//funcion para agregar modificar y eliminar los usuarios

{
	int i = 0, Opc_Registro;
	char aux[N][10] = { "\0" }, anio[N][10] = { "\0" };
	do {
		cout << "Registros" << endl;
		cout << "1: Nueva cuenta" << endl;
		cout << "2: Editar cuenta" << endl;
		cout << "3: Eliminar cuenta" << endl;
		cout << "4: Menu principal" << endl;
		cin >> Opc_Registro;
		system("Cls");
		switch (Opc_Registro)
		{
		case 1:
		{
			//agregar usuarios maximo 100
			fflush(stdin);
			cout << "Ingresa los nombre" << endl;
			gets_s(Nombres[i]);
			cout << "Ingresa Tus apellidos" << endl;
			gets_s(Apellidos[i]);
			cout << "Ingrese el anio de asociado" << endl;
			gets_s(anio[i]);
			cout << "Ingresa el numero de DUI" << endl;
			cin >> Dui[i];

			system("Cls");

			//numero correlativo
			do {
				strcpy(Numero_cuenta[i], anio[i]);
				strcat(Numero_cuenta[i], "-");
				if ((strlen(Numero_cuenta[i]) + i) == 8 - i)
				{
					strcat(Numero_cuenta[i], "0");
				}
				else
				{
					//ito(i,aux[i],10);
					strcat(Numero_cuenta[i], "7");
				}

			} while (strlen(Numero_cuenta[i]) == 8);



			i++;

		}break;
		case 2:
		{
			//muestra de usuario
			gotoxy(0, 0);
			cout << "N de usuario";
			gotoxy(25, 0);
			cout << "Numero de cuenta";
			gotoxy(50, 0);
			cout << "Nombre";
			gotoxy(75, 0);
			cout << "Apellido";
			gotoxy(100, 0);
			cout << "Dui" << endl;
			cout << "\n";
			for (int j = 0; j < i; j++)
			{
				gotoxy(0, j + 1);
				cout << j;
				gotoxy(25, j + 1);
				cout << Numero_cuenta[j];
				gotoxy(50, j + 1);
				cout << Nombres[j];
				gotoxy(75, j + 1);
				cout << Apellidos[j];
				gotoxy(100, j + 1);
				cout << Dui[j];

			}
			system("pause>null");
			system("Cls");
			//editar cuenta
		}break;
		case 3:
		{
			//eliminar cuenta

		}break;
		default:
		{

		}break;
		}

	} while (Opc_Registro != 4);
}


void registro_pago()
{
	cout << "REGISTRO DE PAGO" << endl;
}

