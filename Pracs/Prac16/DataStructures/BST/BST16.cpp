#include "BST16.h"

BSTNode16::BSTNode16(int inValue) : value(inValue)
{
}

BST16::BST16() : root(nullptr)
{
}

BST16::~BST16()
{
    deleteTree(root);
    root = nullptr;
}

BST16::BST16(const BST16& other)
{
    root = copyTree(other.root);
}

BST16& BST16::operator=(const BST16& other)
{
    if (this!=&other)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

BST16::BST16(BST16&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

BST16& BST16::operator=(BST16&& other) noexcept
{
    if (this!=&other)
    {
        deleteTree(root);
        root = other.root;

        other.root = nullptr;
    }
    return *this;
}

void BST16::insert(int value)
{
    root = insertNode(root, value);
}

void BST16::remove(int value)
{
    root = removeNode(root,value);
}

BSTNode16* BST16::find(int value) const
{
    return findNode(root, value);
}

BSTNode16* BST16::insertNode(BSTNode16* node, int value)
{
    if (node == nullptr)
    {
        node = new BSTNode16(value);
    }
    
    if (node->value> value)
    {
        node->left = insertNode(node->left, value);
    }
    else if (node->value < value)
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

BSTNode16* BST16::removeNode(BSTNode16* node, int value)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (node->value == value)
    {
        // 둘다 있을 때
        if (node->left!= nullptr && node->right!= nullptr)
        {
            // left에서 가장 큰거 찾아와서 배치
            BSTNode16* temp = findMax(node->left);
            node->value = temp->value;
            node->left = removeNode(node->left, node->value);
        }
        else if (node->left != nullptr || node->right != nullptr)
        {
            // 자식을 내껄로
            BSTNode16* child  = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        else
        {
            delete node;
            return nullptr;
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

BSTNode16* BST16::findNode(BSTNode16* node, int value) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->value == value)
    {
        return node;
    }
    else if (node->value > value )
    {
        return findNode(node->left, value);
    }
    else
    {
        return findNode(node->right, value);
    }
}

BSTNode16* BST16::copyTree(BSTNode16* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    BSTNode16* newNode = new BSTNode16(node->value);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    
    return newNode;
}

void BST16::deleteTree(BSTNode16* node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

BSTNode16* BST16::findMax(BSTNode16* node) const
{
    while (node !=nullptr && node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}
