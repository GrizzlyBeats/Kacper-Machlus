#include <iostream>
#include <string>
 
int main(int argc, char *argv[])
{
    std::string firstArg = argv[1];
    std::string secondArg = argv[2];
    if(firstArg.compare("-r")==0)
    {
        for(int i = argc-1; i > 0; i--)
        {
            std::cout<<argv[i]<<" ";
            if(secondArg.compare("-l")==0)
            {
                std::cout<<"\n";
            }
        }
         if(secondArg.compare("-n")!=0)
         {
                std::cout<<"\n";
         }
    }else 
    {
        for(int i = 1; i < argc; i++)
        {
            std::cout<<argv[i];
            if(firstArg.compare("-l")==0)
            {
                std::cout<<"\n";
            }
        }
         if(firstArg.compare("-n")!=0)
         {
            std::cout<<"\n";
         }
    }
    
 
 
    return 0;
}