#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	leafcount = 0;
	root = NULL;
}

TreeNode* BinaryTree::MakeTreeNode(Data data)
{
	TreeNode* temp = new TreeNode;
	temp->right = NULL;
	temp->left = NULL;
	temp->data = data;
	return temp;
}

void BinaryTree::SetSubTree(TreeNode* main, TreeNode* sub, bool Direction)
{
	if(Direction)//right
		main->right = sub;
	else//left
		main->left = sub;
}

TreeNode* BinaryTree::GetSubTree(TreeNode* main, bool Direction)
{
	if(Direction)
		return main->right;
	else
		return main->left;
}

void BinaryTree::PreorderTraverse(TreeNode* bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void BinaryTree::InorderTraverse(TreeNode* bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void BinaryTree::PostorderTraverse(TreeNode* bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}