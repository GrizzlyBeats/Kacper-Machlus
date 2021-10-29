#include <iostream>
#include <string>
auto main(int argc, char* argv[])-> int{
    if (argc == 1) {
        return 1;
    }
   
    std::string password=argv[1],haslo;
    do{
        std::cout << "password: ";
        std::cin >> haslo;
    }
    while(password!=haslo);
    std::cout << "ok!\n";

    return 0;
}