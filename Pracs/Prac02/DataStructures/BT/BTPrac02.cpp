#include "BTPrac02.h"

#include <iostream>

BTPrac02Node::BTPrac02Node(char c) : data(c), left(nullptr), right(nullptr)
{
}

BTPrac02Node::~BTPrac02Node()
{
}

BTPrac02Node::BTPrac02Node(BTPrac02Node&& other) noexcept
{
    left = other.left;
    right = other.right;
    data = other.data;

    other.left = nullptr;
    other.right = nullptr;
    other.data = '\0';
}

BTPrac02Node& BTPrac02Node::operator=(BTPrac02Node&& other) noexcept
{
    left = other.left;
    right = other.right;
    data = other.data;

    other.left = nullptr;
    other.right = nullptr;
    other.data = '\0';
    return *this;
}

void BTPrac02::printPreorder(BTPrac02Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::cout << root->data;
    printPreorder(root->left);
    printPreorder(root->right);
}

void BTPrac02::printInorder(BTPrac02Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    printInorder(root->left);
    std::cout << root->data;
    printInorder(root->right);
}

void BTPrac02::printPostorder(BTPrac02Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    std::cout << root->data;
}
