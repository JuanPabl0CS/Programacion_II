//NOMBRE:JUAN PABLO CARRION SOLIS

#include <iostream>

int main(){
std::cout << "Introduzca un numero: ";
int x{};
std::cin >> x;
std::cout << "Ingresaste" << x << '\n';
return 0;
}
/*
EJECUTA EL PROGRAMA VARIAS VECES Y RESPONDE
a) Una letra, como h
R= Imprime 0
b) Un número con componente fraccional. Pruebe números con componentes fraccionarios 
    menores que 0.5 y mayores que 0.5 (por ejemplo, 3.2 y 3.7).
R= Imprime 3 y 3, no toma en cuenta el decimal al ser de tipo entero
c) Un pequeño entero negativo, como -3
R= -3
d) Una palabra, como Hola
R=0
e) Un número realmente grande (al menos 10 mil millones
R=Ingrese 100M, y mostro 100M
*/