#include <iostream>

int main()
{
    int lim, dziel, suma=0;
    std::cout<< "Podaj limit: ";
    std::cin>> lim;
    std::cout<< "Podaj dzielnik: ";
    std::cin>> dziel;
    for (int i=0; i <=lim ;i++)
    {
        if (i%dziel==0)
        {
            suma+=i;
        }
     
    }
    std::cout<<suma<<"\n";
    
    return 0;
}