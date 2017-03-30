#include <iostream>
using namespace std;

template <class T>
void PreOrder(BinaryTreeNode<T> *t)
{
	if (t)
	{
		Visit(t);
		PreOrder(t->leftChild);
		PreOrder(t->rightChild);
	}
}

template <class T>
void Inorder(BinaryTreeNode<T> *t)
{
	if (t)
	{
		Inorder(t->leftChild);
		Visit(t);
		Inorder(t->rightChild);
	}
}

