#pragma once
#include <string>
enum class Sex { Male, Female };
using namespace std;

class Person {
private:
	static int next_ID;

	const int ID;
	char* name;
	Sex sex; 
	Person* mother;
	Person* father;

	Person(const char*, Sex);
	Person(const char*, Sex, Person*);
	Person(const char*, Sex, Person*, Person*);

	void Erase();
	void Clone(const Person&);

public:
	static Person CreateAdam();
	static Person CreateEva();

	Person(const Person&); // конструктор копирования

	Person& operator =(const Person&); 

	~Person(); // деструктор

	void SetName(const char*);
	const char* GetName() const;

	Person GiveBirth(const char*, Sex, Person* = NULL);

	string Print();

	int GetID() { return ID; }
};