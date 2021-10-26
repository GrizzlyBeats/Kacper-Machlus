#include <iostream>
 
 
 
int main(int argc, char *argv[])
{
    int liczba = atoi(argv[1]);
    
    for(int i = liczba; i >= 0; i--)
    {
        std::cout << i << "/n";
    }
 
 
    return 0;
}