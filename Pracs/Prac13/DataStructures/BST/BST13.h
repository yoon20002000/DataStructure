#pragma once
class BST13Node
{
public:
    BST13Node(int inValue);
    ~BST13Node() = default;
    BST13Node(const BST13Node& inNode) = delete;
    BST13Node& operator=(const BST13Node& inNode) = delete;
    BST13Node(BST13Node&& inNode) = delete;
    BST13Node& operator=(BST13Node&& inNode) = delete;

private:
    int value;
    BST13Node* left;
    BST13Node* right;
    friend class BST13;
};

class BST13
{
public:
    BST13();
    ~BST13();
    BST13(const BST13& other);
    BST13& operator=(const BST13& other);
    BST13(BST13&& other) noexcept;
    BST13& operator=(BST13&& other) noexcept;

    void insert(int inValue);
    void remove(int inValue);
    BST13Node* find(int inValue) const;

private:
    BST13Node* insertNode(BST13Node* node, int inValue);
    BST13Node* removeNode(BST13Node* node, int inValue);
    BST13Node* findNode(BST13Node* node, int inValue) const;

    BST13Node* copyTree(BST13Node* node);
    void deleteTree(BST13Node* node);

    BST13Node* findMax(BST13Node* node) const;
private:
    BST13Node* root;
};
