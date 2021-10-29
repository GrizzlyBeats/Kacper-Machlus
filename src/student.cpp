#include <iostream>
#include "Student.h"
 
Student::Student()
{
    Imie = "";
    Nazwisko = "";
    numerIndeksu = "";
    aktualnySemestr = 0;
    srednia = 0;
}
 
std::string Student::to_String() const
{
    return Imie + " " + Nazwisko + " " + numerIndeksu + " " + std::to_string(aktualnySemestr) + " " + std::to_string(srednia);
}
 
int main()
{
    Student student;
    student.Imie = "TwojeImie";
    student.Nazwisko = "TwojeNazwisko";
    student.numerIndeksu = "TwojNrIndeksu";
    student.aktualnySemestr = 1;
    student.srednia = 5.0f;
 
    std::cout << student.to_String();
 
    return 0;
}