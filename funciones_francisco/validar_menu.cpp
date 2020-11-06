#include <iostream>
#include "validarmenu.h"
#include <ctype.h>
#include <string.h>

using namespace std;

/*---------------------------------------FUNCION PARA VALIDAR NUMERO---------------------------------------------*/
  int validarmenu(char Nu [1])
  {
  	char c;
  	c= Nu[0];
  	if(isdigit (c) == 0)//Falso si el caracter no es letra
  	  {
  		return 0;
	  }
  }