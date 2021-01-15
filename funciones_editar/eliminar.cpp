#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "eliminar.h"
#include "./imprimir.h"
#include "clearP.h"
#include "../funciones_diego/validar_correlativo.h"
#include "../funciones_diego/estructura_r_r.h"


void eliminar (char Nombres[N][100], char Apellidos[N][100], char Dui[N][11], char Numero_cuenta[N][10], char anio[N][11], int& i)
{
    

    int posicion = 0;
    bool exito = false;
    char clear;
    do
    //se verifica que el numero correlativo que se esta ingresando coincida con uno existente
    {
        imprimir("ingrese el numero correlativo del usuario a eliminar");
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

    //validacion para eliminar 
    char confirmar[1];
    
    do
    {
        imprimir("desea eliminar su cuenta?   [precione 's' para si o 'n' para no ]");
        cin >> confirmar;

        if (confirmar[0] == 115)
        {
            exito = true;
        }

        else if (confirmar[0] == 110)
        {
            exito = false;
            return;
        }
        limpiar();

    } while (confirmar[0] != 115 && confirmar[0]!= 110 );

    for (int a = posicion; a < i; a++)
    {
       strcpy(Nombres[a],Nombres[a+1]);
       strcpy(Apellidos[a],Apellidos[a+1]);
       strcpy(Dui[a],Dui[a+1]);
       strcpy(anio[a],anio[a+1]);
       strcpy(Numero_cuenta[a],Numero_cuenta[a+1]);

       

    }

}
