#pragma once

class TreeNode
{
public:
    TreeNode();
    TreeNode(char inData, TreeNode* inLeft, TreeNode* inRight);
    ~TreeNode();
public:
    char data;
    TreeNode* left;
    TreeNode* right;
};

class DT_OrderTree
{
public:
    DT_OrderTree();
    ~DT_OrderTree();
public:
    void solve();
private:
    void preOrder(TreeNode* root);
    void inOrder(TreeNode* root);
    void postOrder(TreeNode* root);
};
