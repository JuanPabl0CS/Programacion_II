//Pregunta 1: ¿Qué imprime el siguiente programa?
#include <iostream>

void doIt( int x)
{
    int y {4};
    std::cout << "doIt: x =" << x << "y = " << y << '\n';
    x = 3;
    std::cout << "doIt: x =" << x << "y = " << y  << ' \n ';
}

int main ()
{
    int x{1};
    int y{2};
    std::cout << "doIt: x =" << x << "y = " << y << '\n';
    doIt(x);
    std::cout << "doIt: x =" << x << "y = " << y  << ' \n ';

}
// imrpime primero x = 1/ y = 2
// llama la segunda funcion e imprime repetido
// despues muestra lo primero y al  final 
// muestra lo  3 y 4