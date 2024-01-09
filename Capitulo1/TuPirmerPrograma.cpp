#include <iostream>
//Libreria estandar para STD/COUT/CIN

int main(){

    int numero, mul;
    //Declaracion de variables

    std::cout << "Ingrese un numero: \n";// Pide un numero
    std::cin  >> numero;
    //ingresa el numero
    mul = numero * 2;
    // hace la multiplicacion x2
    std::cout << "El doble de su numero es: \n"; // muestra en pantalla el numero
    std::cout << mul;// ingresa la multiplicacion resultante

    return 0;

}