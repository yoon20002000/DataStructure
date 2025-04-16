#include "BSTPrac02.h"

#include <iostream>

BSTNodePrac02::BSTNodePrac02() : data(0), left(nullptr), right(nullptr)
{
}

BSTNodePrac02::BSTNodePrac02(int value, BSTNodePrac02* left, BSTNodePrac02* right) : data(value), left(left),
    right(right)
{
}


BSTNodePrac02::~BSTNodePrac02()
{
}

BSTNodePrac02::BSTNodePrac02(BSTNodePrac02&& other) noexcept
{
    data = other.data;
    left = other.left;
    right = other.right;

    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
}

BSTNodePrac02& BSTNodePrac02::operator=(BSTNodePrac02&& other) noexcept
{
    data = other.data;
    left = other.left;
    right = other.right;

    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
    return *this;
}

BSTPrac02::BSTPrac02() : root(nullptr)
{
}

BSTPrac02::~BSTPrac02()
{
    if (root != nullptr)
    {
        deleteBST(root);
    }
}

BSTPrac02::BSTPrac02(const BSTPrac02& other)
{
    root = copyNode(other.root);
}

BSTPrac02& BSTPrac02::operator=(const BSTPrac02& other)
{
    if (this == &other)
    {
        return *this;
    }
    
    if (root != nullptr)
    {
        deleteBST(root);
    }

    root = copyNode(other.root);
    return *this;
}

BSTPrac02::BSTPrac02(BSTPrac02&& other) noexcept
{
    root = other.root;
    other.root = nullptr;
}

BSTPrac02& BSTPrac02::operator=(BSTPrac02&& other) noexcept
{
    if (root != nullptr)
    {
        deleteBST(root);
    }

    root = other.root;
    other.root = nullptr;
    return *this;
}

void BSTPrac02::insert(int value)
{
    root = insert(root, value);
}

BSTNodePrac02* BSTPrac02::insert(BSTNodePrac02* node, int value)
{
    if (node == nullptr)
    {
        return new BSTNodePrac02(value);
    }

    if (node->data > value)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }

    return node;
}

BSTNodePrac02* BSTPrac02::copyNode(BSTNodePrac02* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BSTNodePrac02* newNode = new BSTNodePrac02(node->data);
    newNode->left = copyNode(node->left);
    newNode->right = copyNode(node->right);
    return newNode;
}

void BSTPrac02::deleteBST(BSTNodePrac02* node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteBST(node->left);
    deleteBST(node->right);

    delete node;
}

void BSTPrac02::deleteNode(BSTNodePrac02* node, int value)
{
    if (node == nullptr)
    {
        return;
    }

    BSTNodePrac02* targetNode = node;
    BSTNodePrac02* parent = nullptr;
    while (targetNode != nullptr && targetNode->data != value)
    {
        parent = targetNode;
        if (value < targetNode->data)
        {
            targetNode = targetNode->left;
        }
        else
        {
            targetNode = targetNode->right;
        }
    }

    if (targetNode == nullptr)
    {
        return;
    }

    if (targetNode->left == nullptr && targetNode->right == nullptr)
    {
        if (parent->left == targetNode)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
        delete targetNode;
    }
    else if (targetNode->left == nullptr || targetNode->right == nullptr)
    {
        BSTNodePrac02* child = targetNode->right != nullptr ? targetNode->right : targetNode->left;
        targetNode->data = child->data;
        targetNode->left = child->left;
        targetNode->right = child->right;
        delete child;
    }
    else
    {
        BSTNodePrac02* max = findMax(targetNode->left);
        targetNode->data = max->data;
        deleteNode(targetNode->left, targetNode->data);
    }
}

BSTNodePrac02* BSTPrac02::getNode(BSTNodePrac02* node, int value)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == value)
    {
        return node;
    }

    if (node->data < value)
    {
        return getNode(node->right, value);
    }
    else
    {
        return getNode(node->left, value);
    }
}

BSTNodePrac02* BSTPrac02::findMax(BSTNodePrac02* node)
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

void BSTPrac02::print(BSTNodePrac02* node)
{
    if (node == nullptr)
    {
        return;
    }

    print(node->left);
    std::cout << node->data << " ";
    print(node->right);
}
