#include "BSTPrac03.h"

#include <algorithm>

BSTPrac03Node::BSTPrac03Node() : data(0), left(nullptr), right(nullptr)
{
}

BSTPrac03Node::BSTPrac03Node(int data, BSTPrac03Node* left, BSTPrac03Node* right) : data(data), left(left), right(right)
{
}

BSTPrac03Node::~BSTPrac03Node()
{
}

BSTPrac03Node::BSTPrac03Node(BSTPrac03Node&& other) noexcept
{
    data = other.data;
    left = other.left;
    right = other.right;

    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
}

BSTPrac03Node& BSTPrac03Node::operator=(BSTPrac03Node&& other) noexcept
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

BSTPrac03::BSTPrac03() : root(nullptr)
{
}

BSTPrac03::~BSTPrac03()
{
    deleteNode(root);
}

BSTPrac03::BSTPrac03(const BSTPrac03& other)
{
    root = copyNode(other.root);
}

BSTPrac03& BSTPrac03::operator=(const BSTPrac03& other)
{
    if (&other == this)
    {
        return *this;
    }
    deleteNode(root);
    root = copyNode(other.root);
    return *this;
}

BSTPrac03::BSTPrac03(BSTPrac03&& other) noexcept
{
    root = other.root;
    other.root = nullptr;
}

BSTPrac03& BSTPrac03::operator=(BSTPrac03&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }

    root = other.root;
    other.root = nullptr;

    return *this;
}

void BSTPrac03::insert(int data)
{
    root = insert(root, data);
}

void BSTPrac03::deleteData(int data)
{
    root = deleteData(root, data);
}

BSTPrac03Node* BSTPrac03::insert(BSTPrac03Node* node, int data)
{
    if (node == nullptr)
    {
        return new BSTPrac03Node(data);
    }

    if (node->data > data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }

    return node;
}

BSTPrac03Node* BSTPrac03::search(BSTPrac03Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == data)
    {
        return node;
    }

    if (node->data > data)
    {
        return search(node->left, data);
    }
    else
    {
        return search(node->right, data);
    }
}

BSTPrac03Node* BSTPrac03::deleteData(BSTPrac03Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (data < node->data)
    {
        node->left = deleteData(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = deleteData(node->right, data);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr || node->right == nullptr)
        {
            BSTPrac03Node* childNode = node->left != nullptr ? node->left : node->right;
            delete node;
            return childNode;
        }
        else
        {
            BSTPrac03Node* maxNode = findMax(node->left);
            node->data = maxNode->data;
            node->left = deleteData(node->left, maxNode->data);
        }
    }
    return node;
}

BSTPrac03Node* BSTPrac03::findMax(BSTPrac03Node* node)
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

BSTPrac03Node* BSTPrac03::copyNode(BSTPrac03Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BSTPrac03Node* newNode = new BSTPrac03Node(node->data);
    newNode->left = copyNode(node->left);
    newNode->right = copyNode(node->right);

    return newNode;
}

void BSTPrac03::deleteNode(BSTPrac03Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}
