#include <iostream>
#include <string>



int main()
{
    std::string pass ="profesor";
    std::string x="";
    do
    {
        std::cout<<"Password:";
        std::getline(std::cin,x);
    
    
    }
    while(pass!= x);
    std::cout<<"ok!\n";

    return 0;
}