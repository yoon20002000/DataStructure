#pragma once
class BST09Node
{
public:
    BST09Node(int inData);
    ~BST09Node() = default;
    BST09Node(const BST09Node& other) = delete;
    BST09Node& operator=(const BST09Node& other) = delete;
    BST09Node(BST09Node&& other) = delete;
    BST09Node& operator=(BST09Node&& other) = delete;
private:
    int data;
    BST09Node* left;
    BST09Node* right;

    friend class BST09;
};

class BST09
{
public:
    BST09();
    ~BST09();
    BST09(const BST09& other);
    BST09& operator=(const BST09& other);
    BST09(BST09&& other) noexcept;
    BST09& operator=(BST09&& other) noexcept;

    void insert(int data);
    void remove(int data);
    BST09Node* search(int data);

private:
    BST09Node* insertNode(BST09Node* node, int data);
    BST09Node* removeNode(BST09Node* node, int data);
    BST09Node* searchNode(BST09Node* node, int data);

    BST09Node* copyBST(BST09Node* node);
    BST09Node* deleteBST(BST09Node* node);

    BST09Node* findMax(BST09Node* node);
private:
    BST09Node* root;
};
