#pragma once
#include <iostream>
#include <ostream>

class FolderTreeNode
{
public:
    FolderTreeNode() : size(0), left(nullptr), right(nullptr)
    {
        
    }
    FolderTreeNode(int data, FolderTreeNode* inLeft, FolderTreeNode* inRight) : size(data), left(inLeft), right(inRight)
    {
        
    }
    ~FolderTreeNode()
    {
        delete left;
        delete right;
    }
public:
    int size;
    FolderTreeNode* left;
    FolderTreeNode* right;
};

class DT_CalcFolderSize
{
public:
    int calcFolderSize(FolderTreeNode* FolderTreeNode)
    {
        int size = FolderTreeNode->size;
        if (FolderTreeNode->left != nullptr)
        {
            size += calcFolderSize(FolderTreeNode->left);    
        }

        if (FolderTreeNode->right != nullptr)
        {
            size += calcFolderSize(FolderTreeNode->right);    
        }
        
        return size;
    }
    
    void solve()
    {
        FolderTreeNode* F11 = new FolderTreeNode(120, nullptr, nullptr);
        FolderTreeNode* F10 = new FolderTreeNode(55, nullptr, nullptr);
        FolderTreeNode* F9 = new FolderTreeNode(100, nullptr, nullptr);
        FolderTreeNode* F8 = new FolderTreeNode(200, nullptr, nullptr);
        FolderTreeNode* F7 = new FolderTreeNode(68, F10, F11);
        FolderTreeNode* F6 = new FolderTreeNode(40, nullptr, nullptr);
        FolderTreeNode* F5 = new FolderTreeNode(15, nullptr, nullptr);
        FolderTreeNode* F4 = new FolderTreeNode(2, F8, F9);
        FolderTreeNode* F3 = new FolderTreeNode(10, F6, F7);
        FolderTreeNode* F2 = new FolderTreeNode(0, F4, F5);
        FolderTreeNode* F1 = new FolderTreeNode(0, F2, F3);

        std::cout<< "F1 : " << calcFolderSize(F1)<<'\n';
        std::cout<< "F2 : " << calcFolderSize(F2)<<'\n';
        std::cout<< "F3 : " << calcFolderSize(F3)<<'\n';
    }
};
