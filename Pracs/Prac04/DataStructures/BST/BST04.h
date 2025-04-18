#pragma once

class BST04Node
{
public:
    BST04Node();
    BST04Node(int data, BST04Node* left = nullptr, BST04Node* right = nullptr);
    ~BST04Node();
    BST04Node(const BST04Node& other) = delete;
    BST04Node& operator=(const BST04Node& other) = delete;
    BST04Node(BST04Node&& other) noexcept;
    BST04Node& operator=(BST04Node&& other) noexcept;

public:
    int data;
    BST04Node* left;
    BST04Node* right;
};

class BST04
{
public:
    BST04();
    ~BST04();
    BST04(const BST04& other);
    BST04& operator=(const BST04& other);
    BST04(BST04&& other) noexcept;
    BST04& operator=(BST04&& other) noexcept;
    void insertData(int data);
    void deleteData(int data);

    BST04Node* search(BST04Node* node, int data);

private:
    BST04Node* insert(BST04Node* node,int data);
    BST04Node* deleteNode(BST04Node* node, int data);
    BST04Node* findMax(BST04Node* node);
    BST04Node* copyNode(BST04Node* node);
    BST04Node* deleteTree(BST04Node* node);

public:
    BST04Node* root;
};
