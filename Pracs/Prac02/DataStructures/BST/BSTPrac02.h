#pragma once

class BSTNodePrac02
{
public:
    BSTNodePrac02();
    BSTNodePrac02(int value, BSTNodePrac02* left = nullptr, BSTNodePrac02* right = nullptr);
    ~BSTNodePrac02();
    BSTNodePrac02(const BSTNodePrac02& other) = delete;
    BSTNodePrac02& operator=(const BSTNodePrac02& other) = delete;
    BSTNodePrac02(BSTNodePrac02&& other) noexcept;
    BSTNodePrac02& operator=(BSTNodePrac02&& other) noexcept;

    int data;
    BSTNodePrac02* left;
    BSTNodePrac02* right;
};

class BSTPrac02
{
public:
    BSTPrac02();
    ~BSTPrac02();
    BSTPrac02(const BSTPrac02& other);
    BSTPrac02& operator=(const BSTPrac02& other);
    BSTPrac02(BSTPrac02&& other) noexcept;
    BSTPrac02& operator=(BSTPrac02&& other) noexcept;
    void insert(int value);

    void deleteNode(BSTNodePrac02* node, int value);
    BSTNodePrac02* getNode(BSTNodePrac02* node, int value);
    BSTNodePrac02* findMax(BSTNodePrac02* node);
    void print(BSTNodePrac02* node);

private:
    BSTNodePrac02* insert(BSTNodePrac02* node, int value);
    BSTNodePrac02* copyNode(BSTNodePrac02* node);
    void deleteBST(BSTNodePrac02* node);
private:
    BSTNodePrac02* root;
};
