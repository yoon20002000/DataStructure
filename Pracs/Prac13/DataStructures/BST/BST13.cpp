#include "BST13.h"

#include <iostream>
#include <ostream>

BST13Node::BST13Node(int inValue) :  value(inValue), left(nullptr), right(nullptr)
{
}

BST13::BST13() : root(nullptr)
{
}

BST13::~BST13()
{
    deleteTree(root);
    root = nullptr;
}

BST13::BST13(const BST13& other)
{
    root = copyTree(other.root);
}

BST13& BST13::operator=(const BST13& other)
{
    if (&other != this)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

BST13::BST13(BST13&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST13& BST13::operator=(BST13&& other) noexcept
{
    if (&other != this)
    {
        deleteTree(root);
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

void BST13::insert(int inValue)
{
    root = insertNode(root, inValue);
}

void BST13::remove(int inValue)
{
    root = removeNode(root, inValue);
}

BST13Node* BST13::find(int inValue) const
{
    return findNode(root,inValue);
}

BST13Node* BST13::insertNode(BST13Node* node, int inValue)
{
    if (node == nullptr)
    {
        return new BST13Node(inValue);
    }

    if (node->value == inValue)
    {
        std::cout << "already exists" << '\n';
        return node;
    }
    else if (node->value < inValue)
    {
        node->right = insertNode(node->right, inValue);
    }
    else
    {
        node->left = insertNode(node->left, inValue);
    }
    return node;
}

BST13Node* BST13::removeNode(BST13Node* node, int inValue)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (node->value == inValue)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr || node->right == nullptr)
        {
            BST13Node* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        else
        {
            BST13Node* maxNode= findMax(node->left);
            node->value = maxNode->value;
            node->left = removeNode(node->left, node->value);
        }
    }
    else if (node->value < inValue)
    {
        node->right = removeNode(node->right, inValue);
    }
    else
    {
        node->left = removeNode(node->left, inValue);
    }
    return node;
}

BST13Node* BST13::findNode(BST13Node* node, int inValue) const
{
    if (node ==nullptr)
    {
        return nullptr;
    }
    else if (node->value == inValue)
    {
        return node;
    }
    else if (node->value < inValue)
    {
        return findNode(node->right, inValue);
    }
    else
    {
        return findNode(node->left, inValue);
    }
}

BST13Node* BST13::copyTree(BST13Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST13Node* newNode = new BST13Node(node->value);
    newNode->right = copyTree(node->right);
    newNode->left = copyTree(node->left);

    return newNode;
}

void BST13::deleteTree(BST13Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    
    delete node;
}
BST13Node* BST13::findMax(BST13Node* node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}