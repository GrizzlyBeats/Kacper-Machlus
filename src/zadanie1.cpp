#include <iostream>
#include <string>



int main()
{
    std::string pass ="student";
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
