#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;
void registro_pago();

void Registros();
int main()
    {
        int opccion, Opc_Registro;
        cout<<"CONTROL DE RECIBO DE AGUA"<<endl;
        cout<<"1: Registro de usuario"<<endl;
        cout<<"2: Registro de consumo de agua mensual"<<endl;
        cout<<"3: Registro de pago de recibo de agua"<<endl;
        cout<<"4: Informe de pago de usuarios"<<endl;
        cout<<"5: salir"<<endl;
        cin>>opccion;

        do{
            switch(opccion)
                case 1: {
                            Registros();
                        }break;
                case 2: {

                        }break;
                case 3: {

                        }break;
                case 4: {

                        }break;
                default{

                        }break
            }while(opccion > 0);
            


        getchar();
        cin.get();
    }

<<<<<<< HEAD
ingresar()
=======
void Registros()
>>>>>>> d167099723b32cb01d092b4b639f48f8d5fa5794
    {
        cout<<"Registros"<<endl;
        cout<<"1: Nueva cuenta"<<endl;
        cout<<"2: Editar cuenta"<<endl;
        cout<<"3: Eliminar cuenta"<<endl;
        cin>>Opc_Registro;
            do{
                switch(opccion)
                    case 1: {
                           }break;
                    case 2: {
                            }break;
                    case 3: {
                            }break;
                    default {
                            }break;

                    }while(Opc_Registro > 0);
    }
<<<<<<< HEAD
=======

>>>>>>> d167099723b32cb01d092b4b639f48f8d5fa5794

void registro_pago()
{
	cout << "REGISTRO DE PAGO" << endl;
}
<<<<<<< HEAD
//se debe de trabajar con git hub y git
=======
>>>>>>> d167099723b32cb01d092b4b639f48f8d5fa5794
