#pragma once
#include <iostream>
#include <stack>
#include "TransInorderToPostorder.h"
#include "BinaryTree.h"
using namespace std;

class ExpTree
{
	BinaryTree tree;
public:
	ExpTree();
	TreeNode* MakeExpTree(char exp[]);
	int EvaluateExpTree(TreeNode* bt);
	
	void ShowPrefixTypeExp(TreeNode* bt);
	void ShowInfixTypeExp(TreeNode* bt);
	void ShowPostfixTypeExp(TreeNode* bt, VisitFuncPtr action);
	void ShowData(Data data);
};