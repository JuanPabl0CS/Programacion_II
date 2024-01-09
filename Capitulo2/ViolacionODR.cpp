int add(int x, int y)
{
    return x + y;
}

int add(int x, int y)
{
    return x+ y;
}

int main()
{
    int x;
    int x;
}
/*
Como se puede apreciar, una funcion se repite, cosa que ODR no permite,
a su vez se ingresa doble variable x, cosa que de igual manera ODR no permite 
y causa error al codigo.
*/