#pragma once
class BST10Node
{
public:
    BST10Node(int inData);
private:
    int data;
    BST10Node* left;
    BST10Node* right;
    friend class BST10;
};
class BST10
{
public:
    BST10();
    ~BST10();
    BST10(const BST10& other);
    BST10& operator=(const BST10& other);
    BST10(BST10&& other) noexcept;
    BST10& operator=(BST10&& other) noexcept;

    void insertNode(int data);
    void deleteNode(int data);
    BST10Node* searchNode(int data);

private:
    BST10Node* insertNode(BST10Node* node, int data);
    BST10Node* deleteNode(BST10Node* node, int data);
    BST10Node* searchNode(BST10Node* node, int data);
    BST10Node* findMaxNode(BST10Node* node);

    void deleteBST(BST10Node* node);
    BST10Node* copyBST(BST10Node* node);
    
private:
    BST10Node* root;
};
