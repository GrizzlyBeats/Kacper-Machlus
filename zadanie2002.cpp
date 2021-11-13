#include <iostream>

int main()
{
    int a,b,c;
    std::cout<< "Podaj a: ";
    std::cin>>a;
    std::cout<< "Podaj b: ";
    std::cin>>b;
    std::cout<< "Podaj c: ";
    std::cin>>c;
    if(c==0)
    {
        std::cerr<<"Nieprawidłowa wartość c, nie można dzielić przez zero!\n";
        return 1;
    }
    else
    {
        for (int i=a; i<b; i++)
        {
            if ( i%c==0)
            {
                std::cout<< i << "\n";
            }    
        }
    }    
    return 0;
}