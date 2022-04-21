#include <iostream>
#include "Usuarios.h"
#include "Catalogos.h"
#include "Procesos.h"
#include "Informes.h"

using namespace std;

int escribirOpcion();
enum Opciones { Catalogos = 1, Procesos, Informes, FIN };

int main()
{
   Usuarios claseusuarios;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
            case Catalogos:
                {
                    Catalogos clasecatalogos;
                }
            break;
            case Procesos:
                {
                    Procesos claseprocesos;
                }
            break;
            case Informes:
                {
                    Informes claseinformes;
                }

            break;
        }
    }
    return 0;
}

int escribirOpcion(){
    system("cls");
    cout<<"\t\t\t--------------------------------------------------"<<endl;
	cout<<"\t\t\t|    9959-21-1395 Daniel Alexander Hall Alvarez  |"<<endl;
	cout<<"\t\t\t--------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. Catalogos" << endl
        << "\t\t\t  2. Procesos" << endl
        << "\t\t\t  3. Informes" << endl
        << "\t\t\t  4. Finalizar el Programa" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}
