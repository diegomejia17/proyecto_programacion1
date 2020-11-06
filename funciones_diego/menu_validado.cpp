#include "menu_validado.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 bool menuvalidado(char a[1])
{
	int c = a[0];
	if (isdigit(c)==0)
	{
		return false;
	}
}
