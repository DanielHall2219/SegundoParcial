#ifndef DATOSUSUARIOEDU_H
#define DATOSUSUARIOEDU_H


class datosUsuarioEdu
{
    public:
        virtual ~datosUsuarioEdu();
        datosUsuarioEdu(int = 0 , int =0);

        void establecerUsuario( int );
        int obtenerUsuario() const;

        void establecerContra( int );
        int obtenerContra() const;

    protected:

    private:
        int usuario;
        int contra;
};

#endif // DATOSUSUARIOEDU_H
