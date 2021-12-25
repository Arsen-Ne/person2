#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h> 
#include "Person.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Person Adam = Person::CreateAdam();
	Person Eva = Person::CreateEva();
    cout << Adam.Print() << endl;
    cout << Eva.Print() << endl;
	
    Person Noi = Eva.GiveBirth("Noi", Sex::Male, &Adam);
    cout << Noi.Print() << endl; 

    try {
        Person Tu = Noi.GiveBirth("Era", Sex::Female);
    }
    catch (exception e) {
        cout << e.what() << endl;
    };
	
    try {
        Person Tu = Eva.GiveBirth("Sara", Sex::Female, &Eva);
    }
    catch (exception e) {
        cout << e.what();
    };

}