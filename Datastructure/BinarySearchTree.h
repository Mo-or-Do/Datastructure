#pragma once
#include <iostream>
using namespace std;

class bst_node
{
public:
	bst_node();
	bst_node* right;
	bst_node* left;
	int key;
	int data;
};
//test or test

class bst//binary search tree
{
	bst_node* rootnode;
public:
	void bstInsert(bst_node** root, int data);
	bst_node* bstSearch(bst_node* root, int data);
	int getData(bst_node* target);
	int getKey(bst_node* target);
	bst_node* bstDelete(bst_node** root, int data);
	void RemoveLeftsubtree(bst_node* pnode);
	void RemoveRightsubtree(bst_node* pnode);
	void ChangeLeftsubtree(bst_node* pnode);
	void ChangeRightsubtree(bst_node* pnode);
};