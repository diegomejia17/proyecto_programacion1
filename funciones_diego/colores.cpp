#include "colores.h"
using namespace std;
void color (int colores)
{

    switch (colores )
    {
    case 0:
    cout <<"\033[0m  ";
        break;
    case 1:
    cout <<"\x1b[36m";
    break;
    case 2:
    cout<<"\x1b[41;37m";
    break;
    case 3: 
    cout <<"\x1b[102m";
    default:
     cout <<"\033[0m  ";
        break;
    }
}