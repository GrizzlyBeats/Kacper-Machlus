#include <iostream>
#include <cmath>
int main() {
    int x;
    std::cout << "Choose operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Division of integers\n"
                 "6.Remainder of division\n7.Exponentiation\n8.Square root\n9.Absolute value\n";
    std::cin >> x;
    switch (x){
        case 1:
            int A1,A2;
            std::cout << "Type numbers for addition\n";
            std::cin  >> A1 >> A2;
            std::cout << "Result is " << A1+A2 << "\n";
            break;
        case 2:
            int S1,S2;
            std::cout << "Type numbers for subtraction\n";
            std::cin  >> S1 >> S2;
            std::cout << "Result is " << S1-S2 << "\n";
            break;
        case 3:
            int M1,M2;
            std::cout << "Type numbers for multiplication\n";
            std::cin  >> M1 >> M2;
            std::cout << "Result is " << M1*M2 << "\n";
            break;
        case 4:
            double D1,D2;
            std::cout << "Type numbers for division\n";
            std::cin >> D1 >> D2;
            if(D2==0){
                std::cout << "Divisor can't be 0" << "\n";
            }
            else{
                std::cout << D1/D2 << "\n";
            }
            break;
        case 5:
            int DI1,DI2;
            std::cout << "Type numbers for division of integers\n";
            std::cin >> DI1 >> DI2;
            if(DI2==0){
                std::cout << "Divisor can't be 0" << "\n";
            }
            else{
                std::cout << DI1/DI2 << "\n";
            }
            break;
        case 6:
            int MD1,MD2;
            std::cout << "Type numbers for remainder of division\n";
            std::cin >> MD1 >> MD2;
            if(MD2==0){
                std::cout << "Divisor can't be 0" << "\n";
            }
            else{
                std::cout << MD1%MD2;
            }
            break;
        case 7:
            int P1,P2;
            std::cout << "Type numbers for exponentiation\n";
            std::cin >> P1 >> P2;
            std::cout << pow(P1,P2) << "\n";
            break;
        case 8:
            int SQR;
            std::cout << "Type number for square root\n";
            std::cin >> SQR;
            if(SQR<0){
                std::cout << "Can't calculate square root of negative number" << "\n";
            }
            else {
                std::cout << sqrt(SQR) << "\n";
            }
            break;
        case 9:
            int AB;
            std::cout << "Type number for absolute value\n";
            std::cin >> AB;
            if(AB<0) {
                std::cout << "Result is " << AB*-1 << "\n";
            }else{
                std::cout << "Result is " << AB << "\n";
            }
            break;
        default:
            std::cout << "Wrong number" << "\n";
    }
    return 0;
}