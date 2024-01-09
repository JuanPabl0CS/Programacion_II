#include <iostream>

int add( int x, int y)

int main()
{
    std::cout << "La suma 3 de 4 es: " << add(3, 4) << '\n';
    return 0;
}

int add( int x, int y)
{
    return x + y;
}
/*
Uno pensara que estara mal o que no servira, pero de hecho
es buena practica para saber que es lo que tenemos despues del main
si tenemos algo despues de este  no compilara por no tenerlo en la mira
trasera, por lo que se crea el prototipo de funcion para asi llamarlo si tener que
escribir codigo arriba y que este se mire mas limpio.
*/