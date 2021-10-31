#include <iostream>
 
struct Dane {
	std::string Imie;
 
	Dane(std::string nImie)
	{
		Imie = nImie;
	}
 
	~Dane()
	{
		std::cout << Imie << " DESTRUCTION";
	}
};
 
int main()
{
	Dane dane("Bozydar");
	return 0;
}