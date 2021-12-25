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

	Person adam = Person::CreateAdam();
	Person eva = Person::CreateEva();

	Person noi = eva.GiveBirth("Noi", Sex::Male, &adam);
	
	cout << adam.Print() << endl;
	cout << eva.Print() << endl;
	cout << noi.Print() << endl;
}