#include <string.h>
#include <ctype.h>
#include<string.h>
const int I = 100;
void Ortografia(char texto[I][100],int i)
    {
        int Nu, j = 0;
        Nu = strlen(texto[i]);

        texto[i][0] = toupper(texto[i][0]);
        texto[i][1] = tolower(texto[i][1]);
        for(j = 1; j <= Nu; j++)
            {
                 if(texto[i][j] == 32)
                    {
                        texto[i][j+1] = toupper(texto[i][j+1]);
                    }else
                        {
                            texto[i][j+1] = tolower(texto[i][j+1]);
                        }
            }
    }