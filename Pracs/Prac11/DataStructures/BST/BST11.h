#pragma once
class BST11Node
{
public:
    BST11Node(int inValue);
    ~BST11Node() = default;
    BST11Node(const BST11Node&) = delete;
    BST11Node& operator=(const BST11Node&) = delete;
    BST11Node(BST11Node&&) = delete;
    BST11Node& operator=(BST11Node&&) = delete;

private:
    int value;
    BST11Node* left;
    BST11Node* right;

    friend class BST11;
};
class BST11
{
public:
    BST11();
    ~BST11();
    BST11(const BST11& other);
    BST11& operator=(const BST11& other);
    BST11(BST11&& other) noexcept;
    BST11& operator=(BST11&& other) noexcept;

    void insert(int value);
    void remove(int value);
    BST11Node* search(int value);

private:
    BST11Node* insertNode(BST11Node* node, int value);
    BST11Node* removeNode(BST11Node* node, int value);
    BST11Node* searchNode(BST11Node* node, int value);

    BST11Node* findMax(BST11Node* node) const;
    
    BST11Node* copyTree(BST11Node* node);
    void deleteTree(BST11Node* node);
private:
    BST11Node* root;
};
