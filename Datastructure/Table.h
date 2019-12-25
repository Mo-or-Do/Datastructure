#pragma once
#include <iostream>
#include <list>
#include "Slot.h"
using namespace std;

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table
{
	list<Slot*> tbl[MAX_TBL];
	HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc* k);
void TBLInsert(Table* pt, Key k, Value v);
Value TBLDelete(Table* pt, Key k);
Value TBLSearch(Table* pt, Key k);