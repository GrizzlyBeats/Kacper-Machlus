#include <iostream>

bool czy_pierwsza(int a)
{
    if (a<2)
    {
        return false;
    }
    for (int i=2; i*i<=a; i++)
        {
            if(a%i==0)
            {
                return false ;
                
            }
            
        }
        return true;
    
}

int main()
{
    int a;
    std::cout<<"Podaj liczbe do sprawdzenia: ";
    std::cin>>a;
    if(czy_pierwsza(a)==0)
    {
        std::cout<<"Podana liczba nie jest pierwsza\n";
    }   
    else
    {
        std::cout<<"Podana liczba jest pierwsza\n";
    }
    return 0;
}