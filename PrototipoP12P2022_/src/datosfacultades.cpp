#include "datosfacultades.h"
#include"facultades.h"
#include <cstring>
#include <iostream>

using std::string;

datosfacultades::datosfacultades(int valorCodigo, string valorApellido, string valorNombre, string valorCorreo, double valorSueldo )
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );
    establecerCorreo( valorCorreo );
    establecerSueldo( valorSueldo );

    }
int datosfacultades::obtenerCodigo() const
{
   return codigo;
}
void datosfacultades::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string datosfacultades::obtenerApellido() const
{
   return apellido;

}
void datosfacultades::establecerApellido( string apellidoString )
{
    const char *valorApellido = apellidoString.data();
    int longitud = strlen( valorApellido );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( apellido, valorApellido, longitud );

    apellido[ longitud ] = '\0';

}
string datosfacultades::obtenerNombre() const
{
   return nombre;
}
void datosfacultades::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';

}
double datosfacultades::obtenerSueldo() const
{
   return sueldo;
}
void datosfacultades::establecerSueldo( double valorSueldo )
{
   sueldo = valorSueldo;
}
string datosfacultades::obtenerCorreo() const
{
   return correo;
}
void datosfacultades::establecerCorreo( string correostring )
{
    const char *valorCorreo = correostring.data();
    int longitud = strlen( valorCorreo );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( correo, valorCorreo, longitud );

    correostring[ longitud ] = '\0';

}

datosfacultades::~datosfacultades()
{
    //dtor
}
