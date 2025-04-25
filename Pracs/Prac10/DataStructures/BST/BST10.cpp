#include "BST10.h"

#include <iostream>

BST10Node::BST10Node(int inData) : data(inData), left(nullptr), right(nullptr)
{
}

BST10::BST10() : root(nullptr)
{
}

BST10::~BST10()
{
    deleteBST(root);
    root = nullptr;
}

BST10::BST10(const BST10& other) : root(nullptr)
{
    root = copyBST(other.root);
}

BST10& BST10::operator=(const BST10& other)
{
    if (&other != this)
    {
        deleteBST(root);
        root = copyBST(other.root);
    }
    return *this;
}

BST10::BST10(BST10&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST10& BST10::operator=(BST10&& other) noexcept
{
    if (&other != this)
    {
        deleteBST(root);
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

void BST10::insertNode(int data)
{
    root = insertNode(root, data);
}

void BST10::deleteNode(int data)
{
    root = deleteNode(root, data);
}

BST10Node* BST10::searchNode(int data)
{
    return searchNode(root, data);
}

BST10Node* BST10::insertNode(BST10Node* node, int data)
{
    if (node == nullptr)
    {
        return new BST10Node(data);
    }

    if (node->data == data)
    {
        std::cout << "Data is already exists\n";
        return node;
    }
    else if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else
    {
        node->right = insertNode(node->right, data);
    }
    return node;}

BST10Node* BST10::deleteNode(BST10Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (data == node->data)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr || node->right == nullptr)
        {
            BST10Node* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        else
        {
            BST10Node* maxNode = findMaxNode(node->left);
            node->data = maxNode->data;
            node->left = deleteNode(node->left,node->data);
        }
    }
    else if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
    }
    else
    {
        node->right = deleteNode(node->right, data);
    }

    return node;
    
}

BST10Node* BST10::searchNode(BST10Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (data == node->data)
    {
        return node;
    }
    else if (data < node->data)
    {
        return searchNode(node->left, data);
    }
    else
    {
        return searchNode(node->right, data);
    }
}

BST10Node* BST10::findMaxNode(BST10Node* node)
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

void BST10::deleteBST(BST10Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteBST(node->left);
    deleteBST(node->right);
    delete node;
}

BST10Node* BST10::copyBST(BST10Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST10Node* newNode = new BST10Node(node->data);
    newNode->left = copyBST(node->left);
    newNode->right = copyBST(node->right);
    return newNode;
}
