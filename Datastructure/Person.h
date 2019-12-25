#pragma once
#include <iostream>
using namespace std;

#define STR_LEN 50

typedef struct _person
{
	int ssh;
	char name[STR_LEN];
	char addr[STR_LEN];
} Person;

int Getssn(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);