#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
//#include "funciones_francisco/gotoxy.h"
#include "funciones_francisco/menu_registro_usuario.h"

using namespace std;

int main()
    {
        char Nombres[N][100] = {"\0"}, Apellidos[N][100] = {"\0"};
        char  Numero_cuenta[N][10] = {"\0"}, anio[N][11] = {"\0"}, Dui[N][11] = {"\0"};
        int  i= 0;
        int opccion;

        do{
        cout<<"CONTROL DE RECIBO DE AGUA"<<endl;
        cout<<"1: Registro de usuario"<<endl;
        cout<<"2: Registro de consumo de agua mensual"<<endl;
        cout<<"3: Registro de pago de recibo de agua"<<endl;
        cout<<"4: Informe de pago de usuarios"<<endl;
        cout<<"5: salir"<<endl;
        cin>>opccion;
        system("Cls");

        
            switch(opccion)
                {

                        case 1: 
                                {
                                        Menu_Registros_usuarios(Nombres, Apellidos, Dui, Numero_cuenta, anio, i);//agregar modificar y eliminar los usuarios
                                        system("Cls");
                                } break;
                        case 2: 
                                {

                                }break;
                        case 3:
                                {
									
                                }break;
                        case 4:
                                {

                                }break;
                        default:
                                {

                                }break;

                }        
            }while(opccion > 0);
            


        getchar();
        cin.get();
    }



//Funciones de Diego Mejia
bool verificar_registo_resibos(char numero_cuenta[N][10], char c_ingresada[10], int& posicion)
{
	int a;//variables controladoras de los ciclos
	for ( a = 0; a < N; a++)
	{
		if (numero_cuenta[a] == c_ingresada)//condicional que regula el acceso al menu de registro recibos
		{
			posicion = a;
			return true; //si se cumple la condicion retornara verdadero.
		}
	}
	return false; //si el condicional no se cumple durante todo el for, retornara falso
}
void menu_registo_recibos(int posicion, char c_usuario[10])
{
	cout << "seleccione lo que desea hacer " << endl;
	cout << "1- agregar consumo de agua del cliente " << endl;
	cout << "2- modificar el consumo del cliente " << endl;

}
void registro_resibos(char menu_registro[N][10] )
{
	char c_usuario[10] = { '\0' };
	bool controlador;
	int posicion;
	int mes;
	do
	{
		cout << "ingrese el numero de cuenta del usuario al que desea agregar consumo de agua" << endl;
		cin >> c_usuario;
		system("cls");
		cout << "ingrese el mes del que desea generar registro" << endl;
		cout << "01 -> Enero" << "\n 02 -> Febrero" << "\n 03 -> Marzo" << "\n 04 -> Abril" << endl;
		cout << "05 -> Mayo" << "\n 06 -> Junio" << "\n 07 -> Julio" << "\n 08 -> Agosto" << endl;
		cout << "09 -> Septiembre " << "\n 10 -> Octubre " << "\n 11 -> Novienbre " << "\n 12 -> Dieciembre " << endl;
		cin >> mes;
		controlador = verificar_registo_resibos(menu_registro, c_usuario,posicion);
		system("cls");
	} while (controlador == false);

	menu_registo_recibos(posicion);


}

