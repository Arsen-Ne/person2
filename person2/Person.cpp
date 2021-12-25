#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <exception>
#include <string>
#include <sstream>

using namespace std;

int Person::next_ID = 0;

Person::Person(const char* aname, Sex asex) : ID(++next_ID), sex(asex) {
	SetName(aname);
}

Person::Person(const char* aname, Sex asex, Person* amother) : Person(aname, asex) {	
	mother = amother;
}

Person::Person(const char* aname, Sex asex, Person* amother, Person* afather) : Person(aname, asex, amother) {
	father = afather;
}

void Person::Erase() {
	delete[] name;
}
void Person::Clone(const Person& p) {
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	sex = p.sex;
	mother = p.mother;
	father = p.father;
}

Person:: ~Person() {
	Erase();
}

Person::Person(const Person& p) : ID(++next_ID) {
	Clone(p);
}

Person& Person::operator =(const Person& p) {
	if (this != &p) {
		Erase(); Clone(p);
	}
	return *this;
}

void Person::SetName(const char* aname) {
	if (aname == NULL)
		throw exception("Invalid parameter name (NULL)");
	if (aname[0] == '\0')
		throw exception("Invalid parameter name (empty)");
	name = new char[strlen(aname) + 1];
	strcpy(name, aname);
}

const char* Person::GetName() const {
	return name;
}

string GetSexAsString(Sex s) {
	switch (s) {
	case Sex::Male: return "мужской";
	case Sex::Female: return "женский";
	}
}

Person Person::CreateAdam() {
	return Person("Adam", Sex::Male);
}

Person Person::CreateEva() {
	return Person("Eva", Sex::Female);
}

Person Person::GiveBirth(const char* aname, Sex asex, Person* afather) {
	if (sex == Sex::Male) {
		throw exception("This mother cannot give birth. Invalid sex (MALE)");
	}
	if (afather != NULL && afather->sex == Sex::Female) {
		throw exception("Cannot give birth from this father. Invalid sex (FEMALE)");
	}
	return Person(aname, asex, this, afather);
}

string Person::Print() {	
	stringstream ss;
	ss << "ID: " << ID << ", Name: " << name << ", Sex: " << GetSexAsString(sex);
	if (mother != NULL) {
		ss << ", Mother: " << mother->GetName();
	}
	else {
		ss << ", Mother: -";
	};
	if (father != NULL) {
		ss << ", Father: " << father->GetName();
	}
	else {
		ss << ", Father: -";
	};
	return ss.str();
		return "";
	}