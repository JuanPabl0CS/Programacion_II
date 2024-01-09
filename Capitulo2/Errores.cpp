#include

int main()
{
    int foo ()
    {
        std :: cout << "¡foo! \n";
        return 0;

    }

    foo();
    return 0;

}
/*
En este codigo podemos observar un error, el cual es hacer una funcion
en la funcion principal, y despues llamarla ya que esta creada sola se llama
y no hay necesidad de llamarla nuevamente, de igualmanera
no debemos crear funciones dentro de la funcion principal.
La forma correcta de hacerlo seria fuera de la funcion principal
y despues llamarla dentro de esta.
*/