#pragma once

class BST14Node
{
public:
    BST14Node(int inValue);
    ~BST14Node();
    BST14Node(const BST14Node& inNode) = delete;
    BST14Node& operator=(const BST14Node& inNode) = delete;
    BST14Node(BST14Node&& inNode) = delete;
    BST14Node& operator=(BST14Node&& inNode) = delete;

private:
    int value;
    BST14Node* left;
    BST14Node* right;
    friend class BST14;
};

class BST14
{
public:
    BST14();
    ~BST14();
    BST14(const BST14& other);
    BST14& operator=(const BST14& other);
    BST14(BST14&& other) noexcept;
    BST14& operator=(BST14&& other) noexcept;

    void insert(int value);
    void remove(int value);
    BST14Node* search(int value);
    
private:
    BST14Node* insertNode(BST14Node* node, int value);
    BST14Node* removeNode(BST14Node* node, int value);
    BST14Node* searchNode(BST14Node* node, int value);

    BST14Node* findMax(BST14Node* node);
    
    BST14Node* copyTree(BST14Node* node);
    void deleteTree(BST14Node* node);
private:
    BST14Node* root;
};
