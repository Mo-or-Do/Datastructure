#pragma once
#include <iostream>
using namespace std;

typedef int PriorityComp(int d1, int d2);

class HeapNode
{
public:
	HeapNode();
	HeapNode(int data);
	int priority;
	int data;
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
	int Delete();
	int GetParentIDX(int idx);
	int GetLeftChildIDX(int idx);
	int GetRightChildIDX(int idx);
	int GetHighPriorChild(int idx);
	void print();
};