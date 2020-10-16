 const  int C = 100;
using namespace std;
/*---------------------------------------FUNCION PARA VALIDAR NUMERO---------------------------------------------*/
int ValidarNumeros(char Nu[C][11], int i)
        {
                int j = 0;
                char c;
                for (j = 0; j < strlen(Nu[i]); j++)//Numero de caracteres
                        {
                                c=Nu[i][j];
                                if(isdigit (c) == 0)//Falso si el caracter no es letra
                                        {
                                                cout<<"El caracter: "<<c<<" no es valido"<<endl;
                                                return 0;
                                        }
                        }
        }

