#include "BST07.h"

#include <iostream>

BST07Node::BST07Node(int inData) : data(inData), left(nullptr), right(nullptr)
{
}

bool BST07Node::isEmptyChild() const
{
    return left == nullptr && right == nullptr;
}

bool BST07Node::isFullChild() const
{
    return left != nullptr && right != nullptr;
}

bool BST07Node::isOneChild() const
{
    return (left != nullptr && right == nullptr) || (left == nullptr && right != nullptr);
}

BST07::BST07() : root(nullptr)
{
}

BST07::~BST07()
{
    deleteTree(root);
}

void BST07::insert(int data)
{
    root = insertNode(root, data);
}

void BST07::remove(int data)
{
    root = deleteNode(root, data);
}

BST07Node* BST07::search(int data)
{
    return searchNode(root, data);
}

BST07Node* BST07::insertNode(BST07Node* node, int data)
{
    if (node == nullptr)
    {
        return new BST07Node(data);
    }

    if (node->data == data)
    {
        std::cout << "Same Data already inserted"<< '\n';
        return node;
    }

    if (node->data < data)
    {
        node->right = insertNode(node->right, data);
    }
    else
    {
        node->left = insertNode(node->left, data);
    }

    return node;
}

BST07Node* BST07::deleteNode(BST07Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == data)
    {
        if (node->isEmptyChild())
        {
            delete node;
            return nullptr;
        }
        else if (node->isOneChild())
        {
            BST07Node* child = node->right != nullptr ? node->right : node->left;
            delete node;
            return child;
        }
        else
        {
            BST07Node* leftMax = findMaxNode(node->left);
            node->data = leftMax->data;
            node->left = deleteNode(node->left, node->data);
        }
    }
    else
    {
        if (node->data < data)
        {
            node->right = deleteNode(node->right, data);
        }
        else
        {
            node->left = deleteNode(node->left, data);
        }
    }

    return node;
}

BST07Node* BST07::searchNode(BST07Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->data == data)
    {
        return node;
    }
    else if (node->data < data)
    {
        return searchNode(node->right, data);
    }
    else
    {
        return searchNode(node->left, data);
    }
}

BST07Node* BST07::findMaxNode(BST07Node* node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

void BST07::deleteTree(BST07Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}
