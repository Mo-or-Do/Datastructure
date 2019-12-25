#include <iostream>
#include "Avltree.h"
using namespace std;

typedef void VisitFuncPtr(int);

/*ExpTree exp;
	TreeNode* test;
	char temp[100];
	cin >> temp;
	test = exp.MakeExpTree(temp);
	exp.ShowPostfixTypeExp(test, exp.ShowData); 왜 이부분이 안되는걸까?
	cout << endl;
	cout << exp.EvaluateExpTree(test) << endl;
	
	*/

int pricomp(int d1, int d2)
{
	return d2 - d1;
	if (d1 < d2)
		return 1;
	else
		return 0;
}//This fuction is used for heapsort

void InorderTraverse(bst_node* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}//This function is used for bst.

void main()
{
}


