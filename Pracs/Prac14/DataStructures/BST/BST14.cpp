#include "BST14.h"

BST14Node::BST14Node(int inValue) : value(inValue), left(nullptr), right(nullptr)
{
}

BST14Node::~BST14Node()
{
}

BST14::BST14() : root(nullptr)
{
}

BST14::~BST14()
{
    deleteTree(root);
}

BST14::BST14(const BST14& other): root(nullptr)
{
    root = copyTree(other.root);
}

BST14& BST14::operator=(const BST14& other)
{
    if (&other != this)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

BST14::BST14(BST14&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST14& BST14::operator=(BST14&& other) noexcept
{
    if (&other != this)
    {
        deleteTree(root);
        root = other.root;

        other.root = nullptr;
    }
    return *this;
}

void BST14::insert(int value)
{
    root = insertNode(root, value);
}

void BST14::remove(int value)
{
    root = removeNode(root, value);
}

BST14Node* BST14::search(int value)
{
    return searchNode(root, value);
}

BST14Node* BST14::insertNode(BST14Node* node, int value)
{
    if (node == nullptr)
    {
        return new BST14Node(value);
    }

    if (node->value == value)
    {
        return node;
    }
    else if (node->value < value)
    {
        node->right = insertNode(node->right, value);
    }
    else
    {
        node->left = insertNode(node->left, value);
    }
    return node;
}

BST14Node* BST14::removeNode(BST14Node* node, int value)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->value == value)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr || node->right == nullptr)
        {
            BST14Node* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        else
        {
            BST14Node* maxNode = findMax(node->left);
            node->value = maxNode->value;
            node->left = removeNode(node->left, node->value);
        }
    }
    else if (node->value < value)
    {
        node->right = removeNode(node->right, value);
    }
    else
    {
        node->left = removeNode(node->left, value);
    }
    return node;
}

BST14Node* BST14::searchNode(BST14Node* node, int value)
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

BST14Node* BST14::findMax(BST14Node* node)
{
    while (node != nullptr && node->right)
    {
        node = node->right;
    }
    return node;
}

BST14Node* BST14::copyTree(BST14Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    BST14Node* newNode = new BST14Node(node->value);
    newNode->right = copyTree(node->right);
    newNode->left = copyTree(node->left);

    return newNode;
}

void BST14::deleteTree(BST14Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}
