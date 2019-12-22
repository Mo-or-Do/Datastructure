#include "ExpressionTree.h"


ExpTree::ExpTree()
{
}

TreeNode* ExpTree::MakeExpTree(char exp[])
{
	int len = strlen(exp);
	TreeNode* temp = NULL;
	stack<TreeNode*> T;

	TransInorderToPostorder(exp, len);//왜 +1해줘야하지

	cout << exp << endl;
	
	len = strlen(exp);

	for(int i = 0; i < len; i++)
	{
		temp = tree.MakeTreeNode(exp[i]);

		if(isdigit(exp[i]))
		{
			T.push(temp);
		}
		else
		{
			tree.SetSubTree(temp, T.top(), 1);
			T.pop();
			tree.SetSubTree(temp, T.top(), 0);
			T.pop();
			T.push(temp);
		}
	}
	
	return T.top();
}

int ExpTree::EvaluateExpTree(TreeNode* bt)
{
	if (bt->left == NULL && bt->right == NULL)
		return (bt->data - '0');

	int op1, op2;

	op1 = EvaluateExpTree(bt->left);
	op2 = EvaluateExpTree(bt->right);

	switch (bt->data)
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
	return 0;
}	

void ExpTree::ShowData(Data data)
{
	cout << data;
}

void ExpTree::ShowPrefixTypeExp(TreeNode* bt)
{
	
}

void ExpTree::ShowInfixTypeExp(TreeNode* bt)
{
	
}

void ExpTree::ShowPostfixTypeExp(TreeNode* bt, VisitFuncPtr action)
{
	tree.PostorderTraverse(bt, action);
	/*if (bt == NULL)
		return;

	char a;
	ShowPostfixTypeExp(bt->left);
	ShowPostfixTypeExp(bt->right);
	a = bt->data;
	cout << a;*/
}