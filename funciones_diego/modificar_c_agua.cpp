#include "modificar_c_agua.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

void modificar_c_agua (int posicion, char c_usuario[10],register_anual * registro_user,char nombres[N][100], char mes[1])
{
    int mes_n= atoi(mes);
	bool exito = false;
	float modificar;
	do
	{
		
		if(mes_n>0)
		{
			
		cout <<"el consumo a modificar del usuario: "<< c_usuario<<"  es : "<<endl;
        cout <<registro_user[posicion].registro_anual[2][mes_n]<<"metros cubicos "<<endl;
        cout <<"ingrese el nuevo consumo "<<endl;
        cin>> modificar;
        if (modificar > 0 )
        {
		    registro_user[posicion].registro_anual[2][mes_n]= modificar;
            exito=true;
            cout <<"modificacion exitosa"<<endl;
		    system("pause>0");
		    system("cls");
		    return;	
        }

		
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