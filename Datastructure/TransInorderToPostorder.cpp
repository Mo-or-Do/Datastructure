#include "TransInorderToPostorder.h"

int GetOpPriority(char t)
{
	switch (t)
	{
	case '(':
	case ')':
		return 1;
		break;
	case '+':
	case '-':
		return 2;
		break;
	case '*':
	case '/':
		return 3;
	}
	return 0;
}

int WhoisPrecOp(char op1, char op2)
{
	if (GetOpPriority(op1) > GetOpPriority(op2))
		return 1;
	if (GetOpPriority(op1) < GetOpPriority(op2))
		return -1;
	return 0;
}

void TransInorderToPostorder(char* exp, int explen)
{
	int cur = 0;
	char *temp = NULL;
	stack<int> T;
	temp = new char[explen+1];

	for (int i = 0; i < explen; i++)
	{
		if (isdigit(exp[i]))
			temp[cur++] = exp[i];
		else
		{
			int op;

			if (exp[i] == ')')
			{
				op = T.top();
				T.pop();
				while (op != '(')
				{
					temp[cur++] = op;
					op = T.top();
					T.pop();
				}
			}
			else if (exp[i] == '(')
			{
				T.push(exp[i]);
			}
			else
			{
				while (!T.empty() && WhoisPrecOp(exp[i], T.top()) <= 0)
				{
					temp[cur++] = T.top();
					T.pop();
				}
				T.push(exp[i]);
			}

		}
	}

	while (!T.empty())
	{
		temp[cur++] = T.top();
		T.pop();
	}

	temp[cur] = '\0';//이거 넣으면 에러 없음

	for (int i = 0; i < cur+1; i++)
		exp[i] = temp[i];
	
	delete temp;
}