#include <iostream>

int getValueFromUser()
{
    std::cout << "Ingrese un entero: \n";
    int input{};
    std::cin >> input;
    return input;
}

int main()
{
    int input = getValueFromUser();  
    std::cout << input << " duplicado es: " << input * 2 << '\n';

    return 0;
}
/*
El error estaba que al iniciar la "entrada" como no estaba declaraada no podia ingresar el numero
por lo que solo input podria recibir valor, al recibirlo se le coloca un return para cuando este reciba
un valor vaya directamente a la funcion principal donde es llamada, y realiza el mensaje que el input 
ingresado duplicado es input * 2.

*/