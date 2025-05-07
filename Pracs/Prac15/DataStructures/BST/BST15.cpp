#include "BST15.h"

#include <iostream>

BST15Node::BST15Node(int value) : value(value), left(nullptr), right(nullptr)
{
    
}
BST15::BST15() : root(nullptr)
{
}

BST15::~BST15()
{
    deleteTree(root);
}

BST15::BST15(const BST15& other)
{
    root = copyTree(other.root);
}

BST15& BST15::operator=(const BST15& other)
{
    if (&other != this)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

BST15::BST15(BST15&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST15& BST15::operator=(BST15&& other) noexcept
{
    if (&other != this)
    {
        deleteTree(root);
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

void BST15::insertData(int value)
{
    root = insertNode(root, value);
}

void BST15::deleteData(int value)
{
    root = deleteNode(root, value);
}

BST15Node* BST15::findData(int value) const
{
    return findNode(root, value);
}

BST15Node* BST15::insertNode(BST15Node* node, int value)
{
    if (node == nullptr)
    {
        return new BST15Node(value);
    }
    if (node->value == value)
    {
        std::cout << "Is already exists"<<'\n';
        return node;
    }
    else if (value < node->value)
    {
        node->left = insertNode(node->left, value);;
    }
    else
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

BST15Node* BST15::deleteNode(BST15Node* node, int value)
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
            BST15Node* child = node->left ? node->left : node->right;

            delete node;
            return child;
        }
        else
        {
            BST15Node* maxNode = findMax(node->left);
            node->value = maxNode->value;
            node->left = deleteNode(node->left, node->value);
            return node;
        }
    }
    else if (value < node->value)
    {
        node->left = deleteNode(node->left, value);
    }
    else
    {
        node->right = deleteNode(node->right, value);
    }
    return node;
}

BST15Node* BST15::findNode(BST15Node* node, int value) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->value == value)
    {
        return node;
    }
    else if (value < node->value)
    {
        return findNode(node->left, value);
    }
    else
    {
        return findNode(node->right, value);
    }
}

BST15Node* BST15::findMax(BST15Node* node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}


void BST15::deleteTree(BST15Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

BST15Node* BST15::copyTree(BST15Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST15Node* newNode = new BST15Node(node->value);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}
