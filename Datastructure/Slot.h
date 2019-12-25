#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

typedef int Key;
typedef Person* Value;

enum SlotStatus {
	EMPTY,
	DELETED,
	INUSE
};

typedef struct _slot
{
	Key key;
	Value val;
	//enum SlotStatus status;//This code is not used in closed addressing method.
} Slot;