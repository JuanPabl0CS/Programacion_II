#include <iostream>

//Este seria add.cpp
int add(int x, int y){
    return x + y;
} 
#include <iostream>
#include "add.h" //Inserte el contenido de add.h en este punto, tenga en cuenta el uso de comillas dobles aqui

//Estos serian los codigos 
//Este seria main.cpp 

int add(int x, int y);

int main(){
    std::cout << "La suma de 3 + 4 es: " << add(3, 4) << '\n';
    return 0;
}

//Empezaria el add.h
//1) Deberiamos de tener un protector de encabezado aqui, pero lo omitiremos por simplicidad 

//2) Esto es el contenido del archivo.h, que es donde van las declaraciones 
int add(int x, int y); //Prototipo de funcion para add.h - !NO olvide el punto y coma 
