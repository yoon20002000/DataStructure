#include "BST05.h"

BST05Node::BST05Node() : data(0), left(nullptr), right(nullptr)
{
}

BST05Node::BST05Node(int val, BST05Node* left, BST05Node* right) : data(val), left(left), right(right)
{
}

BST05Node::~BST05Node()
{
}

BST05Node::BST05Node(BST05Node&& other) noexcept
{
    data =other.data;
    left = other.left;
    right = other.right;

    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
}

BST05Node& BST05Node::operator=(BST05Node&& other) noexcept
{
    if (&other != this)
    {
        data =other.data;
        left = other.left;
        right = other.right;

        other.data = 0;
        other.left = nullptr;
        other.right = nullptr;    
    }
    return *this;
}

BST05::BST05() : root(nullptr)
{
}

BST05::~BST05()
{
    deleteTree(root);
}

BST05::BST05(const BST05& other)
{
    root = copyTree(other.root);
}

BST05& BST05::operator=(const BST05& other)
{
    if (this != &other)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }

    return *this;
}

BST05::BST05(BST05&& other) noexcept
{
    root = other.root;
    other.root = nullptr;
}

BST05& BST05::operator=(BST05&& other) noexcept
{
    if (this != &other)
    {
        deleteTree(root);
        
        root = other.root;
        other.root = nullptr;
    }

    return *this;
}

void BST05::insert(int data)
{
    root = insert(root, data);
}

void BST05::deleteData(int data)
{
    root = deleteNode(root,data);
}

BST05Node* BST05::search(int data)
{
    return search(root, data);
}

BST05Node* BST05::insert(BST05Node* node, int data)
{
    if (node == nullptr)
    {
        node = new BST05Node(data);
    }
    else
    {
        if (node->data > data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
    }
    return node;
}

BST05Node* BST05::search(BST05Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (data == node->data)
    {
        return node;
    }
    else
    {
        if (node->data > data)
        {
            return search(node->left, data);
        }
        else
        {
            return search(node->right, data);
        }
    }
}

BST05Node* BST05::deleteNode(BST05Node* node, int data)
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
            BST05Node* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        else
        {
            BST05Node* maxNode = findMax(node->left);
            node->data = maxNode->data;
            node->left = deleteNode(node->left, maxNode->data);
        }
    }
    else
    {
        if (node->data > data)
        {
            node->left = deleteNode(node->left, data);
        }
        else
        {
            node->right =deleteNode(node->right, data);
        }
    }
    return node;
}

BST05Node* BST05::findMax(BST05Node* node)
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

BST05Node* BST05::copyTree(BST05Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    BST05Node* newNode = new BST05Node(node->data);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    
    return newNode;
}

void BST05::deleteTree(BST05Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
