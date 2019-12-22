#include <iostream>
using namespace std;

typedef int Data;
typedef void VisitFuncPtr(Data data);

class TreeNode
{
public:
	Data data;
	TreeNode* right;
	TreeNode* left;
};

class BinaryTree
{
	TreeNode* root;
	int leafcount;
public:
	BinaryTree();
	TreeNode* MakeTreeNode(Data data);
	void SetSubTree(TreeNode* main, TreeNode* sub, bool Direction);//0 is left, 1 is right
	TreeNode* GetSubTree(TreeNode* main, bool Direction);
	void PreorderTraverse(TreeNode* bt, VisitFuncPtr action);//전위
	void InorderTraverse(TreeNode* bt, VisitFuncPtr action);//중위
	void PostorderTraverse(TreeNode* bt, VisitFuncPtr action);//후위
};