//Pregunta 1: ¿Qué pasa con este fragmento de programa?
#include <iostream>

int multiply( int x, int y)
{
    return x * y;

}

int main()
{
    std::cout << multiply (4, 5) << '\n';
    return 0;
}
// el error estaba en que era de tipo vacio por lo tanto no recibia numeros 

//Pregunta 2: ¿Qué dos cosas están mal con este fragmento de programa?

int multiply (int x, int y)
{
    int product{ x * y};
}

int main()
{
    std::cout << multiply(4) << '\n';
    return 0;
}
// este no compilara ya que solo cuenta con un muero el cual multiplicar, y
// lo segundo es que la funcion dentro de la funcion no funciona.

//Pregunta 3: ¿Qué valor imprime el siguiente programa

#include <iostream>

int add(int x, int y, int z)
{
    return x + y + z;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << multiply (add(1, 2, 3), 4) << '\n';
    return 0;
}
// imprimira el numero 24

//Pregunta # 4: Escriba una función llamada doubleNumber () que tome un
//parámetro entero. La función debe devolver el doble del valor del parámetro.
#include <iostream>

int doubleNumber(int number) {
    return number * 2;
}

int main() {

    int input;
    
    std::cout << "Ingrese un número entero: ";
    std::cin >> input;

   
    int result = doubleNumber(input);

    
    std::cout << "El doble del número ingresado es: " << result << std::endl;

    return 0;
}

//Pregunta # 5: Escriba un programa completo que lea un número entero del
//usuario, lo duplique usando la función doubleNumber () y luego imprima el
//valor duplicado en la consola.

#include <iostream>


int doubleNumber(int number) {
    return number * 2;
}

int main() {
    
    int input;

    
    std::cout << "Ingrese un número entero: ";
    std::cin >> input;

    
    int result = doubleNumber(input);

    
    std::cout << "El doble del número ingresado es: " << result << std::endl;

    return 0;
}
