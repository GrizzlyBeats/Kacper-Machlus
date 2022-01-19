#include <iostream> 
#include <vector>
#include <string>
 
struct Student {
    std::string imie;
    std::string nazwisko;
    std::vector <float> oceny;
};
 
struct Group {
    std::string nazwa;
    std::vector <Student> st;
};
 
//Zadanie 1
float average_of(std::vector < float > Tab)
{
    float suma = 0;
    for (int i = 0; i < Tab.size(); i++)
    {
        suma = suma + Tab[i];
    }
    return suma / Tab.size();
}
 
//Zadanie 2
std::vector <std::string> filter_palindromes(std::vector <std::string> words)
{
    std::vector <std::string> result;
 
    for (int i = 0; i < words.size(); i++)
    {
        bool isPalindrome = true;
        std::string word = words[i];
        int j = word.size() - 1;
        int k = 0;
        while (k < j)
        {
            if (word[k] != word[j])
            {
                isPalindrome = false;
            }
            ++k;
            --j;
        }
        if (isPalindrome)
        {
            result.push_back(word);
        }
    }
    return result;
 
}
 
 
//Zadanie 3
float dot_product(std::vector<float> a, std::vector<float> b)
{
    float result = 1;
    if (a.size() != b.size())
    {
        std::cout << "Error: wektory maja rozna wielkosc \n";
        return 0;
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            result *= (a[i] + b[i]);
        }
        return result;
    }
}
 
//Zadanie 4
float average_of(Student st)
{
    float suma = 0;
    for (int i = 0; i < st.oceny.size(); i++)
    {
        suma += st.oceny[i];
    }
    return suma / st.oceny.size();
}
 
//Zadanie 5
std::vector<std::string> split(std::string sentence)
{
    std::vector < std::string> words;
    std::string word = "";
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            word += sentence[i];
        }
        else 
        {
            words.push_back(word);
            word = "";
        }
 
        if (i == sentence.length() - 1 && word.length() > 0)
        {
            words.push_back(word);
        }
    }
    return words;
}
 
//Zadanie 6
Student best_of_student(std::vector <Student> st)
{
    int tmp = 0;
    float max = average_of(st[0]);
 
    for (int i = 0; i < st.size(); i++)
    {
        if (average_of(st[i]) > max)
        {
            max = average_of(st[i]);
            tmp = i;
        }
    }
    return st[tmp];
}
 
//Zadanie 7
void add_student(Group& grp, Student& student)
{
    grp.st.push_back(student);
}
 
//Zadanie 8
std::string best_groups_name(std::vector<Group> grp)
{
    float max = 0;
    float suma;
    std::string result;
    float average;
 
    for (int i = 0; i < grp.size(); i++)
    {
        suma = 0;
        for (int j = 0; j < grp[i].st.size(); j++)
        {
            suma += average_of(grp[i].st[j]);
        }
        average = suma / grp[i].st.size();
        if (max < average)
        {
            max = average;
            result = grp[i].nazwa;
        }
    }
    return result;
}
 
int main()
{
    
    std::vector <float> a;
    a.push_back(7.5);
    a.push_back(9);
    a.push_back(10.5);
    std::cout << average_of(a) << std::endl;
 
    std::vector <std::string> b;
    b.push_back("kajak");
    b.push_back("adam");
    b.push_back("tolomasamolot");
    b.push_back("aganaga");
    b.push_back("samolot");
    std::vector <std::string> c = filter_palindromes(b);
    for (int i = 0; i < c.size(); i++)
    {
        std::cout << c[i] << std::endl;
    }
 
    std::vector <float> first;
    first.push_back(3.5);
    first.push_back(1.5);
    first.push_back(2.6);
    
    std::vector <float> second;
    second.push_back(2.5);
    second.push_back(4.5);
    second.push_back(3.1);
 
    std::vector <float> third;
    third.push_back(2.6);
    third.push_back(8.76);
 
    std::cout << dot_product(first, second) << "\n";
    std::cout << dot_product(first, third) << "\n";
 
    Student student;
    student.imie = "Adam";
    student.nazwisko = "Malysz";
    student.oceny.push_back(3.7);
    student.oceny.push_back(6.0);
    student.oceny.push_back(5.1);
    std::cout << average_of(student)<<"\n";
 
    std::vector <std::string> words = split("Ala ma kota");
    for (int i = 0; i < words.size(); i++)
    {
        std::cout << words[i] << "\n";
    }
 
    Student st_sec;
    Student st_thd;
 
    st_sec.imie = "Aleksander";
    st_sec.nazwisko = "Sobiech";
    st_sec.oceny.push_back(6);
    st_sec.oceny.push_back(5.8);
    st_sec.oceny.push_back(5.11);
 
    st_thd.imie = "Andrzej";
    st_thd.nazwisko = "Dziupla";
    st_thd.oceny.push_back(5.09);
    st_thd.oceny.push_back(5.81);
    st_thd.oceny.push_back(5.95);
 
    std::vector <Student> studenci;
    studenci.push_back(st_sec);
    studenci.push_back(st_thd);
    studenci.push_back(student);
 
    Student best = best_of_student(studenci);
    std::cout << best.imie << " " << best.nazwisko << " " << average_of(best) <<"\n";
 
    Group grp;
    grp.nazwa = "Grupa 7";
    add_student(grp, student);
    add_student(grp, st_sec);
 
    std::cout << grp.nazwa << "\n";
    for (int i = 0; i < grp.st.size(); i++)
    {
       std::cout << grp.st[i].imie << " " << grp.st[i].nazwisko << "\n";
    }
 
    Student st1;
    st1.oceny.push_back(5.11);
    st1.oceny.push_back(5.61);
    Student st2;
    st2.oceny.push_back(5.41);
    st2.oceny.push_back(4.61);
    Student st3;
    st3.oceny.push_back(5.21);
    st3.oceny.push_back(4.99);
    Group grp1;
    grp1.nazwa = "Grupa 1";
    add_student(grp1, st1);
    add_student(grp1, st2);
    add_student(grp1, st3);
 
    
    Student st4;
    st4.oceny.push_back(3.11);
    st4.oceny.push_back(3.71);
    st4.oceny.push_back(2.11);
    st4.oceny.push_back(4.61);
    Student st5;
    st5.oceny.push_back(2.41);
    st5.oceny.push_back(3.61);
    st5.oceny.push_back(3.41);
    st5.oceny.push_back(3.61);
    Student st6;
    st6.oceny.push_back(3.21);
    st6.oceny.push_back(4.00);
    st6.oceny.push_back(1.21);
    st6.oceny.push_back(4.00);
    Group grp2;
    grp2.nazwa = "Grupa 2";
    add_student(grp2, st4);
    add_student(grp2, st5);
    add_student(grp2, st6);
 
    std::vector <Group> grupy;
    grupy.push_back(grp1);
    grupy.push_back(grp2);
    std::string bestGrp = best_groups_name(grupy);
    std::cout << bestGrp << "\n";
}
 