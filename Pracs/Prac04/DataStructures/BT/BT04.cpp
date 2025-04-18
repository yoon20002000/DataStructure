#include "BT04.h"

#include <iostream>

BT04Node::BT04Node() : left(nullptr), right(nullptr)
{
}

BT04Node::BT04Node(int value, BT04Node* left, BT04Node* right) : data(value), left(left), right(right)
{
}

BT04Node::~BT04Node()
{
}

BT04Node::BT04Node(BT04Node&& other) noexcept
{
    data =other.data;
    left = other.left;
    right = other.right;

    other.data=0;
    other.left = nullptr;
    other.right = nullptr;
}

BT04Node& BT04Node::operator=(BT04Node&& other) noexcept
{
    if (&other != this)
    {
        data =other.data;
        left = other.left;
        right = other.right;

        other.data=0;
        other.left = nullptr;
        other.right = nullptr;        
    }

    return *this;
}

BT04::BT04() : root(nullptr)
{
}

BT04::~BT04()
{
    deleteTree(root);
    root = nullptr;
}

BT04::BT04(const BT04& other)
{
    root = copyTree(other.root);
}

BT04& BT04::operator=(const BT04& other)
{
    if (&other != this)
    {
        deleteTree(root);
        root = copyTree(other.root);    
    }
    
    return *this;
}

BT04::BT04(BT04&& other) noexcept
{
    root = other.root;
    other.root = nullptr;
}

BT04& BT04::operator=(BT04&& other) noexcept
{
    if (&other != this)
    {
        deleteTree(root);
        root = other.root;
        other.root = nullptr;    
    }
    return *this;
}

void BT04::printPreOrder(BT04Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void BT04::printInOrder(BT04Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

void BT04::printPostOrder(BT04Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->data << " ";
}

void BT04::deleteTree(BT04Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

BT04Node* BT04::copyTree(BT04Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    
    BT04Node* newNode = new BT04Node(node->data);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}
