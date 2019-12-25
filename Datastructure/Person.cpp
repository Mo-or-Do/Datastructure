#include "Person.h"

int Getssn(Person* p)
{
	return p->ssh;
}

void ShowPerInfo(Person* p)
{
	cout << "SSN NUMBER : " << p->ssh << endl;
	cout << "NAME : " << p->name << endl;
	cout << "ADDRESS : " << p->addr << endl;
}

Person* MakePersonData(int ssn, const char* name, const char* addr)
{
	Person* p = new Person;
	p->ssh = ssn;
	strcpy(p->name, name);
	strcpy(p->addr, addr);

	return p;
}