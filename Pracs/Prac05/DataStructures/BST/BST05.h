#pragma once

class BST05Node
{
public:
    BST05Node();
    BST05Node(int val, BST05Node* left = nullptr, BST05Node* right = nullptr);
    ~BST05Node();
    BST05Node(const BST05Node& other) = delete;
    BST05Node& operator=(const BST05Node& other) = delete;
    BST05Node(BST05Node&& other) noexcept;
    BST05Node& operator=(BST05Node&& other) noexcept;

    int data;
    BST05Node* left;
    BST05Node* right;
};

class BST05
{
public:
    BST05();
    ~BST05();
    BST05(const BST05& other);
    BST05& operator=(const BST05& other);
    BST05(BST05&& other) noexcept;
    BST05& operator=(BST05&& other) noexcept;

    void insert(int data);
    void deleteData(int data);
    BST05Node* search(int data);
    
private:
    
    BST05Node* insert(BST05Node* node, int data);
    BST05Node* search(BST05Node* node, int data);
    BST05Node* deleteNode(BST05Node* node, int data);

    BST05Node* findMax(BST05Node* node);

    BST05Node* copyTree(BST05Node* node);
    void deleteTree(BST05Node* node);
    
    BST05Node* root;
};
