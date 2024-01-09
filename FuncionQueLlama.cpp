#include <iostream>

void doB()
{   // aqui se crea la primer funcion doB
    std::cout << "En doB () \n";
    //esta funcion muestra este mensaje
}

void doA()
{   // se crea la segunda funcion
    std::cout << "Iniciando doA () \n";
    doB();
    // llama a la primer funcion para mostrar el mensaje dentro de ella
    std::cout << "Finalizando doA () \n";
    // finaliza

}

int main()
{   // la funcion principal
    std::cout <<"Iniciando main () \n";
    doA();
    // llama a doA solamente ya que en doA ya se llamo a doB y no hay
    // necesidad de volver a llamarlo
    std::cout << "Finalizando main () \n";
    return 0;

}