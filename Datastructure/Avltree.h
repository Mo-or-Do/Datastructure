#pragma once
#include "BinarySearchTree.h"
using namespace std;

class avl_tree//binary search tree
{
	bst_node* rootnode;
public:
	void avlInsert(bst_node** root, int data);
	bst_node* avlSearch(bst_node* root, int data);
	int getData(bst_node* target);
	int getKey(bst_node* target);
	bst_node* avlDelete(bst_node** root, int data);
	void RemoveLeftsubtree(bst_node* pnode);
	void RemoveRightsubtree(bst_node* pnode);
	void ChangeLeftsubtree(bst_node* pnode);
	void ChangeRightsubtree(bst_node* pnode);
	bst_node* Rebalance(bst_node** root);
	int Getheight(bst_node* bst);
	int GetheightDiff(bst_node* bst);
	bst_node* RotateLL(bst_node* bst);
	bst_node* RotateRR(bst_node* bst);
	bst_node* RotateLR(bst_node* bst);
	bst_node* RotateRL(bst_node* bst);
};