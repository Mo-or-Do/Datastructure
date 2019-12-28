#pragma once
#include <iostream>
#include "ALEdge.h"
using namespace std;

typedef Edge Data;
typedef int PriorityComp(Data d1, Data d2);

class HeapNode
{
public:
	HeapNode();
	HeapNode(Data data);
	int priority;
	Data data;
};

class Heap
{
	PriorityComp* comp;//if left is prior then return 1, else 0
	HeapNode* arr[100];
	int numofdata;
public:
	Heap(PriorityComp* action);
	bool IsEmpty();
	void Insert(HeapNode* hn);
	Data* Delete();
	int GetParentIDX(int idx);
	int GetLeftChildIDX(int idx);
	int GetRightChildIDX(int idx);
	int GetHighPriorChild(int idx);
	void print();
};