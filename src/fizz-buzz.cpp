#include <iostream>
 
int main(int argc, char *argv[])
{
    int liczba = atoi(argv[1]);
    
    std::cout<<liczba<<" ";
    
    
    if(liczba%3 == 0)
    {
        std::cout<<"Fizz";
    }
    
     if(liczba%5 == 0)
    {
        std::cout<<"Buzz";
    }
 
 
    return 0;
}