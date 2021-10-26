#include <iostream>
 
int main(int argc, char *argv[])
{
    int liczba;
    
    if(argc[1] == null)
    {
        liczba = 99;
    }else
    {
        liczba = atoi(argv[1]);
    }
    
    
    for(int i = liczba; i>= 0; i-- )
    {
        if(i > 0)
        {
            std::cout<<i<<" bottles of beer on the wall, "<<i<<" bottles of beer. \n Take one down, pass it around, "<<i-1<<" bottles of beer on the wall\n";
        }
        
        if(i == 0)
        {
            std::cout<<"No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, "<<liczba<<" bottles of beer on the wall...";
        }
    }
 
 
    return 0;
}