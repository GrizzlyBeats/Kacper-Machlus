#include <iostream>

int main(int argc, char* argv[])
{
    int w;
    w =  std::stoi(argv[1]);
    for(int i=1; i<=w;i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(i>1 && i<w && j>1 && j<w)
            {
                std::cout<<" ";
            }
            else
            {
            std::cout<<"*";
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}