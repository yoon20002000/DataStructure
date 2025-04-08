#include "DT_OrderTree.h"

#include <iostream>

TreeNode::TreeNode() : data(), left(nullptr), right(nullptr)
{
}

TreeNode::TreeNode(char inData, TreeNode* inLeft, TreeNode* inRight) : data(inData), left(inLeft), right(inRight)
{
    
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

DT_OrderTree::DT_OrderTree()
{
    
}

DT_OrderTree::~DT_OrderTree()
{
    
}

void DT_OrderTree::solve()
{
    TreeNode* n7 = new TreeNode('D', nullptr, nullptr);
    TreeNode* n6 = new TreeNode('C', nullptr, nullptr);
    TreeNode* n5 = new TreeNode('B', nullptr, nullptr);
    TreeNode* n4 = new TreeNode('A', nullptr, nullptr);
    TreeNode* n3 = new TreeNode('/', n6, n7);
    TreeNode* n2 = new TreeNode('*', n4, n5);
    TreeNode* n1 = new TreeNode('-', n2, n3);

    std::cout<< "전위 "<<'\n';
    preOrder(n1);

    std::cout<< "\n중위 "<<'\n';
    inOrder(n1);

    std::cout<< "\n후위 "<<'\n';
    postOrder(n1);
}

void DT_OrderTree::preOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        std::cout<< root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void DT_OrderTree::inOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        std::cout<< root->data << " ";
        inOrder(root->right);
    }
}

void DT_OrderTree::postOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        std::cout<< root->data << " ";
    }
}
