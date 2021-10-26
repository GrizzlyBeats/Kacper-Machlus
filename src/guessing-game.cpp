#include <iostream>
#include <cstdlib>
#include <ctime>
 
int main()
{
    srand( time( NULL ) );
    int liczba, guess;
    liczba =( std::rand() % 100 ) + 1;
    bool flag = true;
    
    while(flag)
    {
        std::cout<<"Guess: ";
        std::cin>>guess;
        if(guess==liczba)
        {
            flag = false;
            std::cout<<"just right!\n";
        }else if(guess>liczba)
        {
            std::cout<<"too big\n";
        }else
        {
            std::cout<<"too small\n";
        }
    }
 
    
    return 0;
}