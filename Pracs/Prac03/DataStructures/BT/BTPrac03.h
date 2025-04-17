#pragma once

class BTPrac03Node
{
public:
    BTPrac03Node();
    BTPrac03Node(int data, BTPrac03Node* left = nullptr, BTPrac03Node* right = nullptr);
    ~BTPrac03Node();
    BTPrac03Node(const BTPrac03Node& other) = delete;
    BTPrac03Node& operator=(const BTPrac03Node& other) = delete;
    BTPrac03Node(BTPrac03Node&& other) noexcept;
    BTPrac03Node& operator=(BTPrac03Node&& other)noexcept;

public:
    int data;
    BTPrac03Node* left;
    BTPrac03Node* right;
};

class BTPrac03
{
public:
    BTPrac03();
    ~BTPrac03();
    BTPrac03(const BTPrac03& other);
    BTPrac03& operator=(const BTPrac03& other);
    BTPrac03(BTPrac03&& other) noexcept;
    BTPrac03& operator=(BTPrac03&& other)noexcept;

    void printPreOrder(BTPrac03Node* node);
    void printInOrder(BTPrac03Node* node);
    void printPostOrder(BTPrac03Node* node);
private:
    BTPrac03Node* copyBTNode(BTPrac03Node* node);
    void deleteBTNode(BTPrac03Node* node);
private:
    BTPrac03Node* root;
};
