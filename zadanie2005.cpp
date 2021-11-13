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
    int a,suma=0;
    std::cout<<"Podaj liczbe do sprawdzenia: ";
    std::cin>>a;
    if(czy_pierwsza(a)==0)
    {
        
        std::cout<<"Liczba nie jest pierwsza\n";
    }   
    else
    {
        for(int i=2; i<=a; i++)
        {
            if(czy_pierwsza(i))
            {
                suma+=i;
            }
        }
        std::cout<<"Suma liczb pierwszych: "<<suma<<"\n";
           
     }
    return 0;
}