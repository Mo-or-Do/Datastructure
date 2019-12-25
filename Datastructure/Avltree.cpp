#include "Avltree.h"

void avl_tree::avlInsert(bst_node** root, int data)
{
	bst_node* pNode = NULL;
	bst_node* cNode = *root;

	if ((*root) == NULL)
	{
		*root = new bst_node;
		(*root)->data = data;
	}
	else if (getData(*root) > data)
	{
		avlInsert(&((*root)->left), data);
		(*root) = Rebalance(root);
	}
	else if (getData(*root) < data)
	{
		avlInsert(&((*root)->right), data);
		(*root) = Rebalance(root);
	}
	else
	{
	}
}//어케생각하노시바ㄹ련아

bst_node* avl_tree::avlSearch(bst_node* root, int data)
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

bst_node* avl_tree::avlDelete(bst_node** root, int data)
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
	else if (dNode->left != NULL && dNode->right != NULL)//dNode has two child.
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

	Rebalance(root);

	return NULL;//temp
}

void avl_tree::RemoveLeftsubtree(bst_node* pnode)
{
	bst_node* rnode = pnode->left;
	pnode->left = NULL;

	delete rnode;
}

void avl_tree::RemoveRightsubtree(bst_node* pnode)
{
	bst_node* rnode = pnode->right;
	pnode->right = NULL;

	delete rnode;
}

void avl_tree::ChangeLeftsubtree(bst_node* pnode)
{
	bst_node* dNode = pnode->left;

	if (dNode->left != NULL)
		pnode->left = dNode->left;
	else
		pnode->left = dNode->right;

	delete dNode;
}

void avl_tree::ChangeRightsubtree(bst_node* pnode)
{
	bst_node* dNode = pnode->right;

	if (dNode->left != NULL)
		pnode->right = dNode->left;
	else
		pnode->right = dNode->right;

	delete dNode;
}

int avl_tree::getData(bst_node* cNode)
{
	return cNode->data;
}

int avl_tree::getKey(bst_node* cNode)
{
	return cNode->key;
}

bst_node* avl_tree::Rebalance(bst_node** root)
{
	int hDiff = GetheightDiff(*root);

	if (hDiff > 1)
	{
		if (GetheightDiff((*root)->left) > 0)
			*root = RotateLL(*root);
		else
			*root = RotateLR(*root);
	}
	else if (hDiff < -1)
	{
		if (GetheightDiff((*root)->right) < 0)
			*root = RotateRR(*root);
		else
			*root = RotateRL(*root);
	}

	return (*root);
}//Amazing...

int avl_tree::Getheight(bst_node* bst)
{
	int leftH, rightH;

	if (bst == NULL)
		return 0;

	leftH = Getheight(bst->left);
	rightH = Getheight(bst->right);


	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int avl_tree::GetheightDiff(bst_node* bst)
{
	if (bst == NULL)
		return 0;

	int lsh = Getheight(bst->left);
	int rsh = Getheight(bst->right);

	return (lsh - rsh);
}

bst_node* avl_tree::RotateLL(bst_node* bst)
{
	bst_node* pNode;
	bst_node* cNode;

	pNode = bst;
	cNode = bst->left;

	pNode->left = cNode->right;
	cNode->right = pNode;

	return cNode;
}

bst_node* avl_tree::RotateRR(bst_node* bst)
{
	bst_node* pNode;
	bst_node* cNode;

	pNode = bst;
	cNode = bst->right;

	pNode->right = cNode->left;
	cNode->left = pNode;

	return cNode;
}

bst_node* avl_tree::RotateLR(bst_node* bst)
{
	bst_node* pNode;
	bst_node* cNode;

	pNode = bst;
	cNode = bst->left;

	pNode->left = RotateRR(cNode);
	return RotateLL(pNode);
}

bst_node* avl_tree::RotateRL(bst_node* bst)
{
	bst_node* pNode;
	bst_node* cNode;

	pNode = bst;
	cNode = bst->right;

	pNode->right = RotateLL(cNode);
	return RotateRR(pNode);
}