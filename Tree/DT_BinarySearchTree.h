#pragma once

class BinarySearchTreeNode
{
public:
    BinarySearchTreeNode() : data(0), left(nullptr), right(nullptr)
    {
        
    }
    BinarySearchTreeNode(char data) : data(data), left(nullptr), right(nullptr)
    {
        
    }

    BinarySearchTreeNode(char inData, BinarySearchTreeNode* inLeft, BinarySearchTreeNode* inRight)
                                        : data(inData), left(inLeft), right(inRight)
    {
        
    }
    ~BinarySearchTreeNode()
    {
        delete left;
        delete right;
    }

public:
    char data;
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
};

class DT_BinarySearchTree
{
public:
    BinarySearchTreeNode* SearchNode(BinarySearchTreeNode* node, int inData);
    BinarySearchTreeNode* InsertNode(BinarySearchTreeNode* node,int data);
    void DeleteNode(BinarySearchTreeNode* node, int data);
    void DisplayNodes(BinarySearchTreeNode* node);

    void solve();
private:
    BinarySearchTreeNode* findMax(BinarySearchTreeNode* node);
    
private:
    BinarySearchTreeNode* root;
};
