 const  int E = 100;
using namespace std;
/*---------------------------------------FUNCION PARA EDITAR CUENTA---------------------------------------------*/
void Editar(char Nombres[E][100], char Apellidos[E][100], char Dui[E][11], char Numero_cuenta[E][10], char anio[E][11], int i)
        {
                gotoxy(0,0);
                cout<<"N de usuario";
                gotoxy(25,0);
                cout<<"Numero de cuenta";
                gotoxy(50,0);
                cout<<"Nombre";
                gotoxy(75,0);
                cout<<"Apellido";
                gotoxy(100,0);
                cout<<"Dui"<<endl;
                cout<<"\n";
                for(int j = 0; j < i; j++)
                   {
                        gotoxy(0,j+1);
                        cout<<j;
                        gotoxy(25,j+1);
                        cout<<Numero_cuenta[j];
                        gotoxy(50,j+1);
                        cout<<Nombres[j];
                        gotoxy(75,j+1);
                        cout<<Apellidos[j];
                        gotoxy(100,j+1);
                        cout<<Dui[j];                                     
                   }
                system("pause>null");
                system("Cls");
        }
