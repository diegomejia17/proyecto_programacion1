#include "registro_recibo.h"
#include <iostream>
#include "validar_correlativo.cpp"
#include "menu_registro_recibo.cpp"
void registro_resibos(char numero_cuenta[N][10],register_anual * registro_user,char nombres[N][100])
{
	char c_usuario[10] = { '\0' };//arreglo que contiene el numero correlativo que sera evaluado
	int posicion;//almacena la pocicion del numero correlativo
	char mes [1];//almacena el mes que se desea pagar
	int mes_n;

    do
    {
        system("cls");
        cout << "ingrese el numero de cuenta del usuario al que desea agregar consumo de agua" << endl;
		cin >> c_usuario;
        
		system("cls");
		cout << "ingrese el mes del que desea generar registro" << endl;
		cout << "01 -> Enero" << "\n 02 -> Febrero" << "\n 03 -> Marzo" << "\n 04 -> Abril" << endl;
		cout << "05 -> Mayo" << "\n 06 -> Junio" << "\n 07 -> Julio" << "\n 08 -> Agosto" << endl;
		cout << "09 -> Septiembre " << "\n 10 -> Octubre " << "\n 11 -> Novienbre " << "\n 12 -> Dieciembre " << endl;
		cin >> mes;
		mes_n= atoi(mes);

        }while( verificar_registo_resibos(numero_cuenta,c_usuario,posicion)==false || mes_n<=0 || mes_n >12);
        //mientras las funciones retornen falso, se seguira pidiendo los datos
		

	menu_registro_recibo(posicion, c_usuario, registro_user , nombres , mes); /* 
	esta funcion sirve para mostrar las opciones para poder registrar un consumo de agua o modificar, 
	ademas en ella estan contenidas las otras funciones correspondientes a las opciones del men*/
}
