#pragma once
#include <iostream>
using namespace std;

typedef int Data;

class Node
{
	public:
	Data data;
	Node* next;
};

class Stack
{
	int current_size;
	Node* cur;
public:
	Stack();
	void Push(Data data);
	Data Pop();
	Data Peek();
	bool IsEmpty();
};