#pragma once

class BST15Node
{
public:
    BST15Node(int value);
    ~BST15Node() = default;
    BST15Node(const BST15Node& other) = default;
    BST15Node& operator=(const BST15Node& other) = default;
    BST15Node(BST15Node&& other) = delete;
    BST15Node& operator=(BST15Node&& other) = delete;
    
private:
    int value;
    BST15Node* left;
    BST15Node* right;

    friend class BST15;
};

class BST15
{
public:
    BST15();
    ~BST15();
    BST15(const BST15& other);
    BST15& operator=(const BST15& other);
    BST15(BST15&& other) noexcept;
    BST15& operator=(BST15&& other) noexcept;

    void insertData(int value);
    void deleteData(int value);
    BST15Node* findData(int value) const;
private:
    BST15Node* insertNode(BST15Node* node, int value);
    BST15Node* deleteNode(BST15Node* node, int value);
    BST15Node* findNode(BST15Node* node, int value) const;

    BST15Node* findMax(BST15Node* node) const;
    
    void deleteTree(BST15Node* node);
    BST15Node* copyTree(BST15Node* node);
    
private:
    BST15Node* root;
};
