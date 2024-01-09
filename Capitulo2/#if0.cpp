#include <iostream>

int main(){

    std::cout << "Joe\n";

    #if 0 //No compile nada a partir de aqui 
        std :: cout << "Bob\n";
        std :: cout << "Steve\n";
    #endif // Hasta este este punto 

    return 0;    
}