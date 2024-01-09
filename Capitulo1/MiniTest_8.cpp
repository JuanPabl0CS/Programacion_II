/*
 Pregunta 1: Determine qué valores produce el siguiente programa. No 
compile este programa. Simplemente trabaja a través de él línea por línea en 
tu cabeza.
*/
#include <iostream>

int main()
{
    std::cout << 2 + 3 << '\n';
    // imprime 5

    int x{ 6 };
    int y{ x - 2 };
    std::cout << y << '\n';
    // imprime 4
    int z{ 0 };
    z = x;
    std::cout << z - x << '\n';
    // imrpime 0 ya que z tiene el valor de 0, y "x" copia el valor de z por lo tanto suma 0+0

    return 0;



}