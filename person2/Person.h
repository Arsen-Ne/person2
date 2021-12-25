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

	void SetFather(Person*);

public:
	static Person CreateAdam();
	static Person CreateEva();

	Person(const Person&); // конструктор копирования

	Person(const char*, Sex, Person*);
	Person(const char*, Sex, Person*, Person*);

	~Person(); // деструктор

	void SetName(const char*);
	const char* GetName() const;

	Person GiveBirth(const char*, Sex);
	Person GiveBirth(const char*, Sex, Person*);

	string Print();

	int GetID() { return ID; }
};