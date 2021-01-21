#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "../constante.h"
#ifndef __VALIDAR_CORRELATIVO__H__
#define __VALIDAR_CORRELATIVO__H__
bool verificar_registo_resibos (char numero_cuenta[N][10], char c_ingresada[10], int& posicion )
{
	//variables controladoras de los ciclos
	for ( int a = 0; a < N; a++)
	{
		if ((stricmp (numero_cuenta[a],c_ingresada))==0)//condicional que regula el acceso al menu de registro recibos
		{
			posicion = a;
			return true; //si se cumple la condicion retornara verdadero.
		}
	}
	return false; //si el condicional no se cumple durante todo el for, retornara falso
} 

#endif  //!__VALIDAR_CORRELATIVO__H__