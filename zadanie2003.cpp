#include <iostream>

int main()
{
    int a,b,s;
    std::cout<< "Podaj liczbę początkową: ";
    std::cin>>a;
    std::cout<< "Podaj liczbę maksymalną: ";
    std::cin>>b;
    std::cout<< "Podaj liczbę na której zakończyć: ";
    std::cin>>s;
    if (s==0)
    {
        std::cout<< " s nie może byc zerem\n";
    }
    else if (b<a)
    {
        std::cout << " b nie może być mniejsze od a\n";
    }
    else if (s<0)
    
    {
        s*=-1;
        if(s>b)
        {
            std::cout<<" s nie może być większe od b";
        }    
        while (a<b)
        {
            std::cout<< a << "\n";
            a+=s;
        }
        /*Alternatywne rozwiązanie przy użyciu pętli for*/
        /*
        for(int i=a; i<b; i+=s)
        {
            std::cout<< i <<"\n";
        }
        */
        }
        else
        {
            if(s>b)
            {
                std::cout<<" s nie może być większe od b";
            }    
            while (a<b)
            {
                std::cout<< a << "\n";
                a+=s;
            }
             /*Alternatywne rozwiązanie przy użyciu pętli for*/
                /*
                for(int i=a; i<b; i+=s)
                {
                    std::cout<< i <<"\n";
                }
                */
    }
    return 0;
}