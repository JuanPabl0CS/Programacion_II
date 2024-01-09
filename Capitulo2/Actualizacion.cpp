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
    int x{getValueFromUser()};
    int y{getValueFromUser()};
    std::cout << x << " + " << y << " = " << x + y << '\n';
    return 0;
}
// se llama getvaluefromuser en las funciones de X y Y, asi se ingresa su valor y muestra a 
// consola su suma 