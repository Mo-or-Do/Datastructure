#pragma once
#include <iostream>
using namespace std;

typedef int Data;

class Node
{
	public:
	Node* next;
	Data data;
};

class Queue
{
	int current_size;
	Node* tail;
public:
	Queue();
	void Enque(Data data);
	Data Deque();
	Data Peek();
	bool IsEmpty();
};