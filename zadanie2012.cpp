#include <iostream>

int main(int argc, char* argv[])
{
    int w,in=1;  
    w =  std::stoi(argv[1]);
    for(int i=1; i<=w;i++)
    {
        
        for(int j=i; j<=in; j++)
        {
            std::cout<<"*";
            
        }
        in+=2;
        std::cout<<std::endl;
    }
    return 0;
}