#pragma once

class BT04Node
{
public:
    BT04Node();
    BT04Node(int value, BT04Node* left = nullptr, BT04Node* right = nullptr);
    ~BT04Node();
    BT04Node(const BT04Node&) = delete;
    BT04Node& operator=(const BT04Node&) = delete;
    BT04Node(BT04Node&& other) noexcept;
    BT04Node& operator=(BT04Node&& other) noexcept;

public:
    int data;
    BT04Node* left;
    BT04Node* right;
};

class BT04
{
public:
    BT04();
    ~BT04();
    BT04(const BT04& other);
    BT04& operator=(const BT04& other);
    BT04(BT04&& other) noexcept;
    BT04& operator=(BT04&& other) noexcept;

    void printPreOrder(BT04Node* node);
    void printInOrder(BT04Node* node);
    void printPostOrder(BT04Node* node);
private:
    void deleteTree(BT04Node* node);
    BT04Node* copyTree(BT04Node* node);
public:
    BT04Node* root;
};
