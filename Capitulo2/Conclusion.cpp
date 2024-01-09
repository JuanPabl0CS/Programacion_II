#include <iostream>

int return7(){

    return 7;

}

int return9(){

    return 9;
    
}

int main()
{
    std::cout << return7() + return9() << '\n' ;

    return 0;
}

/*
Este compilara el numero 16 ya que este retrona numeros 7 y 9
solo se llama la funcion creada y las suma, en su interior estan dichos numeros
por lo tanto suma lo que este dentro de ellas.
*/

#include <iostream>

int return7(){

    return 7;

    int return9(){

    return 9;
    
}

}


int main()
{
    std::cout << return7() + return9() << '\n' ;

    return 0;
}
/*
En este programa hay un error, tenemos una funcion dentro de otra, por lo tanto
el programa no compilara, y al hacer la suma no encuentra el return 9 ya que este esta dentro de return 7.

*/

#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    return7();
    return9();

    return 0;
}
/*
Este compilara los numeros
7
9
en ese orden respectivamente 
*/

#include <iostream>

void printA()
{
    std::cout << "A \n";
}

void printB()
{
    std::cout << "B \n";
}

int main()
{
    printA();
    printB();

    return 0;
}
// Este programa imprime A y B

#include <iostream>

void printA()
{
    std::cout << "A \n";

}

int main()
{
    std:cout << printA() << '\n';
    return 0;
}
//este programa solo imrpime A

#include <iostream>

int getNumbers()
{
    return 5;
    return 7;

}

int main()
{
    std::cout << getNumbers()<< '\n';
    std::cout << getNumbers()<< '\n';

    return 0;
}
// este codigo de aqui impirmira 5 y 7 dos veces
// ya que la funcion imprime 5 y 7 y se llama 2 veces
// la funcion.

#include <iostream>

int return 5()
{
    return 5;
}

int main()
{
    std:cout << return 5() << '\n';

    return 0;

}

// este programa no compilara, ya que la funcion return 5 
// esta mal hecha toma la funcion como un return y no procede a la siguiente
// intruccion del main.

#include <iostream>

int returnFive()
{
    return 5;
}

int main()
{
    std::cout << returnFive << '\n';

    return 0;
}
// este codigo mostrara el numero 5

/*
Pregunta 2: ¿Qué significa “DRY” y por qué es una práctica útil a seguir?
R= Dont repeat yourself o no te repitas en español, es una practica muy util, ya que 
no nos repetimos como con los errores que hicimos en el pasado ahora son aprendizajez de
lo que no debemos realizar.
*/