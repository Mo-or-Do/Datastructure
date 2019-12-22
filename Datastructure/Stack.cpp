#include "Stack.h"

Stack::Stack()
{
	current_size = 0;
	cur = NULL;
}

bool Stack::IsEmpty()
{
	if( current_size == 0 )
		return true;
	return false;
}

void Stack::Push(Data data)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->data = data;
	
	if(IsEmpty())
		cur = temp;
	else
	{
		temp->next = cur;
		cur = temp;
	}
	
	current_size++;
}

Data Stack::Pop()
{
	if(IsEmpty())
		return NULL;
	
	Data temp;
	
	Node* rPos = cur;
	cur = rPos->next;
	
	temp = rPos->data;
	
	delete rPos;
	
	current_size--;
	
	return temp;
}

Data Stack::Peek()
{
	if(IsEmpty())
		return NULL;
	
	return cur->data;
}