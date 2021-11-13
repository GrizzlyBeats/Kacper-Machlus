#include <iostream>

int main( int argc, char* argv[])
{
    int n =std::stoi(argv[1]);
    
    for (int i=2; i<argc; i++)
    {
        int x = std::stoi(argv[i]);
        if(n>x)
        {
            std::cout<<n<<">"<<argv[i]<<"\n";
        }
        else if(n<x)
        {
            std::cout<<n<<"<"<<argv[i]<<"\n";
        }
        else
        {
            std::cout<<n<<"="<<argv[i]<<"\n";
        }
    }    
    return 0;

}