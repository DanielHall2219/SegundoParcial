#include <iostream>
#include "datosUsuarioEdu.h"
#include "Usuariosedu.h"
#include "facultades.h"

using namespace std;


int escribirOpcion();
int escribirOpcionCatalogo();
enum Opciones { catalogos = 1, procesos, informes, FIN };

int main()
{
    Usuariosedu usuarios;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
            case catalogos:
                {
                    enum OpcionesCatalogos { facultadess = 1, carreras, cursos, aulas, sedes, FIN };
                    int opcionCatalogos=0;
                    while (( opcionCatalogos = escribirOpcionCatalogo() ) != FIN)

                 {
                    switch ( opcionCatalogos ) {
                    case facultadess:
                    {
                        facultades facultadesclase;
                    }
                    break;
                    case carreras:
                    {
                        cout << "dscs :)";
                    }
                    break;
                    case cursos:
                    {
                        cout << "dscs :)";
                    }
                    break;
                    case aulas:
                    {
                        cout << "dscs :)";
                    }
                    break;
                    case sedes:
                    {
                        cout << "dscs :)";
                    }
                    break;

                    }
                 }
                }
        }
    }
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
int escribirOpcionCatalogo(){
    system("cls");
    cout<<"\t\t\t--------------------------------------------------"<<endl;
	cout<<"\t\t\t|                CATALOGOS SISTEMA               |"<<endl;
	cout<<"\t\t\t--------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. Facultades" << endl
        << "\t\t\t  2. carreras" << endl
        << "\t\t\t  3. cursos" << endl
        << "\t\t\t  4. aulas" << endl
        << "\t\t\t  5. sedes" << endl
        << "\t\t\t  6. Finalizar el Programa" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenuC;
   cin >> opcionMenuC;

   return opcionMenuC;
}
