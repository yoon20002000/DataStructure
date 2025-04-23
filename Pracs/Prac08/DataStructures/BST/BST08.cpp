#include "BST08.h"

#include <iostream>

BST08Node::BST08Node(int inData) : data(inData), left(nullptr), right(nullptr)
{
}

BST08::BST08() : root(nullptr)
{
    
}

BST08::~BST08()
{
    root = deleteBST(root);
}

BST08::BST08(const BST08& other)
{
    root = copyBST(other.root);
}

BST08& BST08::operator=(const BST08& other)
{
    if (&other != this)
    {
        root = deleteBST(root);

        root = copyBST(other.root);
    }
    return *this;
}

BST08::BST08(BST08&& other) noexcept
{
    root = other.root;

    other.root = nullptr;
}

BST08& BST08::operator=(BST08&& other) noexcept
{
    if (&other != this)
    {
        root = deleteBST(root);
        
        root = other.root;

        other.root = nullptr;
    }
    return *this;
}

void BST08::insertData(int data)
{
    root = insertData(root, data);
}

void BST08::deleteData(int data)
{
    root = deleteData(root, data);
}

BST08Node* BST08::searchData(int data)
{
    return searchData(root, data);
}

BST08Node* BST08::insertData(BST08Node* node, int data)
{
    if (node == nullptr)
    {
        return new BST08Node(data);
    }

    if (data == node->data)
    {
        std::cout << "Data " << data << " already exists." << '\n';
        return node;
    }

    if (data < node->data)
    {
        node->left = insertData(node->left, data);    
    }
    else
    {
        node->right = insertData(node->right, data);
    }
    
    return node;
}

BST08Node* BST08::deleteData(BST08Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == data)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr || node->right == nullptr)
        {
            BST08Node* childNode = node->left ? node->left : node->right;
            delete node;
            return childNode;
        }
        else
        {
            BST08Node* maxNode = findMax(node->left);
            node->data = maxNode->data;
            node->left = deleteData(node->left, node->data);
        }
    }
    else
    {
        if (node->data < data)
        {
            node->right = deleteData(node->right, data);
        }
        else
        {
            node->left = deleteData(node->left, data);
        }
    }

    return node;
}

BST08Node* BST08::searchData(BST08Node* node, int data)
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
        return searchData(node->right, data);
    }
    else
    {
        return searchData(node->left, data);
    }
}

BST08Node* BST08::copyBST(BST08Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST08Node* newNode = new BST08Node(node->data);
    newNode->left = copyBST(node->left);
    newNode->right = copyBST(node->right);

    return newNode;
}

BST08Node* BST08::deleteBST(BST08Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    node->left = deleteBST(node->left);
    node->right = deleteBST(node->right);

    delete node;
    return nullptr;
}
BST08Node* BST08::findMax(BST08Node* node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}