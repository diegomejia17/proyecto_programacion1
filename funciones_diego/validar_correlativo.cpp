#include "validar_correlativo.h"
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