#include "Table.h"

void TBLInit(Table* pt, HashFunc* k)
{
	pt->hf = k;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	Key hv = pt->hf(k);
	Slot* ns = new Slot;
	ns->key = k;
	ns->val = v;

	pt->tbl[hv].push_back(ns);
}

Value TBLDelete(Table* pt, Key k)
{
	list<Slot*>::iterator it;
	Key hv = pt->hf(k);
	Slot* cslot;

	it = pt->tbl[hv].begin();

	do
	{
		if ((*it)->key == k)
		{
			cslot = (*it);
			pt->tbl[hv].erase(it);
			return cslot->val;
		}
		it++;
	} while (it != pt->tbl[hv].end());

	return NULL;
}

Value TBLSearch(Table* pt, Key k)
{
	list<Slot*>::iterator it;
	Key hv = pt->hf(k);
	Slot* cslot;

	it = pt->tbl[hv].begin();

	do
	{
		if ((*it)->key == k)
		{
			cslot = (*it);
			return cslot->val;
		}
		it++;
	} while (it != pt->tbl[hv].end());

	return NULL;
}