#include "BST06.h"

BST06Node::BST06Node() : data(0), left(nullptr), right(nullptr)
{
}

BST06Node::BST06Node(int inData, BST06Node* inLeft, BST06Node* inRight) : data(inData), left(inLeft), right(inRight)
{
}

BST06Node::~BST06Node()
{
}

int BST06Node::getData() const
{
    return data;
}

void BST06Node::setData(int inData)
{
    data = inData;
}

BST06Node* BST06Node::getLeft() const
{
    return left;
}

void BST06Node::setLeft(BST06Node* inLeft)
{
    left = inLeft;
}

BST06Node* BST06Node::getRight() const
{
    return right;
}

void BST06Node::setRight(BST06Node* inRight)
{
    right = inRight;
}

bool BST06Node::isFullNode() const
{
    return left != nullptr && right != nullptr;
}

bool BST06Node::hasOneChild() const
{
    return (left == nullptr && right != nullptr) || (left != nullptr && right == nullptr);
}

bool BST06Node::hasNoChild() const
{
    return left == nullptr && right == nullptr;
}

BST06::BST06() : root(nullptr)
{
}

BST06::~BST06()
{
    deleteNode(root);
}

void BST06::insertData(int inData)
{
    root = insert(root, inData);
}

const BST06Node* BST06::getNode(int inData) const
{
    return search(root,inData);   
}

void BST06::deleteData(int inData)
{
    root = deleteNode(root, inData);
}

BST06Node* BST06::getMax(BST06Node* node)
{
    while (node != nullptr && node->getRight() != nullptr)
    {
        node = node->getRight();
    }
    return node;
}

BST06Node* BST06::insert(BST06Node* node, int inData)
{
    if (node == nullptr)
    {
        return new BST06Node(inData);
    }

    if (node->getData() < inData)
    {
        node->setRight(insert(node->getRight(), inData));
    }
    else
    {
        node->setLeft(insert(node->getLeft(), inData));
    }

    return node;
}

const BST06Node* BST06::search(BST06Node* node, int inData) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->getData() == inData)
    {
        return node;
    }

    if (node->getData() < inData)
    {
        return search(node->getRight(), inData);
    }
    else
    {
        return search(node->getLeft(), inData);
    }
}

BST06Node* BST06::deleteNode(BST06Node* node, int inData)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->getData() == inData)
    {
        if (node->hasNoChild())
        {
            delete node;
            return nullptr;
        }
        else if (node->hasOneChild())
        {
            BST06Node* getChild = node->getRight() ? node->getRight() : node->getLeft();
            delete node;
            return getChild;
        }
        else
        {
            BST06Node* maxNode = getMax(node->getLeft());
            node->setData(maxNode->getData());
            node->setLeft(deleteNode(node->getLeft(), node->getData()));
        }
    }
    else
    {
        if (node->getData() < inData)
        {
            node->setRight(deleteNode(node->getRight(), inData));
        }
        else
        {
            node->setLeft(deleteNode(node->getLeft(), inData));
        }
    }
    return node;
}

void BST06::deleteNode(BST06Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteNode(node->getLeft());
    deleteNode(node->getRight());
    delete node;
}
