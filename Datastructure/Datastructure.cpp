#include <iostream>
#include "BinarySearchTree.h"
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
}

void printdata(int num)
{
	cout << num << endl;
}

void main()
{
	bst_node* root = NULL, *sNode = NULL;

	bst b;
	b.bstInsert(&root, 9);
	b.bstInsert(&root, 1);
	b.bstInsert(&root, 6);
	b.bstInsert(&root, 2);
	b.bstInsert(&root, 8);
	b.bstInsert(&root, 3);
	b.bstInsert(&root, 5);

	InorderTraverse(root, printdata);
	cout << endl;

	b.bstDelete(&root, 9);
	/*sNode = b.bstSearch(root, 1);
	if (sNode == NULL)
		cout << "Search Fail" << endl;
	else


		cout << "key value f: " << sNode->data<<endl;
		h
	b.bstDelete(root, 6);

	sNode = b.bstSearch(root, 6);
	if (sNode == NULL)
		cout << "Search Fail" << endl;
	else
		cout << "key value : " << sNode->data << endl;*/

	InorderTraverse(root, printdata);
}
