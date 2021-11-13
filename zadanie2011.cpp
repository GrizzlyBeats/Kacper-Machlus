#include <iostream>

int main(int argc, char* argv[])
{
    int w,h;
    w =  std::stoi(argv[1]);
    h = std::stoi(argv[2]);
    for(int i=0; i<w;i++)
    {
        for(int j=0; j<h; j++)
        {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    return 0;
}