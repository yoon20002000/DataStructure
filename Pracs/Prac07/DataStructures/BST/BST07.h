#pragma once

class BST07Node
{
public:
    BST07Node(int inData);
    bool isEmptyChild() const;
    bool isFullChild() const;
    bool isOneChild() const;
    
private:
    int data;
    BST07Node* left;
    BST07Node* right;

    friend class BST07;
};

class BST07
{
public:
    BST07();
    ~BST07();

    void insert(int data);
    void remove(int data);
    BST07Node* search(int data);

private:
    BST07Node* insertNode(BST07Node* node, int data);
    BST07Node* deleteNode(BST07Node* node, int data);
    BST07Node* searchNode(BST07Node* node, int data);
    BST07Node* findMaxNode(BST07Node* node) const;
    
    void deleteTree(BST07Node* node);
private:
    BST07Node* root;
};
