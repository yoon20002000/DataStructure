#pragma once

class BST06Node
{
public:
    BST06Node();
    BST06Node(int inData, BST06Node* inLeft = nullptr, BST06Node* inRight = nullptr);
    ~BST06Node();
    BST06Node(const BST06Node&) = delete;
    BST06Node& operator=(const BST06Node&) = delete;
    BST06Node(BST06Node&&) = delete;
    BST06Node& operator=(BST06Node&&) = delete;

    int getData() const;
    void setData(int inData);
    BST06Node* getLeft() const;
    void setLeft(BST06Node* inLeft);
    BST06Node* getRight() const;
    void setRight(BST06Node* inRight);

    bool isFullNode() const;
    bool hasOneChild() const;
    bool hasNoChild() const;
    
private:
    int data;
    BST06Node* left;
    BST06Node* right;
};

class BST06
{
public:
    BST06();
    ~BST06();
    BST06(const BST06& other) = delete;
    BST06& operator=(const BST06& other)= delete;
    BST06(BST06&& other) = delete;
    BST06& operator=(BST06&& other) = delete;

    void insertData(int inData);
    const BST06Node* getNode(int inData) const;
    void deleteData(int inData);
    
private:
    BST06Node* getMax(BST06Node* node);
    BST06Node* insert(BST06Node* node, int inData);
    const BST06Node* search(BST06Node* node, int inData) const;
    BST06Node* deleteNode(BST06Node* node, int inData);
    void deleteNode(BST06Node* node);
private:
    BST06Node* root;
};
