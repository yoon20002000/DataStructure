#pragma once
class BSTNode16
{
public:
    BSTNode16(int inValue);
    ~BSTNode16() = default;
    BSTNode16(const BSTNode16& other) = delete;
    BSTNode16& operator=(const BSTNode16& other) = delete;
    BSTNode16(BSTNode16&& other) = delete;
    BSTNode16& operator=(BSTNode16&& other) = delete;
private:
    int value;
    BSTNode16* left;
    BSTNode16* right;
    friend class BST16;
};

class BST16
{
public:
    BST16();
    ~BST16();
    BST16(const BST16& other);
    BST16& operator=(const BST16& other);
    BST16(BST16&& other) noexcept;
    BST16& operator=(BST16&& other) noexcept;

    void insert(int value);
    void remove(int value);
    BSTNode16* find(int value) const;
private:
    BSTNode16* insertNode(BSTNode16* node, int value);
    BSTNode16* removeNode(BSTNode16* node, int value);
    BSTNode16* findNode(BSTNode16* node, int value) const;

    BSTNode16* copyTree(BSTNode16* node);
    void deleteTree(BSTNode16* node);
    BSTNode16* findMax(BSTNode16* node) const;
private:
    BSTNode16* root;
};
