#include <iostream>

int main()
{
    std::cout << "Ingrese un entero:";
    int num{};
    std::cin >> num;

    std::cout << num << " duplicado es:" << num * 2 << '\n';
    
    
    return 0;
}