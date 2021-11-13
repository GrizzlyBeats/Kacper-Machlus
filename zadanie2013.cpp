#include <iostream>

int main(int argc, char* argv[])
{
    int w,h;  
    w =  std::stoi(argv[1]);
    for(int i=w; i>0;i--)
    {
        
        for(int j=i; j>0; j--)
        {
            std::cout<<"*";
            
        }
      
        std::cout<<std::endl;
    }
    return 0;
}