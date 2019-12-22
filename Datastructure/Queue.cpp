#include "Queue.h"

Queue::Queue()
{
	current_size = 0;
	tail = NULL;
}

bool Queue::IsEmpty()
{
	if( current_size == 0 )
		return true;
	return false;
}

void Queue::Enque(Data data)
{	
	Node* temp = new Node;
	temp->data = data;
	
	if(IsEmpty())
	{
		temp->next = temp;
		tail = temp;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	
	current_size++;
}

Data Queue::Deque()
{
	if(IsEmpty())
		return NULL;
	
	Node* rPos = tail->next;
	tail->next = rPos->next;
	
	Data temp = rPos->data;
	
	delete rPos;
	
	current_size--;
	
	return temp;
}

Data Queue::Peek()
{
	if(IsEmpty())
		return NULL;
	
	return tail->next->data;
}