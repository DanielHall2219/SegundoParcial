#include "datosUsuarioEdu.h"
#include "Usuariosedu.h"
#include <cstring>
#include <iostream>

using std::string;

datosUsuarioEdu::datosUsuarioEdu(int valorUsuario, int valorContra)
{
    establecerUsuario( valorUsuario );
    establecerContra( valorContra );
}
int datosUsuarioEdu::obtenerUsuario() const
{
   return usuario;
}
void datosUsuarioEdu::establecerUsuario( int valorUsuario )
{
   usuario = valorUsuario;
}
int datosUsuarioEdu::obtenerContra() const
{
   return contra;
}
void datosUsuarioEdu::establecerContra( int valorContra )
{
    contra = valorContra;
}

datosUsuarioEdu::~datosUsuarioEdu()
{
    //dtor
}
