#include <iostream>

void doPrint()  // aqui se crea la funcion
{
    std :: cout << "En doPrint () \n";
    // muestra mensaje en consola
}

int main ()
{
    std :: cout << "Iniciando main () \n";
    doPrint();
    // aqui se llama la funcion
    doPrint();
    // se puede llamar mas de una vez
    std :: cout << "Finalizando main () \n";

    return 0;
}