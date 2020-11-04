#include "registro_recibo.h"
#include <iostream>
#include "../funciones_francisco/validarmenu.cpp"
#include "validar_correlativo.cpp"
#include "menu_registro_recibo.cpp"
void registro_resibos(char numero_cuenta[N][10] )
{
	char c_usuario[10] = { '\0' };//arreglo que contiene el numero correlativo que sera evaluado
	int posicion;//almacena la pocicion del numero correlativo
	char mes [1];//almacena el mes que se desea pagar

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

        }while(Validarmenu(mes,2)==false || verificar_registo_resibos(numero_cuenta,c_usuario,posicion)==false);
        //mientras las funciones retornen falso, se seguira pidiendo los datos
		

	menu_registo_recibo(posicion, c_usuario);


}