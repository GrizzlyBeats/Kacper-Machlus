#include <iostream>

int main()
{
    int x,silnia=1;
    std::cout<<"Podaj liczbe: ";
    std::cin>>x;
    int i=x;
    while(i>=1)
    {
       silnia*=i;
        --i; 
    }   
    std::cout<<silnia<<"\n";
    return 0;
}