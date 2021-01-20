#include "llenado.h"
#include "../constante.h"
#include "estructura_r_r.h"
void llenando(register_anual * registro_user)
{
    for (int  h = 0; h < N; h++)
    {
        for (int  i = 0; i < 5; i++)
        {
            for (int  j = 0; j <12 ; j++)
            {
               registro_user[h].registro_anual[i][j]=0; 
            }
        }  
    }
   
}
