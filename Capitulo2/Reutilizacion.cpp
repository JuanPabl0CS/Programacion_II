#include <iostream>

int main()
{
    int x{};
    std::cout << "Ingrese un entero: ";
    std::cin >> x;

    int y{};
    std::cout << "Ingrese un entero : ";
    std::cin >> y;

    std::cout << x << " + " << y << " = " << x + y << '\n';
    return 0;

}
/*
Se reutiliza las funciones X y Y distintas veces para mostrar en consola
la reutilizacion es efectiva pero hay que tener cuidado cuando escribamos la funcion
a reutilizar.
*/