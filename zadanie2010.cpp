#include <iostream>

int main()
{
    int x,silnia=1;
    std::cout<<"Podaj liczbe: ";
    std::cin>>x;
    int i=x;
    do
    {
       silnia*=i;
        --i; 
    }while(i>=1)  ; 
    std::cout<<silnia<<"\n";
    return 0;
}