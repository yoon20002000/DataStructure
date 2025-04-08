#include "DT_BinarySearchTree.h"

#include <cstdlib>
#include <iostream>

#include "DT_OrderTree.h"

BinarySearchTreeNode* DT_BinarySearchTree::SearchNode(BinarySearchTreeNode* node, int inData)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == inData)
    {
        return node;
    }
    
    if (node->data > inData)
    {
        SearchNode(node->left, inData);
    }
    else
    {
        SearchNode(node->right, inData);
    }
}

BinarySearchTreeNode* DT_BinarySearchTree::InsertNode(BinarySearchTreeNode* node, int data)
{
    if (node == nullptr)
    {
        return new BinarySearchTreeNode(data);
    }

    if (node->data > data)
    {
        node->left = InsertNode(node->left, data);
    }
    else if (node->data < data)
    {
        node->right = InsertNode(node->right, data);
    }
    else
    {
        std::cout << "is have same value already" << '\n';
    }
    return node;
}

void DT_BinarySearchTree::DeleteNode(BinarySearchTreeNode* node, int data)
{
    BinarySearchTreeNode* targetNode = node;
    BinarySearchTreeNode* parent = nullptr;
    while (targetNode != nullptr && targetNode->data != data)
    {
        parent = targetNode;
        if (targetNode->data > data)
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
        std::cout << "not exist" << '\n';
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
        BinarySearchTreeNode* childNode = targetNode->left != nullptr ? targetNode->left : targetNode->right;
        if (parent != nullptr)
        {
            if (parent->left == targetNode)
            {
                parent->left = childNode;
            }
            else
            {
                parent->right = childNode;
            }
        }
        else
        {
            root = childNode;
        }
    }
    else
    {
        BinarySearchTreeNode* q = findMax(root->left);
        targetNode->data=q->data;
        DeleteNode(targetNode->left,targetNode->data);
    }
}

void DT_BinarySearchTree::DisplayNodes(BinarySearchTreeNode* node)
{
    if (node != nullptr)
    {
        DisplayNodes(node->left);
        std::cout<< node->data << "_";
        DisplayNodes(node->right);
    }
}

void DT_BinarySearchTree::solve()
{
    root = new BinarySearchTreeNode('G');
    InsertNode(root,'I');
    InsertNode(root,'H');
    InsertNode(root,'D');
    InsertNode(root,'B');
    InsertNode(root,'M');
    InsertNode(root,'N');
    InsertNode(root,'A');
    InsertNode(root,'J');
    InsertNode(root,'E');
    InsertNode(root,'Q');

    int choice ;
    while (true)
    {
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            default:
            {
                DisplayNodes(root);
                break;
            }
        case 2:
            {
                std::cout << "Data를 입력하시오 : ";
                char data;
                std::cin>>data;
                InsertNode(root,data);
                break;
            }
        case 3:
            {
                std::cout << "삭제할 data를 입력하시오 : ";
                char data;
                std::cin>>data;
                DeleteNode(root,data);
                break;
            }
        case 4:
            {
                std::cout<<"찾을 data를 입력하시오 : ";
                char data;
                std::cin>>data;
                BinarySearchTreeNode* node = SearchNode(root,data);

                if (node != nullptr)
                {
                    std::cout<<"찾았습니다. : " << node->data<<'\n';
                }
                break;
            }
        }
        
    }
}

BinarySearchTreeNode* DT_BinarySearchTree::findMax(BinarySearchTreeNode* node)
{
    BinarySearchTreeNode* cur = node;
    while (cur->right!=nullptr)
    {
        cur = cur->right;
    }
    return cur;
}
