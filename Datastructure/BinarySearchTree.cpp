#include "BinarySearchTree.h"

bst_node::bst_node()
{
	key = 0;
	data = 0;
	right = NULL;
	left = NULL;
}

void bst::bstInsert(bst_node** root, int data)
{
	bst_node* pNode = NULL;
	bst_node* cNode = *root;

	while (cNode != NULL)
	{
		if (data == this->getData(cNode))
			return;

		pNode = cNode;

		if (getData(cNode) > data)
			cNode = cNode->left;
		else
			cNode = cNode->right;
	}
	
	if(pNode == NULL)
	{
		(*root) = new bst_node;
		(*root)->data = data;
	}
	else
	{
		if (getData(pNode) > data)
		{
			pNode->left = new bst_node;
			pNode->left->data = data;
		}
		else
		{
			pNode->right = new bst_node;
			pNode->right->data = data;
		}
	}
}

bst_node* bst::bstSearch(bst_node* root, int data)
{
	bst_node* cNode = root;

	while (cNode != NULL)
	{
		if (getData(cNode) == data)
			return cNode;

		if (getData(cNode) > data)
			cNode = cNode->left;
		else
			cNode = cNode->right;
	}

	return NULL;
}

bst_node* bst::bstDelete(bst_node** root, int data)
{
	bst_node* vRoot = new bst_node;//virtual root node
	bst_node* dNode = *root;
	bst_node* pNode = NULL;

	while (dNode != NULL)
	{
		if (data == this->getData(dNode))
			break;

		pNode = dNode;

		if (getData(dNode) > data)
			dNode = dNode->left;
		else
			dNode = dNode->right;
	}

	if (pNode == NULL)//dNode is root node
	{
		pNode = vRoot;
		vRoot->right = *root;
	}

	if (dNode->left == NULL && dNode->right == NULL)//dNode is terminal Node.
	{
		if (pNode->left == dNode)
			RemoveLeftsubtree(pNode);
		else
			RemoveRightsubtree(pNode);
	}
	else if(dNode->left != NULL && dNode->right != NULL)//dNode has two child.
	{
		bst_node* mNode = dNode->right;//node with minimum value in right sub tree.
		bst_node* pNode_of_mNode = NULL;

		while (mNode->left != NULL)
		{
			pNode_of_mNode = mNode;
			mNode = mNode->left;
		}

		if (pNode_of_mNode == NULL)//any node in right sub tree has not left child.
		{
			dNode->data = mNode->data;
			dNode->right = mNode->right;

			delete mNode;
		}
		else
		{
			dNode->data = mNode->data;
			pNode_of_mNode->left = NULL;

			delete dNode;
		}

	}
	else//dNode has one child.
	{
		if (pNode->left == dNode)
			ChangeLeftsubtree(pNode);
		else
			ChangeRightsubtree(pNode);
	}

	*root = vRoot->right;
	delete vRoot;

	return NULL;//temp
}

void bst::RemoveLeftsubtree(bst_node* pnode)
{
	bst_node* rnode = pnode->left;
	pnode->left = NULL;

	delete rnode;
}

void bst::RemoveRightsubtree(bst_node* pnode)
{
	bst_node* rnode = pnode->right;
	pnode->right = NULL;

	delete rnode;
}

void bst::ChangeLeftsubtree(bst_node* pnode)
{
	bst_node* dNode = pnode->left;

	if (dNode->left != NULL)
		pnode->left = dNode->left;
	else
		pnode->left = dNode->right;

	delete dNode;
}

void bst::ChangeRightsubtree(bst_node* pnode)
{
	bst_node* dNode = pnode->right;

	if (dNode->left != NULL)
		pnode->right = dNode->left;
	else
		pnode->right = dNode->right;

	delete dNode;
}

int bst::getData(bst_node* cNode)
{
	return cNode->data;
}

int bst::getKey(bst_node* cNode)
{
	return cNode->key;
}