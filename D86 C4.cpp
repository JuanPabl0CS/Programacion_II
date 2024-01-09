#include <iomanip>
#include <iostream>


int main()
{
double zero {0.0};
double posinf {5.0 / zero } 
std::cout « posinf « '\n';
double neginf { -5.0 / zero }; // infinito r
std：：cout << neginf << 'In'；
double nan { zero / zero }; // no es un núme 
std:: cout « nan « '\n';

    return 0;
}