#include "BST11.h"

#include <iostream>

BST11Node::BST11Node(int inValue) : value(inValue), left(nullptr), right(nullptr)
{
}

BST11::BST11() : root(nullptr)
{
}

BST11::~BST11()
{
    deleteTree(root);
}

BST11::BST11(const BST11& other)
{
    root = copyTree(other.root);
}

BST11& BST11::operator=(const BST11& other)
{
    if (&other != this)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

BST11::BST11(BST11&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST11& BST11::operator=(BST11&& other) noexcept
{
    if (&other != this)
    {
        deleteTree(root);

        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

void BST11::insert(int value)
{
    root = insertNode(root, value);
}

void BST11::remove(int value)
{
    root = removeNode(root, value);
}

BST11Node* BST11::search(int value)
{
    return searchNode(root, value);
}

BST11Node* BST11::insertNode(BST11Node* node, int value)
{
    if (node == nullptr)
    {
        return new BST11Node(value);
    }

    if (node->value == value)
    {
        std::cout << "already exists value." << '\n';
        return nullptr;
    }
    else if (node->value < value)
    {
        node->right = insertNode(node->right, value);
    }
    else if (node->value > value)
    {
        node->left = insertNode(node->left, value);
    }

    return node;
}

BST11Node* BST11::removeNode(BST11Node* node, int value)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->value == value)
    {
        // 둘다 없을때
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        // 둘중 하나 있을 때
        else if (node->left == nullptr || node->right == nullptr)
        {
            BST11Node* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        // 둘다 있을때
        else
        {
            BST11Node* maxNode = findMax(node->left);
            node->value = maxNode->value;
            removeNode(node->left, node->value);
        }
    }
    else if (node->value < value)
    {
        node->right = removeNode(node->right, value);
    }
    else if (node->value > value)
    {
        node->left = removeNode(node->left, value);
    }
    return node;
}

BST11Node* BST11::searchNode(BST11Node* node, int value)
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

BST11Node* BST11::findMax(BST11Node* node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

BST11Node* BST11::copyTree(BST11Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST11Node* newNode = new BST11Node(node->value);
    newNode->right = copyTree(node->right);
    newNode->left = copyTree(node->left);
    
    return newNode;
}

void BST11::deleteTree(BST11Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->right);
    deleteTree(node->left);
    delete node;
}
