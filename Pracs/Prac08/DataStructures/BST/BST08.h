#pragma once
class BST08Node
{
public:
    BST08Node(int inData);
    ~BST08Node() = default;
    BST08Node(const BST08Node& other) = delete;
    BST08Node& operator=(const BST08Node& other) = delete;
    BST08Node(BST08Node&& other) = delete;
    BST08Node& operator=(BST08Node&& other) = delete;
    
private:
    int data;
    BST08Node* left;
    BST08Node* right;

    friend class BST08;
};

class BST08
{
public:
    BST08();
    ~BST08();
    BST08(const BST08& other);
    BST08& operator=(const BST08& other);
    BST08(BST08&& other) noexcept;
    BST08& operator=(BST08&& other) noexcept;

    void insertData(int data);
    void deleteData(int data);
    BST08Node* searchData(int data);
    
private:
    BST08Node* insertData(BST08Node* node, int data);
    BST08Node* deleteData(BST08Node* node, int data);
    BST08Node* searchData(BST08Node* node, int data);
    
    BST08Node* copyBST(BST08Node* node);
    BST08Node* deleteBST(BST08Node* node);
    BST08Node* findMax(BST08Node* node) const;
private:
    BST08Node* root;
};
