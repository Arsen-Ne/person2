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

Person::Person(const Person& d) : ID(++next_ID) {
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
	sex = d.sex;
	mother = d.mother;
	father = d.father;
}

Person::Person(const char* aname, Sex asex, Person* amother) : ID(++next_ID) {
	SetName(aname);
	sex = asex;
	mother = amother;
}

Person::Person(const char* aname, Sex asex, Person* amother, Person* afather) : ID(++next_ID) {
	SetName(aname);
	sex = asex;
	mother = amother;
	father = afather;
}

Person::~Person() {
	delete[] name;
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

Person Person::GiveBirth(const char* aname, Sex asex) {
	if (this->sex == Sex::Male) {
		throw exception("Cannot give birth. Invalid sex (MALE)");
	}
	return Person(aname, asex, this);
}
Person Person::GiveBirth(const char* aname, Sex asex, Person* afather) {
	Person child = GiveBirth(aname, asex);
	child.SetFather(afather);
	return child;
}

void Person::SetFather(Person* afather) {
	if (this->sex == Sex::Female) {
		throw exception("Cannot assert father. Invalid sex (FEMALE)");
	}
	father = afather;
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