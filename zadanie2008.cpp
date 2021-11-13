#include <iostream>

int main()
{
    int x,silnia=1;
    std::cout<<"Podaj liczbe: ";
    std::cin>>x;
    for (int i=x; i >=1; i--)
    {
       silnia*=i; 
    }   
    std::cout<<silnia<<"\n";
    return 0;
}