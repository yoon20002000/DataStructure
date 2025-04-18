#include "BST04.h"

BST04Node::BST04Node() : data(0), left(nullptr), right(nullptr)
{
}

BST04Node::BST04Node(int data, BST04Node* left, BST04Node* right) : data(data), left(left), right(right)
{
    
}

BST04Node::~BST04Node()
{
}

BST04Node::BST04Node(BST04Node&& other) noexcept : data(other.data), left(other.left), right(other.right)
{
    other.data = 0;
    other.left = nullptr;
    other.right = nullptr;
}

BST04Node& BST04Node::operator=(BST04Node&& other) noexcept
{
    if (&other != this)
    {
        data = other.data;
        left = other.left;
        right = other.right;
        
        other.data = 0;
        other.left = nullptr;
        other.right = nullptr;
    }
    return *this;
}

BST04::BST04() : root(nullptr)
{
}

BST04::~BST04()
{
    deleteTree(root);
}

BST04::BST04(const BST04& other)
{
    root = copyNode(other.root);
}

BST04& BST04::operator=(const BST04& other)
{
    if (&other != this)
    {
        deleteTree(root);
        root = copyNode(other.root);    
    }
    return *this;
}

BST04::BST04(BST04&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST04& BST04::operator=(BST04&& other) noexcept
{
    if (&other != this)
    {
        deleteTree(root);
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

void BST04::insertData(int data)
{
    root = insert(root, data);
}

void BST04::deleteData(int data)
{
    root = deleteNode(root,data);
}

BST04Node* BST04::insert(BST04Node* node,int data)
{
    if (node== nullptr)
    {
        return new BST04Node(data);
    }

    if (node->data > data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
}

BST04Node* BST04::search(BST04Node* node, int data)
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
        node->left = search(node->left, data);
    }
    else
    {
        node->right = search(node->right, data);
    }
}

BST04Node* BST04::deleteNode(BST04Node* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->data != data)
    {
        if (node->data > data)
        {
            node->left = deleteNode(node->left, data);    
        }
        else
        {
            node->right = deleteNode(node->right, data);    
        }
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
            BST04Node* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        else
        {
            BST04Node* max = findMax(node->left);
            node->data = max->data;
            node->left = deleteNode(node->left, node->data);
        }
    }

    return node;
}

BST04Node* BST04::findMax(BST04Node* node)
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}
BST04Node* BST04::copyNode(BST04Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BST04Node* newNode = new BST04Node(node->data);
    newNode->left = copyNode(node->left);
    newNode->right = copyNode(node->right);
    return newNode;
}

BST04Node* BST04::deleteTree(BST04Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
    node = nullptr;
}
