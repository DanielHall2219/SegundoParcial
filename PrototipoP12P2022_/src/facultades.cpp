#include "facultades.h"
#include "datosfacultades.h"
#include <iostream>
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>
using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;
#include <cstdlib>

int opcionEmp();
void imprimirRegistroEmp( fstream& );
void crearArchivoCreditoEmp();
void mostrarLineaEmp( ostream&, const datosfacultades & );
void nuevoRegistroEmp( fstream& );
int obtenernCodigoEmp( const char * const );
void modificarRegistroEmp( fstream& );
void eliminarRegistroEmp( fstream& );
void consultarRegistroEmp( fstream& );
void mostrarLineaPantallaEmp( const datosfacultades &);

using namespace std;

facultades::facultades()
{
    fstream creditoEntradaSalida( "facu.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoEmp();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionEmp() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroEmp( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroEmp( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroEmp( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroEmp( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroEmp( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
}
int opcionEmp(){
    //system("cls");
    cout<<"\n\t\t\t---------------------------------"<<endl;
    cout<<"\n\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t |   FACULTADES  |"<<endl;
	cout<<"\t\t\t\t------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar facultad" << endl
        << "\t\t\t 3. Modificar facultad" << endl
        << "\t\t\t 4. Eliminar facultad" << endl
        << "\t\t\t 5. Mostrar Lista de facultad" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu;
    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroEmp( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirFacultad.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Apellido" << setw( 14 ) << "Nombre" << setw( 16 ) << "Correo"<< right
       << setw( 10 ) << "Sueldo" << endl;
    leerDeArchivo.seekg( 0 );

    datosfacultades facultadess;
    leerDeArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

    while ( !leerDeArchivo.eof() ) {
        if ( facultadess.obtenerCodigo() != 0 )
        mostrarLineaEmp( archivoImprimirSalida, facultadess );
        leerDeArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaEmp( ostream &salida, const datosfacultades &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerCorreo().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed<< showpoint << registro.obtenerSueldo() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoEmp()
{
    ofstream creditoSalida( "facu.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    datosfacultades empleadoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &empleadoEnBlanco ), sizeof( datosfacultades ) );
}
void nuevoRegistroEmp( fstream &insertarEnArchivo )
{
    int codigo = obtenernCodigoEmp( "\nEscriba el Codigo de la facultad " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( datosfacultades ) );
    datosfacultades facultadess;
    insertarEnArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

    if ( facultadess.obtenerCodigo() == 0 ) {
        char apellido[ 15 ];
        char nombre[ 10 ];
        char correo[ 15 ];
        double sueldo;
        cout<<"Escriba el Area de la facultad: ";
        cin>> setw( 15 ) >> apellido;
        cout<<"Escriba el Nombre de la facultad: ";
        cin>> setw( 10 ) >> nombre;
        cout<<"Escriba el Correo de la facultad ";
        cin>> setw( 15 ) >> correo;
        cout<<"Escriba el Sueldo de la facultad ";
        cin>> sueldo;
        facultadess.establecerApellido( apellido );
        facultadess.establecerNombre( nombre );
        facultadess.establecerCorreo( correo );
        facultadess.establecerSueldo( sueldo );
        facultadess.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( datosfacultades ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &facultadess ), sizeof( datosfacultades ) );
        cout<<"\n Empleado agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "La facultad con codigo #" << codigo << " ya contiene informacion.\n" << endl;

} //FIN REGISTRO
int obtenernCodigoEmp( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroEmp( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Sueldo\n 2. Nombre\n 3. Estatus \n 4. Correo\n  R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo de la facultad que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosfacultades ));

        datosfacultades facultadess;
        actualizarArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

        if (facultadess.obtenerCodigo() != 0 ) {
            mostrarLineaEmp( cout, facultadess );
            cout << "\nEscriba aumento (+) o descuento (-): ";
            double cambiosu;
            cin >> cambiosu;
            double sueldoAnterior = facultadess.obtenerSueldo();
            facultadess.establecerSueldo( sueldoAnterior + cambiosu );
            mostrarLineaEmp( cout, facultadess );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosfacultades ));

            actualizarArchivo.write(reinterpret_cast< const char * >( &facultadess ), sizeof( datosfacultades ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo de la facultad que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosfacultades ));

        datosfacultades facultadess;
        actualizarArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

        //ACTUALIZAR EL REGISTRO
        if (facultadess.obtenerCodigo() != 0 ) {
            mostrarLineaEmp( cout, facultadess );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = facultadess.obtenerNombre();
            facultadess.establecerNombre( nombre );
            mostrarLineaEmp( cout, facultadess );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosfacultades ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &facultadess ), sizeof( datosfacultades ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo de la facultad que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosfacultades ));

        datosfacultades facultadess;
        actualizarArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

        if (facultadess.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, facultadess );
                cout << "\nEscriba el nuevo Estatus: ";
                string apellido;
                cin >> apellido;

                string apellidoAnterior = facultadess.obtenerApellido();
                facultadess.establecerApellido( apellido );
                mostrarLineaEmp( cout, facultadess );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosfacultades ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &facultadess ), sizeof( datosfacultades ) );
        }
    }else if(opcionAc == 4){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo de la facultad que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosfacultades ));

        datosfacultades facultadess;
        actualizarArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

        if (facultadess.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, facultadess );
                cout << "\nEscriba el nuevo Correo: ";
                string correo;
                cin >> correo;

                string correoAnterior = facultadess.obtenerCorreo();
                facultadess.establecerCorreo( correo );
                mostrarLineaEmp( cout, facultadess );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosfacultades ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &facultadess ), sizeof( datosfacultades ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroEmp( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigoEmp( "\nEscriba el codigo de la facultad a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( datosfacultades ) );
    datosfacultades facultadess;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

    if ( facultadess.obtenerCodigo() != 0 ) {
        datosfacultades clienteEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( datosfacultades ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( datosfacultades ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-
void consultarRegistroEmp( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Apellido" << setw( 14 ) << " Nombre" << setw( 16 ) << " Correo" << right << setw( 10 ) << " Sueldo" << endl;
    leerDeArchivo.seekg( 0 );
    datosfacultades facultadess;
    leerDeArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );
    while ( !leerDeArchivo.eof() ) {
        if ( facultadess.obtenerCodigo() != 0 )
            mostrarLineaPantallaEmp(facultadess);
            leerDeArchivo.read( reinterpret_cast< char * >( &facultadess ), sizeof( datosfacultades ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaEmp( const datosfacultades &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerCorreo().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-


facultades::~facultades()
{
    //dtor
}
