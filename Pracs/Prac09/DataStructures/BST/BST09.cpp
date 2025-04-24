#include "BST09.h"

#include <iostream>

BST09Node::BST09Node(int inData) : data(inData), left(nullptr), right(nullptr)
{
}

BST09::BST09() : root(nullptr)
{
}

BST09::~BST09()
{
    root = deleteBST(root);
}

BST09::BST09(const BST09& other) : root(nullptr)
{
    root = copyBST(other.root);
}

BST09& BST09::operator=(const BST09& other)
{
    if (&other != this)
    {
        root = deleteBST(root);
        root = copyBST(other.root);
    }
    return *this;
}

BST09::BST09(BST09&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST09& BST09::operator=(BST09&& other) noexcept
{
    if (&other != this)
    {
        root = deleteBST(root);
        root = other.root;
        
        other.root = nullptr;
    }
    return *this;
}

void BST09::insert(int data)
{
    root = insertNode(root,data);
}

void BST09::remove(int data)
{
    root = removeNode(root,data);
}

BST09Node* BST09::search(int data)
{
    return searchNode(root,data);
}

BST09Node* BST09::insertNode(BST09Node* node, int data)
{
    if (node == nullptr)
    {
        return new BST09Node(data);
    }

    if (node->data == data)
    {
        std::cout << "Data " << data << " already exists." << '\n';
        return node;
    }
    else if (node->data > data)
    {
        node->left = insertNode(node->left, data);
    }
    else
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}

BST09Node* BST09::removeNode(BST09Node* node, int data)
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
            BST09Node* childNode = node->left ? node->left : node->right;
            delete node;
            return childNode;
        }
        else
        {
            BST09Node* maxNode = findMax(node->left);
            node->data = maxNode->data;
            node->left = removeNode(node->left, maxNode->data);
            return node;
        }
    }
    else if (node->data > data)
    {
        node->left = removeNode(node->left, data);
        return node;
    }
    else
    {
        node->right = removeNode(node->right, data);
        return node;
    }
}

BST09Node* BST09::searchNode(BST09Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == data)
    {
        return node;
    }
    else if (node->data > data)
    {
        return searchNode(node->left, data); 
    }
    else
    {
        return searchNode(node->right, data);
    }
}

BST09Node* BST09::copyBST(BST09Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST09Node* newNode = new BST09Node(node->data);
    newNode->left = copyBST(node->left);
    newNode->right = copyBST(node->right);
    return newNode;
}

BST09Node* BST09::deleteBST(BST09Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    node->left = deleteBST(node->left);
    node->right = deleteBST(node->right);
    
    delete node;
    node = nullptr;
}
BST09Node* BST09::findMax(BST09Node* node)
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}
