#include "BTPrac03.h"

#include <iostream>

BTPrac03Node::BTPrac03Node() : data(0), left(nullptr), right(nullptr)
{
}

BTPrac03Node::BTPrac03Node(int data, BTPrac03Node* left, BTPrac03Node* right) : data(data), left(left), right(right)
{
}

BTPrac03Node::~BTPrac03Node()
{
}

BTPrac03Node::BTPrac03Node(BTPrac03Node&& other) noexcept
{
    data = other.data;
    left = other.left;
    right = other.right;

    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
}

BTPrac03Node& BTPrac03Node::operator=(BTPrac03Node&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }

    data = other.data;
    left = other.left;
    right = other.right;

    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
    return *this;
}

BTPrac03::BTPrac03() : root(nullptr)
{
}

BTPrac03::~BTPrac03()
{
    deleteBTNode(root);
}

BTPrac03::BTPrac03(const BTPrac03& other)
{
    root = copyBTNode(other.root);
}

BTPrac03& BTPrac03::operator=(const BTPrac03& other)
{
    if (&other == this)
    {
        return *this;
    }

    deleteBTNode(root);
    root = copyBTNode(other.root);
    
    return *this;
}

BTPrac03::BTPrac03(BTPrac03&& other) noexcept
{
    root = other.root;

    other.root = nullptr;
}

BTPrac03& BTPrac03::operator=(BTPrac03&& other) noexcept
{
    deleteBTNode(root);

    root = other.root;

    other.root = nullptr;
    return *this;
}

void BTPrac03::printPreOrder(BTPrac03Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void BTPrac03::printInOrder(BTPrac03Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

void BTPrac03::printPostOrder(BTPrac03Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->data << " ";
}

BTPrac03Node* BTPrac03::copyBTNode(BTPrac03Node* node)
{
    if (node==nullptr)
    {
        return nullptr;
    }

    BTPrac03Node* newNode = new BTPrac03Node(node->data);
    newNode->left = copyBTNode(node->left);
    newNode->right = copyBTNode(node->right);
    return newNode;
}

void BTPrac03::deleteBTNode(BTPrac03Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    deleteBTNode(node->right);
    deleteBTNode(node->left);

    delete node;
}
