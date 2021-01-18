#include "editar.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "../funciones_francisco/validar_letras.h"
#include "./validarN.cpp"
#include "../funciones_francisco/validar_dui.h"
#include "./imprimir.h"
#include "clearP.h"
#include "../funciones_diego/validar_correlativo.h"
#include "../funciones_francisco/numero_correlativo.h"
using namespace std;

void editar(char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int& i)
{
    

    char name_aux[100],dui_aux[11] = {"\0"},Pcorrelativo[10]  = {"\0"},anio_aux[11]  = {"\0"};
    //variables auxiliares 
    
    int posicion;
    bool exito = false;
    char clear;
    do
    //se verifica que el numero correlativo que se esta ingresando coincida con uno existente
    {
        imprimir("ingrese el numero correlativo del usuario a editar");
        cin >> Pcorrelativo;
        clear = cin.get();
        fflush (stdin);
        if (verificar_registo_resibos(Numero_cuenta,Pcorrelativo,posicion) == false && Pcorrelativo[0] != 48)
        {
            imprimir("DATO INGRESADO INCORRECTO");
            limpiar();
        }
        else
        {
            exito = true;
            limpiar();
        }
        

    } while (exito == false);
    if (Pcorrelativo[0]== 48) return;
    exito =  false;
    int op;
    char menu[1];

    do
    {
        imprimir("EDITAR USUARIO ");
        imprimir("Seleccione una opcion: ");
        imprimir("1.  cambiar nombres.");
        imprimir("2.  cambiar apellidos.");
        imprimir("3.  cambiar numero de dui.");
        imprimir("4.  cambiar anio de registro.");
        imprimir("si desea salir precione 0.");

        cin >> menu;
        fflush(stdin);
        op = atoi(menu);

        switch (op)
        {
        case 0:
        limpiar();
            return;
            break;
        case 1:
            do
            //ciclo que evalua el cambio del nombre.
            {
                cout << "el nombre anterior es: " << Nombres[posicion] << endl;
                cout << " digite el nuevo nombre:  ";
                cin.getline(name_aux, 100, '\n');
                fflush(stdin);
                system("cls");
            } while (!ValidarLetras2(name_aux));

            strcpy( Nombres[posicion],name_aux); //copia a la matriz principal la modificacion del nombre..
            imprimir("nombre sustituido con exito");
            limpiar();
            break;

        case 2:
            do
            //ciclo que evalua el cambio del apellido.
            {
                cout << "los apellidos anteriores son: " << Apellidos[posicion] << endl;
                cout << " digite el nuevo apellido:  ";
                cin.getline(name_aux, 100, '\n');
                fflush(stdin);
                system("cls");

            } while (!ValidarLetras2(name_aux));

            strcpy( Apellidos[posicion], name_aux); //copia a la matriz principal la modificacion del apellido..
            imprimir("apellido sustituido con exito");
            limpiar();
            break;

        case 3:

            do
            //ciclo que evalua el cambio del dui
            {
                cout << "el numero de dui anterior es: " << Dui[posicion] << endl;
                imprimirS("ingrese el nuevo numero: ");
                cin>> dui_aux;
                clear = cin.get();
                fflush(stdin);
                system("cls");
            } while (validarNumeros2(dui_aux) == 0 || validar_dui2(Dui, i, dui_aux) == false  || strlen(dui_aux) < 9 || strlen(dui_aux) > 9);

            strcpy( Dui[posicion],dui_aux); //copia a la matriz principal la modificacion del dui..
            imprimir("dui sustituido con exito");
            limpiar();
            break;

        case 4:
            //ciclo que evalua editar correctamente el año de registro.
            do
            {
                cout << "el anio anterior es: " << anio[posicion] << endl;
                cin>>anio_aux;

                clear = cin.get();
                fflush(stdin);
                system("cls");

            } while (validarNumeros2(anio_aux) == false || strlen(anio_aux) > 4 ||  strlen(anio_aux) < 4);

            strcpy( anio[posicion], anio_aux); //copia a la matriz principal la modificacion del anio..
            Numero_correlativo(Numero_cuenta, anio, posicion);
            imprimir("anio sustituido con exito");
            limpiar();
            break;

        default:
            limpiar();
            break;
        }

    } while (isdigit(menu[0]) == 0 || op != 0);


}