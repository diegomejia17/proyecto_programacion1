#include "consumo_agua.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void consumo_agua(int posicion, char c_usuario[10],register_anual * registro_user,char nombres[N][100],char mes [1])
{
	int mes_n= atoi(mes);
	bool exito = false;
	float pago;
	do
	{
		cout <<"ingrese el consumo que tendra el usuario: "<< c_usuario<<endl;
		cout <<" llamado: "<< nombres[posicion]<<endl;
		cout << "en el mes:  "<<mes<<endl;
		
		registro_user[posicion].registro_anual[1][mes_n]=mes_n;
		cin>>pago;
		
		
		if(registro_user[posicion].registro_anual[1][mes_n]>0&&registro_user[posicion].registro_anual[2][mes_n]>0&& pago > 0)
		{
			registro_user[posicion].registro_anual[2][mes_n]=pago;
			exito = true;
		cout <<"registro exitoso"<<endl;
		
		return;	
		}
		else 
		{
			exito=false;
			cout <<"vuelve a intentarlo"<<endl;
			system("pause>0");
			system("cls");
		}
		
    }while (exito == false);
}
