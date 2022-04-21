#ifndef DATOSFACULTADES_H
#define DATOSFACULTADES_H
#include <iostream>

using namespace std;
class datosfacultades
{
    public:
        virtual ~datosfacultades();
        datosfacultades( int = 0, string = "", string = "", string = "", double = 0.0 );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerApellido( string );
        string obtenerApellido() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerSueldo( double );
        double obtenerSueldo() const;

        void establecerCorreo( string );
        string obtenerCorreo() const;

    protected:

    private:
        int codigo;
        char apellido[ 15 ];
        char nombre[ 10 ];
        char correo[ 15 ];
        double sueldo;

};

#endif // DATOSFACULTADES_H
