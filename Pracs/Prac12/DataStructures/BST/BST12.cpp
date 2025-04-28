#include "BST12.h"
#include <iostream>
using namespace std;

BST12Node::BST12Node(int inValue) : value(inValue), left(nullptr), right(nullptr)
{
}

BST12::BST12() : root(nullptr)
{
}

BST12::~BST12()
{
	deleteTree(root);
}

BST12::BST12(const BST12& other)
{
	root = copyTree(other.root);
}

BST12& BST12::operator=(const BST12& other)
{
	if (&other != this)
	{
		deleteTree(root);
		root = copyTree(other.root);
	}
	return *this;
}

BST12::BST12(BST12&& other) noexcept : root(other.root)
{
	other.root = nullptr;
}

BST12& BST12::operator=(BST12&& other) noexcept
{
	if (&other != this)
	{
		deleteTree(root);
		root = other.root;

		other.root = nullptr;
	}
	return *this;
}

void BST12::insert(int value)
{
	root = insertNode(root, value);
}

void BST12::remove(int value)
{
	root = deleteNode(root, value);
}

BST12Node* BST12::search(int value) const
{
	return searchNode(root, value);
}

BST12Node* BST12::insertNode(BST12Node* node, int value)
{
	if (node == nullptr)
	{
		return new BST12Node(value);
	}

	if (node->value == value)
	{
		cout << "already exist value!" << endl;
		return node;
	}
	else if (node->value < value)
	{
		node->right = insertNode(node->right, value);
	}
	else
	{
		node->left = insertNode(node->left, value);
	}
	return node;
}

BST12Node* BST12::deleteNode(BST12Node* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->value == value)
	{

		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			return nullptr;
		}
		else if (node->left == nullptr || node->right == nullptr)
		{
			BST12Node* child = node->left ? node->left : node->right;

			delete node;
			return child;
		}
		else
		{
			BST12Node* maxNode = findMax(node->left);
			node->value = maxNode->value;
			node->left = deleteNode(node->left, node->value);
		}
	}
	else if (node->value < value)
	{
		node->right = deleteNode(node->right, value);
	}
	else
	{
		node->left = deleteNode(node->left, value);
	}
	return node;
}

BST12Node* BST12::searchNode(BST12Node* node, int value) const
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->value == value)
	{
		return node;
	}
	else if (node->value < value)
	{
		return searchNode(node->right, value);
	}
	else
	{
		return searchNode(node->left, value);
	}
}

BST12Node* BST12::findMax(BST12Node* node) const
{
	while (node != nullptr && node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

BST12Node* BST12::copyTree(BST12Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	BST12Node* newNode = new BST12Node(node->value);
	newNode->right = copyTree(node->right);
	newNode->left = copyTree(node->left);

	return newNode;
}

void BST12::deleteTree(BST12Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

