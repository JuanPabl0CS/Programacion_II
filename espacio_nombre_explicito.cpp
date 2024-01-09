#include <iostream>

int main(){

    std::cout << "Hola mundo!"; //Cuando decimos cout nos referimos al cout definido en el espacio de nombre std
    return 0;
}


//Esta es una directiva using que le dice al compilador que verifique 
//el espacio de nombres estandar al resolver identificadores sin prefijo 
using namespace std;

int main(){

    //Cout no tiene prefijo, por lo que el compilador comprobara 
    //si cout esta definido localmente o en el espacio de nombre std
    cout << "Hola mundo!";
    return 0;
}